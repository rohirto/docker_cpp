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

    display_yellow("██████   █████   █████  ██████  ██    ██");
    std::cout << std::endl;
    display_yellow("██   ██ ██   ██ ██   ██ ██   ██ ██    ██");
    std::cout << std::endl;
    display_yellow("██   ██ ███████ ███████ ██   ██ ██    ██");
    std::cout << std::endl;
    display_yellow("██   ██ ██   ██ ██   ██ ██   ██ ██    ██");
    std::cout << std::endl;
    display_yellow("██████  ██   ██ ██   ██ ██████   ██████");
    std::cout << std::endl;
    std::cout << std::endl;

    display_blue("1. Start the game\n");
    display_green("2. Exit the game\n");

    char c;

    std::cin >> c;

    return c;

    //clear();

}

char menu::display_cowry_menu(std::string_view name)
{
    std::cout << "\n";
    display_blue(name);
    display_yellow("'s turn:\n1. press 'f' to throw cowries: ");
    char c = get_char();

    return c;

}

char menu::display_daa_menu()
{
    display_yellow("\n1. Press 'k' to take out king\n2. Press 'p' to take out pawn\n3. Press 'c' to skip daa: ");

    char c = get_char();

    return c;
}


