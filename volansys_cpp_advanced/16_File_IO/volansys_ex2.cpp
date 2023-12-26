/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Challenge 8 of C++ Advance
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * @paragraph Challenge 8
 * 
 * // Challenge 8
Automated Grader

Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
as well as student responses for the quiz.

The answer key is the first item in the file.
Student1 name
Student1 responses
Student2 name
Student2 responses
. . .

Here is a sample file.

ABCDE                  
Frank                     
ABCDE                  
Larry
ABCAC
Moe
BBCDE
Curly
BBAAE
Michael
BBCDE

You should read the file and display:
Each student's name and score (#correct out of 5)
At the end, the class average should be displayed
You may assume that the data in the file is properly formatted

Program should output to the console the following:
Student                     Score 
----------------------------
Frank                             5
Larry                              3
Moe                              4
Curly                             2
Michael                         4
---------------------------
Average score            3.6

*/
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cstdio>

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/responses.txt"

using namespace std;

class student{
private:
    string name;
    int score;
    
public:
    student():score(0){}  //Initialize with zero score

    vector<char> responses;

    void set_name(const string& s)
    {
        name = s;
    }
    std::string get_name()
    {
        return name;
    }
    int get_score()
    {
        return score;
    }

    void get_responses(const string& r)
    {
        for (char ch : r)
        {
            responses.push_back(ch);
        }

    }

    void calculate_score(const vector<char>& ca)
    {
        for(size_t i = 0; i < ca.size(); i++)
        {
            if(ca[i] == responses[i])
            {
                //correct
                score++;

            }
        }

        //cout << name << " score: " << score << endl;
    }

};

void print_scores(vector<student>& sts)
{
    std::cout << std::setw(15) <<std::left << "Student"
              << std::setw(15) <<std::left << "Scores"
              << endl;
    const char last_fill = cout.fill('-');
    std::cout << std::setw(30) << std::right<< "\n" ;
    cout.fill( last_fill );  //Resets the fill to spaces

    for(size_t i = 0 ; i < sts.size(); i++)
    {
        std::cout << std::setw(15)<< std::left << sts[i].get_name()
                  << std::setw(15) << std::left << sts[i].get_score()
                  << endl;
    }
    cout.fill('-');
    std::cout << std::setw(30) << std::right<< "\n" ;
    cout.fill( last_fill );  //Resets the fill to spaces
}

int main() {
    
    static std::streampos current_pos = 0;

    std::ifstream myfile; 
    myfile.open(FILE_PATH);
    vector<char> correct_resp;
    vector<student> sts;


    std::cout << "reading through getline(): \n";
    std::string myline;

    if (myfile.is_open())
    {

        // read the first line
        std::getline(myfile >> std::ws, myline) >> std::ws; // neglect trailing whitespaces

        // Iterate through each character in the string and push it into the vector
        for (char ch : myline)
        {
            if(ch == ' ')
                continue;
            correct_resp.push_back(ch);
        }

        current_pos = myfile.tellg();

        while (current_pos != std::streampos(-1)) // end of file
        {
            student temp;
            //read student data 
            std::getline(myfile >> std::ws, myline);   // neglect trailing whitespaces
            // Remove whitespaces from the string
            myline.erase(std::remove_if(myline.begin(), myline.end(), ::isspace), myline.end());

            temp.set_name(myline);  //Set name

            // read the responses
            std::getline(myfile >> std::ws, myline) >> std::ws; // neglect trailing whitespaces
            temp.get_responses(myline);

            //calculate score
            temp.calculate_score(correct_resp);

            sts.push_back(temp);

            current_pos = myfile.tellg();

        }
    }

    myfile.close();

    print_scores(sts);

    cout << "Hello world" << endl;
    return 0;
}
