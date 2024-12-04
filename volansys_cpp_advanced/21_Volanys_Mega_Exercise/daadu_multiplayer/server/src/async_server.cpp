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
#include "json_defines.h"
#include "game_server.h"



std::mutex cout_mutex;
std::map<int,std::string> client_map; // List of client names
int client_counter = 0;               // To assign unique client numbers
std::mutex client_map_mutex;                 // Mutex to protect name list

std::set<std::shared_ptr<class Session>> active_sessions; // Set of active sessions
std::mutex active_sessions_mutex;  // Mutex for active_sessions

std::unordered_map<int, std::shared_ptr<Game>> active_games;

void Session::start()
{
    {
        std::lock_guard<std::mutex> lock(active_sessions_mutex);
        active_sessions.insert(shared_from_this());
    }
    read();
}

void Session::write(const std::string &message)
{
    auto self = shared_from_this();
    asio::async_write(socket_, asio::buffer(message),
                      [self](boost::system::error_code ec, std::size_t /*length*/)
                      {
                          if (ec)
                          {
                              {
                                  std::lock_guard<std::mutex> lock(client_map_mutex);
                                  std::cerr << "Write Error: " << ec.message() << std::endl;
                              }
                          }
                      });
}

Session::~Session()
{
    // Remove this session from active_sessions
    {
        std::lock_guard<std::mutex> lock(active_sessions_mutex);
        active_sessions.erase(shared_from_this());
    }
}

