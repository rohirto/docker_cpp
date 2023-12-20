/**
 * @file write_highscores.cpp
 * @author rohirto
 * @brief demo of file write in cpp
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/high_score.txt"
int main()
{
    ofstream file_writer(FILE_PATH);
    if (!file_writer.is_open())
    {
        cout << "Could not open file!" << '\n';
        return 0;
    }
    // since we don't have any real scores, we'll output the numbers 10 to 1
    for (int i = 0; i < 10; i++)
    {
        file_writer << 10 - i << '\n';
    }
    //Check highscore.txt
    file_writer.close();

    return 0;
}