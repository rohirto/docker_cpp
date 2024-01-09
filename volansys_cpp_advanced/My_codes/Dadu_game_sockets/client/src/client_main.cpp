/**
 * @file client_main.cpp
 * @author rohirto
 * @brief Mutiplayer version of Dadu game which can be played over sockets
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "screen.h"
#include "game_menu.h"

int main()
{
    screen *window;  //Polymorphic class

    menu m;

    window = &m;

    int choice = window->display_menu();

    if (choice == 1)
    {
        //Start the game, first connect to the server

    }
    else if (choice == 3)
    {
        // Exit the game
        window->display_red("Exiting the game!\n");
    }
    else if(choice == 2)
    {
        //Display Rules to play
        window->clear();
        window->display_rules();
    }



    return 0;
}