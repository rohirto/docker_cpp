/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief  Exercise 2 of Functions Lesson C++ Basic Course
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 2
 * 
 * In this exercise, extend your previous program to have a message handling function with a default message of "Hello there. How are things?".
 *
*/

#include <iostream>
#include <string_view>

using namespace std;

bool msg_printer(string_view s = {"Hello there. How are things?"}) //Added a default message if no arg is passed to command line
{
    if (s.length() > 10)
    {
         std::cout << s << '\n';
        return true;
    }
    else
    {
         std::cout << s << '\n';
        return false;
    }
}

int main(int argc, char* argv[]) {

    if(argc > 1)
    {
        // There is a argument passed
        //  Loop through each argument and print its number and value
        for (int count{1}; count < argc; ++count)  //Count 0 will be program name
        {
            string_view s {argv[count]};

            if(msg_printer(s))
            {
                std::cout << "That was a long message.\n";
            }
            else
            {
                std::cout << "That was a short message.\n";
            }
        }
    }
    else
    {
        if (msg_printer())
        {
            std::cout << "That was a long message.\n";
        }
        else
        {
            std::cout << "That was a short message.\n";
        }
    }

    cout << endl;
    return 0;
}