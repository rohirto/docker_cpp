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

/**
 * @brief toggle turns between p1 and p2
 * 
 * @param p1  Player 1
 * @param p2  Player 2
 */
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

/**
 * @brief check if all the pieces of player p has reached the check point or not
 * 
 * @param p player
 * @return true all pieces of player has reached the checkpoint
 * @return false not all pieces have reached the checkpoint
 */
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

/**
 * @brief check if the game is won or not
 * 
 * @param p1 player 1 
 * @param p2 player 2
 * @return true if the player winds the game
 * @return false if the game is still not won
 */
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

/**
 * @brief Handle the turn of player p
 * 
 * @param window polymorphic object which is used to and display menu options
 * @param p  player who's turn is currently handled
 * @param other other player
 * @param c cowry object
 * @param gb gameboard oject which is used to set the board
 */
void handle_turn(screen *window, player &p, player &other, cowries& c, game_board& gb)
{
    char ch = window->display_cowry_menu(p.getname()); //Get the cowry throw confirmation from player
    if (ch == 'f')
    {
        //Got the confirmation
        c.cowry_throw();
        int score = c.getCount();

        window->display_yellow("You got: "); //Display cowries score to player
        window->display_blue(score);
        std::cout << std::endl;

        // Add delay
        usleep(2 * 1000000); // sleeps for 2 second

        switch (score)
        {
        case 1:
            if (p.is_daa_remaining())
            {
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
            }
            else //daa done, treat this as 1
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


/**
 * @brief main function
 * 
 * @return int 
 */
int main()
{
    screen *window;  //Polymorphic class
    menu m;
    
    game_board gb;

    window = &m;

    int choice = window->display_menu();

    if (choice == 1)
    {

        // Start the game
        window->clear();
        player p1(1), p2(2);  //Initialize player 1 and player 2

        // Start the game
        window->clear();
        gb.set_board(p1, p2);

        cowries c;

        while (1)
        {
            if (p1.get_turn()) // Player 1 turn
            {
                handle_turn(window,p1,p2,c,gb);
            }
            else if(p2.get_turn()) // Player 2 win
            {
                handle_turn(window,p2,p1,c,gb);
            }

            //After handling turns, update the board to reflect the changes made during turns
            window->clear();
            gb.set_board(p1, p2);

            //check win
            if(check_win(p1,p2))
            {
                break;  //If win break the while loop
            }
            


        }
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