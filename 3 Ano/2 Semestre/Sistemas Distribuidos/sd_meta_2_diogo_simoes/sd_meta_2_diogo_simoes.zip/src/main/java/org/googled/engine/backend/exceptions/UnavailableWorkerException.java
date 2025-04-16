package org.googled.engine.backend.exceptions;

/**
 * Thrown to indicate that this class has no available
 * workers to perform the requested operation.
 *
 */
public class UnavailableWorkerException extends Exception {
    /**
     * Constructs a {@code UnavailableWorkerException} with the specified
     * detail message.
     *
     * @param message the detail message.
     */
    public UnavailableWorkerException(String message) {
        super(message);
    }
}
