/**
 * @file menu.cpp
 * @author rohit S
 * @brief Menu screen of Daadu game
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024 Volansys technologies
 * 
 */

#include <iostream>
#include "game_menu.h"
#include <unistd.h>

/**
 * @brief Display the main screen menu, game name and option plus rules to play
 * 
 * @return int option that user has selected
 */
int menu::display_menu()
{
    display_yellow("█████ █████ █████ █████ █████ █████ █████");
    std::cout << std::endl;
    std::cout << std::endl;
    display_yellow("██████   █████   █████  ██████  ██    ██");
    std::cout << std::endl;
    display_yellow("██   ██ ██   ██ ██   ██ ██   ██ ██    ██");
    std::cout << std::endl;
    display_yellow("██   ██ ███████ ███████ ██   ██ ██    ██");
    std::cout << std::endl;
    display_yellow("██   ██ ██   ██ ██   ██ ██   ██ ██    ██");
    std::cout << std::endl;
    display_yellow("██████  ██   ██ ██   ██ ██████   ██████");
    std::cout << std::endl;
    std::cout << std::endl;
    display_yellow("█████ █████ █████ █████ █████ █████ █████");
    std::cout << std::endl;
    std::cout << std::endl;

    display_blue("1. Start the game\n");
    display_green("2. Rules to play\n");
    display_red("3. Exit the game\n");

    int c = get_int();

    return c;

    //clear();

}

/**
 * @brief Menu to display the Game rules
 * 
 * @return char 
 */
char menu::display_rules()
{
    


display_yellow("┳        ┓    •    ");std::cout << std::endl;
display_yellow("┃┏┓╋┏┓┏┓┏┫┓┏┏╋┓┏┓┏┓");std::cout << std::endl;
display_yellow("┻┛┗┗┛ ┗┛┗┻┗┻┗┗┗┗┛┛┗");std::cout << std::endl;
                   


std::cout << std::endl;
std::cout << std::endl;

display_green("\tDadu is a popular game in the Gujarati Bohra community and is perfect for family gatherings. It is based on wartime  strategy and planning. \
\nThis game is like LUDO but with a different board structure and rules. In LUDO 6 side facing dice is used but in this game  5 cowries are used. \
");

std::cout << std::endl;
std::cout << std::endl;


display_yellow("┓┏              ┓    ");std::cout << std::endl;
display_yellow("┣┫┏┓┓┏┏  ╋┏┓  ┏┓┃┏┓┓┏");std::cout << std::endl;
display_yellow("┛┗┗┛┗┻┛  ┗┗┛  ┣┛┗┗┻┗┫");std::cout << std::endl;
display_yellow("              ┛     ┛");std::cout << std::endl;

std::cout << std::endl;
std::cout << std::endl;

display_green("\tEach player will gate turn one by one to throw the cowries. There are 5 cowries used in this game \
\n The below table shows how the cowries count is taken into account when the player throws the cowries. ");

std::cout << std::endl;

display_green("| Sr  | Cowries position                          | Count         |");
std::cout << std::endl;
display_green("|-----|-------------------------------------------|---------------|");
std::cout << std::endl;
display_green("| 1   | 1 is front facing and 4 are down  facing  | 1 (aka \"Daa\") |");
std::cout << std::endl;
display_green("| 2   | 2 are front facing and 3 are down  facing | 2             |");
std::cout << std::endl;
display_green("| 3   | 3 are front facing and 2 are down  facing | 3             |");
std::cout << std::endl;
display_green("| 4   | 4 are front facing and 1 are down  facing | 4             |");
std::cout << std::endl;
display_green("| 5   | All are Front facing                      | 10            |");
std::cout << std::endl;
std::cout << std::endl;

display_green("When a player gets 1 which is also known as “DAA”, the player will get a chance to take his PAWN on the first position of  his side. \n \
This is similar to Ludo where 6 in a dice get one piece out on the board. If all the pieces are on the board and the  pocket is empty then it is considered as “one” to take one step on board. \
When a player gets 2,3,4,5 he has to move the PAWN 2,3,4,10 steps on the board respectively. When a player gets 1 or 5 cowries then he will get a second chance to throw the cowries.");

std::cout << std::endl;
std::cout << std::endl;




display_yellow("┳┓  ┓            ┓    ");std::cout << std::endl;
display_yellow("┣┫┓┏┃┏┓┏  ╋┏┓  ┏┓┃┏┓┓┏");std::cout << std::endl;
display_yellow("┛┗┗┻┗┗ ┛  ┗┗┛  ┣┛┗┗┻┗┫");std::cout << std::endl;
display_yellow("               ┛     ┛");std::cout << std::endl;

std::cout << std::endl;
std::cout << std::endl;

display_green("Each player will get single chance to throw or roll the cowries \
\n● Each player must get  'DAA' (1 cowry front facing and rest down facing) to get any 1 piece out from the pocket on  the start position of the board \
\n● Player can get PAWN or KING out from the pocket on the board's first position at any point of time when he gets 'DAA'\
\n● The opponent can kill your PAWN or KING when his PAWN or KING fall in your box. Sam as Ludo \
\n● If you have 2 or more PAWNs in one box then the opponent cant kill you but can stay in the same box. (This is  also valid for 1 KING and other PAWNS in same box) \
\n● If your PAWN or KING is in a safe box (cross marked boxes at corner) then the opponent can not kill you but can  stay in the same box. \
\n● If a player has not killed any of the opponent's PAWN or KING then he can't cross the 'Check Post'. \
\n● If opponents KING kill your KING then your all pieces on the board will get killed as well  \
\n● All killed pieces will be back to the player's pocket and has to get “DAA” again to put back on the board in the start  position. \
\nTo win this game, one has to pass all pieces from start to finish and get out of the board. Player 1's start is Player 2's finish  and vice versa.  \
");

std::cout << std::endl;
std::cout << std::endl;


display_red("Press q to to go back");

char c = get_char();

return c;

}


