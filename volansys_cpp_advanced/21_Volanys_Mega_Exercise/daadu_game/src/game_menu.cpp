/**
 * @file menu.cpp
 * @author rohit S
 * @brief Menu screen of Daadu game
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024 Volansys technologies
 * 
 */

#include <iostream>
#include "game_menu.h"


char menu::display_menu()
{
    display_blue("1. Start the game\n");
    display_green("2. Exit the game\n");

    char c;

    std::cin >> c;

    return c;

    //clear();

}


