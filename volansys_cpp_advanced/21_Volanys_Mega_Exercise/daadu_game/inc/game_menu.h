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
#include "screen.h"


class menu: virtual public screen{

public:
    char display_menu();
    char display_cowry_menu(std::string_view name);
    char display_daa_menu();


};

#endif