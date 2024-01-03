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



game_board::game_board()
{
    //Empty box init
    // empty_box.push_back('[');
    // empty_box.push_back(' ');
    // empty_box.push_back(']');

    empty_b.box_content.push_back('[');
    empty_b.box_content.push_back(' ');
    empty_b.box_content.push_back(']');

    //Pawn box
    // pawn_box.push_back('[');
    // pawn_box.push_back(PAWN_CHAR);
    // pawn_box.push_back(']');


    pawn_b.box_content.push_back('[');
    pawn_b.box_content.push_back(PAWN_CHAR);
    pawn_b.box_content.push_back(']');

    //King Box
    // king_box.push_back('[');
    // king_box.push_back(KING_CHAR);
    // king_box.push_back(']');

    king_b.box_content.push_back('[');
    king_b.box_content.push_back(KING_CHAR);
    king_b.box_content.push_back(']');

    //Check point box
    // check_pt_box.push_back('[');
    // check_pt_box.push_back(CHECK_PT_CHAR);
    // check_pt_box.push_back(']');

    check_pt_b.box_content.push_back('[');
    check_pt_b.box_content.push_back(CHECK_PT_CHAR);
    check_pt_b.box_content.push_back(']');

    //Empty space init
    // empty_space.push_back(' ');
    // empty_space.push_back(' ');
    // empty_space.push_back(' ');

    empty_s.box_content.push_back(' ');
    empty_s.box_content.push_back(' ');
    empty_s.box_content.push_back(' ');
    

    // pawn_char.push_back(' ');
    // pawn_char.push_back(PAWN_CHAR);
    // pawn_char.push_back(' ');

    pawn_c.box_content.push_back(' ');
    pawn_c.box_content.push_back(PAWN_CHAR);
    pawn_c.box_content.push_back(' ');
    

    // king_char.push_back(' ');
    // king_char.push_back(KING_CHAR);
    // king_char.push_back(' ');

    king_c.box_content.push_back(' ');
    king_c.box_content.push_back(KING_CHAR);
    king_c.box_content.push_back(' ');

    g_board = std::vector<std::vector<box>>(getheight(), std::vector<box>(getwidth()));

    //board = std::vector<std::vector<std::vector<char>>>(getheight(), std::vector<std::vector<char>>(getwidth(), std::vector<char>(3, ' ')));

    for(int i = 0; i < getheight(); i++)  //6
    {
        for(int j = 0; j < getwidth(); j++) //16
        {
            if((j == 0 || j == 5 || j == 10 || j == 15)&&(i == 0 || i == 5)) //Check point boxes
            {
                
                //board[i][j] = check_pt_box;
                g_board[i][j] = check_pt_b;
            }
            else if((j == 0 || j == 5 || j == 10 || j == 15)&&(i == 1 || i == 2 || i == 3 || i == 4))
            {
                
                //board[i][j] = empty_box;
                g_board[i][j] = empty_b;
            }
            else if((i == 0 ) && (j == 1 || j == 2 || j == 3 || j == 4 || j == 11 || j == 12 || j == 13 || j == 14) )
            {
                //board[i][j] = empty_box;
                g_board[i][j] = empty_b;
                
            }
            else if((i == 5) && (j == 6 || j == 7 || j == 8 || j == 9))
            {
                //board[i][j] = empty_box;
                g_board[i][j] = empty_b;
            }
            else if((i == 1 || i == 2 || i == 3 || i == 4) && (j == 2 || j == 3))
            {
                //player 1 house
                
                //board[i][j] = empty_space;
                g_board[i][j] = empty_s;
                
            }
            else if((i == 1 || i == 2 || i == 3 || i == 4) && (j == 13 || j == 14))
            {
                //Player 2 house
               //board[i][j] = empty_space;
               g_board[i][j] = empty_s;
            }
            else
            {
                //board[i][j] = empty_space;
                g_board[i][j] = empty_s;
            }
            
        }

    }
}

