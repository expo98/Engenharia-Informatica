package org.googled.engine.backend;

import org.googled.engine.backend.exceptions.UnavailableWorkerException;
import org.googled.engine.backend.interfaces.DownloaderInterface;
import org.googled.engine.backend.interfaces.GatewayInterface;
import org.googled.engine.backend.interfaces.ProtocolInterface;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.Serializable;
import java.rmi.registry.LocateRegistry;
import java.util.Properties;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

/**
 * Represents a downloader process that gets URLs from a queue, downloads their
 * web page, extracts its content and sends it to the barrels.
 */
public class Downloader extends UnicastRemoteObject implements ProtocolInterface, DownloaderInterface {
    /**
     * Project's global logger implementation.
     * Logs to the console and to a shared generated log file.
     */
    final private static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(Downloader.class);

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
    final private static String DOWNLOADER_CONFIG = "Downloader.properties";

    /**
     * Max amount of words to store from each downloaded page.
     */
    final private int MAX_WORDS;

    /**
     * The multicast group to send the content to.
     *
     */
    private InetAddress multicastGroupHost;

    /**
     * The multicast port to send the content to.
     */
    private int multicastGroupPort;

    /**
     * The multicast socket to send the content through.
     */
    private MulticastSocket multicastSocket;

    /**
     * Represents the connection to the gateway.
     */
    private GatewayInterface gateway;

    /**
     * Represents the working download thread associated with this downloader.
     */
    public Worker worker;

    /**
     * Constructs a new downloader with all the necessary properties.
     *
     * @param socket    the multicast socket to send the content through.
     * @param groupHost the multicast group to send the content to.
     * @param groupPort the multicast port to send the content to.
     * @param gateway   the gateway to interact with.
     * @param max       the maximum amount of words to store from each downloaded
     *                  page.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    public Downloader(MulticastSocket socket, InetAddress groupHost, int groupPort, GatewayInterface gateway, int max)
            throws RemoteException {
        super();
        this.multicastSocket = socket;
        this.multicastGroupHost = groupHost;
        this.multicastGroupPort = groupPort;
        this.gateway = gateway;
        this.MAX_WORDS = max;
    }

    /**
     * Instantiates the class as a worker process.
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
            int multicastGroupPort = Integer.parseInt(properties.getProperty("MULTICAST_PORT"));

            LOGGER.info("Loading \"{}\" file to acquire downloader properties.", DOWNLOADER_CONFIG);
            properties.load(Thread.currentThread().getContextClassLoader()
                    .getResourceAsStream(DOWNLOADER_CONFIG));
            int max = Integer.parseInt(properties.getProperty("MAX_WORDS"));

            LOGGER.info("Setting security policy and gateway server hostname system properties!");

            System.setProperty("java.security.policy", "policy.all");
            System.setProperty("java.rmi.server.hostname", rmiHost);

            LOGGER.info("Allocating multicast socket.");
            MulticastSocket socket = new MulticastSocket();
            LOGGER.info("Local port {} allocated.", socket.getLocalPort());

            LOGGER.info("Setting up multicast group.", multicastHost);
            InetAddress multicastGroupHost = InetAddress.getByName(multicastHost);
            LOGGER.info("Success, multicast content will be sent to {}:{} address.", multicastHost, multicastGroupPort);

            LOGGER.info("Looking for RMI gateway at [{}:{} -> {}] registry.", rmiHost, rmiPort, rmiName);

            GatewayInterface gateway = (GatewayInterface) LocateRegistry.getRegistry(rmiHost, rmiPort).lookup(rmiName);

            LOGGER.info("Found gateway, reseting system RMI server hostname property.");

            System.setProperty("java.rmi.server.hostname", InetAddress.getLocalHost().getHostAddress());

            LOGGER.info("Instantiating downloader and worker thread.");

            Downloader downloader = new Downloader(socket, multicastGroupHost, multicastGroupPort, gateway, max);
            downloader.worker = downloader.new Worker();

            LOGGER.info("Instantiated correctly.");

            LOGGER.info("Adding shutdown hook.");

            Runtime.getRuntime().addShutdownHook(new Thread() {
                @Override
                public void run() {
                    synchronized (downloader) {
                        LOGGER.info(
                                "Got shutdown signal, unregistering downloader from gateway.");
                        try {
                            downloader.gateway.unregisterDownloader(downloader);
                            downloader.worker.interrupt();
                            downloader.notify();
                            LOGGER.info("Downloader successfully unregistered.");
                        } catch (RemoteException e) {
                            LOGGER.error("Could not unregister downloader from gateway!");
                        } finally {
                            LOGGER.info("Process exited.");
                        }

                    }
                }
            });

            LOGGER.info("Hook added.");

            LOGGER.info("Downloader ready to interact with gateway!");

            LOGGER.info("Registering downloader with gateway.");

            downloader.gateway.registerDownloader(downloader);

            LOGGER.info("Registration successful.");

            LOGGER.info("Downloader now interacting with gateway.");

            synchronized (downloader) {
                downloader.wait();
            }

        } catch (Exception error) {
            LOGGER.error("{}!", error.getMessage());
            LOGGER.info("Process exited.");
            System.exit(1);
        }
    }

    @Override
    public void work() throws RemoteException {
        LOGGER.info("Starting downloader worker thread.");
        worker.start();
    }

    /**
     * Represents a working thread.
     */
    public class Worker extends Thread {

