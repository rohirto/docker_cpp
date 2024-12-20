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
#include <set>
#include <utility>
#include "game_menu.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


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


//Check point pairs
const std::pair<int,int> player_1_cp_p1(1,6);
const std::pair<int,int> player_1_cp_p2(1,7);
const std::pair<int,int> player_1_cp_p3(2,6);
const std::pair<int,int> player_1_cp_p4(2,7);
const std::pair<int,int> player_1_cp_p5(3,6);
const std::pair<int,int> player_1_cp_p6(3,7);
const std::pair<int,int> player_1_cp_p7(4,6);
const std::pair<int,int> player_1_cp_p8(4,7);

const std::pair<int,int> player_1_cp_k(0,7);



const std::pair<int,int> player_2_house_p1(1,13);
const std::pair<int,int> player_2_house_p2(1,14);
const std::pair<int,int> player_2_house_p3(2,13);
const std::pair<int,int> player_2_house_p4(2,14);
const std::pair<int,int> player_2_house_p5(3,13);
const std::pair<int,int> player_2_house_p6(3,14);
const std::pair<int,int> player_2_house_p7(4,13);
const std::pair<int,int> player_2_house_p8(4,14);

const std::pair<int,int> player_2_house_k(3,12);

//Check point pairs

const std::pair<int,int> player_2_cp_p1(1,8);
const std::pair<int,int> player_2_cp_p2(1,9);
const std::pair<int,int> player_2_cp_p3(2,8);
const std::pair<int,int> player_2_cp_p4(2,9);
const std::pair<int,int> player_2_cp_p5(3,8);
const std::pair<int,int> player_2_cp_p6(3,9);
const std::pair<int,int> player_2_cp_p7(4,8);
const std::pair<int,int> player_2_cp_p8(4,9);

const std::pair<int,int> player_2_cp_k(0,8);


//Player 1 map

const std::pair<int,int> player1_map_1(5, 0); // i,j value on the game board //Safe
const std::pair<int,int> player1_map_2(4, 0);
const std::pair<int,int> player1_map_3(3, 0);
const std::pair<int,int> player1_map_4(2, 0);
const std::pair<int,int> player1_map_5(1, 0);
const std::pair<int,int> player1_map_6(0, 0); //Safe
const std::pair<int,int> player1_map_7(0, 1);
const std::pair<int,int> player1_map_8(0, 2);
const std::pair<int,int> player1_map_9(0, 3);
const std::pair<int,int> player1_map_10(0, 4);
const std::pair<int,int> player1_map_11(0, 5); //Safe
const std::pair<int,int> player1_map_12(1, 5);
const std::pair<int,int> player1_map_13(2, 5);
const std::pair<int,int> player1_map_14(3, 5);
const std::pair<int,int> player1_map_15(4, 5);
const std::pair<int,int> player1_map_16(5, 5); //Safe
const std::pair<int,int> player1_map_17(5, 6);
const std::pair<int,int> player1_map_18(5, 7); 
const std::pair<int,int> player1_map_19(5, 8);
const std::pair<int,int> player1_map_20(5, 9);
const std::pair<int,int> player1_map_21(5, 10); //Safe
const std::pair<int,int> player1_map_22(4, 10);
const std::pair<int,int> player1_map_23(3, 10);
const std::pair<int,int> player1_map_24(2, 10);
const std::pair<int,int> player1_map_25(1, 10);
const std::pair<int,int> player1_map_26(0, 10);  //Check point



