package io.github.tuilakhanh.Lab02.TCP;

import io.github.tuilakhanh.log.Log;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TCPServer {
    private final int port;
    private final ExecutorService executorService;
    private final Log log;

    public TCPServer(int port) {
        this.port = port;
        this.executorService = Executors.newCachedThreadPool();
        log = new Log("configs/config.txt");
    }

    public void startServer() throws IOException {
        try (var serverSocket = new ServerSocket(port)) {
            log.writeLog(String.format("[TCPServer] Waiting for client on port %s...%n", serverSocket.getLocalPort()));

            while (true) {
                var clientSocket = serverSocket.accept();
                log.writeLog(String.format("[TCPServer] Just connected to %s%n", clientSocket.getRemoteSocketAddress()));
                executorService.submit(() -> handleClient(clientSocket));
            }
        }
    }

    public void handleClient(Socket clientSocket)
    {
        try (var in = new DataInputStream(clientSocket.getInputStream());
             var out = new DataOutputStream(clientSocket.getOutputStream())) {
            log.writeLog(String.format("[TCPServer] %s", in.readUTF()));
            out.writeUTF(String.format("Thank you for connecting to %s \nGoodbye!", clientSocket.getLocalSocketAddress()));
            close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void close() {
        executorService.shutdownNow();
    }

    public static void main(String[] args) throws IOException {
        int port = 9000;
        if (args.length > 0) {
            port = Integer.parseInt(args[0]);
        }

        TCPServer server = new TCPServer(port);
        server.startServer();
    }
}
