package org.googled.engine.frontend.controllers;

import org.googled.engine.frontend.api.BackendRMIClient;
import org.googled.engine.frontend.models.HackerNewsItemRecord;
import org.googled.engine.frontend.models.HackerNewsUserRecord;
import org.googled.engine.backend.Barrel.PageMetadata;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import org.springframework.core.ParameterizedTypeReference;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.client.RestTemplate;

import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;

/**
 * Represents the controller for the search page.
 */
@Controller
public class SearchController {

    /**
     * Project's global logger implementation.
     * Logs to the console and to a shared generated log file.
     */
    final private static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(BackendRMIClient.class);

    @GetMapping("/search")
    public String search(@RequestParam(name = "query", required = false) String query,
            @RequestParam(name = "page", defaultValue = "0") int page,
            @RequestParam(name = "hackerNewsSearch", defaultValue = "false") boolean hackerNewsSearch,
            Model model) {
        // If a query is provided, display search results
        if (query != null && !query.trim().isEmpty()) {
            if (hackerNewsSearch) {
                // Call the method to search top stories on Hacker News
                LinkedHashMap<String, List<String>> results = searchTopStoriesOnHackerNews(query);
                // Add the search results to the model
                model.addAttribute("results", results);

                model.addAttribute("query", query);
                return "hacker-search"; // Return different view for Hacker News search
            } else {
                // Call backend RMI client and get results from gateway
                LinkedHashMap<String, PageMetadata> allResults = new LinkedHashMap<>();
                try {
                    BackendRMIClient client = new BackendRMIClient();
                    // Fetch all search results including title and description
                    allResults = client.searchQuery(query);
                    LOGGER.info(
                            "Successfully got {} search results from the RMI backend for query with \"{}\" content.",
                            allResults.size(), query);
                } catch (Exception e) {
                    LOGGER.error("{}; Failed to get search results from the RMI backend for query with \"{}\" content.",
                            e.getMessage(), query);
                    return "error";
                }

                // Paginate the results
                int pageSize = 10; // Number of results per page
                int startIdx = page * pageSize;
                int endIdx = Math.min(startIdx + pageSize, allResults.size());
                int totalPages = (int) Math.ceil((double) allResults.size() / pageSize);
                LinkedHashMap<String, PageMetadata> results = new LinkedHashMap<>();
                for (Map.Entry<String, PageMetadata> entry : allResults.entrySet()) {
                    if (startIdx <= 0 && endIdx > 0) {
                        results.put(entry.getKey(), entry.getValue());
                    }
                    startIdx--;
                    endIdx--;
                }

                // Adding pagination data and search results to the model
                model.addAttribute("results", results);
                model.addAttribute("query", query);
                model.addAttribute("currentPage", page);
                model.addAttribute("totalPages", totalPages);

                 // Generate analysis using Gemini API
                 if (results.size() > 0) {
                    try {
                        String analysis = generateAnalysis(query);
                        model.addAttribute("analysis", analysis);
                    } catch (Exception e) {
                        LOGGER.error("Failed to generate analysis: {}", e.getMessage());
                    }
                }

                return "search-results"; // Return search-results view for normal search
            }
        }
        // If no query is provided, display the main search page without any data
        else {
            return "search";
        }
    }

    private LinkedHashMap<String, List<String>> searchTopStoriesOnHackerNews(String query) {
        // URL for getting the top stories IDs from Hacker News
        String hackerNewsTopStoriesUrl = "https://hacker-news.firebaseio.com/v0/topstories.json";
    
        // Initialize a RestTemplate
        RestTemplate restTemplate = new RestTemplate();
    
        // Define a ParameterizedTypeReference for List<Integer>
        ParameterizedTypeReference<List<Integer>> responseType = new ParameterizedTypeReference<List<Integer>>() {};
    
        // Make the HTTP GET request to get the list of top stories IDs
        List<Integer> topStoriesIds = restTemplate.exchange(hackerNewsTopStoriesUrl, HttpMethod.GET, null, responseType)
                .getBody();
    
        // Map to store URLs and titles of top stories containing the query
        LinkedHashMap<String, List<String>> topStoriesMap = new LinkedHashMap<>();
    
        if (topStoriesIds == null) {
            return topStoriesMap;
        }
    
        // Process each top story
        for (Integer storyId : topStoriesIds) {
            String storyItemDetailsEndpoint = String
                    .format("https://hacker-news.firebaseio.com/v0/item/%s.json?print=pretty", storyId);
            HackerNewsItemRecord hackerNewsItemRecord = restTemplate.getForObject(storyItemDetailsEndpoint,
                    HackerNewsItemRecord.class);
            if (hackerNewsItemRecord != null && "story".equals(hackerNewsItemRecord.type())) {
                // Check if the story title contains the query as a separate word
                String title = hackerNewsItemRecord.title();
                String[] words = title.split("\\s+");
                for (String word : words) {
                    if (word.equalsIgnoreCase(query)) {
                        // Add URL and title to the map
                        String url = hackerNewsItemRecord.url();
                        if (!topStoriesMap.containsKey(url)) {
                            topStoriesMap.put(url, new ArrayList<>());
                            try {
                                BackendRMIClient client = new BackendRMIClient();
                                client.index(url);
                            } catch (Exception e) {
                                // Handle any exceptions
                                e.printStackTrace();
                            }
                        }
                        topStoriesMap.get(url).add(title);
                        break; // Once found, no need to continue searching
                    }
                }
            }
        }
        return topStoriesMap;
    }