//Player 2 map
const std::pair<int,int> player2_map_1(5,15); // i,j value on the game board //Safe
const std::pair<int,int> player2_map_2(4,15);
const std::pair<int,int> player2_map_3(3,15);
const std::pair<int,int> player2_map_4(2,15);
const std::pair<int,int> player2_map_5(1,15);
const std::pair<int,int> player2_map_6(0,15); //Safe
const std::pair<int,int> player2_map_7(0,14);
const std::pair<int,int> player2_map_8(0,13);
const std::pair<int,int> player2_map_9(0,12);
const std::pair<int,int> player2_map_10(0,11);
const std::pair<int,int> player2_map_11(0,10); //Safe
const std::pair<int,int> player2_map_12(1,10);
const std::pair<int,int> player2_map_13(2,10);
const std::pair<int,int> player2_map_14(3,10);
const std::pair<int,int> player2_map_15(4,10);
const std::pair<int,int> player2_map_16(5,10); //Safe
const std::pair<int,int> player2_map_17(5,9);
const std::pair<int,int> player2_map_18(5,8);
const std::pair<int,int> player2_map_19(5,7);
const std::pair<int,int> player2_map_20(5,6);
const std::pair<int,int> player2_map_21(5,5); //Safe
const std::pair<int,int> player2_map_22(4,5);
const std::pair<int,int> player2_map_23(3,5);
const std::pair<int,int> player2_map_24(2,5);
const std::pair<int,int> player2_map_25(1,5);
const std::pair<int,int> player2_map_26(0,5); //Cehckpoint

/**
 * @brief piece class
 * 
 */
class piece{
    std::pair<int,int> position;
    
    bool is_king;
    bool is_daa_done;
    bool is_check_point_reached;

public: 
    //Public members
    int step_no;

    piece(){position = player1_map_1; is_king = false; is_daa_done = false; is_check_point_reached=false; step_no = 0;}
    piece(const bool val, const bool king_val, const std::pair<int, int>& pos)
    : position(pos), is_king(king_val), is_daa_done(val), is_check_point_reached(false),step_no(0) {}
    void setpostion(const std::pair<int,int>& pos){position = pos;};
    bool daa_check() const {return is_daa_done ;}
    void set_daa(const bool& val){is_daa_done = val;}
    std::pair<int,int> getposition() const {return position;}
    bool is_p_king() const { return is_king; }
    void set_checkpt(bool val){ is_check_point_reached = val;}
    bool checkpt_check() const {return is_check_point_reached;}

    bool operator!=(const piece& other){if(is_king == other.is_king && position == other.position &&  
                                         is_daa_done == other.is_daa_done ){return false;} return true;};

    //Friend functions
    friend void to_json(json& j, const piece& p);
    friend void from_json(const json& j, piece& p);


};

/**
 * @brief Player class
 * 
 */
class player: virtual public piece, public menu{
    std::string name;
    int player_no; //1 or 2
    bool turn;   //true if player's turn 
    bool daa_initiated;
    bool has_killed;
    std::map<int,piece> pawn_pos; //Status of the pawn 
    piece king_pos;    //Status of king

    std::map<int,std::pair<int,int>> player_map; // 26 steps that player has to complete


    


public:
    player(){}
    void setname(const std::string& s);
    std::string getname() const;
    int get_player_no() const { return player_no; }
    std::map<int,piece> pawn_get_pos() const;
    piece king_get_pos() const;

    void set_turn(bool val);
    bool get_turn() const {return turn;}
    bool daa_check(char c);
    void move_piece( int steps, player& other);
    bool check_daa_initiated() const {return daa_initiated;}
    void set_daa_initiated(bool val){daa_initiated = val;}
    void set_piece_back(piece& p, int no);
    bool check_piece_safe(piece& p, const player& other, int& pos);
    bool if_check_pt_reached(std::pair<int,int> new_pos);
    bool get_kill() const {return has_killed;}
    bool is_daa_remaining();

    player& operator=(player&& other) noexcept {
        if (this != &other) {
            piece::operator=(std::move(other)); // Move-assign virtual base
            //menu::operator=(std::move(other));  // Move-assign non-virtual base
            // Handle member variables specific to 'player' if any
        }
        return *this;
    }

private:
    bool helper_move_piece(piece& p,int steps,int piece_no, player& other);
    void check_possible_moves(std::vector<int>& moves_lst, std::set<int>& cp, std::pair<const int, piece>& p,int steps);
    void check_overlapping_pieces(std::vector<std::string>& s, std::set<int>& cp,std::pair<const int, piece> &p);
    void check_overlapping_enemy_pieces(player& other, std::set<int>& cp,std::pair<const int, piece> &p);

    //Friend functions
    friend void to_json(json& j, const player& pl);
    friend void from_json(const json& j, player& pl);

    

};




#endif