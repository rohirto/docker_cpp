/**
 * @file game_objects.h
 * @author rohit S
 * @brief This header file contains game objects needed to run the game
 * @version 0.1
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024 Volansys Technologies
 * 
 */

#ifndef _GAME_OBJECTS_H_
#define _GAME_OBJECTS_H_

#include <iostream>
#include <vector>
#include "screen.h"
#include "player.h"
#include "game_menu.h"

//Defines
#define BOX_NUM         3
#define PAWN_CHAR       'O'
#define KING_CHAR       '#'
#define CHECK_PT_CHAR   'X'

//Cowry handling
enum cowry_position {
    NONE_FRONT_FACING,
    ONE_FRONT_FACING,
    TWO_FRONT_FACING,
    THREE_FRONT_FACING,
    FOUR_FRONT_FACING,
    ALL_FRONT_FACING
};

class cowries {
public:
    // Constructor
    void cowry_throw();

    // Function to calculate the count based on cowry position
    int getCount() const;

private:
    cowry_position position;
};


class box{
public:
    char color;
    std::vector<char> box_content;
    int max_pieces;  //max pieces that are currently housed into that box
    int piece_no;  //1 to 8 for pawn, 9 for king

    bool operator==(box const& other);
};

class game_board: virtual public screen, public menu, public box{
    
    box empty_b;
    box pawn_b;
    box king_b;
    box check_pt_b;
    box empty_s;
    box pawn_c;
    box king_c;

    std::map<int,box> pawn_boxes;

    std::vector<std::vector<box>> g_board;


    


public:
    game_board();
    void set_board( player& p1,  player& p2);
    

private:
//Helper functions
    
    void print_box(const box& box);
    void print_player_box(const box& box);
    void board_reset();

};




#endif