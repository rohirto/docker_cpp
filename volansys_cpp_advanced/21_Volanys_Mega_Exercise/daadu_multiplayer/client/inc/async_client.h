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
#include <iomanip> // For std::setw
#include <nlohmann/json.hpp>
#include "json_defines.h"
#include "game_event.h"
namespace asio = boost::asio;
using namespace std::placeholders;
using asio::ip::tcp;
using boost::system::error_code;


/**
 * @brief ClientMessage Object, 
 * Message is json
 * Parameters - 
 *  message_type: CONFIG_MESSAGE or GAME_MESSAGE
 *  payload: Enclosed object
 * 
 */
struct ClientMessage{
    nlohmann::json obj;

    public:
    ClientMessage(nlohmann::json& m);

    //Friend functions
    friend void to_json(nlohmann::json& j, const ClientMessage& m);
    friend void from_json(const nlohmann::json& j, ClientMessage& m);

};

/**
 * @brief TCP Client Class
 * 
 */
class TCPClient: public menu{
    public:
    TCPClient(asio::io_context& ioc, std::string const& host, std::string const& port) : socket_(ioc) {
        tcp::resolver resolver(ioc);
        connect(resolver.resolve(host, port));
    }
    void write(std::string const& message);
    void close();
    void process_response(std::string& response);
    std::string display_players(nlohmann::json& player_list);
    void server_matchup_request(std::string& player_no);
    void set_player_name(std::string& n){player_name = n;}
    std::string get_player_name(){return player_name;}

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

    std::string player_name;




};



