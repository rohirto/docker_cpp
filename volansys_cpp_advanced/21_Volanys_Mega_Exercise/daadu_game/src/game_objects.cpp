/**
 * @file game_objects.cpp
 * @author rohit S
 * @brief Implementation of game objects classes, needed to play tge game
 * @version 0.1
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024 Volansys Technologies
 * 
 */
#include <iomanip>
#include <random>
#include "game_objects.h"


/**
 * @brief Construct a new game board::game board object
 * 
 */
game_board::game_board()
{

    empty_b.box_content.push_back('[');
    empty_b.box_content.push_back(' ');
    empty_b.box_content.push_back(']');



    pawn_b.box_content.push_back('[');
    pawn_b.box_content.push_back(PAWN_CHAR);
    pawn_b.box_content.push_back(']');


    king_b.box_content.push_back('[');
    king_b.box_content.push_back(KING_CHAR);
    king_b.box_content.push_back(']');

    safe_b.box_content.push_back('[');
    safe_b.box_content.push_back(SAFE_BOX_CHAR);
    safe_b.box_content.push_back(']');


    p1_check_pt_b.box_content.push_back('[');
    p1_check_pt_b.box_content.push_back(CHECK_PT_CHAR);
    p1_check_pt_b.box_content.push_back(']');
    p1_check_pt_b.color = 'r';

    p2_check_pt_b.box_content.push_back('[');
    p2_check_pt_b.box_content.push_back(CHECK_PT_CHAR);
    p2_check_pt_b.box_content.push_back(']');
    p2_check_pt_b.color = 'g';


    empty_s.box_content.push_back(' ');
    empty_s.box_content.push_back(' ');
    empty_s.box_content.push_back(' ');
    


    pawn_c.box_content.push_back(' ');
    pawn_c.box_content.push_back(PAWN_CHAR);
    pawn_c.box_content.push_back(' ');
    


    king_c.box_content.push_back(' ');
    king_c.box_content.push_back(KING_CHAR);
    king_c.box_content.push_back(' ');

    g_board = std::vector<std::vector<box>>(getheight(), std::vector<box>(getwidth()));

    //board = std::vector<std::vector<std::vector<char>>>(getheight(), std::vector<std::vector<char>>(getwidth(), std::vector<char>(3, ' ')));

    board_reset();
}

/**
 * @brief Reset the Board to default
 * 
 */
void game_board::board_reset()
{
   for(int i = 0; i < getheight(); i++)  //6
    {
        for(int j = 0; j < getwidth(); j++) //16
        {
            if((j == 0 || j == 5 || j == 10 || j == 15)&&(i == 0 || i == 5)) //Check point boxes and safe boxes
            {
                
                //board[i][j] = check_pt_box;
                if(i == 0 && j == 5)
                {
                    //p2 check point
                    g_board[i][j] = p2_check_pt_b;
                }
                else if(i == 0 && j == 10)
                {
                    //p1 check point 
                    g_board[i][j] = p1_check_pt_b;
                }
                else
                {
                    //safe boxes
                    g_board[i][j] = safe_b;
                }
                
            }
            else if((j == 0 || j == 5 || j == 10 || j == 15)&&(i == 1 || i == 2 || i == 3 || i == 4))
            {
                
                //board[i][j] = empty_box;
                g_board[i][j] = empty_b;  //Ordinary empty boxes
            }
            else if((i == 0 ) && (j == 1 || j == 2 || j == 3 || j == 4 || j == 11 || j == 12 || j == 13 || j == 14) )
            {
                //board[i][j] = empty_box;
                g_board[i][j] = empty_b; //Ordinary empty boxes
                
            }
            else if((i == 5) && (j == 6 || j == 7 || j == 8 || j == 9))
            {
                //board[i][j] = empty_box;
                g_board[i][j] = empty_b;  //Ordinary empty box
            }
            else if((i == 1 || i == 2 || i == 3 || i == 4) && (j == 2 || j == 3))
            {
                //player 1 house
                
                //board[i][j] = empty_space;
                g_board[i][j] = empty_s; //Empty space 
                
            }
            else if((i == 1 || i == 2 || i == 3 || i == 4) && (j == 13 || j == 14))
            {
                //Player 2 house
               //board[i][j] = empty_space;
               g_board[i][j] = empty_s; //Empty space 
            }
            else
            {
                //board[i][j] = empty_space;
                g_board[i][j] = empty_s; //Empty space 
            }
            
        }

    } 
}

