package org.googled.engine.backend.interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * Provides methods for requesting actions from a downloader remotely through
 * RMI.
 */
public interface DownloaderInterface extends Remote {
    /**
     * Starts the working threads of the downloader.
     *
     * @throws RemoteException if there is an issue with the remote communication.
     */
    public void work() throws RemoteException;
}
