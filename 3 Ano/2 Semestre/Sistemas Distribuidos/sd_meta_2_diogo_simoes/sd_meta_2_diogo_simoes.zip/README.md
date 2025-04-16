# Googled

This project follows a Maven monorepo approach, with the `backend` and `frontend` modules structured into separate directories. The `backend` contains all the RMI logic and the `frontend` module contains the content handling being served to the client.

## Requirements 📋

- Install JDK 17, other versions may work but are not guaranteed to do so. Maven will also throw a warning if it uses a different version when compiling the source code.
- Download Maven 3.9.6 or later from [here](https://maven.apache.org/download.cgi), pick the binary zip archive link under **Files**.
- Install Maven by following the instructions [here](https://maven.apache.org/install.html).

## Usage 🚀

- Most IDEs have a built-in debugger that can be used to test every `.java` file in the project. The `main()` function in each class can be run independently using the **Play** button present in VSCode and IntelliJ IDEA, for example.

- Note that during runtime a log and data files will be created in the working directory of the program.

## Build 🔧

- If you're using a headless machine or simply want to work from the terminal, you can use Maven to compile the source code into portable JARs on the `target` directory, with dependencies included, and run them more efficiently from there.

```shell
mvn clean verify
```

- Run any class that has a `main()` function from the compiled **backend** file as an independent program
with a single command, for example with the Gateway class:

```shell
java -cp target/googled-engine-backend.jar org.googled.engine.backend.Gateway
```

- Run the **frontend** spring boot application with the following command:

```shell
java -jar target/googled-engine-frontend.jar
```

## Documentation 📚

- Generate a fully automated documentation website for each module using Maven. This website hosts the javadoc, dependencies, plugins and other information about the project.

  ```shell
  mvn site
  ```

- The generated website content will be located in the `target/site` directory. Open the `index.html` file in a web browser to view it. The Javadoc can be found under the **Project Reports** section.
