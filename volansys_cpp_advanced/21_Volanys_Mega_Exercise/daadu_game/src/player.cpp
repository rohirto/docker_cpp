/**
 * @file player.cpp
 * @author rohit S
 * @brief Player class implementation
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024 Volansys technologies
 * 
 */

#include "player.h"

void player::setname()
{
    std::cin >> name;

    std::cout << "Player name set to: " << name << std::endl;
}