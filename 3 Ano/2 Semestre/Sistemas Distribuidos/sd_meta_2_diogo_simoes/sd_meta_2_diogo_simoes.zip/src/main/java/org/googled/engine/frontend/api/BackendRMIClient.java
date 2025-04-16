package org.googled.engine.frontend.api;

import org.googled.engine.backend.Barrel.PageMetadata;
import org.googled.engine.backend.exceptions.UnavailableWorkerException;
import org.googled.engine.backend.interfaces.ClientInterface;
import org.googled.engine.backend.interfaces.GatewayInterface;
import org.googled.engine.backend.Gateway;

import java.net.InetAddress;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.util.Properties;
import java.rmi.server.UnicastRemoteObject;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.ArrayList;
import java.io.IOException;

/**
 * Represents an entity that interacts with the backend gateway to remotely
 * through RMI.
 */
public class BackendRMIClient extends UnicastRemoteObject implements ClientInterface {
    /**
     * Project's global logger implementation.
     * Logs to the console and to a shared generated log file.
     */
    final private static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(BackendRMIClient.class);

    /**
     * Expected directory path to the gateway properties file.
     */
    final private static String GATEWAY_CONFIG = "gateway.properties";

    /**
     * Expected directory path to the client properties file.
     */
    final private static String CLIENT_CONFIG = "client.properties";

    /**
     * Represents the connection to the gateway.
     */
    private GatewayInterface gateway;

        /**
     * Holds the latest gateway stats in a JSON stringified format.
     */
    private String json;

    /**
     * Initializes the client with the gateway connection.
     *
     * @param gateway the gateway connection to be used.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    public BackendRMIClient(GatewayInterface gateway) throws RemoteException {
        super();
        this.gateway = gateway;
    }

    /**
     * Instantiates the client and connects it to the gateway defined in the
     * properties file.
     *
     * @throws RemoteException if there is an issue with the remote communication.
     * @throws IOException     if there is an issue with the startup properties file
     *                         reading.
     */
    public BackendRMIClient() throws RemoteException, IOException {
        super();

        LOGGER.info("Started RMI client instance creation.");

        LOGGER.info("Loading \"{}\" file to acquire gateway properties.", GATEWAY_CONFIG);

        Properties properties = new Properties();
        properties.load(Thread.currentThread().getContextClassLoader()
                .getResourceAsStream(GATEWAY_CONFIG));
        String rmiName = properties.getProperty("RMI_NAME");
        String rmiHost = properties.getProperty("RMI_HOST");
        int rmiPort = Integer.parseInt(properties.getProperty("RMI_PORT"));

        LOGGER.info("Loading \"{}\" file to acquire client properties.", CLIENT_CONFIG);

        properties.load(Thread.currentThread().getContextClassLoader()
                .getResourceAsStream(CLIENT_CONFIG));

        LOGGER.info("Setting security policy and gateway server hostname system properties!");

        System.setProperty("java.security.policy", "policy.all");
        System.setProperty("java.rmi.server.hostname", rmiHost);

        LOGGER.info("Looking at {}:{} for {} named RMI registry.", rmiHost, rmiPort, rmiName);

        try {
            this.gateway = (GatewayInterface) LocateRegistry.getRegistry(rmiHost, rmiPort).lookup(rmiName);
        } catch (Exception error) {
            LOGGER.error("{}!", error.getMessage());
            throw new RemoteException("Could not connect to gateway!");
        }

        LOGGER.info("Found gateway, reseting system RMI server hostname property.");

        System.setProperty("java.rmi.server.hostname", InetAddress.getLocalHost().getHostAddress());

        LOGGER.info("RMI client instance created successfully and awaiting function calls.");
    }

    @Override
    public void updateStats(Gateway.Stats stats) throws RemoteException {
        LOGGER.info("Received updated stats from gateway.");
        LOGGER.info("Updating client latest stats: {}", stats);
        json = createJsonFromStats(stats);
        return;
    }

    /**
     * Gets the latest stats the client has received from the gateway.
     *
     * @return the latest stats from the gateway in a JSON stringified format.
     */
    public String getGatewayStats() {
        return json;
    }

