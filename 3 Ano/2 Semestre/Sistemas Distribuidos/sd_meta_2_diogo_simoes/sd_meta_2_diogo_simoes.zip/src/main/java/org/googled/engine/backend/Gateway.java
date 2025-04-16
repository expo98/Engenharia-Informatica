package org.googled.engine.backend;

import java.rmi.NoSuchObjectException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.time.*;
import java.util.ArrayList;
import java.util.Properties;

import org.googled.engine.backend.Barrel.Index;
import org.googled.engine.backend.Barrel.PageMetadata;
import org.googled.engine.backend.exceptions.DuplicateComponentException;
import org.googled.engine.backend.exceptions.EntryLimitMaxedException;
import org.googled.engine.backend.exceptions.UnavailableWorkerException;
import org.googled.engine.backend.interfaces.BarrelInterface;
import org.googled.engine.backend.interfaces.ClientInterface;
import org.googled.engine.backend.interfaces.DownloaderInterface;
import org.googled.engine.backend.interfaces.GatewayInterface;
import org.googled.engine.backend.interfaces.QueueInterface;

import java.io.Serializable;
import java.util.LinkedHashMap;
import java.util.HashMap;

/**
 * Represents the heart of the architecture, the access point for all remote
 * communication between project components.
 */
public class Gateway extends UnicastRemoteObject implements GatewayInterface {
    /**
     * Project's global logger implementation.
     * Logs to the console and to a shared generated log file.
     */
    final private static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(Gateway.class);

    /**
     * Expected directory path to the gateway properties file.
     */
    final private static String GATEWAY_CONFIG = "gateway.properties";

    /**
     * Regex used to validate URLs.
     */
    final private static String URL_REGEX = "(https?://\\w{2,}\\..{2,})";

    /**
     * Reference to the current gateway statistics.
     */
    private volatile Stats stats;

    /**
     * Represents the RMI connection to the queue.
     */
    private volatile QueueInterface queue;

    /**
     * Represents the RMI connection to the downloaders.
     *
     */
    private volatile ArrayList<DownloaderInterface> downloaders;

    /**
     * Represents the currently connect barrels.
     *
     */
    private volatile ArrayList<BarrelInterface> barrels;

    /**
     * Represents the currently connect clients.
     */
    private volatile ArrayList<ClientInterface> clients;

