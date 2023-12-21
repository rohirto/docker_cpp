/**
 * @file command_line_args.cpp
 * @author rohirto
 * @brief Demo of Command Line Arguments Passing to C++ Program
 * @version 0.1
 * @date 2023-12-21
 *
 * @copyright Copyright (c) 2023
 *
 */

//This code takes filename to be opened as a argument
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])  //argc - no of args, argv - array of args
{
    // argc should be 2 for correct execution, the program name
    // and the filename
    if (argc != 2)
    {
        // when printing out usage instructions, you can use
        // argv[ 0 ] as the file name
        cout << "usage: " << argv[0] << " <filename>" << endl;
    }
    else
    {
        // We assume argv[ 1 ] is a filename to open
        ifstream the_file(argv[1]);
        // Always check to see if file opening succeeded
        if (!the_file.is_open())
        {
            cout << "Could not open file " << argv[1] << endl;
            return 1;
        }
        char x;
        // the_file.get( x ) reads the next character from the file
        // into x, and returns false if the end of the file is hit
        // or if an error occurs
        while (the_file.get(x))
        {
            cout << x;
        }
    } // the_file is closed implicitly here by its destructor
}