/**
 * @file read_file4.cpp
 * @author rohirto
 * @brief demo of file reading using getline
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <string>

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/test.txt"

int main () 
{
    std::ifstream myfile; 
    myfile.open(FILE_PATH);

    std::cout << "reading through getline(): \n";
    std::string myline;
    if (myfile.is_open())
    {
        while (myfile)
        {
            std::getline(myfile, myline);
            std::cout << myline << ": " << myfile.tellg() << '\n';  //Tells about the cursor position
        }
    }
    else
    {
        std::cout << "Couldn't open file\n";
    }

    myfile.close();

    return 0;
}