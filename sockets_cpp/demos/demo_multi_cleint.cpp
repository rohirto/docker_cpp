/**
 * @file demo_multi_cleint.cpp
 * @author rohirto
 * @brief Client for a multithreaded Server
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    if (connect(client_socket, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address)) == -1) {
        perror("Failed to connect to server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    const char* message = "Hello, Server!";
    ssize_t bytesSent = send(client_socket, message, strlen(message), 0);
    if (bytesSent == -1) {
        perror("Failed to send data");
    } else {
        std::cout << "Sent to server: " << message << "\n";
    }

    close(client_socket);
    return 0;
}