    private String generateAnalysis(String query) {
        String apiUrl = "https://generativelanguage.googleapis.com/v1beta/models/gemini-pro:generateContent?key=AIzaSyASD9vmbwSOgLOBT0usro9lmQ8H9K1uOpM";
    
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
    
        // Construct the request body
        String requestBody = "{\"contents\": [{\"parts\": [{\"text\": \"" + query + "\"}]}]}";
    
        // Create an HTTP entity with the request body and headers
        HttpEntity<String> requestEntity = new HttpEntity<>(requestBody, headers);
    
        // Create a RestTemplate instance
        RestTemplate restTemplate = new RestTemplate();
    
        try {
            // Make a POST request to the Gemini API
            ResponseEntity<String> responseEntity = restTemplate.exchange(
                    apiUrl,
                    HttpMethod.POST,
                    requestEntity,
                    String.class
            );
    
            // Extract the response body
            String response = responseEntity.getBody();
            LOGGER.info("Gemini Analysis Response: {}", response);

            // Parse the JSON response
            ObjectMapper mapper = new ObjectMapper();
            JsonNode rootNode = mapper.readTree(response);
            JsonNode contentNode = rootNode.get("candidates").get(0).get("content");
            JsonNode partsNode = contentNode.get("parts");

            // Extract text from partsNode
            StringBuilder textBuilder = new StringBuilder();
            for (JsonNode part : partsNode) {
                textBuilder.append(part.get("text").asText()).append("\n");
            }
            String text = textBuilder.toString();
            LOGGER.info("Extracted Text: {}", text);

            return text;
        } catch (Exception e) {
            // Handle any errors
            LOGGER.error("Failed to generate analysis: {}", e.getMessage());
            return "Failed to generate analysis.";
        }
    }

    @PostMapping("/index")
    public String indexUrl(@RequestParam("url") String url, Model model) {
        try {
            BackendRMIClient client = new BackendRMIClient();
            String result = client.index(url);
            model.addAttribute("result", result);
            return "search";
        } catch (Exception e) {
            model.addAttribute("error", e.getMessage());
            return "search";
        }
    }

    @GetMapping("/page-links")
    public String getPageLinks(@RequestParam(name = "url") String url, Model model) {
        try {
            BackendRMIClient client = new BackendRMIClient();
            ArrayList<String> pointingURLs = client.getPoitingURLs(url);
            LOGGER.info("Successfully got {} pointing URLs for page: {}", pointingURLs.size(), url);
            model.addAttribute("pointingURLs", pointingURLs);
            model.addAttribute("url", url);
            return "page-links";
        } catch (Exception e) {
            LOGGER.error("Failed to get pointing URLs for page {}: {}", url, e.getMessage());
            return "error";
        }
    }

    @PostMapping("/fetch-hackernews-stories")
    public String fetchHackerNewsStories(@RequestParam("username") String username, Model model) {
        try {
            RestTemplate restTemplate = new RestTemplate();
            String url = "https://hacker-news.firebaseio.com/v0/user/" + username + ".json";
            HackerNewsUserRecord userRecord = restTemplate.getForObject(url, HackerNewsUserRecord.class);
            if (userRecord == null) {
                return "error";
            }
            List<Object> submittedStoryIds = userRecord.submitted();
            List<String> submittedStoriesURLS = new ArrayList<>();
            for (Object submittedStoryId : submittedStoryIds) {
                String urlStory = "https://hacker-news.firebaseio.com/v0/item/" + submittedStoryId + ".json";
                HackerNewsItemRecord story = restTemplate.getForObject(urlStory, HackerNewsItemRecord.class);
                if (story != null && "story".equals(story.type())) {
                    // If the item is a story, fetch its details and index the URL
                    String storyUrl = story.url();
                    BackendRMIClient client = new BackendRMIClient();
                    client.index(storyUrl);
                    submittedStoriesURLS.add(storyUrl);
                }
            }
            model.addAttribute("stories", submittedStoriesURLS);
            return "user-stories";
        } catch (Exception e) {
            // Handle any exceptions and return error view
            return "error";
        }
    }
}
