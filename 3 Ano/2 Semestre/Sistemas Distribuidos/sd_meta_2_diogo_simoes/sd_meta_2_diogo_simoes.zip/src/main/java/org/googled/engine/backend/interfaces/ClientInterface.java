package org.googled.engine.backend.interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

import org.googled.engine.backend.Gateway;

/**
 * Provides methods for sending information to the client remotely through RMI.
 */

public interface ClientInterface extends Remote {
    /**
     * Updates the stats held by the client relative to the gateway.
     *
     * @param stats the stats to be updated.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    void updateStats(Gateway.Stats stats) throws RemoteException;

}