    /**
     * Helper method to convert a stats object to a JSON object
     *
     * @param stats the stats object to convert
     * @return the JSON object as a string
     */
    private String createJsonFromStats(Gateway.Stats stats) {
        StringBuilder json = new StringBuilder();
        json.append("{");
        json.append("\"lastUpdated\": \"").append(stats.lastUpdated.toString()).append("\",");
        json.append("\"topTenQueries\": ").append(mapToJson(stats.topTenQueries)).append(",");
        json.append("\"barrelsConnected\": ").append(stats.barrelsConnected).append(",");
        json.append("}");
        return json.toString();
    }

    /**
     * Helper method to convert a Map to a JSON object
     *
     * @param map the map to convert
     * @return the JSON object as a string
     */
    private String mapToJson(Map<?, ?> map) {
        StringBuilder json = new StringBuilder();
        json.append("{");
        for (Map.Entry<?, ?> entry : map.entrySet()) {
            json.append("\"").append(entry.getKey().toString()).append("\": ");
            if (entry.getValue() instanceof Integer || entry.getValue() instanceof Boolean) {
                json.append(entry.getValue().toString());
            } else {
                json.append("\"").append(entry.getValue().toString()).append("\"");
            }
            json.append(",");
        }
        if (!map.isEmpty()) {
            json.deleteCharAt(json.length() - 1); // Remove the last comma
        }
        json.append("}");
        return json.toString();
    }

    /**
     * Sends a search request to the gateway.
     *
     * @param query the query to search for.
     * @return a map of URLs and their metadata that match the query.
     * @throws RemoteException            if there is an issue with the remote
     *                                    communication.
     * @throws UnavailableWorkerException if there is no worker available to satisfy
     */

    public LinkedHashMap<String, PageMetadata> searchQuery(String query)
            throws RemoteException, UnavailableWorkerException {
        LOGGER.info("Sending search request for \"{}\" to gateway.", query, gateway);

        try {
            return gateway.searchQuery(query);
        } catch (UnavailableWorkerException error) {
            LOGGER.error("{}!", error.getMessage());
            throw new UnavailableWorkerException(error.getMessage() + "!");
        } catch (RemoteException error) {
            LOGGER.error("{}!", error.getMessage());
            throw new RemoteException(
                    "Connection to gateway lost, please restart the client to establish a new connection!");
        }

    }

    /**
     * Sends a request to the gateway to get all the URLs that point to the given
     * URL.
     *
     * @param url the URL to get the pointers for.
     * @return a message indicating the result of the operation.
     * @throws RemoteException            if there is an issue with the remote
     *                                    communication.
     * @throws UnavailableWorkerException if there is no worker available to satisfy
     *                                    the request.
     */

    public ArrayList<String> getPoitingURLs(String url) throws RemoteException, UnavailableWorkerException {
        LOGGER.info("Sending pointers request for \"{}\" to gateway.", url, gateway);

        try {
            return gateway.getPointingURLs(url);
        } catch (UnavailableWorkerException error) {
            LOGGER.error("{}!", error.getMessage());
            throw new UnavailableWorkerException(error.getMessage() + "!");
        } catch (RemoteException error) {
            LOGGER.error("{}!", error.getMessage());
            throw new RemoteException(
                    "Connection to gateway lost, please restart the client to establish a new connection!");
        }
    }

    /**
     * Sends a request to the gateway to index a URL.
     *
     * @param url the URL to be indexed.
     * @return a message indicating the result of the operation.
     */

    public String index(String url) {
        LOGGER.info("Sending index request for \"{}\" to gateway.", url, gateway);

        try {
            gateway.putURL(url);
        } catch (RemoteException error) {
            LOGGER.error("{}!", error.getMessage());
            return "Connection to gateway lost, please restart the client to establish a new connection!";
        } catch (Exception error) {
            LOGGER.error("{}!", error.getMessage());
            return error.getMessage() + "!";
        }
        return "URL successfully sent for indexing!";
    }
}