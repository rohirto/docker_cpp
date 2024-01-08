/**
 * @file demo_server.cpp
 * @author rohirto
 * @brief Demo to demonstrate c++ server capabilties
 * @version 0.1
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Set up the server address structure
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified address and port
    if (bind(serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding socket\n";
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error listening on socket\n";
        close(serverSocket);
        return 1;
    }

    std::cout << "Server listening on port 12345...\n";

    // Accept a client connection
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == -1) {
        std::cerr << "Error accepting connection\n";
        close(serverSocket);
        return 1;
    }

    // Receive data from the client
    char buffer[1024];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        std::cerr << "Error receiving data\n";
    } else {
        buffer[bytesRead] = '\0';
        std::cout << "Received: " << buffer << "\n";
    }

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
