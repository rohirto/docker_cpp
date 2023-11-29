/**
 * @file volansys_ex3.cpp
 * @author rohit S
 * @brief Exercise 3 of Controlling Program Flow Lesson C++ Basic Course
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * Use a range-based for loop to loop through a given vector of integers and determine how many elements in the vector are evenly 
 * divisible by either 3 or by  5.
 * The final result should be stored in an integer variable named count.
*/

#include <vector>
#include <bits/stdc++.h>
using namespace std;

int count_divisible() {
    
    vector<int> vec {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700};
    //---- WRITE YOUR CODE BELOW THIS LINE----
    int count = 0;
    for(int x: vec)
    {
        if((x%3 == 0) || ( x%5 == 0 ))
        {
            count++;
        }
    }
    
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    return count;
}

int main() 
{
    int number;
    cout << "No of elements evenly divisible by either 3 or by 5: " << count_divisible() << endl;
    
    return 0;
}