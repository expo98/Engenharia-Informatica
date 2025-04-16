package org.googled.engine.backend.utilities;

import java.rmi.RemoteException;

import org.googled.engine.backend.interfaces.GatewayInterface;

/**
 * Represents a thread checking the gateway's health.
 *
 */
public class Heartbeat extends Thread {
    /**
     * Project's global logger implementation.
     * Logs to the console and to a shared generated log file.
     */
    final private static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(Heartbeat.class);

    /**
     * The gateway to check the health of.
     */
    private GatewayInterface gateway;

    /**
     * Creates a heartbeat thread to check the gateway's health.
     *
     * @param gateway the gateway to check the health of.
     * @param name    the name to give to the thread for logging and identification
     *                purposes.
     */
    public Heartbeat(GatewayInterface gateway, String name) {
        super(name);
        this.gateway = gateway;
    }

    /**
     * Checks the gateway's health periodically and shuts down the process if the
     * gateway is not alive.
     */
    @Override
    public void run() {
        LOGGER.info("Thread started.");
        while (true) {
            try {
                LOGGER.info("Checking if gateway is alive.");
                gateway.heartbeat();
                LOGGER.info("Gateway is alive.");
                Thread.sleep(10000);
            } catch (RemoteException error) {
                LOGGER.error("{}! Gateway is not alive, stopping.", error.getMessage());
                System.exit(1);
            } catch (InterruptedException error) {
                LOGGER.error("{}!", error.getMessage());
                System.exit(1);
            }
        }
    }
}
