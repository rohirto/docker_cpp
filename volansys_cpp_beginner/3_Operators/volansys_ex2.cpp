/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Challenge 2 in C++ Basic Course (Operators Lesson)
 * @version 0.1
 * @date 2023-11-27
 *
 * @copyright Copyright (c) 2023
 *
 * @paragraph : Challenge 2
 * For this program I will be using Indian Rupees.
 *
 * Write a program that asks the user to enter the following:
 * An integer representing the number of Rupees
 *
 *
 * You may assume that the number of Rupees entered is greater than or equal to zero
 *
 * The program should then display how to provide that change to the user.

 * In the India Rupees, Valid currencies are:
 *     2000 Rs
 *     500  Rs
 *     200  Rs
 *     100  Rs
 *     50   Rs
 *     20   Rs
 *     10   Rs
 *     5    Rs
 *     2    Rs
 *     1    Rs
 * 
 *     Here is a sample run:
 * 
 *   Enter an amount in Rupees :  92
 * 
 *   You can provide this change as follows:
 *   50's    : 1
 *   20's    : 2
 *   2's     : 1 
 * 
 *  Also, think of how you might solve the problem using the modulo operator.
 * 
 *  Have fun and test your program!!
 *
 */

#include <iostream>

using namespace std;

int main() {

    int amount;
    const int denominations[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    

    cout << "Enter an amount in Rupees: " ;
    cin >> amount;
    cout << endl;

    for (int i = 0; i < 10; ++i) 
    {
        int count = amount / denominations[i];
        if (count > 0) 
        {
            cout << denominations[i] << "'s\t: " << count << endl;
            amount %= denominations[i];
        }
    }

    
    cout << endl;
    return 0;
}
