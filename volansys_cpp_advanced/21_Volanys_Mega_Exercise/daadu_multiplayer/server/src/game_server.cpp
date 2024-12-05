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
    json player1_json, player2_json;
    to_json(player1_json, p1);
    to_json(player2_json, p2);
    json j = json::object();
    json players = json::object();
    j[JSON_MESSAGE_TYPE] = JSON_GAME_MESSAGE;
    players[JSON_PLAYER_1] = player1_json;
    players[JSON_PLAYER_2] = player2_json;
    j[JSON_PAYLOAD] = players;
    player1_->write(j.dump() + "\r\n");
    player2_->write(j.dump() + "\r\n");

    game_state_ = GameState::GAME_NOTIFIED;
}