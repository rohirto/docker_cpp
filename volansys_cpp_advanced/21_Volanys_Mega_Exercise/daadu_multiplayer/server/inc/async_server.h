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
#include <map>
#include <set>

namespace asio = boost::asio;
using asio::ip::tcp;
using json = nlohmann::json;

/**
 * @brief ClientMessage Object, 
 * Message is json
 * Parameters - 
 *  message_type: CONFIG_MESSAGE or GAME_MESSAGE
 *  payload: Enclosed object
 * 
 */
struct ClientMessage{
    int message_type;
    json payload;

    public:
    //ClientMessage(json& m);

    //Friend functions
    friend void to_json(json& j, const ClientMessage& m);
    friend void from_json(const json& j, ClientMessage& m);

};


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

class Session : public std::enable_shared_from_this<Session> {
    public:
    explicit Session(tcp::socket socket)
        : socket_(std::move(socket)), buffer_(""), client_no(0) {}
    
    void start();
    void write(const std::string& message);
    int get_client_no() const { return client_no; }
    ~Session();
    private:
    void read();
    void process_clientMessage(ClientMessage &m);

    tcp::socket socket_;
    std::string buffer_;
    int client_no;
};