/**
 * @brief Set the board for p1 and p2, take data from p1 and p2 and modify the board accordingly
 * 
 * @param p1 Player 1 player object
 * @param p2 Player 2 player object
 */
void game_board::set_board( player& p1,  player& p2)
{
    //Set default g_board values, without pawns
    board_reset();


    // Position player pawns
    //Get player 1 positions of pawns and king
    std::map<int, piece> player1_pawn_pos = p1.pawn_get_pos();
    piece player1_king_pos = p1.king_get_pos();
    
    //Get Player 2 positions of Pawns and king
    std::map<int, piece> player2_pawn_pos = p2.pawn_get_pos();
    piece player2_king_pos = p2.king_get_pos();

    //Map the piece pair <int, int> to i and j of g_board respectievely
    for ( auto& p_info : player1_pawn_pos)
    {
        std::pair<int,int> temp = p_info.second.getposition();
        if ((temp.first == 0 || temp.first == 5 )|| (temp.second == 0 || temp.second == 5 || temp.second == 10 || temp.second == 15))
        {
            
            g_board[temp.first][temp.second] = pawn_b;
            g_board[temp.first][temp.second].piece_no = p_info.first;
            g_board[temp.first][temp.second].color = 'r';

        }
        else
        {
            // Still in house
            // board[goti.second.first][goti.second.second] = pawn_char;
            g_board[temp.first][temp.second] = pawn_c;
            g_board[temp.first][temp.second].piece_no = p_info.first;
            g_board[temp.first][temp.second].color = 'r';
        }
    }

    // King
    std::pair<int, int> k_temp = player1_king_pos.getposition();
    if ((k_temp.first == 0 || k_temp.first == 5) || (k_temp.second == 0 || k_temp.second == 5 || k_temp.second == 10 || k_temp.second == 15))
    {

        // board[goti.second.first][goti.second.second] = king_box;
        g_board[k_temp.first][k_temp.second] = king_b;
        g_board[k_temp.first][k_temp.second].piece_no = 9;
        g_board[k_temp.first][k_temp.second].color = 'r';
    }
    else
    {
        // Still in house
        // board[goti.second.first][goti.second.second] = king_char;
        g_board[k_temp.first][k_temp.second] = king_c;
        g_board[k_temp.first][k_temp.second].piece_no = 9;
        g_board[k_temp.first][k_temp.second].color = 'r';
    }

    //Do the same for player 2
    for ( auto& p_info : player2_pawn_pos)
    {
        std::pair<int,int> temp = p_info.second.getposition();

        if ((temp.first == 0 || temp.first == 5) || (temp.second == 0 || temp.second == 5 || temp.second == 10 || temp.second == 15))
        {

            g_board[temp.first][temp.second] = pawn_b;
            g_board[temp.first][temp.second].piece_no = p_info.first;
            g_board[temp.first][temp.second].color = 'g';
        }
        else
        {
            // Still in house
            // board[goti.second.first][goti.second.second] = pawn_char;
            g_board[temp.first][temp.second] = pawn_c;
            g_board[temp.first][temp.second].piece_no = p_info.first;
            g_board[temp.first][temp.second].color = 'g';
        }
    }

        // King
        k_temp = player2_king_pos.getposition();

        if ((k_temp.first == 0 || k_temp.first == 5) || (k_temp.second == 0 || k_temp.second == 5 || k_temp.second == 10 || k_temp.second == 15))
        {

            // board[goti.second.first][goti.second.second] = king_box;
            g_board[k_temp.first][k_temp.second] = king_b;
            g_board[k_temp.first][k_temp.second].piece_no = 9;
            g_board[k_temp.first][k_temp.second].color = 'g';
        }
        else
        {
            // Still in house
            // board[goti.second.first][goti.second.second] = king_char;
            g_board[k_temp.first][k_temp.second] = king_c;
            g_board[k_temp.first][k_temp.second].piece_no = 9;
            g_board[k_temp.first][k_temp.second].color = 'g';
        }
    
    //Print the g_board
    for(int i = 0; i < getheight(); i++)
    {
        for(int j = 0; j < getwidth(); j++)
        {

            if(g_board[i][j] == king_b || g_board[i][j] == king_c || g_board[i][j] == pawn_b || g_board[i][j] == pawn_c)
            {
                print_player_box(g_board[i][j]);
            }
            else if (g_board[i][j] == p1_check_pt_b && g_board[i][j] == p2_check_pt_b )
            {
                print_check_point_box(g_board[i][j]);
            }
            else
            {
                print_box(g_board[i][j]);
            }
           
            
        }
        std::cout << std::endl;

    }
}

