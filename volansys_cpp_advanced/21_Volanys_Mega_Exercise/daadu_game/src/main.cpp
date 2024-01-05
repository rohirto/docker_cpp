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

bool player_check(player& p)
{
    std::map<int, piece> pos = p.pawn_get_pos();
    for(auto& pw: pos)
    {
        if(!pw.second.checkpt_check())
        {
            return false;
        }
    }
    piece k = p.king_get_pos();
    if(!k.checkpt_check())
    {
        return false;
    }

   

    return true;

}

bool check_win(player& p1, player& p2)
{
    
    if(player_check(p1))
    {
        std::cout << p1.getname() << " Wins";
        return true;

    }
    else if (player_check(p2))
    {
        std::cout << p2.getname() << "Wins";
        return true;
    }

    return false;
}

void handle_turn(screen *window, player &p, player &other, cowries& c, game_board& gb)
{
    char ch = window->display_cowry_menu(p.getname());
    if (ch == 'f')
    {

        c.cowry_throw();
        int score = c.getCount();

        window->display_yellow("You got: ");
        window->display_blue(score);
        std::cout << std::endl;

        // Add 3sec delay
        usleep(2 * 1000000); // sleeps for 3 second

        switch (score)
        {
        case 1:
            ch = window->display_daa_menu();
            while (ch != 'k' && ch != 'p' && ch != 'c')
            {
                ch = window->get_char();
            }

            if (ch == 'k' || ch == 'p')
            {
                // Player opted for daa
                if (p.daa_check(ch))
                {
                    // remove a pawn
                }
                else
                {
                    // daa already done, account as one
                    p.move_piece(1, other);
                }
            }
            else if (ch == 'c')
            {
                p.move_piece(1, other);
                toggle_turns(p, other);
            }
            break;
        case 2:
            if (p.check_daa_initiated())
            {
                p.move_piece(2, other);
            }

            toggle_turns(p, other);
            break;
        case 3:
            if (p.check_daa_initiated())
            {
                p.move_piece(3, other);
            }

            toggle_turns(p, other);

            break;
        case 4:
            if (p.check_daa_initiated())
            {
                p.move_piece(4, other);
            }

            toggle_turns(p, other);
            break;
        case 10:
            if (p.check_daa_initiated())
            {
                p.move_piece(10, other);
            }

            break;
        default:
            toggle_turns(p, other);
            break;
        }
    }

    else
    {
        window->display_yellow("wrong key pressed!\n");
    }
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
        player p1(1), p2(2);

        // Start the game
        window->clear();
        gb.set_board(p1, p2);

        cowries c;

        while (1)
        {
            // Player 1 turn
            if (p1.get_turn())
            {
                handle_turn(window,p1,p2,c,gb);
            }
            else if(p2.get_turn())
            {
                handle_turn(window,p2,p1,c,gb);
            }

            window->clear();
            gb.set_board(p1, p2);

            //check win
            if(check_win(p1,p2))
            {
                break;
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