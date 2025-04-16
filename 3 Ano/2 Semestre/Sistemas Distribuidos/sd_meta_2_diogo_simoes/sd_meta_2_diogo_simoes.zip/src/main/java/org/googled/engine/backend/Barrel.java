package org.googled.engine.backend;

import java.io.FileInputStream;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Properties;

import org.googled.engine.backend.Downloader.PageContent;
import org.googled.engine.backend.exceptions.UnavailableWorkerException;
import org.googled.engine.backend.interfaces.BarrelInterface;
import org.googled.engine.backend.interfaces.GatewayInterface;
import org.googled.engine.backend.interfaces.ProtocolInterface;
import org.googled.engine.backend.utilities.Heartbeat;

import java.util.ArrayList;
import java.util.HashMap;
import java.io.Serializable;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import java.io.File;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.HashSet;

/**
 * Represents a multicast message receiver that joins a multicast group
 * and listens for incoming messages while opening an RMI registry to
 * allow external remote access to its information.
 */
public class Barrel extends UnicastRemoteObject implements BarrelInterface, ProtocolInterface {
    /**
     * Project's global logger implementation.
     * Logs to the console and to a shared generated log file.
     */
    final private static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(Barrel.class);

    /**
     * Expected directory path to the gateway properties file.
     */
    final private static String GATEWAY_CONFIG = "gateway.properties";

    /**
     * Expected directory path to the multicast properties file.
     */
    final private static String MULTICAST_CONFIG = "multicast.properties";

    /**
     * Expected directory path to the downloader properties file.
     */
    final private static String BARREL_CONFIG = "barrel.properties";

    /**
     * Target directory for the generated data storage file.
     */
    final private static String DATA_PATH = "data/Barrel.data";

    /**
     * Max amount of urls that can be indexed at any given time.
     */
    final private int MAX_INDEXED;

    /**
     * Represents the connection to the gateway.
     */
    private GatewayInterface gateway;

    /**
     * Represents the gateway hearbeat checking thread.
     */
    public Thread hearbeat;

    /**
     * Represents the multicast receiver thread.
     */
    public Thread multigetter;

    /**
     * Represents the list of indexed pages and their respective content.
     */
    public volatile Index index;

    /**
     * Constructs the barrel with an empty search list and the gateway connection.
     *
     * @param gateway the gateway connection to be used.
     * @param max     the maximum amount of URLs to be stored in the barrel.
     * @throws RemoteException if there is an issue with the remote communication.
     */

    public Barrel(GatewayInterface gateway, int max) throws RemoteException {
        super();
        this.gateway = gateway;
        this.index = new Index();
        this.MAX_INDEXED = max;
    }