void game_board::set_board( player& p1,  player& p2)
{
    // Position player pawns
    std::map<int, std::pair<int, int>> player1_pos = p1.get_pos();
    std::map<int, std::pair<int, int>> player2_pos = p2.get_pos();

    for (const auto &goti : player1_pos)
    {
        // 1 to 8 goti is pawns
        if(goti.first != 9) //Not a king
        {
            if ((goti.second.first == 0 || goti.second.first == 5) || (goti.second.second == 0 || goti.second.second == 5 || goti.second.second == 10 || goti.second.second == 15))
            {
                
                //board[goti.second.first][goti.second.second] = pawn_box;
                g_board[goti.second.first][goti.second.second] = pawn_b;
                g_board[goti.second.first][goti.second.second].color = 'r';
                
                
            }
            else
            {
                // Still in house
                //board[goti.second.first][goti.second.second] = pawn_char;
                g_board[goti.second.first][goti.second.second] = pawn_c;
                g_board[goti.second.first][goti.second.second].color = 'r';
            }
        }
        else // 9 goti is king
        {
            if ((goti.second.first == 0 || goti.second.first == 5) || (goti.second.second == 0 || goti.second.second == 5 || goti.second.second == 10 || goti.second.second == 15))
            {
                
                //board[goti.second.first][goti.second.second] = king_box;
                g_board[goti.second.first][goti.second.second] = king_b;
                g_board[goti.second.first][goti.second.second].color = 'r';
            }
            else
            {
                // Still in house
                //board[goti.second.first][goti.second.second] = king_char;
                g_board[goti.second.first][goti.second.second] = king_c;
                g_board[goti.second.first][goti.second.second].color = 'r';
                
            }

        }

        
    }
    for (const auto &goti : player2_pos)
    {
        // 1 to 8 goti is pawns
        if(goti.first != 9) //Not a king
        {
            if ((goti.second.first == 0 || goti.second.first == 5) || (goti.second.second == 0 || goti.second.second == 5 || goti.second.second == 10 || goti.second.second == 15))
            {
                
                //board[goti.second.first][goti.second.second] = pawn_box;
                g_board[goti.second.first][goti.second.second] = pawn_b;
                g_board[goti.second.first][goti.second.second].color = 'g';
                
            }
            else
            {
                // Still in house
                //board[goti.second.first][goti.second.second] = pawn_char;
                g_board[goti.second.first][goti.second.second] = pawn_c;
                g_board[goti.second.first][goti.second.second].color = 'g';
            }
        }
        else // 9 goti is king
        {
            if ((goti.second.first == 0 || goti.second.first == 5) || (goti.second.second == 0 || goti.second.second == 5 || goti.second.second == 10 || goti.second.second == 15))
            {
                
                //board[goti.second.first][goti.second.second] = king_box;
                g_board[goti.second.first][goti.second.second] = king_b;
                g_board[goti.second.first][goti.second.second].color = 'g';
            }
            else
            {
                // Still in house
                //board[goti.second.first][goti.second.second] = king_char;
                g_board[goti.second.first][goti.second.second] = king_c;
                g_board[goti.second.first][goti.second.second].color = 'g';
                
            }

        }

        
    }

    for(int i = 0; i < getheight(); i++)
    {
        for(int j = 0; j < getwidth(); j++)
        {
            // if((j == 0 || j == 5 || j == 10 || j == 15)&&(i == 0 || i == 5))
            // {
            //     print_box(check_pt_box);
            // }
            // else if((j == 0 || j == 5 || j == 10 || j == 15)&&(i == 1 || i == 2 || i == 3 || i == 4))
            // {
            //     print_box(empty_box);
            // }
            // else if((i == 0 ) && (j == 1 || j == 2 || j == 3 || j == 4 || j == 11 || j == 12 || j == 13 || j == 14) )
            // {
            //     print_box(empty_box);
            // }
            // else if((i == 5) && (j == 6 || j == 7 || j == 8 || j == 9))
            // {
            //     print_box(empty_box);
            // }
            // else if((i == 1 || i == 2 || i == 3 || i == 4) && (j == 2 || j == 3))
            // {
            //     //player 1 house
            //     print_box(empty_space);
                
            // }
            // else if((i == 1 || i == 2 || i == 3 || i == 4) && (j == 13 || j == 14))
            // {
            //     //Player 2 house
            //     print_box(empty_space);
            // }
            // else
            // {
            //     print_box(empty_space);
            // }


            if(g_board[i][j] == king_b || g_board[i][j] == king_c || g_board[i][j] == pawn_b || g_board[i][j] == pawn_c)
            {
                print_player_box(g_board[i][j]);
            }
            else
            {
                print_box(g_board[i][j]);
            }
           
            
        }
        std::cout << std::endl;

    }
}

void game_board::print_box(const box& box)
{
    for(char ch: box.box_content)
    {
        std::cout << ch;

    }
}

void game_board::print_player_box(const box& box)
{
    for(char ch: box.box_content)
    {
        if(ch != '[' && ch != ']')
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
                break;
            }
        }
    }
}

bool box::operator==(box const& other)
{
    if(box_content == other.box_content)
    {
        return true;
    }

    return false;
}

// Constructor definition
void cowries::cowry_throw()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(ALL_FRONT_FACING, FIVE_FRONT_FACING);

    // Generate a random value from the enum
    position =  static_cast<cowry_position>(distribution(gen));

}

// Function to calculate the count based on cowry position
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
        case FIVE_FRONT_FACING:
            return 5;
        default:
            return 0; // Handle other cases if needed
    }
}