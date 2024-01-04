/**
 * @file player.cpp
 * @author rohit S
 * @brief Player class implementation
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024 Volansys technologies
 * 
 */

#include "player.h"
#include <algorithm>
#include <limits>

void player::setname()
{
    name = get_string();

    std::cout << "Player name set to: " << name << std::endl;
}

std::string player::getname()
{
    return name;
}

std::map<int,pawn> player::pawn_get_pos()
{
    return pawn_pos;
}

std::map<int,king> player::king_get_pos()
{
    return king_pos;
}

void player::set_pawn_back(pawn p, int no)
{
    switch (no)
    {
    case 1:
        p.position = std::make_pair(1, 1);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;

    
    default:
        break;
    }
}

player::player()
{
    display_yellow("Enter Player name: ");
    name = get_string();
    display_yellow( "\nSet player number (1 or 2): ");
    player_no = get_int();


    turn = false;
    daa_initiated = false;
    

    if(player_no == 1)
    {

        pawn_pos[1] = pawn(false,std::make_pair(1, 1)); // Pawn 1
        pawn_pos[2] = pawn(false,std::make_pair(1, 2)); // Pawn 2
        pawn_pos[3] = pawn(false,std::make_pair(2, 1)); // Pawn 3
        pawn_pos[4] = pawn(false,std::make_pair(2, 2)); // Pawn 4
        pawn_pos[5] = pawn(false,std::make_pair(3, 1)); // Pawn 5
        pawn_pos[6] = pawn(false,std::make_pair(3, 2)); // Pawn 6
        pawn_pos[7] = pawn(false,std::make_pair(4, 1)); // Pawn 7
        pawn_pos[8] = pawn(false,std::make_pair(4, 2)); // Pawn 8
        king_pos[1] = king(false,std::make_pair(3, 3)); // King

        player_map[1] = std::make_pair(5,0); //i,j value on the game board
        player_map[2] = std::make_pair(4,0);;
        player_map[3] = std::make_pair(3,0);;
        player_map[4] = std::make_pair(2,0);;
        player_map[5] = std::make_pair(1,0);;
        player_map[6] = std::make_pair(0,0);;
        player_map[7] = std::make_pair(0,1);;
        player_map[8] = std::make_pair(0,2);;
        player_map[9] = std::make_pair(0,3);;
        player_map[10] = std::make_pair(0,4);;
        player_map[11] = std::make_pair(0,5);;
        player_map[12] = std::make_pair(1,5);;
        player_map[13] = std::make_pair(2,5);;
        player_map[14] = std::make_pair(3,5);;
        player_map[15] = std::make_pair(4,5);;
        player_map[16] = std::make_pair(5,5);;
        player_map[17] = std::make_pair(5,6);;
        player_map[18] = std::make_pair(5,7);;
        player_map[19] = std::make_pair(5,8);;
        player_map[20] = std::make_pair(5,9);;
        player_map[21] = std::make_pair(5,10);;
        player_map[22] = std::make_pair(4,10);;
        player_map[23] = std::make_pair(3,10);;
        player_map[24] = std::make_pair(2,10);;
        player_map[25] = std::make_pair(1,10);;
        player_map[26] = std::make_pair(0,10);;

        turn = true;
        
    }
    else if(player_no == 2)
    {
        pawn_pos[1] = pawn(false,std::make_pair(1, 13));      // Pawn 1
        pawn_pos[2] = pawn(false,std::make_pair(1, 14));      // Pawn 2
        pawn_pos[3] = pawn(false,std::make_pair(2, 13));      // Pawn 3
        pawn_pos[4] = pawn(false,std::make_pair(2, 14));      // Pawn 4
        pawn_pos[5] = pawn(false,std::make_pair(3, 13));      // Pawn 5
        pawn_pos[6] = pawn(false,std::make_pair(3, 14));      // Pawn 6
        pawn_pos[7] = pawn(false,std::make_pair(4, 13));      // Pawn 7
        pawn_pos[8] = pawn(false,std::make_pair(4, 14));      // Pawn 8
        king_pos[1] = king(false,std::make_pair(3, 12));      // King

        player_map[1] = std::make_pair(5,15); //i,j value on the game board
        player_map[2] = std::make_pair(4,15);;
        player_map[3] = std::make_pair(3,15);;
        player_map[4] = std::make_pair(2,15);;
        player_map[5] = std::make_pair(1,15);;
        player_map[6] = std::make_pair(0,15);;
        player_map[7] = std::make_pair(0,14);;
        player_map[8] = std::make_pair(0,13);;
        player_map[9] = std::make_pair(0,12);;
        player_map[10] = std::make_pair(0,11);;
        player_map[11] = std::make_pair(0,10);;
        player_map[12] = std::make_pair(1,10);;
        player_map[13] = std::make_pair(2,10);;
        player_map[14] = std::make_pair(3,10);;
        player_map[15] = std::make_pair(4,10);;
        player_map[16] = std::make_pair(5,10);;
        player_map[17] = std::make_pair(5,9);;
        player_map[18] = std::make_pair(5,8);;
        player_map[19] = std::make_pair(5,7);;
        player_map[20] = std::make_pair(5,6);;
        player_map[21] = std::make_pair(5,5);;
        player_map[22] = std::make_pair(4,5);;
        player_map[23] = std::make_pair(3,5);;
        player_map[24] = std::make_pair(2,5);;
        player_map[25] = std::make_pair(1,5);;
        player_map[26] = std::make_pair(0,5);;
    }
}

