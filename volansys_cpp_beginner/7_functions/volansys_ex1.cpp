/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 1 of Functions Lesson C++ Basic Course
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 1
 * This is a simple exercise. In this exercise, get your message from the command line and pass it as a string to the function which  will 
 * output the message.
 * Your function should also return a Boolean (type bool) indicating if the message was greater than 10 characters long or not. 
 * The main() routine should use this result to comment on the length of the message. 
 * Call your file function hellocmd.cpp and build it to the executable function program runs, it should be invocable from the command line with:
 *
 * $ ./function_hellocmd ’Hello Again World!!!’
 * Hello Again World!!! 
 * That was a long message. 
 *
 * $ ./function_hellocmd ’Hey!’ 
 * Hey! 
 * That was a short message.
 * 
 */
#include <iostream>
#include <string_view>

using namespace std;

bool msg_printer(string_view s)
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
                std::cout <<  "That was a long message.\n";
            }
            else
            {
                std::cout << "That was a short message.\n";
            }
        }
    }
    
 
    cout << endl;
    return 0;
}
