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
#include <game_event.h>



std::mutex cout_mutex;


class Session : public std::enable_shared_from_this<Session> {
public:
    explicit Session(tcp::socket socket)
        : socket_(std::move(socket)), buffer_("") {}

    void start() { read(); }

private:
    void read() {
        auto self = shared_from_this();
        asio::async_read_until(socket_, asio::dynamic_buffer(buffer_), "\r\n",
            [self](boost::system::error_code ec, std::size_t length) {
                if (!ec) {
                    try {
                        // Extract and process JSON data
                        std::string received_data = self->buffer_.substr(0, length);
                        self->buffer_.erase(0, length); // Remove processed data
                        json received_json = json::parse(received_data);

                        // Synchronized output
                        std::lock_guard<std::mutex> lock(cout_mutex);
                        std::cout << "Received JSON: " << received_json.dump(4) << std::endl;

                        // Continue reading
                        self->read();
                    } catch (const json::parse_error& e) {
                        {
                            std::lock_guard<std::mutex> lock(cout_mutex);
                            std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
                            
                        }
                        // Optionally close the connection
                        self->socket_.close();
                    }
                } else {
                    {
                        std::lock_guard<std::mutex> lock(cout_mutex);
                        std::cerr << "Client disconnected: " << ec.message() << std::endl;
                    }
                }
            });
    }

    void write(const std::string& message) {
        auto self = shared_from_this();
        asio::async_write(socket_, asio::buffer(message),
            [self](boost::system::error_code ec, std::size_t /*length*/) {
                if (ec) {
                    {
                        std::lock_guard<std::mutex> lock(cout_mutex);
                        std::cerr << "Write Error: " << ec.message() << std::endl;
                    }
                }
            });
    }

    tcp::socket socket_;
    std::string buffer_;
};

Server::Server(asio::io_context &ioc, unsigned short port, std::size_t thread_count)
    : acceptor_(ioc, tcp::endpoint(tcp::v4(), port)), thread_count_(thread_count)
{
    start_accept();
}

void Server::run()
{
    // Create thread pool
    for (std::size_t i = 0; i < thread_count_; ++i)
    {
        threads_.emplace_back([this]()
                              { ioc_.run(); });
    }

    // Wait for threads to finish
    for (auto &t : threads_)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}

void Server::start_accept()
{
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket)
        {
            if (!ec)
            {
                std::cout << "New client connected!" << std::endl;
                std::make_shared<Session>(std::move(socket))->start();
            }
            else
            {
                std::cerr << "Accept Error: " << ec.message() << std::endl;
            }
            // Continue accepting new clients
            start_accept();
        });
}