void player::set_turn(bool val)
{
    turn = val;
}

bool player::daa_check(char c) //if c == p -> pawn, if c== k -> king
{
    //Check the bool daa value, if any goti pawn is false, set it to true, return true, else return false
    if(c == 'k')
    {
        for(auto& k: king_pos)
        {
            if(!k.second.daa_check())
            {
                k.second.set_daa(true);
                k.second.step_no = 1;
                k.second.position = player_map[k.second.step_no];
                daa_initiated = true;
                return true;

            }
            else
            {
                display_red("King already taken out!\n");
                c = 'p';
            }
        }

    }
    if(c == 'p')
    {
        for(auto& p: pawn_pos)
        {
            if(!p.second.daa_check())
            {
                p.second.set_daa(true);
                p.second.step_no = 1;
                p.second.position = player_map[p.second.step_no];
                daa_initiated = true;
                return true;
            }
        }
        
    }

    display_red("All pawns already out!\n");

    return false;
}

void player::move_piece(int steps, player& other)
{
    

    while (1)
    {
        display_yellow("Enter Piece no to move or '9' to move king: ");
        int piece = get_int();

        if (piece < 9)
        {
            // Check daa
            if (pawn_pos[piece].daa_check())
            {
                pawn_pos[piece].step_no = pawn_pos[piece].step_no + steps;
                if (pawn_pos[piece].step_no <= 26)
                {
                    pawn_pos[piece].position = player_map[pawn_pos[piece].step_no];
                    if(player_map[pawn_pos[piece].step_no] == other.player_map[other.pawn_pos[piece].step_no])
                    {
                        //Clash has occured
                        //Send other to home
                        other.pawn_pos[piece].step_no = 0;
                        other.pawn_pos[piece].position = other.player_map[]
                    }
                }
                else
                {
                    // Illegal and void move
                    display_red("Not permitted!\n");
                    continue;
                }

                break;
            }
            else
            {
                display_red("Cannot move Piece no ");
                display_blue(piece);
                display_red(",still in house!\n");

                if (steps == 1)
                {
                    display_yellow("Do you want to take this piece out (y)?");
                    char ch = get_char();

                    if (ch == 'y')
                    {
                        if (daa_check('p'))
                        {
                            break;
                        }
                    }
                }
            }
        }
        else if (piece == 9)
        {
            // King
            if (king_pos[1].daa_check())
            {
                king_pos[1].step_no = king_pos[1].step_no + steps;
                if (king_pos[1].step_no <= 26)
                {
                    king_pos[1].position = player_map[king_pos[1].step_no];
                }
                else
                {
                    // Illegal and void move
                    display_red("Not permitted!,press 'q' to give up turn\n");

                    char ch = get_char();
                    if (ch == 'q')
                    {
                        break;
                    }
                    continue;
                }
                break;
            }
            else
            {
                display_red("Cannot move King ,still in house!\n");

                if (steps == 1)
                {
                    display_yellow("Do you want to take this piece out (y)?");
                    char ch = get_char();

                    if (ch == 'y')
                    {
                        if (daa_check('k'))
                        {
                            break;
                        }
                    }
                }
            }
        }

        // Pawn piece number

        // Check daa
    }
}

bool pawn::daa_check()
{
    return is_daa_done;
}

bool::king::daa_check()
{
    return is_daa_done;
}

void pawn::set_daa(const bool& val)
{
    is_daa_done = val;
}

void king::set_daa(const bool& val)
{
    is_daa_done = val;
}

void pawn::setpostion(int i, int j)
{   
    position.first = i;
    position.second = j;
}

void king::setpostion(int i, int j)
{
    position.first = i;
    position.second = j;
    
}