    /**
     * Instantiates the class as a storage barrel worker process.
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

            LOGGER.info("Loading \"{}\" file to acquire multicast properties.", MULTICAST_CONFIG);

            properties.load(Thread.currentThread().getContextClassLoader()
                    .getResourceAsStream(MULTICAST_CONFIG));
            String multicastHost = properties.getProperty("MULTICAST_HOST");
            int multicastPort = Integer.parseInt(properties.getProperty("MULTICAST_PORT"));

            LOGGER.info("Loading \"{}\" file to acquire barrel properties.", BARREL_CONFIG);
            properties.load(Thread.currentThread().getContextClassLoader()
                    .getResourceAsStream(BARREL_CONFIG));
            int max = Integer.parseInt(properties.getProperty("MAX_INDEXED"));

            LOGGER.info("Setting security policy and gateway server hostname system properties!");

            System.setProperty("java.security.policy", "policy.all");
            System.setProperty("java.rmi.server.hostname", rmiHost);

            LOGGER.info("Joining multicast group at {}:{}", multicastHost, multicastPort);
            MulticastSocket socket = new MulticastSocket(multicastPort);
            InetAddress address = InetAddress.getByName(multicastHost);
            socket.joinGroup(new InetSocketAddress(address, 0), NetworkInterface.getByIndex(0));

            LOGGER.info("Group for receiving information joined successfuly.");

            LOGGER.info("Looking at {}:{} for {} named RMI registry.", rmiHost, rmiPort, rmiName);

            GatewayInterface gateway = (GatewayInterface) LocateRegistry.getRegistry(rmiHost, rmiPort).lookup(rmiName);

            LOGGER.info("Found gateway, reseting system RMI server hostname property.");

            System.setProperty("java.rmi.server.hostname", InetAddress.getLocalHost().getHostAddress());

            LOGGER.info("Instantiating barrel and heartbeat + receiver threads.");

            Barrel barrel = new Barrel(gateway, max);
            barrel.multigetter = barrel.new Multigetter(socket, "receiver");
            barrel.hearbeat = new Heartbeat(gateway, "heartbeat");

            LOGGER.info("Instantiated correctly.");

            LOGGER.info("Adding shutdown hook.");

            Runtime.getRuntime().addShutdownHook(new Thread() {
                @Override
                public void run() {
                    synchronized (barrel) {
                        LOGGER.info(
                                "Got shutdown signal, unregistering barrel from gateway and sending interrupt to threads.");
                        try {
                            barrel.gateway.unregisterBarrel(barrel);
                            barrel.multigetter.interrupt();
                            barrel.notify();
                            LOGGER.info("Barrel successfully unregistered.");
                        } catch (RemoteException e) {
                            LOGGER.error("Could not unregister barrel from gateway!");
                        } finally {
                            LOGGER.info("Process exited.");
                        }

                    }
                }
            });

            LOGGER.info("Hook added.");

            LOGGER.info("Registering barrel with gateway.");

            barrel.gateway.registerBarrel(barrel);

            LOGGER.info("Registration successful.");

            synchronized (barrel) {
                barrel.wait();
            }

        } catch (Exception error) {
            LOGGER.error("{}!", error.getMessage());
            LOGGER.info("Process exited.");
            System.exit(1);
        }
    }

    @Override
    public void work() throws RemoteException {
        LOGGER.info("Requesting sync with other established barrels.");
        try {
            gateway.syncBarrels();
        } catch (UnavailableWorkerException error) {
            LOGGER.warn("{}! Skipping to local index load.", error.getMessage());
            load();
        } catch (RemoteException error) {
            LOGGER.error("{}! Connection to gateway lost, stopping barrel.", error.getMessage());
            System.exit(1);
        }
        LOGGER.info("Sync finished. Starting multicast receiver thread!");

        multigetter.start();
        hearbeat.start();
    }

    @Override
    public int getIndexedCount() throws RemoteException {
        return index.metadata.size();
    }

    @Override
    public void syncQueries(HashMap<String, Integer> queries) throws RemoteException {
        index.queries = queries;
    }

    @Override
    public boolean isFull() throws RemoteException {
        return index.metadata.size() >= MAX_INDEXED;
    }

    @Override
    public boolean isIndexed(String url) throws RemoteException {
        return index.metadata.containsKey(url);
    }

    @Override
    public void setIndex(Index index) throws RemoteException {
        this.index = index;
    }

    @Override
    public Index getIndex() throws RemoteException {
        return index;
    }

    @Override
    public HashSet<String> getPointingURLs(String url) throws RemoteException {
        LOGGER.info("Requested to get all pointing URLs to URL {} from index.", url);
        return index.pointers.getOrDefault(url, new HashSet<>());
    }

    @Override
    public LinkedHashMap<String, PageMetadata> searchQuery(String query) throws RemoteException {
        LOGGER.info("Requested to search for query \"{}\" in indexed pages.", query);
        LinkedHashMap<String, PageMetadata> results = new LinkedHashMap<>();
        LinkedHashMap<String, PageMetadata> sortedResultsMap = new LinkedHashMap<>();

        String lowerQuery = query.toLowerCase();

        for (String word : lowerQuery.split(" ")) {
            if (index.words.containsKey(word)) {
                for (String url : index.words.get(word)) {
                    if (results.containsKey(url)) {
                        results.get(url).title = index.metadata.get(url).title;
                        results.get(url).description = index.metadata.get(url).description;
                    } else {
                        results.put(url,
                                new PageMetadata(index.metadata.get(url).title, index.metadata.get(url).description));
                    }
                }
            }
        }

        if (results != null && index != null && index.pointers != null) {
            List<Map.Entry<String, PageMetadata>> list = new ArrayList<>(results.entrySet());

            list.sort((entry1, entry2) -> index.pointers.getOrDefault(entry2.getKey(), new HashSet<>()).size()
                    - index.pointers.getOrDefault(entry1.getKey(), new HashSet<>()).size());

            for (Map.Entry<String, PageMetadata> entry : list) {
                sortedResultsMap.put(entry.getKey(), entry.getValue());
            }
        }

        LOGGER.info("Got {} results for query \"{}\" from index.", sortedResultsMap.size(), query);

        LOGGER.info("Adding query to index.");

        index.queries.put(lowerQuery, index.queries.getOrDefault(lowerQuery, 0) + 1);

        save();

        try {
            LOGGER.info("Sending top ten queries to gateway.");
            gateway.updateTopTenQueries(getTopTenQueries());
        } catch (RemoteException error) {
            LOGGER.error("{}! Connection to gateway lost, stopping barrel.", error.getMessage());
            System.exit(1);
        }

        return sortedResultsMap;
    }

    @Override
    public LinkedHashMap<String, Integer> getTopTenQueries() throws RemoteException {
        LOGGER.info("Requested to get top ten queries from index.");
        LinkedHashMap<String, Integer> sortedQueries = new LinkedHashMap<>();
        List<Map.Entry<String, Integer>> list = new ArrayList<>(index.queries.entrySet());
        list.sort((entry1, entry2) -> entry2.getValue() - entry1.getValue());

        for (int i = 0; i < 10 && i < list.size(); i++) {
            sortedQueries.put(list.get(i).getKey(), list.get(i).getValue());
        }

        return sortedQueries;
    }

    /**
     * Saves the current index to a file.
     *
     */
    private void save() {
        try {
            synchronized (this) {
                LOGGER.info("Trying to save updated index to file.");
                String directory = DATA_PATH.substring(0, DATA_PATH.lastIndexOf("/"));
                new File(directory).mkdirs();
                ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(DATA_PATH));
                output.writeObject(index);
                output.close();
                LOGGER.info("Index saved successfully to file.");
            }

        } catch (Exception error) {
            LOGGER.error("{}; Failed to save index contents to file!", error.getMessage());
        }
    }

    /**
     * Loads the index from a file.
     *
     */
    private void load() {
        try {
            synchronized (this) {
                LOGGER.info("Trying to load the queue from existing save file.");
                if (!new File(DATA_PATH).exists()) {
                    LOGGER.info("No existing data file found, starting with an empty index.");
                    return;
                }
                LOGGER.info("Trying to load index from file.");
                ObjectInputStream input = new ObjectInputStream(new FileInputStream(DATA_PATH));
                index = (Index) input.readObject();
                input.close();
                LOGGER.info("Index loaded successfully from file.");
            }

        } catch (Exception error) {
            LOGGER.error("{}; Failed to load index contents from file, proceeding with an empty index!",
                    error.getMessage());
        }
    }

    /**
     * Represents a thread listening for multicast
     * messages from the socket group and decoding them
     * according to the project's protocol.
     */
    public class Multigetter extends Thread {
        private MulticastSocket socket;

        /**
         * Creates a receiver thread to listen for multicast messages.
         *
         * @param socket the multicast socket previously allocated and joined to a
         *               group.
         * @param name   the name to give to the thread for logging and identification
         *               purposes.
         */
        public Multigetter(MulticastSocket socket, String name) {
            super(name);
            this.socket = socket;
        }

        /**
         * Listen for incoming multicast messages and decodes them.
         *
         * <p>
         * Adds the decoded page to the barrel's index and words maps.
         * </p>
         */
        @Override
        public void run() {
            LOGGER.info("Thread started.");
            while (true) {
                try {
                    byte[] buffer = new byte[1024];
                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

                    LOGGER.info("Going to listen for new page contents from multicast group, blocking until received.");

                    if (index.metadata.size() >= MAX_INDEXED) {
                        LOGGER.warn("Received multicast packets, but barrel is full. Ignoring them.");
                        continue;
                    }

                    String section = new String();
                    ArrayList<String> sections = new ArrayList<>();

                    while (!section.endsWith("~")) {
                        socket.receive(packet);
                        section = new String(packet.getData(), 0, packet.getLength());
                        sections.add(section);
                    }

                    LOGGER.info("Got {} packets originating from {} address.", sections.size(),
                            (packet.getAddress() + ":" + packet.getPort()));

                    LOGGER.info("Last packet contained termination character, going to decode message.");

                    String message = String.join("", sections);

                    PageContent decoded = decodeContent(message);

                    LOGGER.info("Decoded page with URL {} from received multicast packets.", decoded.url);

                    LOGGER.info("Adding page contents to index.");

                    index.metadata.put(decoded.url, new PageMetadata(decoded.title, decoded.description));

                    for (String word : decoded.words) {
                        if (!index.words.containsKey(word)) {
                            index.words.put(word, new HashSet<>());
                        }
                        index.words.get(word).add(decoded.url);
                    }

                    for (String pointer : decoded.urls) {
                        if (!index.pointers.containsKey(pointer)) {
                            index.pointers.put(pointer, new HashSet<>());
                        }
                        index.pointers.get(pointer).add(decoded.url);
                    }

                    LOGGER.info("Page contents added to index.");

                    save();

                    LOGGER.info("Contents of page handled.", decoded.url);
                } catch (Exception error) {
                    LOGGER.error("{} : {}! Stopping barrel.", error.getMessage(), error);
                    System.exit(1);
                }

            }
        }
    }

    /**
     * Represents the barrel's index and all the other maps that are used to store
     * pages and their respective content.
     */
    public static class Index implements Serializable {

        /**
         * Serial version UID for serialization.
         */
        private static final long serialVersionUID = 1L;

        /**
         * Maps a URL to its respective page metadata.
         */
        public volatile HashMap<String, PageMetadata> metadata;

        /**
         * Represents the list of indexed urls and all the other urls that point to
         * them.
         */
        public volatile HashMap<String, HashSet<String>> pointers;

        /**
         * Represents the list of indexed words and the urls that contain them.
         */
        public volatile HashMap<String, HashSet<String>> words;

        /**
         * Represents the map for each query done and its respective count of past
         * occurrences.
         */
        public volatile HashMap<String, Integer> queries;

        /**
         * Constructs the index with empty maps.
         */
        public Index() {
            this.pointers = new HashMap<>();
            this.metadata = new HashMap<>();
            this.words = new HashMap<>();
            this.queries = new HashMap<>();
        }
    }

    /**
     * Represents the metadata of a web page
     */
    public static class PageMetadata implements Serializable {
        /**
         * The title of the page.
         */
        public String title;
        /**
         * The description of the page.
         */
        public String description;

        /**
         * Constructs the metadata with the given title and description.
         *
         * @param title       the title of the page.
         * @param description the description of the page.
         */
        public PageMetadata(String title, String description) {
            this.title = title;
            this.description = description;
        }
    }
}
