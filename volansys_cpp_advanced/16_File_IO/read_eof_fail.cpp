/**
 * @file read_eof_fail.cpp
 * @author rohirto
 * @brief Demo of how to use eof() method and fail() method during file reading
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <string>

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/sample.txt"

int main() {
    // Open a file for reading
    std::ifstream inputFile(FILE_PATH);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    // Read data from the file until the end of the file
    while (!inputFile.eof()) {
        std::string line;
        // Read a line from the file
        getline(inputFile, line);

        // Check for errors
        if (inputFile.fail()) {
            // Handle read error
            std::cerr << "Error reading from the file!" << std::endl;
            // Clear the error state to continue reading
            inputFile.clear();
        } else {
            // Process the read data
            std::cout << "Read line: " << line << std::endl;
        }
    }

    // Close the file
    inputFile.close();

    return 0;
}
