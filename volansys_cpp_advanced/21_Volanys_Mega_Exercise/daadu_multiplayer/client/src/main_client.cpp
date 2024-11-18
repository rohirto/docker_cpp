/**
 * @file main_client.cpp
 * @author rohirto
 * @brief 
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "client_screen.h"
#include "async_client.h"
#include "game_menu.h"


#include <boost/asio.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
namespace asio = boost::asio;
using namespace std::placeholders;
using asio::ip::tcp;
using boost::system::error_code;

static std::string const hello_message = "Hello World!";

class TCPClient {
  public:
    TCPClient(asio::io_context& ioc, std::string const& host, std::string const& port) : socket_(ioc) {
        tcp::resolver resolver(ioc);
        connect(resolver.resolve(host, port));
    }

    void write(std::string const& message) {
        post(socket_.get_executor(), std::bind(&TCPClient::do_write, this, message));
    }

    void close() { post(socket_.get_executor(), std::bind(&TCPClient::do_close, this)); }

  private:
    void connect(tcp::resolver::iterator endpoint_iterator) {
        async_connect(socket_, endpoint_iterator, std::bind(&TCPClient::handle_connect, this, _1));
    }

    void handle_connect(error_code ec) {
        if (!ec) {
            std::cout << "connected" << std::endl;
            do_write(hello_message);
            read();
        } else {
            std::cout << "connection failed (" << ec.message() << ")" << std::endl;
        }
    }

    void do_write(std::string const& message) {
        async_write(socket_, asio::buffer(message), std::bind(&TCPClient::handle_write, this, _1));
    }

    void handle_write(error_code ec) { std::cout << "write " << ec.message() << std::endl; }

    void read() {
        socket_.async_read_some(asio::buffer(data_), std::bind(&TCPClient::handle_read, this, _1, _2));

        // socket_.async_read_some(buf.prepare(1024), std::bind(&TCPClient::handle_read, this, _1, _2));
    }

    void handle_read(error_code ec, size_t bytes_transferred) {
        std::cout << "Read " << ec.message() << " (" << bytes_transferred << ")" << std::endl;
        if (!ec) {
            std::cout << "Received: " 
            << std::string(data_.data(), bytes_transferred) 
            << bytes_transferred << std::endl;
            read();

        } else {
            // Handle the error
        }
    }

    void do_close() { socket_.close(); }

    tcp::socket            socket_;
    std::array<char, 1024> data_{0};
    // asio::streambuf     buf;
};

int main() {
    asio::io_context ioc;
    TCPClient        client(ioc, "127.0.0.1", "12345");
    

    client_screen *window;  //Polymorphic class
    menu m;

    window = &m;
    int choice = window->display_menu();

    if (choice == 1)
    {
        // Start the game
        window->clear();

        //Get the list of players on the Server

        ioc.run();
    }
}
