/**
 * @file game_server.h
 * @author rohirto
 * @brief Header File Game Class
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "async_server.h"

class Game
{
    public:
    Game(std::shared_ptr<class Session> player1, std::shared_ptr<class Session> player2)
        : player1_(player1), player2_(player2), turn_(1) {}
    private:

    enum class GameState
    {

    };


    std::shared_ptr<class Session> player1_, player2_;
    GameState game_state_; // Encapsulation of the game rules and state
    int turn_;
};