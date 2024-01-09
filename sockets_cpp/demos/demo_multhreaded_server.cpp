/**
 * @file demo_multhreaded_server.cpp
 * @author rohirto
 * @brief Demo of Multithreaded server showing capabilties of handling multiple clients
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <algorithm>

struct ClientInfo {
    int socket;
    struct sockaddr_in address;
    // Other client-specific data
};

std::vector<ClientInfo> clients;
std::mutex clientListMutex;

void handle_client(int client_socket) {
    // Communication with the client
    // ...

    // Example: Receive and print data from the client
    char buffer[1024];
    ssize_t bytesRead = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        perror("Failed to receive data");
    } else {
        buffer[bytesRead] = '\0';
        std::cout << "Received from client " << client_socket << ": " << buffer << "\n";
    }

    // Close the client's socket
    close(client_socket);

    // Remove the client from the list
    std::lock_guard<std::mutex> lock(clientListMutex);
    clients.erase(std::remove_if(clients.begin(), clients.end(),
        [client_socket](const ClientInfo& client) { return client.socket == client_socket; }),
        clients.end());
}

int main() {
    
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address)) == -1) {
        perror("Failed to bind socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        perror("Error listening on socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port 12345...\n";

    while (true) {
        int client_socket = accept(server_socket, nullptr, nullptr);
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;  // Skip to the next iteration
        }

        // Create a new thread for each client
        std::thread clientThread(handle_client, client_socket);
        clientThread.detach();  // Detach the thread to allow it to run independently

        // Store information about the connected client
        {
            std::lock_guard<std::mutex> lock(clientListMutex);
            clients.push_back({client_socket, {} /* address initialization */});
        }
    }

    close(server_socket);
    return 0;
}
