package org.googled.engine.backend.exceptions;

/**
 * Thrown to indicate that this class has reached
 * its maximum limit of entries for a given field.
 *
 */
public class EntryLimitMaxedException extends Exception {
    /**
     * Constructs a {@code EntryLimitMaxedException} with the specified
     * detail message.
     *
     * @param message the detail message.
     */
    public EntryLimitMaxedException(String message) {
        super(message);
    }

}
