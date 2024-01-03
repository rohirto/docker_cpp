/**
 * @file player.h
 * @author rohit S
 * @brief Header for player class
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024 Volansys Technologies
 * 
 * 
 * 
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <iostream>
#include <map>
#include <utility>

class player{
    char name[20];
    char player_no; //1 or 2
    bool turn;   //true if player's turn 
    std::map<int,std::pair<int,int>> pos; //Status of the goti 

    std::map<int,std::pair<int,int>> player_map; // 26 steps that player has to complete


public:
    player();
    void setname();
    std::string getname();
    std::map<int,std::pair<int,int>> get_pos();

    void set_turn(bool val);
    bool daa_check();

};

#endif