/**
 * @file volansys_ex3.cpp
 * @author rohit S
 * @brief Challenge 9
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Challenge 9
 * // Challenge 9
 *
 * Word finder
 * 
 * Ask the user to enter a word
 * Process the Romeo and Juliet file and determine how many total words there are
 * and how many times the word the user entered appears as a substring of a word in the play.
 * 
 * For example.
 * If the user enters: love
 * Then the words love, lovely, and beloved will all be considered matches.
 * You decide whether you want to be case sensitive or not.
 *
 * Sample are some sample runs:
 *
 * Enter the substring to search for: love
 * 25919 words were searched...
 * The substring love was found 171 times
 *
 * Enter the substring to search for: Romeo
 * 25919 words were searched...
 * The substring Romeo was found 132 times
 *
 * Enter the substring to search for: Juliet
 * 25919 words were searched...
 * The substring Juliet was found 49 times
 * 
 * Enter the substring to search for: Frank
 * 25919 words were searched...
 * The substring Frank was found 0 times
 *
 *Have fun!
*/
// Word counter


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/romeoandjuliet.txt"

int main() 
{
    std::ifstream file(FILE_PATH);

    if (!file.is_open()) 
    {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string userSubstring;
    std::cout << "Enter the substring to search for: ";
    std::cin >> userSubstring;

    // Convert userSubstring to lowercase for case-insensitive comparison
    std::transform(userSubstring.begin(), userSubstring.end(), userSubstring.begin(), ::tolower);

    std::string word;
    int totalWords = 0;
    int substringCount = 0;

    while (file >> word) 
    {
        // Convert the word to lowercase for case-insensitive comparison
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Check if the userSubstring is a substring of the current word
        if (word.find(userSubstring) != std::string::npos) 
        {
            ++substringCount;
        }

        ++totalWords;
    }

    std::cout << totalWords << " words were searched..." << std::endl;
    std::cout << "The substring " << userSubstring << " was found " << substringCount << " times" << std::endl;

    file.close();

    return 0;
}

