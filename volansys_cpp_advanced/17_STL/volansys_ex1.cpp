/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Challenge 10 of C++ Advance
 * @version 0.1
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Challenge 10
 * A Palindrome is a string that reads the same backwards or forwards.
    Simple examples are:
    madam
    bob
    toot
    radar

    An entire phrase can also be a palindome, for example:
    A Toyota's a toyota
    A Santa at NASA
    A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!

    For the purposes of this assignment we will only consider alpha characters and omit all other characters.
    We will also not be considering case.
    So,
    A Santa at Nasa, will be processed as:
    ASANTAATNASA

    A common method to solve this problem is to compare the string to its reverse and
    if the are equal then it must be a palindrome. But we will use a deque.

    I am providing the main driver for you which will automatically run several test cases.
    You challenge is to write the following function:

    bool is_palindrome(const std::string &s) {

    This function will expect a string and it must determine if that string is a palindrome and return true if it is, or false if it is not.

    So,

    is_palindrome("A Santa at Nasa");   will return true 
    is_palindrome("Hello");   will return false

    Please use a deque to solve the problem.

    Good luck and have fun!
 * 
 */

// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> pali;

    for(char ch: s)
    {
        ch = std::toupper(ch); // Change to upper case
        if(isalpha(ch))
            pali.push_back(ch);    // Add the characters to deque
        
    } //O(n)

    //pali.insert(pali.end(), s.begin(), s.end());  //O(n)


    std::deque<char>::iterator it = pali.begin();
    std::deque<char>::reverse_iterator rit = pali.rbegin();

    for (size_t i = 0; i < pali.size() / 2; i++)
    {
        if (*it != *rit)
        {
            return false;
        }
        ++it;
        ++rit;
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}