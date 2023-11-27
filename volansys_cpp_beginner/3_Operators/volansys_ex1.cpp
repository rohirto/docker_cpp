/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 1 of Operators Lesson C++ Basic Course
 * @version 0.1
 * @date 2023-11-27 
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */
#include <iostream>
using namespace std;

int arithmetic_operators(int number) {
    int original_number {number};  //Backup of Original Value

    
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    //-- Multiply number by 2 and assign the result back to number
    number *= 2;

    //-- Add 9 to number and assign the result back to number
    number +=9;
    //-- Subtract 3 from number and assign the result back to number
    number -=3;
    //-- Divide number by 2 and assign the result back to number
    number /= 2;
    //-- Subtract original_number from number and assign the result back to number
    number -= original_number;
    //-- Take the modulus 3 (%) of number and assign it back to number
    number %=3;
 
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    
    return number;
}

int main() 
{
    int number;
    cout << "Enter Number: ";
    cin >> number;
    cout << "Original Number is: " << number << endl;
    cout << "Modified Number is: " << arithmetic_operators(number);
    return 0;
}