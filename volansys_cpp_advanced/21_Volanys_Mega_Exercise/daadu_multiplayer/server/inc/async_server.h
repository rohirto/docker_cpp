/**
 * @file async_server.h
 * @author rohirto
 * @brief Async Server header File
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <boost/asio.hpp>
#include <iostream>
#include <nlohmann/json.hpp> // For JSON serialization
#include <thread>
#include <vector>
#include <memory>
#include <mutex>

namespace asio = boost::asio;
using asio::ip::tcp;
using json = nlohmann::json;


class Server {

    public:
    Server(asio::io_context& ioc, unsigned short port, std::size_t thread_count);
    void run();

    private:
    void start_accept();


    asio::io_context ioc_;
    tcp::acceptor    acceptor_;
    std::vector<std::thread> threads_;
    std::size_t      thread_count_;
};

