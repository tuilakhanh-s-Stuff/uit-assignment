package io.github.tuilakhanh.Lab02.TCP;

import io.github.tuilakhanh.log.Log;

import java.io.*;
import java.net.Socket;

public class TCPClient {
    private Log log;
    private final String serverAddress;
    private final int port;

    public TCPClient(String serverAddress, int port) {
        this.serverAddress = serverAddress;
        this.port = port;
        log = new Log("configs/config.txt");
    }

    public void connect() {
        try
        {
            log.writeLog(String.format("[TCPClient] Connecting to %s on port %s%n", serverAddress, port));
            var client = new Socket(serverAddress, port);
            log.writeLog(String.format("[TCPClient] Just connected to %s", client.getRemoteSocketAddress()));
            var out = new DataOutputStream(client.getOutputStream());
            var in = new DataInputStream(client.getInputStream());

            out.writeUTF(String.format("Hello from %s", client.getLocalSocketAddress()));
            log.writeLog(String.format("[TCPClient] Server says %s", in.readUTF()));
            client.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        String host = "localhost";
        int port = 9000;
        var client = new TCPClient(host, port);
        client.connect();
    }
}
