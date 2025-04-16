package org.googled.engine.backend.interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

import org.googled.engine.backend.exceptions.EntryLimitMaxedException;

/**
 * Provides methods for adding and retrieving URLs from a queue remotely through
 * RMI.
 */
public interface QueueInterface extends Remote {

    /**
     * Starts the working threads of the queue.
     *
     * @throws RemoteException if there is an issue with the remote communication.
     */
    void work() throws RemoteException;

    /**
     * @return a URL from the queue, waiting if necessary.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    String get() throws RemoteException;

    /**
     * Adds a URL to the queue.
     *
     * <p>
     * Validation is expected to be performed by the gateway beforehand, so non
     * http/https protocol urls will be accepted here.
     * </p>
     *
     * @param link the URL to be added.
     * @throws RemoteException          if there is an issue with the remote
     *                                  communication.
     * @throws IllegalArgumentException if the URL is invalid.
     * @throws EntryLimitMaxedException if the queue is full.
     */
    void put(String link) throws RemoteException, IllegalArgumentException, EntryLimitMaxedException;

    /**
     * Gets the queue's size.
     *
     * @return the number of URLs in the queue.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    int size() throws RemoteException;

    /**
     * Checks if the queue contains a given URL.
     *
     * @param url the URL to be checked.
     * @return true if the URL is in the queue, false otherwise.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    public boolean contains(String url) throws RemoteException;
}
