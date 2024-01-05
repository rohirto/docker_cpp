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

std::map<int, piece> player::pawn_get_pos()
{
    return pawn_pos;
}

piece player::king_get_pos()
{
    return king_pos;
}

// void player::set_pawn_back(pawn& p, int no)
// {
//     switch (no)
//     {
//     case 1:
//         if(player_no == 1)
//             p.position = player_2_house_p1;
//         else
//             p.position = player_1_house_p1;
//         break;
//     case 2:
//         if(player_no == 1)
//             p.position = player_2_house_p2;
//         else
//             p.position = player_1_house_p2;
//         break;
//     case 3:
//         if(player_no == 1)
//             p.position = player_2_house_p3;
//         else
//             p.position = player_1_house_p3;
//         break;
//     case 4:
//         if(player_no == 1)
//             p.position = player_2_house_p4;
//         else
//             p.position = player_1_house_p4;
//         break;
//     case 5:
//         if(player_no == 1)
//             p.position = player_2_house_p5;
//         else
//             p.position = player_1_house_p5;
//         break;
//     case 6:
//         if(player_no == 1)
//             p.position = player_2_house_p6;
//         else
//             p.position = player_1_house_p6;
//         break;
//     case 7:
//         if(player_no == 1)
//             p.position = player_2_house_p7;
//         else
//             p.position = player_1_house_p7;
//         break;
//     case 8:
//         if(player_no == 1)
//             p.position = player_2_house_p8;
//         else
//             p.position = player_1_house_p8;
//         break;

//     default:
//         break;
//     }
// }

// void player::set_king_back(king& k, int no)
// {
//     if(player_no == 1)
//         k.position = player_2_house_k;
//     else
//         k.position = player_1_house_k;
// }

void player::set_piece_back(piece &p, int no, int player_no)
{
    if (p.is_p_king())
    {
        if (player_no == 1)
            p.setpostion(player_2_house_k);
        else
            p.setpostion(player_1_house_k);
    }
    else
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

        default:
            break;
        }
    }
}

// bool player::check_safe_pawn(pawn& p, const player& other, int& pos)
// {
//     if(player_no == 1)
//     {
//         //Safe boxes check
//         if(p.position == player2_map_1 || p.position == player2_map_6 || p.position == player2_map_11 || p.position == player2_map_16 || p.position == player2_map_21 )
//         {
//             return true;
//         }

//     }
//     else
//     {
//         if(p.position == player1_map_1 || p.position == player1_map_6 || p.position == player1_map_11 || p.position == player1_map_16 || p.position == player1_map_21)
//         {
//             return true;
//         }

//     }

//     // Multiple box occupancy check
//     bool multiple_chck_val = std::any_of(other.pawn_pos.begin(), other.pawn_pos.end(), [&p, &pos](const std::pair<int, pawn> &op)
//                                          { if(pos != op.first){ return op.second.position == p.position; }return false;});

//     if (multiple_chck_val == true)
//     {
//         return true;
//     }
//     else
//     {
//         return std::any_of(other.king_pos.begin(), other.king_pos.end(), [&p](const std::pair<int, king> &op)
//                            { return op.second.position == p.position; });
//     }
// }
// bool player::check_safe_king(king& k, const player& other, int& pos)
// {
//     if(player_no == 1)
//     {
//         //Safe boxes check
//         if(k.position == player2_map_1 || k.position == player2_map_6 || k.position == player2_map_11 || k.position == player2_map_16 || k.position == player2_map_21 )
//         {
//             return true;
//         }

//     }
//     else
//     {
//         if(k.position == player1_map_1 || k.position == player1_map_6 || k.position == player1_map_11 || k.position == player1_map_16 || k.position == player1_map_21)
//         {
//             return true;
//         }
//     }

