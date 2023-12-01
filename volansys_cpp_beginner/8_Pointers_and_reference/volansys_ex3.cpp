/**
 * @file volansys_ex3.cpp
 * @author rohit S
 * @brief Exercise 3 of Pointers and References Lesson  C++ Basics
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 3
 * 
 * Write a function which takes two int reference argument and swap the values.
 * 
 */

#include <iostream>

using namespace std;

void swap(int& a, int& b)  //Swap without 3rd int
{
    a = a+b;
    b = a-b;
    a = a-b;
}

int main() {

    int a = 3, b = 2;

    swap(a,b);

    cout << "a = " << a << " b = " << b << endl;

	return 0;
}

