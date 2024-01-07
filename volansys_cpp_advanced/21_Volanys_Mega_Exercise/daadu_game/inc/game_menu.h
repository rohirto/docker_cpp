/**
 * @file menu.h
 * @author rohit S
 * @brief Menu header for Dadu game
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024 Volansys Technolgies
 * 
 */

#ifndef _GAME_MENU_H_
#define _GAME_MENU_H_

#include <ncurses.h>
#include <iostream>
#include <vector>
#include "screen.h"

/**
 * @brief menu object, to display various types of menu to user
 * 
 */
class menu: virtual public screen{

public:
    int display_menu();
    char display_cowry_menu(std::string_view name);
    char display_daa_menu();
    int display_possible_moves(std::vector<int>& moves);
    char display_rules();
    void display_overlaps(std::vector<std::string>& s);


};

#endif