//     // Multiple box occupancy check
//     bool multiple_chck_val = std::any_of(other.pawn_pos.begin(), other.pawn_pos.end(), [&k, &pos](const std::pair<int, pawn> &op)
//                                         { if(pos != op.first){ return op.second.position == k.position; }return false;});

//     if (multiple_chck_val == true)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }

// }

bool player::check_piece_safe(piece &p, const player &other, int &pos)
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

    // Multiple box occupancy check
    bool multiple_chck_val = std::any_of(other.pawn_pos.begin(), other.pawn_pos.end(), [&p, &pos](std::pair<int, piece> op)
                                         { if(pos != op.first){ return op.second.getposition() == p.getposition(); }return false; });

    if (multiple_chck_val == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool player::if_check_pt_reached(piece &p)
{
    if (player_no == 1)
    {
        if (p.getposition() == player1_map_26)
        {
            // Reached chk point
            return true;
        }
    }
    else
    {
        if (p.getposition() == player2_map_26)
        {
            // reached check point
            return true;
        }
    }

    return false;
}

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

void player::set_turn(bool val)
{
    turn = val;
}

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
            // if(player_map[pawn_pos[piece].step_no] == other.player_map[other.pawn_pos[piece].step_no])
            if (std::any_of(other.pawn_pos.begin(), other.pawn_pos.end(), [&piece_no, &temp,&new_pos](std::pair<int, piece> op)    //anyof loop to see if other pawn piece clash with our piece
                            { if( op.second.getposition() == new_pos){temp = op.first; return true;} return false; }) ||
                [&other, &temp,&new_pos]()
                {if( other.king_pos.getposition() == new_pos){temp = 9; return true;} return false; }() //IIFE for other's kingpos clash
                )
            {
                if (temp != 9)
                {
                    // Check safe condition
                    if (!check_piece_safe(other.pawn_pos[temp], other, temp)) // Check if the pawn of the other player is safe or not
                    {
                        // Not safe
                        // Clash has occured
                        // Send other to home
                        other.pawn_pos[temp].step_no = 0;
                        other.pawn_pos[temp].set_daa(false);
                        set_piece_back(other.pawn_pos[temp], temp, player_no);
                        has_killed = true;  //Player has killed other's pawn
                    }
                }
                else
                {
                    //if pawn killed king, then send only king back
                    // Check safe condition
                    if (!check_piece_safe(other.king_pos, other, temp)) // Check if the pawn of the other player is safe or not
                    {
                        if(p != king_pos)
                        {
                            // Not safe
                            // Clash has occured
                            // Send other to home
                            other.king_pos.step_no = 0;
                            other.king_pos.set_daa(false);
                            set_piece_back(other.king_pos, temp, player_no);

                            has_killed = true;  //Player has killed other's pieces
                        }
                        else
                        {
                            //King has killed king, send all pieces to home
                            other.king_pos.step_no = 0;
                            other.king_pos.set_daa(false);
                            other.set_daa_initiated(false);
                            set_piece_back(other.king_pos,9,player_no);
                            has_killed = true;  //Player has killed other's pawn
                            for(auto& p: other.pawn_pos)
                            {
                                if(!p.second.checkpt_check())
                                {
                                     p.second.step_no = 0;
                                    p.second.set_daa(false);
                                    set_piece_back(p.second, p.first, player_no);
                                    
                                }
                               
                            }

                        }
                    }

                }

                p.step_no = temp_step_no;
                p.setpostion(player_map[p.step_no]);
            }
            else if (if_check_pt_reached(p)) // Check if reached check point
            {
                if (has_killed)
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
                else
                {
                    display_yellow("Need to take out atleast one piece of other player to reach checkpoint");
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

void player::move_piece(int steps, player &other)
{

    while (1)
    {
        display_yellow("Enter Piece no to move or '9' to move king: ");
        int piece_no = get_int();

        if(piece_no != 9)
        {
            if(helper_move_piece(pawn_pos[piece_no],steps, piece_no, other))
                break;
            else
                continue;
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
