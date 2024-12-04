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

void Game::notify_game_start()
{

    // player1_->write();
    // player2_->write();

    game_state_ = GameState::GAME_NOTIFIED;
}