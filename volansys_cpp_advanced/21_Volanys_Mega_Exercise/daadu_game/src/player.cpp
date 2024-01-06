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

/**
 * @brief Method to set name of player
 * 
 */
void player::setname()
{
    name = get_string();

    std::cout << "Player name set to: " << name << std::endl;
}

/**
 * @brief Method to get name of the player object
 * 
 * @return std::string 
 */
std::string player::getname()
{
    return name;
}

/**
 * @brief get the pawn_pos object, it is a map of 8 piece object which are treated as pawns
 * 
 * @return std::map<int, piece> 
 */
std::map<int, piece> player::pawn_get_pos()
{
    return pawn_pos;
}

/**
 * @brief get the king object of the player, it is a piece object treated as king
 * 
 * @return piece 
 */
piece player::king_get_pos()
{
    return king_pos;
}

/**
 * @brief Is daa remaining for the player
 * 
 * @return true - yes daa is remaining
 * @return false - daa is completed
 */
bool player::is_daa_remaining()
{
    for(std::pair<const int,piece>& p : pawn_pos)
    {
        if(p.second.daa_check() == false)
        {
            return true;
        }
    }
    if(king_pos.daa_check() == false)
    {
        return true;
    }
    return false;
}


/**
 * @brief method to set a peice back to the house, it happens when other player kills your piece
 * 
 * @param p piece which is killed by the other player
 * @param no 1-8 for pawns, 9 for king
 */
void player::set_piece_back(piece &p, int no)
{

    switch (no)
    {
    case 1:
        if (player_no == 1)
            p.setpostion(player_2_house_p1);
        else
            p.setpostion(player_1_house_p1);
        break;
    case 2:
        if (player_no == 1)
            p.setpostion(player_2_house_p2);
        else
            p.setpostion(player_1_house_p2);
        break;
    case 3:
        if (player_no == 1)
            p.setpostion(player_2_house_p3);
        else
            p.setpostion(player_1_house_p3);
        break;
    case 4:
        if (player_no == 1)
            p.setpostion(player_2_house_p4);
        else
            p.setpostion(player_1_house_p4);
        break;
    case 5:
        if (player_no == 1)
            p.setpostion(player_2_house_p5);
        else
            p.setpostion(player_1_house_p5);
        break;
    case 6:
        if (player_no == 1)
            p.setpostion(player_2_house_p6);
        else
            p.setpostion(player_1_house_p6);
        break;
    case 7:
        if (player_no == 1)
            p.setpostion(player_2_house_p7);
        else
            p.setpostion(player_1_house_p7);
        break;
    case 8:
        if (player_no == 1)
            p.setpostion(player_2_house_p8);
        else
            p.setpostion(player_1_house_p8);
        break;
    case 9: // King
        if (player_no == 1)
            p.setpostion(player_2_house_k);
        else
            p.setpostion(player_1_house_k);

    default:
        break;
    }
}

/**
 * @brief check if piece p is safe or not
 * 
 * @param p piece whose safety is being checked
 * @param other other player from whom the safety of peice p is being assesed
 * @param piece_no (1-8 is for pawns and 9 for king)
 * @return true piece p is safe
 * @return false piece p is not safe and can be eliminated by other player
 */
bool player::check_piece_safe(piece &p, const player &other, int &piece_no)
{
    if (player_no == 1)
    {
        // Safe boxes check
        if (p.getposition() == player2_map_1 || p.getposition() == player2_map_6 || p.getposition() == player2_map_11 || p.getposition() == player2_map_16 || p.getposition() == player2_map_21)
        {
            return true;
        }
    }
    else
    {
        if (p.getposition() == player1_map_1 || p.getposition() == player1_map_6 || p.getposition() == player1_map_11 || p.getposition() == player1_map_16 || p.getposition() == player1_map_21)
        {
            return true;
        }
    }

    /**
     * @brief Multiple box occupancy check Any of loop along with a lambda fucntion
     * @paragraph If any of the other player's pawns, has the same position as piece p (p itself is a piece of other player), if 
     *            yes, then the piece is safe, else it can be eliminated
     * 
     */
    bool multiple_chck_val = std::any_of(other.pawn_pos.begin(), other.pawn_pos.end(), [&p, &piece_no](std::pair<int, piece> op)
                                         { if(piece_no != op.first){ return op.second.getposition() == p.getposition(); }return false; });

    if (multiple_chck_val == true)
    {
        return true;
    }
    else
    {
        if( p != other.king_pos) //pawn overloapping with king
        {
            piece t = other.king_pos;
            if(t.getposition() == p.getposition())
            {
                //overloapping with king
                return true;
            }
        }
        return false;
    }
}


