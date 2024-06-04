package io.github.tuilakhanh.Lab05.RMIServer;

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;
import io.github.tuilakhanh.log.Log;

public class Main {
    public static void main(String[] args) {
        var log = new Log("configs/config.txt");
        try {
            LocateRegistry.createRegistry(1099);
            Naming.bind("Service", new MathObject());
            log.writeLog("Server Started!!!");
        }
        catch (Exception e) {
            log.writeLog("Error: " + e.getMessage());
        }
    }
}