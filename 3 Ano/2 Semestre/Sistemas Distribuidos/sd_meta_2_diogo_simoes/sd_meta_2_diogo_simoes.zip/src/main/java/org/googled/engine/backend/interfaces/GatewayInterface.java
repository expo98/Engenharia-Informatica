package org.googled.engine.backend.interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.LinkedHashMap;

import org.googled.engine.backend.Gateway;
import org.googled.engine.backend.Barrel.PageMetadata;
import org.googled.engine.backend.exceptions.*;

/**
 * Provides methods for requesting remote interactions with the gateway through
 * RMI.
 */
public interface GatewayInterface extends Remote {

	/**
	 * Allows the caller to check if the gateway is alive.
	 *
	 * @throws RemoteException if there is an issue with the remote communication,
	 *                         meaning the gateway is not alive.
	 */
	void heartbeat() throws RemoteException;

	/**
	 * Registers a queue with the gateway.
	 *
	 * @param queue the queue to register.
	 * @throws RemoteException             if there is an issue with the remote
	 *                                     communication.
	 * @throws DuplicateComponentException if there is a queue is already
	 *                                     registered.
	 */
	void registerQueue(QueueInterface queue) throws RemoteException, DuplicateComponentException;

	/**
	 * Unregisters a queue with the gateway.
	 *
	 * @param queue the queue to unregister.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	void unregisterQueue(QueueInterface queue) throws RemoteException;

	/**
	 * Registers a downloader with the gateway.
	 *
	 * @param downloader the downloader to register.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	void registerDownloader(DownloaderInterface downloader) throws RemoteException;

	/**
	 * Unregisters a downloader with the gateway.
	 *
	 * @param downloader the downloader to unregister.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	void unregisterDownloader(DownloaderInterface downloader) throws RemoteException;

	/**
	 * Registers a barrel with the gateway.
	 *
	 * @param barrel the barrel to register.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	void registerBarrel(BarrelInterface barrel) throws RemoteException;

	/**
	 * Unregisters a barrel with the gateway.
	 *
	 * @param barrel the barrel to unregister.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	void unregisterBarrel(BarrelInterface barrel) throws RemoteException;

	/**
	 * Registers a client with the gateway.
	 *
	 * @param client the client to register.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	void registerClient(ClientInterface client) throws RemoteException;

	/**
	 * Unregisters a client with the gateway.
	 *
	 * @param client the client to unregister.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	void unregisterClient(ClientInterface client) throws RemoteException;

	/**
	 * Requests a list of URLs relevant to the given query keywords from the
	 * barrels.
	 *
	 * @param query list of keywords to search for.
	 * @return matching URLs.
	 * @throws RemoteException            if there is an issue with the remote
	 *                                    communication.
	 * @throws UnavailableWorkerException if there are no barrels registered with
	 *                                    the gateway to satisfy the request.
	 */
	LinkedHashMap<String, PageMetadata> searchQuery(String query) throws RemoteException, UnavailableWorkerException;

	/**
	 * Requests a list of indexed URLs that point to the given URL from the barrels.
	 *
	 * @param url the URL to search for.
	 * @return a list of indexed URLs that point to the given URL.
	 * @throws RemoteException            if there is an issue with the remote
	 *                                    communication.
	 * @throws UnavailableWorkerException if there are no barrels registered with
	 *                                    the gateway to satisfy the request.
	 * @throws IllegalArgumentException   if the URL is unacceptable.
	 */
	ArrayList<String> getPointingURLs(String url)
			throws RemoteException, UnavailableWorkerException, IllegalArgumentException;

	/**
	 * Tells the gateway the top ten most searched queries have been updated.
	 *
	 * @param topTenQueries the updated top ten most searched queries.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	void updateTopTenQueries(LinkedHashMap<String, Integer> topTenQueries) throws RemoteException;

	/**
	 * Request made by a barrel to be synced with the other existing barrels.
	 *
	 * @throws RemoteException            if there is an issue with the remote
	 *                                    communication.
	 * @throws UnavailableWorkerException if there are no barrels registered with
	 *                                    the gateway to sync from.
	 */
	void syncBarrels() throws RemoteException, UnavailableWorkerException;

	/**
	 * Requests platform stats from the gateway.
	 *
	 * @return a string containing the platform stats.
	 * @throws RemoteException if there is an issue with the remote communication.
	 */
	Gateway.Stats getStats() throws RemoteException;

	/**
	 * Requests the gateway to send a URL to the queue for indexing.
	 *
	 * @param url the URL to be indexed.
	 * @throws RemoteException            if there is an issue with the remote
	 *                                    communication.
	 * @throws UnavailableWorkerException if there is no queue registered with the
	 *                                    gateway to satisfy the request.
	 * @throws IllegalArgumentException   if the URL is unacceptable.
	 * @throws EntryLimitMaxedException   if the queue has reached its maximum size.
	 */
	void putURL(String url)
			throws RemoteException, UnavailableWorkerException, IllegalArgumentException, EntryLimitMaxedException;

	/**
	 * Requests the gateway to retreive a URL waiting to be indexed from the queue.
	 *
	 * @return the URL to be indexed.
	 * @throws RemoteException            if there is issue with the remote
	 *                                    communication.
	 * @throws UnavailableWorkerException if there is no queue registered with the
	 *                                    gateway to satisfy the request.
	 */
	String getURL() throws RemoteException, UnavailableWorkerException;

}
