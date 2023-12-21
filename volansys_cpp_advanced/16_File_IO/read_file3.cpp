/**
 * @file read_file3.cpp
 * @author rohirto
 * @brief Demo of read with get()
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


    std::cout << "reading through get(): \n";
    if (myfile.is_open())
    {
        while (myfile)
        {
            char mychar;
            mychar = myfile.get();
            std::cout << mychar;
        }
    }
}