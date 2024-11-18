/**
 * @file async_server.cpp
 * @author rohirto
 * @brief Async Server module
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "async_server.h"
#include "server_screen.h"

using namespace boost::asio;
using ip::tcp;

void handle_client(tcp::socket socket) {
    try {
        char buf[1024];
        size_t len = socket.read_some(buffer(buf));
        std::cout << "Received: " << std::string(buf, len) << std::endl;

        std::string response = "Hello from async server!";
        write(socket, buffer(response));
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void async_server() {
    io_context io;
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 12345));

    server_screen::get_instance().display_green("Server listening on Port 12345...");

    while (true) {
        tcp::socket socket(io);
        acceptor.accept(socket);
        std::thread(handle_client, std::move(socket)).detach();
    }
}