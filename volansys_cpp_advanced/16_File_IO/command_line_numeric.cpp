/**
 * @file command_line_numeric.cpp
 * @author rohirto
 * @brief Demo of taking numeric inputs from the command line
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
//this program reads a command line argument, converts it to a number, and prints the square of that number

#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // when printing out usage instructions, you can use
        // argv[ 0 ] as the file name
        cout << "usage: " << argv[0] << " <number>" << endl;
    }
    else
    {
        int val = atoi(argv[1]); //The atoi function takes a char * and returns the integer represented by the string, 
                                 // and you must include the cstdlib header to use it
        cout << val * val;
    }
    return 0;
}