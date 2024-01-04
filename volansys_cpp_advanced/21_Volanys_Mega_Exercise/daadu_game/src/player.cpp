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

void player::set_pawn_back(pawn& p, int no)
{
    switch (no)
    {
    case 1:
        if(player_no == 1)
            p.position = player_2_house_p1;
        else
            p.position = player_1_house_p1;
        break;
    case 2:
        if(player_no == 1)
            p.position = player_2_house_p2;
        else
            p.position = player_1_house_p2;
        break;
    case 3:
        if(player_no == 1)
            p.position = player_2_house_p3;
        else
            p.position = player_1_house_p3;
        break;
    case 4:
        if(player_no == 1)
            p.position = player_2_house_p4;
        else
            p.position = player_1_house_p4;
        break;
    case 5:
        if(player_no == 1)
            p.position = player_2_house_p5;
        else
            p.position = player_1_house_p5;
        break;
    case 6:
        if(player_no == 1)
            p.position = player_2_house_p6;
        else
            p.position = player_1_house_p6;
        break;
    case 7:
        if(player_no == 1)
            p.position = player_2_house_p7;
        else
            p.position = player_1_house_p7;
        break;
    case 8:
        if(player_no == 1)
            p.position = player_2_house_p8;
        else
            p.position = player_1_house_p8;
        break;

    
    default:
        break;
    }
}

void player::set_king_back(king& k, int no)
{
    if(player_no == 1)
        k.position = player_2_house_k;
    else
        k.position = player_1_house_k;
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

        pawn_pos[1] = pawn(false,player_1_house_p1); // Pawn 1
        pawn_pos[2] = pawn(false,player_1_house_p2); // Pawn 2
        pawn_pos[3] = pawn(false,player_1_house_p3); // Pawn 3
        pawn_pos[4] = pawn(false,player_1_house_p4); // Pawn 4
        pawn_pos[5] = pawn(false,player_1_house_p5); // Pawn 5
        pawn_pos[6] = pawn(false,player_1_house_p6); // Pawn 6
        pawn_pos[7] = pawn(false,player_1_house_p7); // Pawn 7
        pawn_pos[8] = pawn(false,player_1_house_p8); // Pawn 8
        king_pos[1] = king(false,player_1_house_k); // King

        player_map[1] = player1_map_1; //i,j value on thegame board
        player_map[2] = player1_map_2;
        player_map[3] = player1_map_3;
        player_map[4] =player1_map_4;
        player_map[5] = player1_map_5;
        player_map[6] = player1_map_6;
        player_map[7] =player1_map_7;
        player_map[8] = player1_map_8;
        player_map[9] = player1_map_9;
        player_map[10] = player1_map_10;
        player_map[11] = player1_map_11;
        player_map[12] = player1_map_12;
        player_map[13] = player1_map_13;
        player_map[14] = player1_map_14;
        player_map[15] = player1_map_15;
        player_map[16] = player1_map_16;
        player_map[17] = player1_map_17;
        player_map[18] = player1_map_18;
        player_map[19] = player1_map_19;
        player_map[20] = player1_map_20;
        player_map[21] = player1_map_21;
        player_map[22] = player1_map_22;
        player_map[23] = player1_map_23;
        player_map[24] = player1_map_24;
        player_map[25] = player1_map_25;
        player_map[26] = player1_map_26;

        turn = true;
        
    }
    else if(player_no == 2)
    {
        pawn_pos[1] = pawn(false,player_2_house_p1); // Pawn 1
        pawn_pos[2] = pawn(false,player_2_house_p2); // Pawn 2
        pawn_pos[3] = pawn(false,player_2_house_p3); // Pawn 3
        pawn_pos[4] = pawn(false,player_2_house_p4); // Pawn 4
        pawn_pos[5] = pawn(false,player_2_house_p5); // Pawn 5
        pawn_pos[6] = pawn(false,player_2_house_p6); // Pawn 6
        pawn_pos[7] = pawn(false,player_2_house_p7); // Pawn 7
        pawn_pos[8] = pawn(false,player_2_house_p8); // Pawn 8
        king_pos[1] = king(false,player_2_house_k); // King

        player_map[1] = player2_map_1; //i,j value on thegame board
        player_map[2] = player2_map_2;
        player_map[3] = player2_map_3;
        player_map[4] =player2_map_4;
        player_map[5] = player2_map_5;
        player_map[6] = player2_map_6;
        player_map[7] =player2_map_7;
        player_map[8] = player2_map_8;
        player_map[9] = player2_map_9;
        player_map[10] = player2_map_10;
        player_map[11] = player2_map_11;
        player_map[12] = player2_map_12;
        player_map[13] = player2_map_13;
        player_map[14] = player2_map_14;
        player_map[15] = player2_map_15;
        player_map[16] = player2_map_16;
        player_map[17] = player2_map_17;
        player_map[18] = player2_map_18;
        player_map[19] = player2_map_19;
        player_map[20] = player2_map_20;
        player_map[21] = player2_map_21;
        player_map[22] = player2_map_22;
        player_map[23] = player2_map_23;
        player_map[24] = player2_map_24;
        player_map[25] = player2_map_25;
        player_map[26] = player2_map_26;
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
        int temp = 0;

        if (piece < 9)
        {
            // Check daa
            if (pawn_pos[piece].daa_check())
            {
                temp =  pawn_pos[piece].step_no + steps;
                if (temp <= 26)
                {
                    pawn_pos[piece].step_no = temp;
                    pawn_pos[piece].position = player_map[pawn_pos[piece].step_no];
                    if(player_map[pawn_pos[piece].step_no] == other.player_map[other.pawn_pos[piece].step_no])
                    {
                        //Clash has occured
                        //Send other to home
                        other.pawn_pos[piece].step_no = 0;
                        other.pawn_pos[piece].set_daa(false);
                        if(piece != 9)
                            set_pawn_back(other.pawn_pos[piece], piece);
                        else
                            set_king_back(other.king_pos[piece],piece);
                    }
                }
                else
                {
                    // Illegal and void move
                    display_red("Not permitted!,press 'q' to give up turn, or any 'r' to move nay other piece\n");

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
                temp = king_pos[1].step_no + steps;
                
                if (temp <= 26)
                {
                    king_pos[1].step_no = temp;
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