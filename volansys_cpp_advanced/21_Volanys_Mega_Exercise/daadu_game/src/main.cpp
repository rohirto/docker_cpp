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
#include<unistd.h>
#include "game_menu.h"
#include "game_objects.h"
#include "player.h"
#include <limits>

void toggle_turns(player& p1, player& p2)
{
    if(p1.get_turn())
    {
        p1.set_turn(false);
        p2.set_turn(true);
    }
    else
    {
        p1.set_turn(true);
        p2.set_turn(false);
    }
}

void check_clashes(player& p1, player& p2)
{
    
}

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

        while (1)
        {
            char ch;
            // Player 1 turn
            if (p1.get_turn())
            {
                window->display_yellow(p1.getname());
                window->display_yellow(" ,press f to thrown cowries");

                std::cin >> ch;
                if (ch == 'f')
                {

                    c.cowry_throw();
                    int score = c.getCount();

                    window->display_yellow("You got: ");
                    window->display_blue(score);
                    std::cout << std::endl;

                    //Add 3sec delay
                    usleep(3 * 1000000);//sleeps for 3 second

                    switch (score)
                    {
                    case 1:
                        window->display_yellow("Press 'k' to tale out king or press 'p' to take out pawn, press 'c' to skip daa: ");

                        ch = window->get_char();
                        while(ch != 'k' && ch != 'p' && ch != 'c')
                        {
                            ch = window->get_char();
                        }
                        
                        if(ch == 'k' || ch == 'p')
                        {
                            // Player opted for daa
                            if (p1.daa_check(ch))
                            {
                                // remove a pawn
                                
                            }
                            else
                            {
                                //daa already done, account as one
                                p1.move_piece(1,p2);
                            }
                        }
                        else if(ch == 'c')
                        {
                            p1.move_piece(1,p2);
                        }
                        break;
                    case 2:
                        if(p1.check_daa_initiated())
                        {
                            p1.move_piece(2,p2);
                        }
                        
                        toggle_turns(p1,p2);
                        break;
                    case 3:
                        if(p1.check_daa_initiated())
                        {
                            p1.move_piece(3,p2);
                        }
                        
                        toggle_turns(p1,p2);
                        
                        break;
                    case 4:
                        if(p1.check_daa_initiated())
                        {
                            p1.move_piece(4,p2);
                        }
                        
                        toggle_turns(p1,p2);
                        break;
                    case 10:
                        if(p1.check_daa_initiated())
                        {
                            p1.move_piece(10,p2);
                        }
                        
                        break;
                    default:
                        toggle_turns(p1,p2);
                        break;
                    }

                    window->clear();
                    gb.set_board(p1, p2);
                }

                else
                {
                    window->display_yellow("wrong key pressed!\n");
                }
            }
            else if(p2.get_turn())
            {
                window->display_yellow(p2.getname());
                window->display_yellow(" ,press f to thrown cowries");

                std::cin >> ch;
                if (ch == 'f')
                {

                    c.cowry_throw();
                    int score = c.getCount();

                    window->display_yellow("You got: ");
                    window->display_blue(score);
                    std::cout << std::endl;

                    //Add 3sec delay
                    usleep(3 * 1000000);//sleeps for 3 second

                    switch (score)
                    {
                    case 1:
                        window->display_yellow("Press 'k' to tale out king or press 'p' to take out pawn, press 'c' to skip daa: ");
                        ch = window->get_char();
                        while(ch != 'k' && ch != 'p' && ch != 'c')
                        {
                            ch = window->get_char();
                        }
                        
                        if(ch == 'k' || ch == 'p')
                        {
                            // Player opted for daa
                            if (p2.daa_check(ch))
                            {
                                // remove a pawn
                                
                            }
                            else
                            {
                                //daa already done, account as one
                                p2.move_piece(1,p1);
                            }
                        }
                        else if(ch == 'c')
                        {
                            p2.move_piece(1,p1);
                        }

                        break;
                    case 2:
                        if(p2.check_daa_initiated())
                        {
                            p2.move_piece(2,p1);
                        }
                        
                        toggle_turns(p1,p2);
                        break;
                    case 3:
                        if(p2.check_daa_initiated())
                        {
                             p2.move_piece(3,p1);
                        }
                       
                        toggle_turns(p1,p2);
                        break;
                    case 4:
                        if(p2.check_daa_initiated())
                        {
                            p2.move_piece(4,p1);
                        }
                        
                        toggle_turns(p1,p2);
                        break;
                    case 10:
                        if(p2.check_daa_initiated())
                        {
                            p2.move_piece(10,p1);
                        }
                        break;
                    default:
                        toggle_turns(p1,p2);
                        break;
                    }

                    window->clear();
                    gb.set_board(p1, p2);
                }

                else
                {
                    window->display_yellow("wrong key pressed!\n");
                }

            }

            //Check clashes
            check_clashes(p1,p2);


        }
    }
    else if (choice == '2')
    {
        // Exit the game
        window->display_red("Exiting the game!\n");
    }

    return 0;
}