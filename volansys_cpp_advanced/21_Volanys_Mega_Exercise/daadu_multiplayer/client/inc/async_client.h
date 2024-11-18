/**
 * @file async_client.h
 * @author rohirto
 * @brief async client header file
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

namespace asio = boost::asio;
using namespace std::placeholders;
using asio::ip::tcp;
using boost::system::error_code;

class TCPClient {
    public:
    TCPClient(asio::io_context& ioc, std::string const& host, std::string const& port) : socket_(ioc) {
        tcp::resolver resolver(ioc);
        connect(resolver.resolve(host, port));
    }
    void write(std::string const& message);
    void close();

    private:
    tcp::socket            socket_;
    std::array<char, 1024> data_{0};
    void connect(tcp::resolver::iterator endpoint_iterator);
    void handle_connect(error_code ec);
    void do_write(std::string const& message);
    void handle_write(error_code ec);
    void read();
    void handle_read(error_code ec, size_t bytes_transferred);
    void do_close();


};

