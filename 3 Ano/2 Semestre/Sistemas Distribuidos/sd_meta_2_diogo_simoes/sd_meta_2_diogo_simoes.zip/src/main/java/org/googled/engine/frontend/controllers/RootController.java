package org.googled.engine.frontend.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

/**
 * Represents the controller for the root page.
 */
@Controller
public class RootController {
    /**
     * Redirects the user from the root URL to the search page.
     *
     * @return the redirect URL.
     */
    @GetMapping("/")
    public String redirect() {
        return "redirect:/search";
    }
}
