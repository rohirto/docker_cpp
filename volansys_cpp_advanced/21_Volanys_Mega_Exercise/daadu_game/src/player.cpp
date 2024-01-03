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

void player::setname()
{
    std::cin >> name;

    std::cout << "Player name set to: " << name << std::endl;
}

std::string player::getname()
{
    return name;
}

std::map<int,std::pair<int,int>> player::get_pos()
{
    return pos;
}

player::player()
{
    std::cout << "Enter Player name: ";
    std::cin >> name;
    std::cout << "\nSet player number (1 or 2): ";
    std::cin >> player_no;


    turn = false;
    

    if(player_no == '1')
    {
        pos[1] = std::make_pair(1, 1); // Pawn 1
        pos[2] = std::make_pair(1, 2); // Pawn 2
        pos[3] = std::make_pair(2, 1); // Pawn 3
        pos[4] = std::make_pair(2, 2); // Pawn 4
        pos[5] = std::make_pair(3, 1); // Pawn 5
        pos[6] = std::make_pair(3, 2); // Pawn 6
        pos[7] = std::make_pair(4, 1); // Pawn 7
        pos[8] = std::make_pair(4, 2); // Pawn 8
        pos[9] = std::make_pair(3, 3); // King

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
    }
    else if(player_no == '2')
    {
        pos[1] = std::make_pair(1, 13);      // Pawn 1
        pos[2] = std::make_pair(1, 14);      // Pawn 2
        pos[3] = std::make_pair(2, 13);      // Pawn 3
        pos[4] = std::make_pair(2, 14);      // Pawn 4
        pos[5] = std::make_pair(3, 13);      // Pawn 5
        pos[6] = std::make_pair(3, 14);      // Pawn 6
        pos[7] = std::make_pair(4, 13);      // Pawn 7
        pos[8] = std::make_pair(4, 14);      // Pawn 8
        pos[9] = std::make_pair(3, 12);      // King

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

bool player::daa_check()
{

    for (const auto &goti : pos)
    {
        if ((goti.second.first != 0 && goti.second.first != 5) || (goti.second.second != 0 && goti.second.second != 5 && goti.second.second != 10 && goti.second.second != 15))
        {
            return true;
        }
    }

    return false;
}