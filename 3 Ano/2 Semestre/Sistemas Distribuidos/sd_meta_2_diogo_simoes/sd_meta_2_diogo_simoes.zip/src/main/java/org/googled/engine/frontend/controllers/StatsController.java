package org.googled.engine.frontend.controllers;

import org.googled.engine.frontend.api.BackendRMIClient;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.messaging.simp.SimpMessagingTemplate;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
@EnableScheduling
public class StatsController {
    /**
     * Project's global logger implementation.
     * Logs to the console and to a shared generated log file.
     */
    final private static org.slf4j.Logger LOGGER = org.slf4j.LoggerFactory.getLogger(BackendRMIClient.class);

    @Autowired
    private SimpMessagingTemplate messagingTemplate;

    @GetMapping("/stats")
    public String stats() {
        return "stats";
    }

    @Scheduled(fixedRate = 5000)
    public void sendStats() {
        try {
             // BackendRMIClient client = new BackendRMIClient();
            // String stats = client.getGatewayStats();
            
            String stats = "{\"lastUpdated\": \"2024-05-16T14:30:00Z\", \"topTenQueries\":[\"How to connect a websocket?\", \"JavaScript fetch example\", \"CSS gridtutorial\", \"React hooks useState\", \"Python list comprehension\", \"Asyncawait in JavaScript\", \"HTML5 semantic elements\", \"Node.js expresssetup\", \"Java Streams API\", \"Docker container basics\"],\"barrelsConnected\": 42}";

            LOGGER.info("Successfully got stats from the RMI backend: {}; Sending to websocket endpoint!", stats);
            messagingTemplate.convertAndSend("/topic/stats", stats);
        } catch (Exception e) {
            LOGGER.error("Error getting gateway stats: {}", e.getMessage());
        }
    }
}