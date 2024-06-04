package io.github.tuilakhanh.log;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Log {

    private final String logName;


    public Log(String configPath) {
        logName = readConfig(configPath);
    }

    private String readConfig(String configPath) {
        try (BufferedReader reader = Files.newBufferedReader(Paths.get(configPath))) {
            return reader.readLine();  // Assuming the config is a single line
        } catch (IOException e) {
            System.err.println("Error reading config file: " + e.getMessage());
            return "";
        }
    }

    public String createLogFile() {
        String logFilePath = "logs" + File.separator + logName + ".txt";
        Path logFile = Paths.get(logFilePath);
        try {
            if (Files.notExists(logFile)) {
                Files.createDirectories(logFile.getParent());
                Files.createFile(logFile);
            }
        } catch (Exception e) {
            System.err.println("Error creating log file: " + e.getMessage());
        }
        return logFilePath;
    }

    public void writeLog(String message) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        String logContent = formatter.format(LocalDateTime.now()) + " - " + message;
        try (BufferedWriter writer = Files.newBufferedWriter(
                Paths.get(createLogFile()),
                StandardCharsets.UTF_8,
                StandardOpenOption.CREATE,
                StandardOpenOption.APPEND)) {

            writer.write(logContent + "\n");
            System.out.printf("%s\n%n", logContent);
        } catch (IOException e) {
            System.err.println("Error writing to log file: " + e.getMessage());
        }
    }
}
