/**
 * @file read_file2.cpp
 * @author rohirto
 * @brief demo of file read
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

    std::string mystring;


    std::cout << "Raw reading: \n";  
    if ( myfile.is_open() ) //Raw reading, ignoreing the whitespaces
    {     
        while ( myfile.good() ) 
        {
            myfile >> mystring;
            std::cout << mystring;
        }       
    }

    
}