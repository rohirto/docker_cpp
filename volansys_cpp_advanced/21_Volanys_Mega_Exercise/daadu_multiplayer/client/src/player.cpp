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
#include <sstream>
#include <set>

/**
 * @brief Method to set name of player
 *
 */
void player::setname(const std::string& s)
{
    name = s;

    std::cout << "Player name set to: " << name << std::endl;
}

/**
 * @brief Method to get name of the player object
 *
 * @return std::string
 */
std::string player::getname() const
{
    return name;
}

/**
 * @brief get the pawn_pos object, it is a map of 8 piece object which are treated as pawns
 *
 * @return std::map<int, piece>
 */
std::map<int, piece> player::pawn_get_pos() const
{
    return pawn_pos;
}

/**
 * @brief get the king object of the player, it is a piece object treated as king
 *
 * @return piece
 */
piece player::king_get_pos() const
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
    for (std::pair<const int, piece> &p : pawn_pos)
    {
        if (p.second.daa_check() == false)
        {
            return true;
        }
    }
    if (king_pos.daa_check() == false)
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
        if (p != other.king_pos) // pawn overloapping with king
        {
            piece t = other.king_pos;
            if (t.getposition() == p.getposition())
            {
                // overloapping with king
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
 * @brief set the turn of the player
 *
 * @param val if true, the set the turn of player, else give turn to other
 */
void player::set_turn(bool val)
{
    turn = val;
}

// /**
//  * @brief check the daa for pawns and king, if daa is remaining, then take a piece out and update daa
//  *
//  * @param c character which determiines if pawn or king
//  * @return true if a piece is taken out
//  * @return false if all peices are already out
//  */
// bool player::daa_check(char c) // if c == p -> pawn, if c== k -> king
// {
//     // Check the bool daa value, if any goti pawn is false, set it to true, return true, else return false
//     if (c == 'k')
//     {
//         if (!king_pos.daa_check() && !king_pos.checkpt_check())
//         {
//             king_pos.set_daa(true);
//             king_pos.step_no = 1;
//             king_pos.setpostion(player_map[king_pos.step_no]);
//             daa_initiated = true;
//             return true;
//         }
//         else
//         {
//             display_red("King already taken out!\n");
//             c = 'p';
//         }
//     }
//     if (c == 'p')
//     {
//         for (auto &p : pawn_pos)
//         {
//             if (!p.second.daa_check() && !p.second.checkpt_check())
//             {
//                 p.second.set_daa(true);
//                 p.second.step_no = 1;
//                 p.second.setpostion(player_map[p.second.step_no]);
//                 daa_initiated = true;
//                 return true;
//             }
//         }
//     }

//     display_red("All pawns already out!\n");

//     return false;
// }
#if 0
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
bool player::helper_move_piece(piece &p, int steps, int piece_no, player &other)
{
    int temp = 0;
    int temp_step_no = 0;
    if (p.daa_check())
    {
        temp_step_no = p.step_no + steps;
        if (temp_step_no < 26)
        {
            std::pair<int, int> new_pos = player_map[temp_step_no];
            /**
             * @brief any_of loop, along with lambda fucntion
             * @paragraph If any of other player's pawn, has the same position as new position of piece p or other player's king has
             *            same position as new position of piece p.
             *            This is a condition to test the clash of pieces
             */
            if (std::any_of(other.pawn_pos.begin(), other.pawn_pos.end(), [&piece_no, &temp, &new_pos](std::pair<int, piece> op) // anyof loop to see if other pawn piece clash with our piece
                            { if( op.second.getposition() == new_pos){temp = op.first; return true;} return false; }) ||
                [&other, &temp, &new_pos]()
                {if( other.king_pos.getposition() == new_pos){temp = 9; return true;} return false; }() // IIFE for other's kingpos clash
            )
            {
                if (temp != 9) // If not king
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
                        has_killed = true; // Player has killed other's pawn
                    }
                }
                else // If a king
                {
                    // Check safe condition
                    if (!check_piece_safe(other.king_pos, other, temp)) // Check if the pawn of the other player is safe or not
                    {
                        if (p != king_pos) // Pawn killed king
                        {
                            // Not safe
                            // Clash has occured
                            // Send other to home
                            other.king_pos.step_no = 0;
                            other.king_pos.set_daa(false);
                            set_piece_back(other.king_pos, 9);

                            has_killed = true; // Player has killed other's pieces
                        }
                        else
                        {
                            // King has killed king, send all pieces to home
                            other.king_pos.step_no = 0;
                            other.king_pos.set_daa(false);
                            other.set_daa_initiated(false);
                            set_piece_back(other.king_pos, 9);
                            has_killed = true; // Player has killed other's pawn
                            for (auto &p : other.pawn_pos)
                            {
                                if (!p.second.checkpt_check())
                                {
                                    p.second.step_no = 0;
                                    p.second.set_daa(false);
                                    set_piece_back(p.second, p.first);
                                }
                            }
                        }
                    }
                }

                // Update the positions
                p.step_no = temp_step_no;
                p.setpostion(player_map[p.step_no]);
            }
            else
            {
                // No clash but need to update position
                p.step_no = temp_step_no;
                p.setpostion(player_map[p.step_no]);
            }
        }
        else if (temp_step_no == 26)  //Check point validation
        {
            std::pair<int, int> new_pos = player_map[temp_step_no];
            // Reached check point, check the check point conditions
            if (if_check_pt_reached(new_pos)) // Check if reached check point
            {
                if (has_killed) // Can reach check point only if player has eliminated atleast 1 of other player's pieces
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
                else // Not killed any of the other player's pieces
                {
                    display_yellow("Need to take out atleast one piece of other player to reach checkpoint\n");
                    display_yellow("Move any other piece? (y or n)");
                    char chh = get_char();
                    if (chh == 'y')
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
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
#endif
bool isNumberInSet(int number, const std::set<int>& cp) {
    // Use std::find to check if the number is present in the vector
    auto it = std::find(cp.begin(), cp.end(), number);

    // Check if the iterator points to the end of the vector
    // indicating that the number was not found
    return it != cp.end();
}
#if 0
/**
 * @brief Method to check all possible moves for piece p object
 *
 * @param moves_lst a vector of int containing the piece no which can be moved
 * @param p piece object in map form, p.first is the piece no (1-8 for pawns, 9 for king)
 * @param steps no of steps needed to be taken
 */
void player::check_possible_moves(std::vector<int> &moves_lst,std::set<int>& cp, std::pair<const int, piece> &p, int steps)
{
    std::vector<std::string> overlapping_pieces;
    if (p.second.daa_check() && !p.second.checkpt_check()) // Daa done and not reached checkpoint
    {
        int temp = p.second.step_no + steps;
        if (temp <= 26)
        {
            // Yes can move this peice
            moves_lst.push_back(p.first);
        }

        //Check overlapping positions with self pawns
        if(!isNumberInSet(p.first, cp))
            check_overlapping_pieces(overlapping_pieces,cp, p);
    }

   
}
#endif

#if 0
void player::check_overlapping_pieces(std::vector<std::string>& s,std::set<int>& cp,std::pair<const int, piece> &p)
{
    std::set<int> pp;
    if (!isNumberInSet(p.first, cp))
    {

        for (std::pair<const int, piece> &otherp : pawn_pos)
        {

            if (otherp.first != p.first)
            {
                if (otherp.second.getposition() == p.second.getposition())
                {
                    // Overlap
                    std::ostringstream oss;

                    oss << p.first << " <--> " << otherp.first;

                    std::string temp = oss.str();
                    s.push_back(temp);

                    //Add to print set
                    pp.insert(p.first);
                    pp.insert(otherp.first);
                    // If not in checked pieces then push to checked pieces vector
                    cp.insert(p.first); // Insert the overlapped piece in set
                    cp.insert(otherp.first);
                }
            }
        }
    }

    //Display overlaps
    display_overlaps_set(pp, player_no);
}


void player::check_overlapping_enemy_pieces(player& other, std::set<int>& cp,std::pair<const int, piece> &p)
{
    if (!isNumberInSet(p.first, cp))
    {
        std::set<int> pp;
        for (std::pair<const int, piece> &otherp : other.pawn_pos)
        {
            if (otherp.second.getposition() == p.second.getposition())
            {
                pp.insert(otherp.first);
                cp.insert(p.first); // Insert the overlapped piece in set
            }
        }

        //Display overlaps
        display_overlaps_set(pp, other.player_no);
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
        // check possible moves
        std::vector<int> possible_moves;
        std::set<int> checked_pieces; //It is a set of values which represents overlapping piece nos
        std::set<int> checked_pieces_enemy;
        for (std::pair<const int, piece> &p : pawn_pos)
        {
            check_possible_moves(possible_moves,checked_pieces, p, steps);
            check_overlapping_enemy_pieces(other,checked_pieces_enemy, p);
        }
        if (king_pos.daa_check() && !king_pos.checkpt_check())
        {
            std::pair<const int, piece> temp = std::make_pair(9, king_pos);
            check_possible_moves(possible_moves,checked_pieces, temp, steps);
            check_overlapping_enemy_pieces(other,checked_pieces_enemy, temp);
        }
        checked_pieces.clear(); //Clear the set of checked pieces after the process is complete
        checked_pieces_enemy.clear();
        int piece_no = display_possible_moves(possible_moves);

        

        if (piece_no != 9 && piece_no != 0) // not king and there are possible moves
        {
            if (helper_move_piece(pawn_pos[piece_no], steps, piece_no, other))
                break;
            else
                continue;
        }
        else if (piece_no == 0)
        {
            // NO possible moves left
            break;
        }
        else
        {
            if (helper_move_piece(king_pos, steps, piece_no, other))
                break;
            else
                continue;
        }
    }
}
#endif
// JSON Serialization for piece
void to_json(json& j, const piece& p) 
{
    j = json{
        {"position", {p.getposition().first, p.getposition().second}},
        {"is_king", p.is_p_king()},
        {"is_daa_done", p.daa_check()},
        {"is_check_point_reached", p.checkpt_check()},
        {"step_no", p.step_no}
    };
}

//JSON Deserialize for piece
void from_json(const json& j, piece& p) {
    // Extract position manually
    std::pair<int, int> position;
    position.first = j.at("position")[0].get<int>();
    position.second = j.at("position")[1].get<int>();
    p.setpostion(position); // Use setter function

    // Directly set other members
    p.set_daa(j.at("is_daa_done").get<bool>());
    p.set_checkpt(j.at("is_check_point_reached").get<bool>());
    p.step_no = j.at("step_no").get<int>();

    bool is_king = j.at("is_king").get<bool>();
    if (is_king) {
        // Handle setting 'is_king' if there's a dedicated setter
        // e.g., p.set_king(is_king);
    }
}

// JSON Serialization for player
void to_json(json& j, const player& pl) {
    json pawns_json;
    for (const auto& [pawn_no, pawn_piece] : pl.pawn_get_pos()) {
        pawns_json[std::to_string(pawn_no)] = pawn_piece;
    }

    j = json{
        {"name", pl.getname()},
        {"player_no", pl.get_player_no()},
        {"turn", pl.get_turn()},
        {"daa_initiated", pl.check_daa_initiated()},
        {"has_killed", pl.get_kill()},
        {"pawn_positions", pawns_json},
        {"king_position", pl.king_get_pos()}
    };
}

//JSON Deserialzation for player
void from_json(const json& j, player& pl) {
    pl.set_daa_initiated(j.at("daa_initiated").get<bool>());
    pl.has_killed = j.at("has_killed").get<bool>();
    // Deserialize king position
    piece king_piece;
    from_json(j.at("king_position"), king_piece);
    pl.king_pos = king_piece;

    // Deserialize player-specific fields
    pl.setname(j.at("name").get<std::string>());

    // Deserialize pawn positions (map<int, piece>)
    const auto& pawns_json = j.at("pawn_positions");
    for (const auto& [key, value] : pawns_json.items()) {
        int key_int = std::stoi(key); // Convert JSON key to int
        piece pawn_piece;
        from_json(value, pawn_piece); // Deserialize individual piece
        pl.pawn_pos[key_int] = pawn_piece;
    }

    pl.player_no = j.at("player_no").get<int>();

    pl.set_turn(j.at("turn").get<bool>());
    
    // Deserialize base class (piece)
    //from_json(j.at("piece"), static_cast<piece&>(pl));

}