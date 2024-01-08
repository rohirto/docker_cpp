/**
 * @file demo_client.cpp
 * @author rohirto
 * @brief demo code to demonstrate client capabilites of c++ 
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
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Set up the server address structure
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    // Connect to the server
    if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        std::cerr << "Error connecting to server\n";
        close(clientSocket);
        return 1;
    }

    // Send data to the server
    const char* message = "Hello, Server!";
    ssize_t bytesSent = send(clientSocket, message, strlen(message), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending data\n";
    } else {
        std::cout << "Sent: " << message << "\n";
    }

    // Close the socket
    close(clientSocket);

    return 0;
}
