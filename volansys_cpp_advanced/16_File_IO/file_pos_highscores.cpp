/**
 * @file file_pos_highscores.cpp
 * @author rohirto
 * @brief demo of File Position seeking in cpp
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//This C++ program opens a file in both read and write modes and inserts a new high score in a sorted list of scores in the file. 

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/high_score.txt"


int main()
{
    fstream file(FILE_PATH, ios::in | ios::out); //Additional flags for stream to signify read and write, note we are using fstream (not ifstream, ofstream)
    if (!file.is_open())
    {
        cout << "Could not open file!" << '\n';
        return 0;
    }

    int new_high_score;
    cout << "Enter a new high score: ";
    cin >> new_high_score;

    // the while loop below searches the file until it finds a value
    // less than the current high score; at this point, we know we
    // want to insert our high score right before that value. To make
    // sure that we know the right position, we keep track of the
    // position prior to the current score; the pre_score_pos
    streampos pre_score_pos = file.tellg();
    int cur_score;
    while (file >> cur_score) //This op will increment the file stream
    {
        if (cur_score < new_high_score)
        {
            break;
        }
        pre_score_pos = file.tellg(); //This gives the position of cursor
    }
    // if fail is true, and we aren't at eof, there was some bad input
    if (file.fail() && !file.eof())
    {
        cout << "Bad score/read--exiting";
        return 0;
    }

    // without calling clear, we won't be able to write to the file if
    // we hit eof
    file.clear(); //Clears the file stream flags
    // return to the point right before the last score we read, for reading
    // so that we can read in all the scores that are less than our
    // high score, and move them one position later in the file
    file.seekg(pre_score_pos);  //Seek get
    // now we will read in all the scores, starting with the one we
    // previously read in
    vector<int> scores;
    while (file >> cur_score)
    {
        scores.push_back(cur_score);
    }
    // we expect to reach the end of file via this read loop because we
    // want to read in all scores in the file
    if (!file.eof())
    {
        cout << "Bad score/read--exiting";
        return 0;
    }
    // since we hit eof, we need to clear the file again so that we can
    // write to it
    file.clear();
    // see back to the position we want to do our insert
    file.seekp(pre_score_pos); //Seek put
    // if we are not writing to the beginning of the file, we need to
    // include a newline. The reason is that when a number is read in
    // it stops at the first whitepsace, so the position we are at
    // prior to writing is at the end of the number rather than
    // at the start of the next line
    if (pre_score_pos != 0)
    {
        file << endl;
    }
    // write out our new high score
    file << new_high_score << endl;
    // loop through the rest of the scores, outputting all of them
    for (vector<int>::iterator itr = scores.begin(); itr != scores.end();
         ++itr)
    {
        file << *itr << endl;
    }
}