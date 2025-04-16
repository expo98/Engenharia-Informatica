package org.googled.engine.backend;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Properties;
import java.util.concurrent.LinkedBlockingQueue;

import org.googled.engine.backend.exceptions.EntryLimitMaxedException;
import org.googled.engine.backend.interfaces.GatewayInterface;
import org.googled.engine.backend.interfaces.QueueInterface;
import org.googled.engine.backend.utilities.Heartbeat;

/**
 * Represents a queue of URLs and provides methods for adding
 * and retrieving said URLs remotely, through its built-in RMI
 * interface.
 */
public class Queue extends UnicastRemoteObject implements QueueInterface {
    /**
     * Project's global logger implementation.
     * Logs to the console and to a shared generated log file.
     */
    final private static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(Queue.class);

    /**
     * Expected directory path to the gateway properties file.
     */
    final private static String GATEWAY_CONFIG = "gateway.properties";

    /**
     * Expected directory path to the queue properties file.
     */
    final private static String QUEUE_CONFIG = "queue.properties";

    /**
     * Target directory for the generated data storage file.
     */
    final private static String DATA_PATH = "data/Queue.data";

    /**
     * Max amount of urls to be stored in the queue at any given time.
     */
    final private int MAX_SIZE;

    /**
     * Structure to maintain URLs and the respective access synchronization.
     */
    private LinkedBlockingQueue<String> urls;

    /**
     * Represents the connection to the gateway.
     */
    private GatewayInterface gateway;

    /**
     * Represents the gateway hearbeat checking thread.
     */
    public Thread hearbeat;

    /**
     * Constructs the queue with an empty URL list and the gateway connection.
     *
     * @param gateway the gateway connection to be used.
     * @param max     the maximum amount of URLs to be stored in the queue.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    public Queue(GatewayInterface gateway, int max) throws RemoteException {
        super();
        this.urls = new LinkedBlockingQueue<>();
        this.gateway = gateway;
        this.MAX_SIZE = max;
    }

    /**
     * Instantiates the class as an RMI server.
     *
     * @param args command-line arguments (unused, properties file is used instead).
     */
    public static void main(String[] args) {
        try {
            LOGGER.info("Process started.");

            LOGGER.info("Loading \"{}\" file to acquire gateway properties.", GATEWAY_CONFIG);

            Properties properties = new Properties();
            properties.load(Thread.currentThread().getContextClassLoader()
                    .getResourceAsStream(GATEWAY_CONFIG));
            String rmiName = properties.getProperty("RMI_NAME");
            String rmiHost = properties.getProperty("RMI_HOST");
            int rmiPort = Integer.parseInt(properties.getProperty("RMI_PORT"));

            LOGGER.info("Loading \"{}\" file to acquire queue properties.", QUEUE_CONFIG);
            properties.load(Thread.currentThread().getContextClassLoader()
                    .getResourceAsStream(QUEUE_CONFIG));
            int max = Integer.parseInt(properties.getProperty("MAX_SIZE"));

            LOGGER.info("Setting security policy and gateway server hostname system properties!");

            System.setProperty("java.security.policy", "policy.all");
            System.setProperty("java.rmi.server.hostname", rmiHost);

            LOGGER.info("Looking for RMI gateway at [{}:{} -> {}] registry.", rmiHost, rmiPort, rmiName);

            GatewayInterface gateway = (GatewayInterface) LocateRegistry.getRegistry(rmiHost, rmiPort).lookup(rmiName);

            LOGGER.info("Found gateway, reseting system RMI server hostname property.");

            System.setProperty("java.rmi.server.hostname", InetAddress.getLocalHost().getHostAddress());

            LOGGER.info("Instantiating queue + heartbeat thread and loading.");

            Queue queue = new Queue(gateway, max);
            queue.hearbeat = new Heartbeat(gateway, "heartbeat");
            queue.load();

            LOGGER.info("Instantiated correctly.");

            LOGGER.info("Adding shutdown hook.");

            Runtime.getRuntime().addShutdownHook(new Thread() {
                @Override
                public void run() {
                    synchronized (queue) {
                        LOGGER.info("Got shutdown signal, unregistering queue from gateway.");
                        try {
                            queue.gateway.unregisterQueue(queue);
                            queue.notify();
                            LOGGER.info("Queue successfully unregistered.");
                        } catch (RemoteException e) {
                            LOGGER.error("Could not unregister queue from gateway!");
                        } finally {
                            LOGGER.info("Process exited.");
                        }

                    }
                }
            });

            LOGGER.info("Hook added.");

            LOGGER.info("Registering queue with gateway.");

            queue.gateway.registerQueue(queue);

            LOGGER.info("Registration successful.");

            LOGGER.info("Queue ready and accepting requests from gateway!");

            synchronized (queue) {
                queue.wait();
            }

        } catch (Exception error) {
            LOGGER.error("{}!", error.getMessage());
            LOGGER.info("Process exited.");
            System.exit(1);
        }
    }

