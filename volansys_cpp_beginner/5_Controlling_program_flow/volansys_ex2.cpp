/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Exercise 2 of Controlling Program Flow exercise C++ Basic Course
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 2
 * Write code that uses a for loop to calculate the sum of the odd integers from 1 to 35, inclusive.
 * The final result should be stored in an integer variable named sum.
*/

#include <iostream>
using namespace std;

int calculate_sum() 
{
    //---- WRITE YOUR CODE BELOW THIS LINE
    int sum = 0;

    for (int i = 1; i <= 35; i += 2) 
    {
        sum += i;
    }
    
    //---- WRITE YOUR CODE ABOVE THIS LINE
 
    return sum;
}

int main()
{
	cout << "Sum of odd integers: " << calculate_sum() << endl;
	return 0;
}