void Session::read() {
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
                        ClientMessage m = received_json.get<ClientMessage>();
                        self->process_clientMessage(m);

                        // Continue reading
                        self->read();
                    } catch (const json::parse_error& e) {
                        {
                            std::lock_guard<std::mutex> lock(client_map_mutex);
                            std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
                            
                        }
                        // Optionally close the connection
                        self->socket_.close();
                    }
                } else {
                    {
                        std::lock_guard<std::mutex> lock(client_map_mutex);
                        std::cerr << "Client disconnected: " << ec.message() << std::endl;
                        // Remove client from the map
                        if (self->client_no != 0) {
                            client_map.erase(self->client_no);
                        }
                    }
                }
            });
    }

    

    void Session::process_clientMessage(ClientMessage &m)
    {
        auto self = shared_from_this();
        std::cout << "Payload : " << m.payload.dump(4) << std::endl;
        switch (m.message_type)
        {
        case JSON_CONFIG_MESSAGE:
            // Push forward to Config Message Handler - Add to the list
            if (m.payload.contains(JSON_NAME))
            {
                {
                    std::lock_guard<std::mutex> lock(client_map_mutex);
                    if (self->client_no == 0)
                    { // Assign client number if not already done
                        self->client_no = ++client_counter;
                        client_map[self->client_no] = m.payload[JSON_NAME];
                    }
                }
                //Send Response
                json response = json::object();
                json client_list = json::object();
                response[JSON_MESSAGE_TYPE] = JSON_CONFIG_MESSAGE;
                {
                    std::lock_guard<std::mutex> lock(client_map_mutex);
                    for (const auto &[no, name] : client_map)
                    {
                        if(no == self->client_no)
                        {
                            continue;   //Dont include the name of the client in the list to send
                        }
                        else
                        {
                            client_list[std::to_string(no)] = name;
                        }
                        
                    }
                }
                response[JSON_PAYLOAD][JSON_PLAYER_LIST] = client_list;
                response[JSON_PAYLOAD][JSON_PLAYER_NO] = self->client_no;
                std::string list_message = response.dump() + "\r\n";
                std::cout << list_message <<std::endl;
                self->write(list_message);
            }
            else
            {
                // Name field no there
            }
            break;
        case JSON_MATCHUP_PACKET:
            if (m.payload.contains(JSON_SOURCE_PLAYER))
            {
                int source_player_no = m.payload.at(JSON_SOURCE_PLAYER).get<int>();
                int dest_player_no = m.payload.at(JSON_DEST_PLAYER).get<int>();
                for (const auto &session : active_sessions)
                {
                    if (dest_player_no == session->get_client_no())
                    {
                        std::cout << "Player no " << dest_player_no << "found" << std::endl;
                        //Send the Matchup request to that Player
                        json response = json::object();
                        response[JSON_MESSAGE_TYPE] = JSON_MATCHUP_PACKET;
                        json player_request = json::object();
                        player_request[JSON_SOURCE_PLAYER] = source_player_no;
                        player_request[JSON_DEST_PLAYER] = dest_player_no;
                        response[JSON_PAYLOAD] = player_request;
                        std::string m_request = response.dump() + "\r\n";
                        session->write(m_request);
                        std::cout << "Sent Match up request from Player " << self->get_client_no() << "to Player " << session->get_client_no() << std::endl;
                        return; 
                    }
                }
                std::cout << "No such Player" << std::endl;
            }
            else
            {
                // No field Player no
            }

            break;
        case JSON_MATCHUP_RESP:
            //Send the packet as it is to the requester
            if (m.payload.contains(JSON_DEST_PLAYER) && m.payload.contains(JSON_SOURCE_PLAYER))
            {
                int source_player = m.payload.at(JSON_SOURCE_PLAYER).get<int>();
                int dest_player = m.payload.at(JSON_DEST_PLAYER).get<int>();
                std::string requested_response = m.payload.at(JSON_RESPONSE).get<std::string>();

                for (const auto &session : active_sessions)
                {
                    if (dest_player == session->get_client_no())
                    {
                        json response = json::object();
                        response = {
                            {JSON_MESSAGE_TYPE, JSON_MATCHUP_RESP},
                            {JSON_PAYLOAD, {
                                    {JSON_DEST_PLAYER, dest_player}, 
                                    {JSON_SOURCE_PLAYER, source_player},
                                    {JSON_RESPONSE, requested_response}}}};
                        std::string m_response = response.dump() + "\r\n";
                        session->write(m_response);
                        std::cout << "Sent Match up response from Player " << source_player << "to Player " <<  dest_player << std::endl;
                    }
                }
                if (requested_response == JSON_POSITIVE)
                {
                    // Start the game for 2 players
                    int game_id = 1 + (rand() % 100);

                    // Use a map for efficient session lookups
                    std::unordered_map<int, std::shared_ptr<Session>> session_map;
                    for (const auto &session : active_sessions)
                    {
                        session_map[session->get_client_no()] = session;
                    }

                    // Find Player 1
                    auto player1_it = session_map.find(source_player);
                    if (player1_it != session_map.end())
                    {
                        auto player1_session = player1_it->second;

                        // Find Player 2
                        auto player2_it = session_map.find(dest_player); // Assuming `dest_player` refers to Player 2 here.
                        if (player2_it != session_map.end())
                        {
                            auto player2_session = player2_it->second;
                            //Remove these players from client map
                            auto it = client_map.find(player2_session->get_client_no());
                            if (it != client_map.end())
                            {
                                client_map.erase(it);
                            }
                            it = client_map.find(player1_session->get_client_no());
                            if (it != client_map.end())
                            {
                                client_map.erase(it);
                            }
                            // Players 1 and 2 are found; start the game
                            std::cout << "Game started with ID: " << game_id << std::endl;
                            // Start game logic here
                            auto game = std::make_shared<Game>(player1_session, player2_session);
                        }
                    }
                }
            }
            break;
        case JSON_GAME_MESSAGE:
            break;

        default:
            break;
        }
    }


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



/**
 * @brief Construct a new Client Message:: Client Message object
 * 
 * @param m json object
 */
// ClientMessage::ClientMessage(json& m)
// {
//     obj = m;
// }

/**
 * @brief Serialize Method for ClientMessage Class
 * 
 * @param j  json object to which object is serialized
 * @param m Object to be Serialized
 * 
 * This method is used by the JSON Library to serialize the object
 */
void to_json(json& j, const ClientMessage& m)
{
    j[JSON_MESSAGE_TYPE] = m.message_type;
    j[JSON_PAYLOAD] = m.payload;
}

/**
 * @brief Deserialize Method for ClientMessage Class
 * 
 * @param j json object to from object is deserialized
 * @param m Object to be deserialized
 */
void from_json(const json& j, ClientMessage& m)
{
    m.message_type = j.at(JSON_MESSAGE_TYPE).get<int>();
    m.payload = j.at(JSON_PAYLOAD).get<json>();
    
}