/**
 * @brief Print a simple box, no coloring
 * 
 * @param box box object
 */
void game_board::print_box(const box& box)
{
    for(char ch: box.box_content)
    {
        std::cout << ch;

    }
}


/**
 * @brief Print a check point box, there are 2 checkpoint boxes, player 1 and player 2
 * 
 * @param box box object
 */
void game_board::print_check_point_box(const box& box)
{
    for(char ch: box.box_content)
    {
        if(ch != '[' && ch != ']' && ch != ' ')
        {
            //print in color
            switch (box.color)
            {
                case 'r':
                    display_red(ch);
                    break;
                case 'g':
                display_green(ch);
                    break;

                default:
                    std::cout << ch;
            }

        }
        else
        {
            std::cout << ch;
        }
    }

}

/**
 * @brief Print a player box, its content are red for p1 and green for p2
 * 
 * @param box box object
 */
void game_board::print_player_box(const box& box)
{
    for(char ch: box.box_content)
    {
        if(ch != '[' && ch != ']' && ch != ' ')
        {
            //print in color
            switch (box.color)
            {
            case 'r':
                if(box.piece_no != 9)
                    display_red(box.piece_no);
                else   
                    display_red(KING_CHAR);
                break;
            case 'g':
                if(box.piece_no != 9)
                    display_green(box.piece_no);
                else
                    display_green(KING_CHAR);
                break;
            
            default:
                break;
            }
        }
        else
        {
            std::cout << ch;
        }
    }
}

/**
 * @brief operator== overload implementation, to test equality of box object
 * 
 * @param other other box object
 * @return true if 2 boxes are equal
 * @return false if 2 bxes are not equal
 */
bool box::operator==(box const& other)
{
    if(box_content == other.box_content)
    {
        return true;
    }

    return false;
}

/**
 * @brief Cowry throw method, random number is selected from a predefined enums of cowries outcomes
 * 
 */
void cowries::cowry_throw()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(NONE_FRONT_FACING, ALL_FRONT_FACING);

    // Generate a random value from the enum
    position =  static_cast<cowry_position>(distribution(gen));

}

/**
 * @brief Function to calculate the count based on cowry position
 * 
 * @return int the cowry score based on cowry positions
 */
int cowries::getCount() const {
    switch (position) {
        case ALL_FRONT_FACING:
            return 10;
        case ONE_FRONT_FACING:
            return 1;
        case TWO_FRONT_FACING:
            return 2;
        case THREE_FRONT_FACING:
            return 3;
        case FOUR_FRONT_FACING:
            return 4;
        case NONE_FRONT_FACING:
            return 0;
        default:
            return 0; // Handle other cases if needed
    }
}