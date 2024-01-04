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
#include "game_menu.h"


//House position pairs

const std::pair<int,int> player_1_house_p1(1,1);
const std::pair<int,int> player_1_house_p2(1,2);
const std::pair<int,int> player_1_house_p3(2,1);
const std::pair<int,int> player_1_house_p4(2,2);
const std::pair<int,int> player_1_house_p5(3,1);
const std::pair<int,int> player_1_house_p6(3,2);
const std::pair<int,int> player_1_house_p7(4,1);
const std::pair<int,int> player_1_house_p8(4,2);

const std::pair<int,int> player_1_house_k(3,3);



const std::pair<int,int> player_2_house_p1(1,13);
const std::pair<int,int> player_2_house_p2(1,14);
const std::pair<int,int> player_2_house_p3(2,13);
const std::pair<int,int> player_2_house_p4(2,14);
const std::pair<int,int> player_2_house_p5(3,13);
const std::pair<int,int> player_2_house_p6(3,14);
const std::pair<int,int> player_2_house_p7(4,13);
const std::pair<int,int> player_2_house_p8(4,14);

const std::pair<int,int> player_2_house_k(3,12);


//Player 1 map

const std::pair<int,int> player1_map_1(5, 0); // i,j value on the game board
const std::pair<int,int> player1_map_2(4, 0);
const std::pair<int,int> player1_map_3(3, 0);
const std::pair<int,int> player1_map_4(2, 0);
const std::pair<int,int> player1_map_5(1, 0);
const std::pair<int,int> player1_map_6(0, 0);
const std::pair<int,int> player1_map_7(0, 1);
const std::pair<int,int> player1_map_8(0, 2);
const std::pair<int,int> player1_map_9(0, 3);
const std::pair<int,int> player1_map_10(0, 4);
const std::pair<int,int> player1_map_11(0, 5);
const std::pair<int,int> player1_map_12(1, 5);
const std::pair<int,int> player1_map_13(2, 5);
const std::pair<int,int> player1_map_14(3, 5);
const std::pair<int,int> player1_map_15(4, 5);
const std::pair<int,int> player1_map_16(5, 5);
const std::pair<int,int> player1_map_17(5, 6);
const std::pair<int,int> player1_map_18(5, 7);
const std::pair<int,int> player1_map_19(5, 8);
const std::pair<int,int> player1_map_20(5, 9);
const std::pair<int,int> player1_map_21(5, 10);
const std::pair<int,int> player1_map_22(4, 10);
const std::pair<int,int> player1_map_23(3, 10);
const std::pair<int,int> player1_map_24(2, 10);
const std::pair<int,int> player1_map_25(1, 10);
const std::pair<int,int> player1_map_26(0, 10);



//Player 2 map
const std::pair<int,int> player2_map_1(5,15); // i,j value on the game board
const std::pair<int,int> player2_map_2(4,15);
const std::pair<int,int> player2_map_3(3,15);
const std::pair<int,int> player2_map_4(2,15);
const std::pair<int,int> player2_map_5(1,15);
const std::pair<int,int> player2_map_6(0,15);
const std::pair<int,int> player2_map_7(0,14);
const std::pair<int,int> player2_map_8(0,13);
const std::pair<int,int> player2_map_9(0,12);
const std::pair<int,int> player2_map_10(0,11);
const std::pair<int,int> player2_map_11(0,10);
const std::pair<int,int> player2_map_12(1,10);
const std::pair<int,int> player2_map_13(2,10);
const std::pair<int,int> player2_map_14(3,10);
const std::pair<int,int> player2_map_15(4,10);
const std::pair<int,int> player2_map_16(5,10);
const std::pair<int,int> player2_map_17(5,9);
const std::pair<int,int> player2_map_18(5,8);
const std::pair<int,int> player2_map_19(5,7);
const std::pair<int,int> player2_map_20(5,6);
const std::pair<int,int> player2_map_21(5,5);
const std::pair<int,int> player2_map_22(4,5);
const std::pair<int,int> player2_map_23(3,5);
const std::pair<int,int> player2_map_24(2,5);
const std::pair<int,int> player2_map_25(1,5);
const std::pair<int,int> player2_map_26(0,5);


class pawn{
    bool is_daa_done;
    

public:
    std::pair<int, int> position; // ij position of the pawn
    int step_no;  //Mapped with player map first
    pawn(){};
    pawn(bool val, const std::pair<int,int>& pos):is_daa_done(val),position(pos),step_no(0){}
    void setpostion(int i, int j);
    void set_daa(const bool& val);
    bool daa_check();

};

class king{
    bool is_daa_done;
    

public:
    std::pair<int, int> position; // ij position of the pawn 
    int step_no;  //Mapped with player map first
    king(){};
    king(bool val, const std::pair<int,int>& pos):is_daa_done(val),position(pos),step_no(0){}
    void setpostion(int i, int j);
    void set_daa(const bool& val);
    bool daa_check();

};

class player:virtual public pawn, virtual public king, public menu{
    std::string name;
    int player_no; //1 or 2
    bool turn;   //true if player's turn 
    bool daa_initiated;
    std::map<int,pawn> pawn_pos; //Status of the pawn 
    std::map<int,king> king_pos;    //Status of king

    std::map<int,std::pair<int,int>> player_map; // 26 steps that player has to complete


    


public:
    player();
    void setname();
    std::string getname();
    std::map<int,pawn> pawn_get_pos();
    std::map<int,king> king_get_pos();

    void set_turn(bool val);
    bool get_turn(){return turn;}
    bool daa_check(char c);
    void move_piece( int steps, player& other);
    bool check_daa_initiated(){return daa_initiated;}
    void set_pawn_back(pawn p, int no);
    void set_king_back(king k, int no);
    

};



#endif