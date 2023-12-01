/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Exercise 2 of Pointers and References Lesson C++ Basic Lesson
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 2
 * 
 * Write a program to find out the greatest and the smallest among three numbers using pointers.
 */

#include <iostream>

using namespace std;

int main() {

    int *greatest = new int;
    int *smallest = new int;

    int input {};

    cout << "Enter 3 numbers\n";

    cin >> input;
    *greatest = input;
    *smallest = input;

    for(int i = 1; i < 3; i++)
    {
        cin >> input;

        if(input > *greatest)
        {
            *greatest = input;
        }
        else if(input < *smallest)
        {
            *smallest = input;
        }
    }

    cout << "Greatest: " << *greatest << endl << "Smallest: " << *smallest << endl;

    delete greatest;
    delete smallest;
    

	return 0;
}