package org.googled.engine.backend.interfaces;

import java.util.ArrayList;

import org.googled.engine.backend.Downloader.PageContent;

/**
 * Provides methods for validating, encoding and decoding multicast messages
 * according to the projects protocol.
 */
public interface ProtocolInterface {

    /**
     * Validates whether a string contains invalid characters in the context of the
     * multicast protocol.
     *
     * @param str the string to validate.
     * @return true if the string is valid, false otherwise.
     */

    default boolean isValid(String str) {
        return str != null && !str.isEmpty() && !str.contains("|") && !str.contains(";") && !str.contains("\n")
                && !str.contains("~");
    }

    /**
     * Encodes a PageContent object into a multicast message according to the
     * project's protocol.
     *
     * @param content the PageContent object to encode.
     * @return the encoded multicast message.
     */
    default String encodeContent(PageContent content) {
        StringBuilder encodedMessage = new StringBuilder();
        encodedMessage.append("type | page_content ; ");

        if (isValid(content.url))
            encodedMessage.append("url | ").append(content.url).append(" ; ");

        if (isValid(content.title))
            encodedMessage.append("title | ").append(content.title).append(" ; ");

        if (isValid(content.description))
            encodedMessage.append("description | ").append(content.description).append(" ; ");

        if (content.words != null && !content.words.isEmpty()) {
            encodedMessage.append("words_count | ").append(content.words.size()).append(" ; ");
            for (int i = 0; i < content.words.size(); i++) {
                if (isValid(content.words.get(i)))
                    encodedMessage.append("word_").append(i).append("_value | ").append(content.words.get(i))
                            .append(" ; ");
            }
        }

        if (content.urls != null && !content.urls.isEmpty()) {
            encodedMessage.append("urls_count | ").append(content.urls.size()).append(" ; ");
            for (int i = 0; i < content.urls.size(); i++) {
                if (isValid(content.urls.get(i)))
                    encodedMessage.append("url_").append(i).append("_value | ").append(content.urls.get(i))
                            .append(" ; ");
            }
        }

        encodedMessage.append("~");

        return encodedMessage.toString();
    }

    /**
     * Decodes a multicast message into a PageContent object according to the
     * project's protocol.
     *
     * @param message the multicast message to decode.
     * @return the decoded PageContent object.
     */

    default PageContent decodeContent(String message) {
        if (message == null || message.isEmpty())
            return null;

        PageContent content = new PageContent();
        String[] pairs = message.split(" ; ");

        if (message.endsWith("~")) {
            pairs[pairs.length - 1] = pairs[pairs.length - 1].substring(0, pairs[pairs.length - 1].length() - 1);
        }

        for (String pair : pairs) {
            String[] keyValue = pair.trim().split(" \\| ");
            if (keyValue.length != 2)
                continue;

            String key = keyValue[0].trim();
            String value = keyValue[1].trim();

            switch (key) {
                case "url":
                    content.url = value;
                    break;
                case "title":
                    content.title = value;
                    break;
                case "description":
                    content.description = value;
                    break;
                case "words_count":
                    int wordsCount = Integer.parseInt(value);
                    content.words = new ArrayList<>();
                    for (int i = 0; i < wordsCount; i++) {
                        String wordKey = "word_" + i + "_value";
                        if (containsKey(pairs, wordKey)) {
                            content.words.add(getValue(pairs, wordKey));
                        }
                    }
                    break;
                case "urls_count":
                    int urlsCount = Integer.parseInt(value);
                    content.urls = new ArrayList<>();
                    for (int i = 0; i < urlsCount; i++) {
                        String urlKey = "url_" + i + "_value";
                        if (containsKey(pairs, urlKey)) {
                            content.urls.add(getValue(pairs, urlKey));
                        }
                    }
                    break;
            }
        }
        return content;
    }

    /**
     * Checks if a multicast message contains a given key.
     *
     * @param pairs the multicast message to check.
     * @param key   the key to check for.
     * @return true if the key is present, false otherwise.
     */

    default boolean containsKey(String[] pairs, String key) {
        for (String pair : pairs) {
            if (pair.startsWith(key))
                return true;
        }
        return false;
    }

    /**
     * Gets the value of a key from a multicast message.
     *
     * @param pairs the multicast message to get the value from.
     * @param key   the key to get the value of.
     * @return the value of the key.
     */
    default String getValue(String[] pairs, String key) {
        for (String pair : pairs) {
            if (pair.startsWith(key)) {
                int index = key.length() + 3;
                if (pair.length() > index) {
                    return pair.substring(index);
                }
            }
        }
        return null;
    }

}
