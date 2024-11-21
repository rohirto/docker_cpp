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
void TCPClient::close()
{
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
        display_green("Connected to Server\r\n");
        display_blue("Enter Player name: \r\n");
        std::string n = get_string();
        set_player_name(n);

        nlohmann::json j = nlohmann::json{
            {JSON_MESSAGE_TYPE, JSON_CONFIG_MESSAGE},          // Config Message
            {JSON_PAYLOAD, {{JSON_NAME, get_player_name()}}}}; // Serialize to json
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
void TCPClient::handle_write(error_code ec)
{
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
        // std::cout << "Received: "
        //           << std::string(data_.data(), bytes_transferred)
        //           << bytes_transferred << std::endl;
        std::string r = std::string(data_.data(), bytes_transferred);
        process_response(r);

        read();
    }
    else
    {
        // Handle the error
    }
}

void TCPClient::process_response(std::string &response)
{
    nlohmann::json resp_json = nlohmann::json::parse(response);
    if (resp_json.contains(JSON_MESSAGE_TYPE))
    {
        int m_type = resp_json.at(JSON_MESSAGE_TYPE).get<int>();
        switch (m_type)
        {
        case JSON_CONFIG_MESSAGE:
        {
            // Extract the payload
            nlohmann::json client_list = resp_json["payload"];
            // Display Players
            std::string player_no = display_players(client_list);
            server_matchup_request(player_no);
            break;
        }
        case JSON_GAME_MESSAGE:
            break;

        default:
            break;
        }
    }
    else
    {
        // Invalid Packet received
    }
}

std::string TCPClient::display_players(nlohmann::json &player_list)
{
    clear();
    display_blue("Availabe Players on Server, Enter no to match up with: \r\n");
    display_green("Press R to refresh the list\r\n");
    //  Display the table header
    std::cout << std::setw(5) << "No." << std::setw(15) << "Name" << std::endl;
    std::cout << "-----------------------" << std::endl;

    // Iterate through the payload and display the table
    for (auto &[key, value] : player_list.items())
    {
        std::cout << std::setw(5) << key << std::setw(15) << value << std::endl;
    }
    while (true)
    {
        std::string selection = get_string();
        // Check if input is 'R' or 'r'
        if (selection.size() == 1 && (tolower(selection[0]) == 'r'))
        {
            return "R"; // Normalize to uppercase 'R'
        }

        // Check if input is numeric
        bool is_numeric = true;
        for (char c : selection)
        {
            if (!isdigit(c))
            {
                is_numeric = false;
                break;
            }
        }

        if (is_numeric)
        {
            return selection; // Valid numeric input
        }

        display_red("Invalid Input please try again\r\n");
    }
}

void TCPClient::server_matchup_request(std::string& player_no)
{
    nlohmann::json j;
    if (player_no == "R")
    {
        // Send Refresh Packet
        j = nlohmann::json{
            {JSON_MESSAGE_TYPE, JSON_CONFIG_MESSAGE},        // Config Message
            {JSON_PAYLOAD, {{JSON_NAME, get_player_name()}}} // Serialize to json
        };
    }
    else
    {
        j = nlohmann::json{
            {JSON_MESSAGE_TYPE, JSON_MATCHUP_PACKET},
            {JSON_PAYLOAD, {{JSON_PLAYER_NO, std::stoi(player_no)}}}

        };
    }
    write(j.dump(4) + "\r\n");
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
ClientMessage::ClientMessage(nlohmann::json &m)
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
void to_json(nlohmann::json &j, const ClientMessage &m)
{
    j = m.obj;
}

/**
 * @brief Deserialize Method for ClientMessage Class
 *
 * @param j json object to from object is deserialized
 * @param m Object to be deserialized
 */
void from_json(const nlohmann::json &j, ClientMessage &m)
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