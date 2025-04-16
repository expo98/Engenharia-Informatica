package org.googled.engine.frontend;

import org.springframework.boot.Banner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

/**
 * Represents the core and entrypoint of the Spring Boot application.
 *
 */
@SpringBootApplication
public class Application {
	/**
	 * Constructs an instance of the App class.
	 */
	public Application() {
	}

	/**
	 * Runs the app.
	 *
	 * @param args command-line arguments (unused).
	 */
	public static void main(String[] args) {
		SpringApplication app = new SpringApplication(Application.class);
		app.setBannerMode(Banner.Mode.OFF);
		app.setLogStartupInfo(false);
		app.run(args);
	}

}
