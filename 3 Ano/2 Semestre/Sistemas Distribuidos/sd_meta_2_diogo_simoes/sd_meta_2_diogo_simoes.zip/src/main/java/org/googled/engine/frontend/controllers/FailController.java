package org.googled.engine.frontend.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.boot.web.servlet.error.ErrorController;

@Controller
public class FailController implements ErrorController {

    @RequestMapping("/error")
    public String handle() {
        return "error";
    }
}
