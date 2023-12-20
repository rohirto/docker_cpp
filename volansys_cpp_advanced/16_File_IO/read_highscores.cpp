/**
 * @file read_highscores.cpp
 * @author rohirto
 * @brief Another read file demo
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/high_score.txt"

int main()
{
    ifstream file_reader(FILE_PATH);
    if (!file_reader.is_open())
    {
        cout << "Could not open file!" << '\n';
    }

    vector<int> scores;
    for (int i = 0; i < 10; i++)
    {
        int score;
        
        // here, we're checking if reading in an integer succeeded or not
        if (!(file_reader >> score)) //This checks for EOF, if end, then breaks the loop
        {
            break;
        }
        scores.push_back(score);
    }

    for(const int& i: scores)
    {
        cout << i << endl;
    }

    return 0;
}