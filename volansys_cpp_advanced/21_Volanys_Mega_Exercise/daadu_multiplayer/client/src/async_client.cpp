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
        Client_Init player;
        nlohmann::json j = player; //Serialize to json
        ClientMessage init_player(j);
        j = init_player;
        //do_write(hello_message);
        std::cout << j.dump(4) << std::endl;
        write(j.dump(4));
        write("\r\n");
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


ClientMessage::ClientMessage(nlohmann::json& m)
{
    obj = m;
}

void to_json(nlohmann::json& j, const ClientMessage& m)
{
    j = m.obj;
}

void from_json(const nlohmann::json& j, ClientMessage& m)
{
    int m_type = j.at(JSON_MESSAGE_TYPE).get<int>();

    std::cout << "Incoming message type :" << m_type << std::endl;

    switch (m_type)
    {
    case JSON_CONFIG_MESSAGE:
        /* code */
        break;
    case JSON_GAME_MESSAGE:
        break;
    
    default:
        break;
    }
}