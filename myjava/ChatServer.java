package myjava;

import java.io.*;
import java.net.*;
import java.util.*;

class ClientHandler extends Thread {
    private Socket client;
    private DataInputStream input;
    private DataOutputStream output;
    private static List<ClientHandler> clients = new ArrayList<>();

    public ClientHandler(Socket socket) throws IOException {
        this.client = socket;
        this.input = new DataInputStream(client.getInputStream());
        this.output = new DataOutputStream(client.getOutputStream());
        clients.add(this);
    }

    public void run() {
        try {
            String message;
            while (true) {
                message = input.readUTF();
                System.out.println("Client: " + message);
                broadcastMessage(message);
            }
        } catch (IOException e) {
            System.out.println("Client disconnected.");
        }
    }

    private void broadcastMessage(String message) throws IOException {
        for (ClientHandler client : clients) {
            client.output.writeUTF(message);
        }
    }
}

public class ChatServer {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(5000);
        System.out.println("Chat server started...");
        while (true) {
            Socket clientSocket = serverSocket.accept();
            System.out.println("New client connected.");
            new ClientHandler(clientSocket).start();
        }
    }
}