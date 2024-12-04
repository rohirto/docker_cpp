/**
 * @file game_server.cpp
 * @author rohirto
 * @brief Game Class for 2 Client Threads
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "game_server.h"
#include "json_defines.h"

void Game::notify_game_start()
{

    json j = json::object();
    j[JSON_MESSAGE_TYPE] = JSON_GAME_MESSAGE;
    j[JSON_PAYLOAD] = json{
        {JSON_SOURCE_PLAYER, JSON_SERVER_NO},
        {JSON_DEST_PLAYER, player1_->get_client_no()},
        {JSON_TURN, JSON_GAME_TRUE}
    };

    player1_->write(j.dump() + "\r\n");
    j[JSON_PAYLOAD] = json{
        {JSON_SOURCE_PLAYER, JSON_SERVER_NO},
        {JSON_DEST_PLAYER, player2_->get_client_no()},
        {JSON_TURN, JSON_GAME_FALSE}
    };
    player2_->write(j.dump() + "\r\n");

    game_state_ = GameState::GAME_NOTIFIED;
}