/**
 * @file game_event.cpp
 * @author rohirto
 * @brief Game Event Module for Client
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "game_event.h"
#include "json_defines.h"

/**
 * @brief Construct a new Client_Init::Client_Init object
 * 
 */
Client_Init::Client_Init()
{
    display_yellow("Enter Player ");
    display_yellow(" name: ");

    name = get_string();
}

/**
 * @brief Serialize Method for Client_Init Class
 * 
 * @param j  json object to which object is serialized
 * @param m Object to be Serialized
 * 
 * This method is used by the JSON Library to serialize the object
 */
void to_json(nlohmann::json& j, const Client_Init& m)
{
    j = nlohmann::json{
        {JSON_MESSAGE_TYPE, JSON_CONFIG_MESSAGE},  //Config Message
        {"name", m.name}
    };
}

/**
 * @brief Deserialize Method for Client_Init Class
 * 
 * @param j json object to from object is deserialized
 * @param m Object to be deserialized
 */
void from_json(const nlohmann::json& j, Client_Init& m)
{
    j.at("name").get_to(m.name);
}