        /**
         * Performs download and nested URL retrieval/recursive operations, sending the
         * content to the barrels afterwards.
         */
        @Override
        public void run() {
            while (true) {
                LOGGER.info("Going to retrieve new URL from queue, blocking until available.");

                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    LOGGER.warn("Downloader timeout interrupted!");
                }

                String url = null;
                try {
                    url = gateway.getURL();
                } catch (RemoteException error) {
                    LOGGER.error("{}! Connection to gateway lost, stopping downloader.", error.getMessage());
                    System.exit(1);
                } catch (UnavailableWorkerException error) {
                    LOGGER.error("{}! No queue online, stopping downloader.", error.getMessage());
                    System.exit(1);
                }

                LOGGER.info("Got {} URL, downloading content.", url);

                PageContent content = download(url);

                if (content == null) {
                    continue;
                }

                if (content.words.size() > MAX_WORDS) {
                    content.words = new ArrayList<String>(content.words.subList(0, MAX_WORDS));
                }

                LOGGER.info("Download successful, sending nested URLs to queue!");

                for (String link : content.urls) {
                    try {
                        gateway.putURL(link);
                    } catch (RemoteException error) {
                        LOGGER.error("{}! Connection to gateway lost, stopping downloader.", error.getMessage());
                        System.exit(1);
                    } catch (UnavailableWorkerException error) {
                        LOGGER.error("{}! No queue online, stopping downloader.", error.getMessage());
                        System.exit(1);
                    } catch (Exception error) {
                        LOGGER.warn("{}! Skipping URL addition to queue.", error.getMessage());
                    }
                }

                LOGGER.info("URLs sent, dispatching parsed content to barrels.");

                if (content.words.isEmpty()) {
                    LOGGER.info("URL had no content for indexing, skipping.");
                    continue;
                }

                multicast(content);

                LOGGER.info("Information dispatched.");
            }
        }
    }

    /**
     * Downloads the contents of a web page.
     *
     * @param url The URL of the web page to download
     * @return The content of the web page.
     */
    public static PageContent download(String url) {
        try {
            PageContent content = new PageContent(url);

            Document html = Jsoup.connect(url).get();
            content.title = html.title();
            if (content.title == null || content.title.isEmpty()) {
                content.title = "No title found";
            }
            content.title = content.title.replaceAll("\\|", "/")
                    .replaceAll(";", ".").replaceAll("\n", " ").replaceAll("~", " ");

            content.description = html.select("meta[name=description]").attr("content");
            if (content.description == null || content.description.isEmpty()) {
                content.description = "No description found.";
            }

            content.description = content.description.replaceAll("\\t", " ")
                    .replaceAll("; ", ". ").replaceAll("\n", " ").replaceAll("~", " ");

            StringTokenizer tokens = new StringTokenizer(html.body().text());
            int count = 0;
            while (tokens.hasMoreElements() && count++ < 1000) {
                String word = tokens.nextToken().replaceAll("\\p{Punct}", "").toLowerCase();
                if (!(word == null || word.isEmpty())) {
                    word = word.replaceAll("\\|", "/").replaceAll(";", ".").replaceAll("\n", " ").replaceAll("~", " ");
                    content.words.add(word);
                }
            }
            Elements links = html.select("a[href]");
            for (Element link : links) {
                String href = link.attr("abs:href");
                if (!(href == null || href.isEmpty())) {
                    content.urls.add(href);
                }
            }

            return content;
        } catch (Exception error) {
            LOGGER.error("{}! Skipping URL download.", error.getMessage());
            return null;
        }
    }

    /**
     * Sends the content of a web page to all listening barrels
     * through multicast.
     *
     * @param content The content of the web page to send.
     */
    private void multicast(PageContent content) {
        try {
            String message = encodeContent(content);
            byte[] buffer = message.getBytes();
            int packetSize = 32;
            int numPackets = (int) Math.ceil((double) buffer.length / packetSize);

            for (int i = 0; i < numPackets; i++) {
                int offset = i * packetSize;
                int length = Math.min(packetSize, buffer.length - offset);
                byte[] packetData = Arrays.copyOfRange(buffer, offset, offset + length);
                DatagramPacket packet = new DatagramPacket(packetData, packetData.length, multicastGroupHost,
                        multicastGroupPort);
                multicastSocket.send(packet);
            }
        } catch (Exception error) {
            LOGGER.error("{}! Skipping multicast for this URL.", error.getMessage());
        }

    }

    /**
     * Represents the content of a web page.
     *
     */
    public static class PageContent implements Serializable {
        /**
         * URL of the web page.
         */
        public String url;

        /**
         *
         * Title extracted from the web page.
         */
        public String title;

        /**
         *
         * Description extracted from the web page.
         */
        public String description;

        /**
         *
         * Words extracted from the web page.
         */
        public ArrayList<String> words;

        /**
         *
         * URLs extracted from the web page.
         */
        public ArrayList<String> urls;

        /**
         * Constructs a new page content with no fields set.
         */
        public PageContent() {
            url = null;
            title = null;
            description = null;
            words = new ArrayList<String>();
            urls = new ArrayList<String>();
        }

        /**
         * Constructs a new page content with only the URL set.~
         *
         * @param url the URL to set.
         */
        public PageContent(String url) {
            this.url = url;
            title = null;
            description = null;
            words = new ArrayList<String>();
            urls = new ArrayList<String>();
        }

        /**
         * Constructs a new page content with all fields set.
         *
         * @param url         the URL to set.
         * @param title       the title to set.
         * @param description the description to set.
         * @param words       the words to set.
         * @param urls        the URLs to set.
         */
        public PageContent(String url,
                String title, String description, ArrayList<String> words, ArrayList<String> urls) {
            this.url = url;
            this.title = title;
            this.description = description;
            this.words = words;
            this.urls = urls;
        }

        /**
         * Compares the page content with another.
         *
         * @param content the content to compare with.
         * @return {@code true} if the content is equal, {@code false} otherwise.
         */
        public boolean equals(PageContent content) {
            if (!this.url.equals(content.url) || !this.title.equals(content.title)
                    || !this.description.equals(content.description)) {
                return false;
            }
            if (this.words.size() != content.words.size() || this.urls.size() != content.urls.size()) {
                return false;
            }
            for (int i = 0; i < this.words.size(); i++) {
                if (!this.words.get(i).equals(content.words.get(i))) {
                    return false;
                }
            }
            for (int i = 0; i < this.urls.size(); i++) {
                if (!this.urls.get(i).equals(content.urls.get(i))) {
                    return false;
                }
            }
            return true;
        }
    }
}
