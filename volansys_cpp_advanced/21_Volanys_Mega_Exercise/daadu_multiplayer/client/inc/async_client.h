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
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
#include <iomanip> // For std::setw
#include <nlohmann/json.hpp>
#include "json_defines.h"
#include "game_event.h"
namespace asio = boost::asio;
using namespace std::placeholders;
using asio::ip::tcp;
using boost::system::error_code;
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
    TCPClient(const std::string& host, unsigned short port)
        : socket_(ioc_), endpoint_(boost::asio::ip::address::from_string(host), port), client_state_(ClientState::IDLE) {}

    void write(std::string const& message);
    void close();
    void process_response(std::string& response);
    std::string display_players(nlohmann::json& player_list);
    void server_matchup_request(std::string& player_no);
    void set_player_name(std::string& n){player_name = n;}
    std::string get_player_name(){return player_name;}
    void run();

    private:
    //tcp::socket            socket_;
    std::array<char, 1024> data_{0};
    void connect(tcp::resolver::iterator endpoint_iterator);
    void handle_connect(error_code ec);
    void do_write(std::string const& message);
    void handle_write(error_code ec);
    void read();
    void handle_read(error_code ec, size_t bytes_transferred);
    void do_close();
    void connect_to_server();
    void handle_user_input();
    void process_user_input();
    void handle_server_response();

    /**
     * @brief The Enum which stores various states of Client
     *
     */
    enum class ClientState
    {
        IDLE,
        CONNECTED_TO_SERVER,
        MAIN_SCREEN,
        ENTER_PLAYER_NAME_SCREEN,
        RULES_DISPLAY_SCREEN,
        DISPLAY_PLAYERS,
        Idle,
        WaitingForOpponent,
        Playing,
        Disconnected
    };

    std::string player_name;
    boost::asio::io_context ioc_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::endpoint endpoint_;
    std::atomic<ClientState> client_state_;
    std::queue<std::string> user_inputs_;
    std::mutex queue_mutex_;
    std::condition_variable cv_;




};

//Thread Prototypes
void handle_user_input();
void process_user_input(boost::asio::ip::tcp::socket& socket);
void handle_server_response(boost::asio::ip::tcp::socket& socket);



