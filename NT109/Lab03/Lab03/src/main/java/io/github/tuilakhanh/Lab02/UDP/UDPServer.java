package io.github.tuilakhanh.Lab02.UDP;

import io.github.tuilakhanh.log.Log;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class UDPServer {
    private final DatagramSocket socket;
    private final ExecutorService executorService;
    private InetAddress clientAddress;
    private int clientPort;
    private Log log;

    public UDPServer(int port) throws SocketException {
        socket = new DatagramSocket(port);
        executorService = Executors.newSingleThreadExecutor();
        log = new Log("configs/config.txt");
    }

    public void start() {
        log.writeLog(String.format("[UDPServer] Server started on port %s", socket.getLocalPort()));
        executorService.execute(this::receiveMessages);

        try (Scanner scanner = new Scanner(System.in)) {
            while (true) {
                String message = scanner.nextLine();
                sendMessage(message);
            }
        }
    }

    private void receiveMessages() {
        while (true) {
            try {
                byte[] buf = new byte[1024];
                var packet = new DatagramPacket(buf, buf.length);
                socket.receive(packet);

                clientAddress = packet.getAddress();
                clientPort = packet.getPort();
                var received = new String(packet.getData(), 0, packet.getLength());
                log.writeLog(String.format("[UDPServer] Client: " + received));
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    private void sendMessage(String message) {
        if (clientAddress == null) {
            return;
        }
        byte[] buf = message.getBytes();
        DatagramPacket packet = new DatagramPacket(buf, buf.length, clientAddress, clientPort);
        try {
            socket.send(packet);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) throws SocketException {
        UDPServer server = new UDPServer(9000);
        server.start();
    }
}
