/**
 * @file main.cpp
 * @author rohit S
 * @brief Main function of Dadu game
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024 Volansys Technologies
 * 
 */

#include "game_menu.h"
#include "player.h"

int main()
{
    screen *window;  //Polymorphic class
    menu m;
    player p;
    

    window = &m;

    char choice = window->display_menu();

    switch (choice)
    {
    case '1':
        //Start the game
        window->clear();
        window->display_yellow("Enter Player name: ");
        p.setname();
        break;
    case '2':
        //Exit the game
        window->display_red("Exiting the game!\n");
        break;
    
    default:
        break;
    }
    return 0;
}