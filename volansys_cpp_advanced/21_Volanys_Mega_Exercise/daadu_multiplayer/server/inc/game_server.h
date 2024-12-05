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
#include "player.h"

class Game
{
    public:
    Game(std::shared_ptr<class Session> player1, std::shared_ptr<class Session> player2)
        : player1_(player1), player2_(player2), p1(1, player1->get_client_name()), p2(2, player2->get_client_name()) {
            game_state_ = GameState::GAME_START;
            notify_game_start();
            
        }
    private:
    void notify_game_start();

    enum class GameState
    {
        GAME_START,
        GAME_NOTIFIED,


    };


    std::shared_ptr<class Session> player1_, player2_;
    player p1, p2;
    GameState game_state_; // Encapsulation of the game rules and state
};