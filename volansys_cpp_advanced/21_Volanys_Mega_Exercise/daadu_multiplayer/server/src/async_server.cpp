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



std::mutex cout_mutex;
std::vector<std::string> client_names_; // List of client names
std::mutex name_mutex_;                 // Mutex to protect name list


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
                        ClientMessage m = received_json.get<ClientMessage>();
                        self->process_clientMessage(m);

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

    void process_clientMessage(ClientMessage &m)
    {
        auto self = shared_from_this();
        switch (m.message_type)
        {
        case JSON_CONFIG_MESSAGE:
            /* code */
            std::cout << "Payload : " << m.payload.dump(4) << std::endl;
            // Push forward to Config Message Handler - Add to the list
            if (m.payload.contains(JSON_NAME))
            {
                add_client_name(m.payload[JSON_NAME]);
                json response = {
                    {"message_type", 1},
                    {"client_names", get_client_names()} 
                };
                self->write(response.dump(4) + "\r\n");
            }
            break;
        case JSON_GAME_MESSAGE:
            break;

        default:
            break;
        }
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

void add_client_name(const std::string &name)
{
    std::lock_guard<std::mutex> lock(name_mutex_);
    client_names_.push_back(name);
}

void remove_client_name(const std::string &name)
{
    std::lock_guard<std::mutex> lock(name_mutex_);
    client_names_.erase(std::remove(client_names_.begin(), client_names_.end(), name), client_names_.end());
}

json get_client_names()
{
    std::lock_guard<std::mutex> lock(name_mutex_);
    return nlohmann::json(client_names_);
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