/**
 * @brief see if the new position has reached the check point or not
 * 
 * @param new_pos valid new position which is a result of cowry throw
 * @return true new position has reached the check point, piece can be removed from the board
 * @return false piece has yet not reached the checkpoint, still on board
 */
bool player::if_check_pt_reached(std::pair<int, int> new_pos)
{
    if (player_no == 1)
    {
        if (new_pos == player1_map_26)
        {
            // Reached chk point
            return true;
        }
    }
    else
    {
        if (new_pos == player2_map_26)
        {
            // reached check point
            return true;
        }
    }

    return false;
}

/**
 * @brief Construct a new player::player object
 * 
 * @param no the player number(Either can be 1 or 2)
 */
player::player(int no)
{
    display_yellow("Enter Player ");
    display_yellow(no);
    display_yellow(" name: ");
    name = get_string();
    //display_yellow("Set player number (1 or 2): ");
    player_no = no;

    turn = false;
    daa_initiated = false;
    has_killed = false;

    if (player_no == 1)
    {

        pawn_pos[1] = piece(false, false, player_1_house_p1); // Pawn 1
        pawn_pos[2] = piece(false, false, player_1_house_p2); // Pawn 2
        pawn_pos[3] = piece(false, false, player_1_house_p3); // Pawn 3
        pawn_pos[4] = piece(false, false, player_1_house_p4); // Pawn 4
        pawn_pos[5] = piece(false, false, player_1_house_p5); // Pawn 5
        pawn_pos[6] = piece(false, false, player_1_house_p6); // Pawn 6
        pawn_pos[7] = piece(false, false, player_1_house_p7); // Pawn 7
        pawn_pos[8] = piece(false, false, player_1_house_p8); // Pawn 8
        king_pos = piece(false, true, player_1_house_k);      // King

        player_map[1] = player1_map_1; // i,j value on thegame board
        player_map[2] = player1_map_2;
        player_map[3] = player1_map_3;
        player_map[4] = player1_map_4;
        player_map[5] = player1_map_5;
        player_map[6] = player1_map_6;
        player_map[7] = player1_map_7;
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
    else if (player_no == 2)
    {
        pawn_pos[1] = piece(false, false, player_2_house_p1); // Pawn 1
        pawn_pos[2] = piece(false, false, player_2_house_p2); // Pawn 2
        pawn_pos[3] = piece(false, false, player_2_house_p3); // Pawn 3
        pawn_pos[4] = piece(false, false, player_2_house_p4); // Pawn 4
        pawn_pos[5] = piece(false, false, player_2_house_p5); // Pawn 5
        pawn_pos[6] = piece(false, false, player_2_house_p6); // Pawn 6
        pawn_pos[7] = piece(false, false, player_2_house_p7); // Pawn 7
        pawn_pos[8] = piece(false, false, player_2_house_p8); // Pawn 8
        king_pos = piece(false, true, player_2_house_k);      // King

        player_map[1] = player2_map_1; // i,j value on thegame board
        player_map[2] = player2_map_2;
        player_map[3] = player2_map_3;
        player_map[4] = player2_map_4;
        player_map[5] = player2_map_5;
        player_map[6] = player2_map_6;
        player_map[7] = player2_map_7;
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

/**
 * @brief set the turn of the player 
 * 
 * @param val if true, the set the turn of player, else give turn to other
 */
void player::set_turn(bool val)
{
    turn = val;
}


/**
 * @brief check the daa for pawns and king, if daa is remaining, then take a piece out and update daa
 * 
 * @param c character which determiines if pawn or king
 * @return true if a piece is taken out
 * @return false if all peices are already out
 */
bool player::daa_check(char c) // if c == p -> pawn, if c== k -> king
{
    // Check the bool daa value, if any goti pawn is false, set it to true, return true, else return false
    if (c == 'k')
    {
        if (!king_pos.daa_check() && !king_pos.checkpt_check())
        {
            king_pos.set_daa(true);
            king_pos.step_no = 1;
            king_pos.setpostion(player_map[king_pos.step_no]);
            daa_initiated = true;
            return true;
        }
        else
        {
            display_red("King already taken out!\n");
            c = 'p';
        }
    }
    if (c == 'p')
    {
        for (auto &p : pawn_pos)
        {
            if (!p.second.daa_check() && !p.second.checkpt_check())
            {
                p.second.set_daa(true);
                p.second.step_no = 1;
                p.second.setpostion(player_map[p.second.step_no]);
                daa_initiated = true;
                return true;
            }
        }
    }

    display_red("All pawns already out!\n");

    return false;
}

/**
 * @brief Helper method to move a piece on the board, according to the rules of the game
 * 
 * @param p piece to be moved
 * @param steps steps by which the piece is to be moved
 * @param piece_no number of piece (1-8 pawns and 9 is king)
 * @param other other player object to check clashes
 * @return true if the move was successful and the caller's while loop needs to be broken
 * @return false if move was invalid and caller's while loop needs to be continued till valid move is made
 */
bool player::helper_move_piece(piece&p, int steps,int piece_no, player &other)
{
    int temp = 0;
    int temp_step_no = 0;
    if (p.daa_check())
    {
        temp_step_no = p.step_no + steps;
        if (temp_step_no <= 26)
        {
            std::pair<int, int> new_pos = player_map[temp_step_no];
            /**
             * @brief any_of loop, along with lambda fucntion
             * @paragraph If any of other player's pawn, has the same position as new position of piece p or other player's king has
             *            same position as new position of piece p. 
             *            This is a condition to test the clash of pieces
             */
            if (std::any_of(other.pawn_pos.begin(), other.pawn_pos.end(), [&piece_no, &temp,&new_pos](std::pair<int, piece> op)    //anyof loop to see if other pawn piece clash with our piece
                            { if( op.second.getposition() == new_pos){temp = op.first; return true;} return false; }) ||
                [&other, &temp,&new_pos]()
                {if( other.king_pos.getposition() == new_pos){temp = 9; return true;} return false; }() //IIFE for other's kingpos clash
                )
            {
                if (temp != 9) //If not king
                {
                    // Check safe condition
                    if (!check_piece_safe(other.pawn_pos[temp], other, temp)) // Check if the pawn of the other player is safe or not
                    {
                        // Not safe
                        // Clash has occured
                        // Send other to home
                        other.pawn_pos[temp].step_no = 0;
                        other.pawn_pos[temp].set_daa(false);
                        set_piece_back(other.pawn_pos[temp], temp);
                        has_killed = true;  //Player has killed other's pawn
                    }
                }
                else //If a king
                {
                    // Check safe condition
                    if (!check_piece_safe(other.king_pos, other, temp)) // Check if the pawn of the other player is safe or not
                    {
                        if(p != king_pos)  //Pawn killed king
                        {
                            // Not safe
                            // Clash has occured
                            // Send other to home
                            other.king_pos.step_no = 0;
                            other.king_pos.set_daa(false);
                            set_piece_back(other.king_pos, 9);

                            has_killed = true;  //Player has killed other's pieces
                        }
                        else
                        {
                            //King has killed king, send all pieces to home
                            other.king_pos.step_no = 0;
                            other.king_pos.set_daa(false);
                            other.set_daa_initiated(false);
                            set_piece_back(other.king_pos,9);
                            has_killed = true;  //Player has killed other's pawn
                            for(auto& p: other.pawn_pos)
                            {
                                if(!p.second.checkpt_check())
                                {
                                     p.second.step_no = 0;
                                    p.second.set_daa(false);
                                    set_piece_back(p.second, p.first);
                                    
                                }
                               
                            }

                        }
                    }

                }

                //Update the positions
                p.step_no = temp_step_no;
                p.setpostion(player_map[p.step_no]);
            }
            else if (if_check_pt_reached(new_pos)) // Check if reached check point
            {
                if (has_killed)  //Can reach check point only if player has eliminated atleast 1 of other player's pieces
                {
                    p.step_no = temp_step_no;
                    // Need to have killed to reach checkpoint
                    p.set_checkpt(true);
                    switch (piece_no)
                    {
                    case 1:
                        /* code */
                        if (player_no == 1)
                            p.setpostion(player_1_cp_p1);
                        else
                            p.setpostion(player_2_cp_p1);
                        break;
                    case 2:
                        /* code */
                        if (player_no == 1)
                            p.setpostion(player_1_cp_p2);
                        else
                            p.setpostion(player_2_cp_p2);
                        break;
                    case 3:
                        /* code */
                        if (player_no == 1)
                            p.setpostion(player_1_cp_p3);
                        else
                            p.setpostion(player_2_cp_p3);
                        break;
                    case 4:
                        /* code */
                        if (player_no == 1)
                            p.setpostion(player_1_cp_p4);
                        else
                            p.setpostion(player_2_cp_p4);
                        break;
                    case 5:
                        /* code */
                        if (player_no == 1)
                            p.setpostion(player_1_cp_p5);
                        else
                            p.setpostion(player_2_cp_p5);
                        break;
                    case 6:
                        /* code */
                        if (player_no == 1)
                            p.setpostion(player_1_cp_p6);
                        else
                            p.setpostion(player_2_cp_p6);
                        break;
                    case 7:
                        /* code */
                        if (player_no == 1)
                            p.setpostion(player_1_cp_p7);
                        else
                            p.setpostion(player_2_cp_p7);
                        break;
                    case 8:
                        /* code */
                        if (player_no == 1)
                            p.setpostion(player_1_cp_p8);
                        else
                            p.setpostion(player_2_cp_p8);
                        break;
                    case 9:
                        if (player_no == 1)
                            king_pos.setpostion(player_1_cp_k);
                        else
                            king_pos.setpostion(player_2_cp_k);

                    default:
                        break;
                    }
                }
                else  //Not killed any of the other player's pieces
                {
                    display_yellow("Need to take out atleast one piece of other player to reach checkpoint\n");
                    display_yellow("Move any other piece? (y or n)");
                    char chh = get_char();
                    if(chh == 'y')
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            else
            {
                //No clash but need to update position
                p.step_no = temp_step_no;
                p.setpostion(player_map[p.step_no]);
            }
        }
        else
        {
            // Illegal and void move
            display_red("Not permitted!,press 'q' to give up turn, or any 'r' to move nay other piece\n");

            char ch = get_char();
            if (ch == 'q')
            {
                return true;
            }

            return false;
        }

        return true;
    }
    else
    {
        display_red("Cannot move Piece no ");
        display_blue(piece_no);
        display_red(",still in house!\n");

        if (steps == 1)
        {
            display_yellow("Do you want to take this piece out (y)?");
            char ch = get_char();

            if (ch == 'y')
            {
                if (daa_check('p'))
                {
                    return true;
                }
            }
        }

        return false;
    }
}


/**
 * @brief Method to check all possible moves for piece p object
 * 
 * @param moves_lst a vector of int containing the piece no which can be moved
 * @param p piece object in map form, p.first is the piece no (1-8 for pawns, 9 for king)
 * @param steps no of steps needed to be taken
 */
void player::check_possible_moves(std::vector<int> &moves_lst, std::pair<const int, piece> &p, int steps)
{
    if (p.second.daa_check() && !p.second.checkpt_check()) // Daa done and not reached checkpoint
    {
        int temp = p.second.step_no + steps;
        if (temp <= 26)
        {
            // Yes can move this peice
            moves_lst.push_back(p.first);
        }
    }
}

/**
 * @brief Method to move the piece as per steps
 * 
 * @param steps steps by which the piece needs to be moved
 * @param other other player to check clashes
 */
void player::move_piece(int steps, player &other)
{

    while (1)
    {
        //check possible moves
        std::vector<int> possible_moves;
        for(std::pair<const int, piece>&p : pawn_pos)
        {
            check_possible_moves(possible_moves,p,steps);

        }
        if(king_pos.daa_check() && !king_pos.checkpt_check())
        {
            std::pair<const int, piece> temp = std::make_pair(9,king_pos);
            check_possible_moves(possible_moves,temp,steps);
        }
        int piece_no = display_possible_moves(possible_moves);

        if(piece_no != 9 && piece_no != 0) //not king and there are possible moves
        {
            if(helper_move_piece(pawn_pos[piece_no],steps, piece_no, other))
                break;
            else
                continue;
        }
        else if( piece_no == 0)
        {
            //NO possible moves left
            break;
        }
        else
        {
            if(helper_move_piece(king_pos,steps, piece_no, other))
                break;
            else
                continue;

        }

    }
}
