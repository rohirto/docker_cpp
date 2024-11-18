/**
 * @file async_client.cpp
 * @author rohirto
 * @brief Async Client Module
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "async_client.h"

using namespace boost::asio;
using ip::tcp;

void sync_tcp_client(const std::string& server_ip) {
    io_context io;

    // Create a socket and connect to the server
    tcp::socket socket(io);
    socket.connect(tcp::endpoint(ip::address::from_string(server_ip), 12345));
    std::cout << "Connected to server at " << server_ip << std::endl;

    // Send data to the server
    std::string message = "Hello from client!";
    write(socket, buffer(message));
    std::cout << "Sent: " << message << std::endl;

    // Receive a response from the server
    char buf[1024];
    size_t len = socket.read_some(buffer(buf));
    std::cout << "Received: " << std::string(buf, len) << std::endl;
}