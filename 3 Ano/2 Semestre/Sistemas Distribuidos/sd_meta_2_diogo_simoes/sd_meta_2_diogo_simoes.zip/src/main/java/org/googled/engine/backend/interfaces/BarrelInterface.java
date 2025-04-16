package org.googled.engine.backend.interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.LinkedHashMap;

import org.googled.engine.backend.Barrel.Index;
import org.googled.engine.backend.Barrel.PageMetadata;

import java.util.HashMap;
import java.util.HashSet;

/**
 * Provides methods for acquiring information from the barrels remotely through
 * RMI.
 */
public interface BarrelInterface extends Remote {

    /**
     * Starts the working threads of the barrel.
     *
     * @throws RemoteException if there is an issue with the remote communication.
     */
    void work() throws RemoteException;

    /**
     * Checks if the barrel is full.
     *
     * @return true if the barrel is full, false otherwise.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    boolean isFull() throws RemoteException;

    /**
     * Requests the total amount of indexed URLs.
     *
     * @return the total amount of indexed URLs.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    int getIndexedCount() throws RemoteException;

    /**
     * Request the entire index of the barrel.
     *
     * @return the index of the barrel.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    Index getIndex() throws RemoteException;

    /**
     * Sets the index of the barrel.
     *
     * @param index the index to set.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    void setIndex(Index index) throws RemoteException;

    /**
     * Requests search results for a given query.
     *
     * @param query the query to be searched.
     * @return the search results consisting of a hashmap with the URLs as the keys
     *         and the page's metadata as the values.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    LinkedHashMap<String, PageMetadata> searchQuery(String query) throws RemoteException;

    /**
     * Requests a list of all URLs that reference a given URL.
     *
     * @param url the URL to be searched.
     * @return a set of URLs that reference the given URL.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    HashSet<String> getPointingURLs(String url) throws RemoteException;

    /**
     * Requests the top ten most searched queries from the index.
     *
     * @return the top ten most searched terms.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    LinkedHashMap<String, Integer> getTopTenQueries() throws RemoteException;

    /**
     * Checks if a URL is already in the index.
     *
     * @param url the URL to be checked.
     *
     * @return true if the URL is already in the index, false otherwise.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    boolean isIndexed(String url) throws RemoteException;

    /**
     * Syncs the local queries once another barrel receives one.
     *
     * @param queries the queries to be synced.
     * @throws RemoteException if there is an issue with the remote communication.
     */
    public void syncQueries(HashMap<String, Integer> queries) throws RemoteException;

}
