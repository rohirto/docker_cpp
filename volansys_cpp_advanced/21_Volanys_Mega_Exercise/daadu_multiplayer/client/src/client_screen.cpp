/**
 * @file client_screen.cpp
 * @author rohirto
 * @brief Client Screen Module
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include  <bits/stdc++.h> 
#include <limits>
#include "client_screen.h"

/**
 * @brief get valid char from user
 * 
 * @return char c from user input
 */
char client_screen::get_char()
{
    char ch;

    std::cin >> ch;

    while (!isalpha(ch))
    {
        std::cin.clear();                                                   // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        display_red("\n Invalid entry try again: ");
        std::cin >> ch;
    }

    return ch;
}

/**
 * @brief get a valid int from user
 * 
 * @return int c from user input
 */
int client_screen::get_int()
{
    int ch;

    std::cin >> ch;

    while(!std::cin.good())
    {
        display_red("Invalid Input, try again: ");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> ch;
    }

    return ch;
}

/**
 * @brief get a valid string from user
 * 
 * @return std::string object from user input
 */
std::string client_screen::get_string()
{
    std::string s;

    std::getline(std::cin >> std::ws,s);

    return s;


}

