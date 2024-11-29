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
#include <set>
#include "client_screen.h"

/**
 * @brief menu object, to display various types of menu to user
 * 
 */
class menu: virtual public client_screen{

public:
    void display_menu() override;
    char display_cowry_menu(std::string_view name)override;
    char display_daa_menu()override;
    int display_possible_moves(std::vector<int>& moves);
    void display_rules()override;
    void display_overlaps(std::vector<std::string>& s);
    void display_overlaps_set(std::set<int>& cp, int player_no);


};

void win_menu(int no);

#endif