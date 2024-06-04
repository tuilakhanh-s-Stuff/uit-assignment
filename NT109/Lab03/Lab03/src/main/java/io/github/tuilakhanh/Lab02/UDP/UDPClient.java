package io.github.tuilakhanh.Lab02.UDP;

import io.github.tuilakhanh.log.Log;

import java.io.IOException;
import java.net.*;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class UDPClient {
    private final InetAddress serverAddress;
    private final int serverPort;
    private final DatagramSocket socket;
    private final ExecutorService executorService;
    private final Log log;

    public UDPClient(String serverAddress, int port) throws UnknownHostException, SocketException {
        this.serverAddress = InetAddress.getByName(serverAddress);
        this.serverPort = port;
        this.socket = new DatagramSocket(5001);
        this.executorService = Executors.newCachedThreadPool();
        log = new Log("configs/config.txt");
    }

    public void connect() {
        log.writeLog(String.format("[UDPClient] Connected to server on port %s", serverPort));
        executorService.execute(this::receiveMessages);

        try (Scanner scanner = new Scanner(System.in)) {
            while (true) {
                String message = scanner.nextLine();
                sendMessages(message);
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private void receiveMessages() {
        while (true) {
            try {
                var buf = new byte[1024];
                var packet = new DatagramPacket(buf, buf.length);
                socket.receive(packet);

                var received = new String(packet.getData(), 0, packet.getLength());
                log.writeLog(String.format("[UDPClient] Server: %s", received));
            } catch (IOException e) {
                log.writeLog(String.format("[UDPClient] Error receiving message: %s", e.getMessage()));
                break;
            }
        }
    }

    private void sendMessages(String message) {
        try {
            var buf = message.getBytes();
            var packet = new DatagramPacket(buf, buf.length, serverAddress, serverPort);
            socket.send(packet);
        } catch (IOException e) {
            log.writeLog(String.format("[UDPClient] Error receiving message: %s", e.getMessage()));
        }
    }

    public static void main(String[] args) throws IOException {
        var client = new UDPClient("localhost", 9000);
        client.connect();
    }
}
