/**
 * @file volansys_ex3.cpp
 * @author rohit S
 * @brief Exercise 3 of C++ Basic course
 * @version 0.1
 * @date 2023-11-27 Volansys Technologies
 * 
 * @copyright Copyright (c) 2023
 * 
 * @paragraph Exercise 3
 * Excercise 3:
 * Write code using cin and the extraction operator >> to allow a user to enter their date of birth. 
 * Declare the int variable m represents the month, d represents the day, and y represents the year. 
 * Assume that the user will enter their date of birth in the order of month, day, year, with each value being separated by a white space.
 * 
 */

#include <iostream>

using namespace std;

int main()
{
    int m,d,y;

    cout << "Enter DoB (mm): ";
    cin >> m;
    cout << endl;

    cout << "Enter DoB (dd): ";
    cin >> d;
    cout << endl;

    cout << "Enter DoB (yyyy): ";
    cin >> y;
    cout << endl;

    cout << "DoB: " << m << "/" << d << "/" << y <<endl;
    


    return 0;
}