    @Override
    public void work() throws RemoteException {
        LOGGER.info("Starting heartbeat thread.");
        hearbeat.start();
    }

    @Override
    public String get() throws RemoteException {
        LOGGER.info("Requested to take a URL.");
        while (true) {
            try {
                String url = urls.take();
                save();
                return url;
            } catch (InterruptedException error) {
                LOGGER.error("{}!", error.getMessage());
                throw new RemoteException("Method interrupted while waiting for URL to get taken from the queue");
            }
        }
    }

    @Override
    public void put(String url) throws RemoteException, IllegalArgumentException, EntryLimitMaxedException {
        LOGGER.info("Requested to add {} URL.", url);
        if (urls.size() >= MAX_SIZE) {
            LOGGER.warn("Queue is full, URL {} cannot be added!", url);
            throw new EntryLimitMaxedException("Queue is full, URL " + url + " cannot be added");
        }
        if (urls.contains(url)) {
            LOGGER.warn("URL {} is already in queue to be indexed!", url);
            throw new IllegalArgumentException("URL " + url + " is already in queue to be indexed");
        }
        this.urls.offer(url);
        // Maybe implement buffering to not save every time?
        save();
    }

    @Override
    public int size() throws RemoteException {
        LOGGER.info("Requested to give queue size.");
        return urls.size();
    }

    @Override
    public boolean contains(String url) throws RemoteException {
        LOGGER.info("Checking if URL {} is currently already in the queue.", url);
        return urls.contains(url);
    }

    /**
     * Saves the current queue content to a file, creating the file
     * and the respective directories if they do not exist.
     */

    private void save() {
        LOGGER.info("Trying to save updated queue to file.");
        try {
            synchronized (this) {
                String directory = DATA_PATH.substring(0, DATA_PATH.lastIndexOf("/"));
                new File(directory).mkdirs();
                ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(DATA_PATH));
                output.writeObject(urls);
                output.close();
                LOGGER.info("Queue successfully saved to file.");
            }
        } catch (Exception e) {
            LOGGER.error("{}; Failed to save the queue contents to file!", e.getMessage());
        }
    }

    /**
     * Loads the queue content from an existing file.
     *
     * <p>
     * Automatically checks if the file exists before trying to load it.
     * If it does not, the queue contents won't be modified.
     * </p>
     */

    @SuppressWarnings("unchecked")
    private void load() {
        if (!new File(DATA_PATH).exists()) {
            LOGGER.info("No existing data file found, starting with an empty queue.");
            return;
        }
        LOGGER.info("Trying to load the queue from existing save file.");
        try {
            synchronized (this) {
                ObjectInputStream input = new ObjectInputStream(new FileInputStream(DATA_PATH));
                urls = (LinkedBlockingQueue<String>) input.readObject();
                input.close();
                LOGGER.info("Queue successfully loaded from file.");
            }
        } catch (Exception e) {
            LOGGER.error(
                    "{}; Failed to load the queue contents from existing save file, proceeding with an empty queue!",
                    e.getMessage());
        }
    }
}
