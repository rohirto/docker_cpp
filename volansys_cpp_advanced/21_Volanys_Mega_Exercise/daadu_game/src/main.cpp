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
#include "game_objects.h"
#include "player.h"

int main()
{
    screen *window;  //Polymorphic class
    menu m;
    
    game_board gb;

    window = &m;

    char choice = window->display_menu();

    if (choice == '1')
    {

        // Start the game
        window->clear();
        player p1, p2;

        // Start the game
        window->clear();
        gb.set_board(p1, p2);

        cowries c;

        while(1)
        {
            //Player 1 turn
            window->display_yellow("Player 1 turn \t press enter to throw cowries: ");
            std::cin >> choice;

            
            if(choice == '\n')
            {

                c.cowry_throw();
                int score = c.getCount();

                switch (score)
                {
                case 1:
                    if(p1.daa_check())
                    {
                        //remove a pawn
                    }
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4: 
                    break;
                case 10:
                    break;
                default:
                    break;
                }
            }
            else
            {
                window->display_yellow("wrong key pressed!\n");
            }

        }

    }
    else if (choice == '2')
    {
        // Exit the game
        window->display_red("Exiting the game!\n");
    }

    return 0;
}