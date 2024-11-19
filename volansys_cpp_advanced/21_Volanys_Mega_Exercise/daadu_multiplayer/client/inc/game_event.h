/**
 * @file game_event.h
 * @author rohirto
 * @brief Game Event module header file
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include "game_menu.h" 

/**
 * @brief Client Init Class, Player Init Class which will take the player name and send to Server
 * 
 */
struct Client_Init: public menu
{
    std::string name;

    public:
    Client_Init();

    //Friend Functions
    friend void to_json(nlohmann::json& j, const Client_Init& m);
    friend void from_json(const nlohmann::json& j, Client_Init& m);
};