/**
 * @brief display the cowry menu, prompting user to throw the cowries
 * 
 * @param name name of the player
 * @return char this shoulf be 'f'
 */
char menu::display_cowry_menu(std::string_view name)
{
    std::cout << "\n";
    display_blue(name);
    display_yellow("'s turn:\n1. press 'f' to throw cowries: ");
    char c = get_char();

    return c;

}

/**
 * @brief display the menu options to player if she gets daa
 * 
 * @return char selected option by the user
 */
char menu::display_daa_menu()
{
    display_yellow("\n1. Press 'k' to take out king\n2. Press 'p' to take out pawn\n3. Press 'c' to skip daa: ");

    char c = get_char();

    return c;
}

/**
 * @brief display the possible pieces that a player can move after a cowry throw
 * 
 * @param moves vector of int holding the pieces no which can be moved (1-8 pawns, 9 king)
 * @return int user option selected, which piece number to move
 */
int menu::display_possible_moves(std::vector<int>& moves)
{
    display_yellow("Select a piece to move, 9 is king:\n");

    if(moves.empty())
    {
        display_yellow("No possible moves!\n");
        return 0;
    }

    while(!moves.empty())
    {
        int temp = moves.back();
        moves.pop_back();
        display_yellow("\t");
        display_yellow(temp);
    }
    std::cout << std::endl;

    int ch = get_int();

    return ch;

}

void menu::display_overlaps(std::vector<std::string>& s)
{
    if(s.empty())
    {
        return;
    }
    display_yellow("Overlapping Pieces: \n");
    for(auto& i: s)
    {
        display_yellow(i);
    }
    std::cout << std::endl;

    s.clear(); //Clear the set

    //Sleep for 3 secs
    usleep(2 * 1000000); // sleeps for 2 second
}

void menu::display_overlaps_set(std::set<int>& cp, int player_no)
{
    if(cp.empty())
    {
        return;
    }
    display_yellow("Overlapping Pieces: \n");
    for(auto& i: cp)
    {
        if(player_no == 1)
            display_red(i);
        else
            display_green(i);
        display_yellow(" <--> ");
    }
    std::cout << std::endl;

    cp.clear();

    

}

void win_menu(int no)
{
    menu m;
    if (no == 1)
    {

        m.display_yellow("██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗    ██╗    ██╗██╗███╗   ██╗███████╗");
        std::cout << std::endl;
        m.display_yellow("██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║    ██║    ██║██║████╗  ██║██╔════╝");
        std::cout << std::endl;
        m.display_yellow("██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║    ██║ █╗ ██║██║██╔██╗ ██║███████╗");
        std::cout << std::endl;
        m.display_yellow("██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║    ██║███╗██║██║██║╚██╗██║╚════██║");
        std::cout << std::endl;
        m.display_yellow("██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║    ╚███╔███╔╝██║██║ ╚████║███████║");
        std::cout << std::endl;
        m.display_yellow("╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚══════╝");
        std::cout << std::endl;
    }
    else
    {

        m.display_yellow("██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗     ██╗    ██╗██╗███╗   ██╗███████╗");std::cout << std::endl;
        m.display_yellow("██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗    ██║    ██║██║████╗  ██║██╔════╝");std::cout << std::endl;
        m.display_yellow("██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝    ██║ █╗ ██║██║██╔██╗ ██║███████╗");std::cout << std::endl;
        m.display_yellow("██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝     ██║███╗██║██║██║╚██╗██║╚════██║");std::cout << std::endl;
        m.display_yellow("██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗    ╚███╔███╔╝██║██║ ╚████║███████║");std::cout << std::endl;
        m.display_yellow("╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚══════╝");std::cout << std::endl;
    }
}