    /**
     * Initializes the gateway with no connections and default stats.
     *
     * @throws RemoteException if there is an issue with the remote communication.
     */
    public Gateway() throws RemoteException {
        super();
        stats = new Stats();
        queue = null;
        downloaders = new ArrayList<DownloaderInterface>();
        barrels = new ArrayList<BarrelInterface>();
        clients = new ArrayList<ClientInterface>();
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
            properties.load(
                    Thread.currentThread().getContextClassLoader()
                            .getResourceAsStream(GATEWAY_CONFIG));
            String rmiName = properties.getProperty("RMI_NAME");

            String rmiHost = properties.getProperty("RMI_HOST");
            int rmiPort = Integer.parseInt(properties.getProperty("RMI_PORT"));

            LOGGER.info("Setting security policy and gateway server hostname system properties!");

            System.setProperty("java.security.policy", "policy.all");
            System.setProperty("java.rmi.server.hostname", rmiHost);

            LOGGER.info("Instantiating gateway.");

            Gateway gateway = new Gateway();

            LOGGER.info("Instantiated correctly.");

            LOGGER.info("Adding shutdown hook.");

            Runtime.getRuntime().addShutdownHook(new Thread() {
                @Override
                public void run() {
                    synchronized (gateway) {
                        LOGGER.info("Got shutdown signal, unexporting gateway from RMI registry.");
                        try {
                            UnicastRemoteObject.unexportObject(gateway, true);
                            gateway.notify();
                            LOGGER.info("Gateway successfully unexported.");
                        } catch (NoSuchObjectException error) {
                            LOGGER.error("Gateway was already unexported, ignoring.");
                        } catch (Exception error) {
                            LOGGER.error("{}!", error.getMessage());
                        } finally {
                            LOGGER.info("Process exited.");
                        }
                    }
                }
            });

            LOGGER.info("Hook added.");

            LOGGER.info("Creating RMI registry on local port {} with {} as the binding name.", rmiPort, rmiName);

            Registry registry = LocateRegistry.createRegistry(rmiPort);
            registry.rebind(rmiName, gateway);

            LOGGER.info("Successfully bound to RMI registry.");

            LOGGER.info("Gateway ready to be remotely accessed through RMI!");

            synchronized (gateway) {
                gateway.wait();
            }

        } catch (Exception error) {
            LOGGER.error("{}!", error.getMessage());
            LOGGER.info("Process exited.");
            System.exit(1);
        }
    }

    @Override
    public void heartbeat() throws RemoteException {
        LOGGER.info("Received heartbeat request.");
        return;
    }

    @Override
    public void registerQueue(QueueInterface queue) throws RemoteException, DuplicateComponentException {
        LOGGER.info("Received request to register queue.");
        if (this.queue != null) {
            throw new DuplicateComponentException(
                    "There is a queue already registered, only a single queue can be registered with the gateway any given time.");
        }
        try {
            this.queue = queue;
            stats.queueConnected = true;
            stats.queueSize = queue.size();
            broadcastStats();
            queue.work();
            LOGGER.info("Queue successfully registered.");
        } catch (RemoteException error) {
            LOGGER.error("{}! Failed to work with queue during registration, discarding it.", error.getMessage());
            this.queue = null;
            stats.queueConnected = false;
            throw error;
        }
    }

    @Override
    public void unregisterQueue(QueueInterface queue) throws RemoteException {
        LOGGER.info("Received request to unregister queue.");
        this.queue = null;
        stats.queueConnected = false;
        stats.queueSize = 0;
        broadcastStats();
        LOGGER.info("Queue successfully unregistered.");
    }

    @Override
    public void registerDownloader(DownloaderInterface downloader) throws RemoteException {
        LOGGER.info("Received request to register a downloader.");
        try {
            downloaders.add(downloader);
            stats.downloadersConnected++;
            broadcastStats();
            downloader.work();
            LOGGER.info("Downloader successfully registered.");
        } catch (RemoteException error) {
            LOGGER.error("{}! Failed to work with downloader during registration, discarding it.",
                    error.getMessage());
            unregisterDownloader(downloader);
        }
    }

    @Override
    public void unregisterDownloader(DownloaderInterface downloader) throws RemoteException {
        LOGGER.info("Received request to unregister a downloader.");
        if (downloaders.contains(downloader)) {
            downloaders.remove(downloader);
            stats.downloadersConnected--;
            broadcastStats();
            LOGGER.info("Downloader successfully unregistered.");
        } else {
            LOGGER.warn("Downloader requested to be unregistered is not registered, ignoring request.");
        }
    }

    @Override
    public void registerBarrel(BarrelInterface barrel) throws RemoteException {
        LOGGER.info("Received request to register a barrel.");
        try {
            barrels.add(barrel);
            stats.barrelsConnected++;
            broadcastStats();
            barrel.work();
            updateTopTenQueries(barrel.getTopTenQueries());
            LOGGER.info("Barrel successfully registered.");
        } catch (RemoteException error) {
            LOGGER.error("{}! Failed to work with barrel during registration, discarding it.", error.getMessage());
            unregisterBarrel(barrel);
        }
    }

    @Override
    public void unregisterBarrel(BarrelInterface barrel) throws RemoteException {
        LOGGER.info("Received request to unregister a barrel.");
        if (barrels.contains(barrel)) {
            barrels.remove(barrel);
            stats.barrelsConnected--;
            broadcastStats();
            LOGGER.info("Barrel successfully unregistered.");
        } else {
            LOGGER.warn("Barrel requested to be unregistered is not registered, ignoring request.");
        }
    }

    @Override
    public void registerClient(ClientInterface client) throws RemoteException {
        LOGGER.info("Received request to register a client.");
        clients.add(client);
        stats.clientsConnected++;
        broadcastStats();
        LOGGER.info("Client successfully registered.");
    }

    @Override
    public void unregisterClient(ClientInterface client) throws RemoteException {
        LOGGER.info("Received request to unregister a client.");
        if (clients.contains(client)) {
            clients.remove(client);
            stats.clientsConnected--;
            broadcastStats();
            LOGGER.info("Client successfully unregistered.");
        } else {
            LOGGER.warn("Client requested to be unregistered is not registered, ignoring request.");
        }
    }

    @Override
    public LinkedHashMap<String, PageMetadata> searchQuery(String query)
            throws RemoteException, UnavailableWorkerException {
        LOGGER.info("Received request to search for \"{}\" query.", query);
        LinkedHashMap<String, PageMetadata> results = new LinkedHashMap<String, PageMetadata>();
        for (BarrelInterface barrel : barrels) {
            try {
                results.putAll(barrel.searchQuery(query));
                LOGGER.info("Query \"{}\" successfully searched.", query);
                return results;
            } catch (RemoteException error) {
                LOGGER.error("Lost connection to barrel, unregistering it.");
                unregisterBarrel(barrel);
            }
        }
        LOGGER.error("No barrels connected, cannot search query, warning caller and throwing exception.");
        throw new UnavailableWorkerException("No barrels connected, cannot search query");
    }

    @Override
    public ArrayList<String> getPointingURLs(String url)
            throws RemoteException, UnavailableWorkerException, IllegalArgumentException {
        LOGGER.info("Received request to get pointers for \"{}\" URL.", url);

        if (!url.matches(URL_REGEX)) {
            LOGGER.warn("Requested to get pointers for invalid URL, ignoring request.");
            throw new IllegalArgumentException(
                    "Invalid URL format");
        }

        ArrayList<String> results = new ArrayList<String>();
        for (BarrelInterface barrel : barrels) {
            try {
                results.addAll(barrel.getPointingURLs(url));
                LOGGER.info("Pointers for \"{}\" URL successfully retrieved.", url);
                return results;
            } catch (RemoteException error) {
                LOGGER.error("Lost connection to barrel, unregistering it.");
                unregisterBarrel(barrel);
            }
        }
        LOGGER.error("No barrels connected, cannot get pointing URLs, warning caller and throwing exception.");
        throw new UnavailableWorkerException("No barrels connected, cannot get pointing URLs");
    }

    @Override
    public void updateTopTenQueries(LinkedHashMap<String, Integer> topTenQueries) throws RemoteException {
        LOGGER.info("Received updated top ten queries.");
        if (!stats.topTenQueries.equals(topTenQueries)) {
            stats.topTenQueries = topTenQueries;
            broadcastStats();
        }
    }

    @Override
    public void syncBarrels() throws RemoteException, UnavailableWorkerException {
        LOGGER.info("Received request to sync established barrels.");
        if (barrels.size() < 2) {
            LOGGER.warn("Only one barrel connected, warning caller and denying request.");
            throw new UnavailableWorkerException("Only one barrel connected, cannot sync remotely");
        }
        for (BarrelInterface barrel : barrels) {
            try {
                Index index = barrel.getIndex();
                for (BarrelInterface otherBarrel : barrels) {
                    try {
                        otherBarrel.setIndex(index);
                    } catch (RemoteException error) {
                        LOGGER.error("Lost connection to barrel, unregistering it.");
                        unregisterBarrel(otherBarrel);
                    }
                }
            } catch (RemoteException error) {
                LOGGER.error("Lost connection to barrel, unregistering it.");
                unregisterBarrel(barrel);
            }
        }
        LOGGER.info("Barrels successfully synced.");
    }

    @Override
    public void putURL(String url)
            throws RemoteException, UnavailableWorkerException, IllegalArgumentException, EntryLimitMaxedException {
        LOGGER.info("Received request to index \"{}\" URL.", url);
        if (queue == null) {
            LOGGER.warn("Queue offline, denying request.");
            throw new UnavailableWorkerException("Queue offline, cannot index URL");
        }
        try {
            if (!url.matches(URL_REGEX)) {
                LOGGER.warn("Requested to index invalid URL, ignoring request.");
                throw new IllegalArgumentException(
                        "Invalid URL format");
            }

            for (BarrelInterface barrel : barrels) {
                try {
                    if (barrel.isIndexed(url)) {
                        LOGGER.warn("Requested to index URL already in barrels, ignoring request.");
                        throw new IllegalArgumentException(
                                "URL already indexed!");
                    }
                } catch (RemoteException error) {
                    LOGGER.error("Lost connection to barrel, unregistering it.");
                    unregisterBarrel(barrel);
                }

            }
            for (BarrelInterface barrel : barrels) {
                try {
                    if (barrel.isFull()) {
                        LOGGER.warn("Barrel is full, URL cannot be indexed!");
                        throw new EntryLimitMaxedException("Barrel is full, URL cannot be indexed");
                    }
                } catch (RemoteException error) {
                    LOGGER.error("Lost connection to barrel, unregistering it.");
                    unregisterBarrel(barrel);
                }
            }

            queue.put(url);

            stats.queueSize = queue.size();
            broadcastStats();

        } catch (IllegalArgumentException error) {
            LOGGER.error("{}!", error.getMessage());
            throw error;
        } catch (EntryLimitMaxedException error) {
            LOGGER.error("{}!", error.getMessage());
            throw error;
        } catch (RemoteException error) {
            LOGGER.error("Lost connection to queue, unregistering it.");
            queue = null;
            throw new UnavailableWorkerException("Queue offline, cannot index URL");
        }
    }

    @Override
    public String getURL() throws RemoteException, UnavailableWorkerException {
        if (queue == null) {
            LOGGER.warn("Requested to get URL without queue online, denying request.");
            throw new UnavailableWorkerException("Queue offline, cannot get URL");
        }
        try {
            return queue.get();
        } catch (RemoteException error) {
            LOGGER.error("Lost connection to queue, unregistering it.");
            queue = null;
            throw new UnavailableWorkerException("Queue offline, cannot get URL");
        }
    }

    @Override
    public Stats getStats() throws RemoteException {
        LOGGER.info("Received request for current stats.");
        return stats;
    }

    /**
     * Broadcasts the current stats to all connected clients and barrels.
     */
    public void broadcastStats() {
        stats.lastUpdated = Clock.systemUTC().instant();
        LOGGER.info("Broadcasting updated stats to all connected clients.");
        for (ClientInterface client : clients) {
            try {
                client.updateStats(stats);
            } catch (RemoteException error) {
                LOGGER.error("Lost connection to client, unregistering it.");
                clients.remove(client);
            }
        }
        LOGGER.info("Stats successfully broadcasted to all connected clients.");
        LOGGER.info("Broadcasting queries received to all connected barrels.");
        for (BarrelInterface barrel : barrels) {
            try {
                barrel.syncQueries(stats.topTenQueries);
            } catch (RemoteException error) {
                LOGGER.error("Lost connection to barrel, unregistering it.");
                barrels.remove(barrel);
            }
        }
        LOGGER.info("Queries successfully broadcasted to all connected barrels.");
    }

    /**
     * Represents the current stats of the gateway.
     */
    public static class Stats implements Serializable {
        /**
         * Instant when the stats were last updated.
         */
        public Instant lastUpdated;

        /**
         * Map for the top ten queries and their respective counts.
         */
        public HashMap<String, Integer> topTenQueries;

        /**
         * Number of barrels connected.
         */
        public int barrelsConnected;

        /**
         * Flag for the queue connection status.
         */
        public boolean queueConnected;

        /**
         * Number of URLs in the queue.
         */
        public int queueSize;

        /**
         * Number of downloaders connected.
         */
        public int downloadersConnected;

        /**
         * Number of clients connected.
         */
        public int clientsConnected;

        /**
         * Constructs the stats object with default values.
         */
        public Stats() {
            this.topTenQueries = new HashMap<String, Integer>();
            this.barrelsConnected = 0;
            this.queueConnected = false;
            this.queueSize = 0;
            this.downloadersConnected = 0;
            this.clientsConnected = 0;
        }
    }

}
