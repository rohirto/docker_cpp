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

/**
 * @brief TCP Client Write Method
 * 
 * @param message Message to write on the Connected Socket
 */
void TCPClient::write(std::string const &message)
{
    post(socket_.get_executor(), std::bind(&TCPClient::do_write, this, message));
}

/**
 * @brief TCP Client Close Method
 * 
 */
void TCPClient::close() { 
    post(socket_.get_executor(), std::bind(&TCPClient::do_close, this)); 
}


/**
 * @brief TCP Client Connect Method
 * 
 * @param endpoint_iterator resolver for Host and Service
 */
void TCPClient::connect(tcp::resolver::iterator endpoint_iterator)
{
    async_connect(socket_, endpoint_iterator, std::bind(&TCPClient::handle_connect, this, _1));
}

/**
 * @brief TCP Client connect callback Function
 * 
 * @param ec Error Code
 */
void TCPClient::handle_connect(error_code ec)
{
    if (!ec)
    {
        std::cout << "connected" << std::endl;
        Client_Init player;
        nlohmann::json j = player; //Serialize to json
        ClientMessage init_player(j);
        j = init_player;
        std::cout << j.dump(4) << std::endl;
        write(j.dump(4) + "\r\n");
        read();
    }
    else
    {
        std::cout << "connection failed (" << ec.message() << ")" << std::endl;
    }
}

/**
 * @brief TCP Client Private Write Method
 * 
 * @param message Message to be written
 */
void TCPClient::do_write(std::string const &message)
{
    async_write(socket_, asio::buffer(message), std::bind(&TCPClient::handle_write, this, _1));
}

/**
 * @brief TCP Client Write Callback Method
 * 
 * @param ec Error Code
 */
void TCPClient::handle_write(error_code ec) { 
    std::cout << "write " << ec.message() << std::endl; 
}

/**
 * @brief TCP Client Read Method
 * 
 */
void TCPClient::read()
{
    socket_.async_read_some(asio::buffer(data_), std::bind(&TCPClient::handle_read, this, _1, _2));

    // socket_.async_read_some(buf.prepare(1024), std::bind(&TCPClient::handle_read, this, _1, _2));
}

/**
 * @brief TCP Client Read Callback Method
 * 
 * @param ec Error Code
 * @param bytes_transferred  Bytes read
 */
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

/**
 * @brief TCP Client Private Close Method
 * 
 */
void TCPClient::do_close()
{
    socket_.close();
}

/**
 * @brief Construct a new Client Message:: Client Message object
 * 
 * @param m json object
 */
ClientMessage::ClientMessage(nlohmann::json& m)
{
    obj = m;
}

/**
 * @brief Serialize Method for ClientMessage Class
 * 
 * @param j  json object to which object is serialized
 * @param m Object to be Serialized
 * 
 * This method is used by the JSON Library to serialize the object
 */
void to_json(nlohmann::json& j, const ClientMessage& m)
{
    j = m.obj;
}

/**
 * @brief Deserialize Method for ClientMessage Class
 * 
 * @param j json object to from object is deserialized
 * @param m Object to be deserialized
 */
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