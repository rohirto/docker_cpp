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



void to_json(nlohmann::json& j, const Client_Init& m)
{
    j = nlohmann::json{
        {JSON_MESSAGE_TYPE, JSON_CONFIG_MESSAGE},  //Config Message
        {"name", m.name}
    };
}

void from_json(const nlohmann::json& j, Client_Init& m)
{
    j.at("name").get_to(m.name);
}