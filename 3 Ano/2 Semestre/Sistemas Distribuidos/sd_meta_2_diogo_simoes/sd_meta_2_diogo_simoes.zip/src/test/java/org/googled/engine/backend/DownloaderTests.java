package org.googled.engine.backend;

import static org.junit.Assert.assertTrue;

import org.googled.engine.backend.Downloader.PageContent;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Contains unit test functions for the Downloader class.
 */
public class DownloaderTests {
        /**
         * Project's global logger implementation.
         * Logs to the console and to a shared generated log file.
         */
        final static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(DownloaderTests.class);

        /**
         * Tests the downloaded content of a web page against the expected example.
         */
        @Test
        public void downloadedContentshouldMatchExpectedExample() {
                PageContent expected = new PageContent(
                                "http://www.example.com",
                                "Example Domain",
                                "No description found.",
                                new ArrayList<String>(Arrays.asList(
                                                "example",
                                                "domain",
                                                "this",
                                                "domain",
                                                "is",
                                                "for",
                                                "use",
                                                "in",
                                                "illustrative",
                                                "examples",
                                                "in",
                                                "documents",
                                                "you",
                                                "may",
                                                "use",
                                                "this",
                                                "domain",
                                                "in",
                                                "literature",
                                                "without",
                                                "prior",
                                                "coordination",
                                                "or",
                                                "asking",
                                                "for",
                                                "permission",
                                                "more",
                                                "information")),
                                new ArrayList<String>(
                                                Arrays.asList(
                                                                "https://www.iana.org/domains/example")));

                PageContent downloaded = Downloader.download("http://www.example.com");

                if (downloaded == null) {
                        throw new AssertionError();
                }

                assertTrue(expected.url.equals(downloaded.url));
                assertTrue(expected.title.equals(downloaded.title));
                assertTrue(expected.description.equals(downloaded.description));
                assertTrue(expected.words.equals(downloaded.words));
                assertTrue(expected.urls.equals(downloaded.urls));
        }
}
