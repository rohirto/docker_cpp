/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 1 of Characters and string lesson of C++ Basic Course
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 1
 * In this exercise you will create a program that determines the length of a first name and last name individually and then the length of 
 * the entire name through the use of the C-style string functions strlen, strcpy, and strcat.
 * 
 * Begin by declaring and initializing the C-style string variable first_name to contain "Bjarne".
 * Now, declare and initialize a second C-style string variable last_name to contain "Stroustrup".
 * You must also declare a third C-style string variable whole_name but do not initialize it yet. 
 * Remember that the variable whole_name must be large enough to contain the first and last name with no whitespaces.
 * 
 * Now, by using the C-style string function strlen, declare and initialize the variable first_name_length to contain the length 
 * of the first_name string and the variable last_name_length to contain the length of the last_name string.
 * 
 * Using the C-style string function strcpy, copy the first_name string into the whole_name string variable.
 * Now, by using the C-style string function strcat, concatenate the last_name string at the end of the whole_name string.
 * Finally, by using the C-style string function strlen, declare and initialize the variable whole_name_length to contain the 
 * length of the whole_name string.
*/

#include <iostream>
#include <cstring>  //C style strings functions defns

int main()
{
    char first_name[] {"Bjarne"};
    char last_name[] {"Stroustrup"};
    char whole_name[255] {};

    int first_name_len = std::strlen(first_name);
    int last_name_len = std::strlen(last_name);

    std::strcpy(whole_name,first_name);
    std::strcat(whole_name,last_name);

    int whole_name_len = std::strlen(whole_name);

    std::cout << "First name len : " << first_name_len << "\nlast name len: " << last_name_len << "\nwhole name len: " << whole_name_len << std::endl;
    return 0;
}
