/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 1 for Pointers and references Lesson C++ Basic Course
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023 Volanys Technologies
 * 
 * @paragraph Exercise 1
 * 
 * Write a function which will take pointer and display the number on screen. Take number from user and print it on screen using that function.
 *
 */

#include <iostream>

using namespace std;

//----WRITE YOUR FUNCTION PROTOTYPES BELOW THIS LINE----

void DisplayNumber(const int *);

//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----

int main() {
    int num;
	cout << "Enter the number: " << endl;
	cin >> num;
	DisplayNumber(&num);
	return 0;
}

void DisplayNumber(const int *num)
{
    cout << "Entered number :" << *num << endl;
}

