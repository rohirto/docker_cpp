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

static std::string const hello_message = "Hello World!";

void TCPClient::write(std::string const &message)
{
    post(socket_.get_executor(), std::bind(&TCPClient::do_write, this, message));
}

void TCPClient::close() { 
    post(socket_.get_executor(), std::bind(&TCPClient::do_close, this)); 
}

void TCPClient::connect(tcp::resolver::iterator endpoint_iterator)
{
    async_connect(socket_, endpoint_iterator, std::bind(&TCPClient::handle_connect, this, _1));
}

void TCPClient::handle_connect(error_code ec)
{
    if (!ec)
    {
        std::cout << "connected" << std::endl;
        do_write(hello_message);
        read();
    }
    else
    {
        std::cout << "connection failed (" << ec.message() << ")" << std::endl;
    }
}

void TCPClient::do_write(std::string const &message)
{
    async_write(socket_, asio::buffer(message), std::bind(&TCPClient::handle_write, this, _1));
}

void TCPClient::handle_write(error_code ec) { 
    std::cout << "write " << ec.message() << std::endl; 
}

void TCPClient::read()
{
    socket_.async_read_some(asio::buffer(data_), std::bind(&TCPClient::handle_read, this, _1, _2));

    // socket_.async_read_some(buf.prepare(1024), std::bind(&TCPClient::handle_read, this, _1, _2));
}

void TCPClient::handle_read(error_code ec, size_t bytes_transferred)
{
    std::cout << "Read " << ec.message() << " (" << bytes_transferred << ")" << std::endl;
    if (!ec)
    {
        std::cout << "Received: "
                  << std::string(data_.data(), bytes_transferred)
                  << bytes_transferred << std::endl;
        read();
    }
    else
    {
        // Handle the error
    }
}

void TCPClient::do_close()
{
    socket_.close();
}