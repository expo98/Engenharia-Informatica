package org.googled.engine.backend.exceptions;

/**
 * Thrown to indicate that this class can only
 * have a single object instance of the component that is
 * trying to be added.
 */
public class DuplicateComponentException extends Exception {
    /**
     * Constructs a {@code DuplicateComponentException} with the specified
     * detail message.
     *
     * @param message the detail message.
     */
    public DuplicateComponentException(String message) {
        super(message);
    }

}
