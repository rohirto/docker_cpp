/**
 * @file read_file.cpp
 * @author rohirto
 * @brief Example of Read File
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <fstream>
#include <iostream>
using namespace std;

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/read_number.txt"

int main()
{
    ifstream file_reader(FILE_PATH); // Searches for this file in working directory
    if (!file_reader.is_open())      // Checks if the file exists, and is opened or not
    {
        cout << "Could not open file!" << '\n'; // In this case the file does not exists
    }

    int number;
    // here, we're checking if reading in an integer succeeded or not
    if (file_reader >> number)
    {
        cout << "The value is: " << number;
    }
    else
    {
        cout << "No number could be read!";
    }

    return 0;
}