/**
 * @file volansys_ex4.cpp
 * @author rohit S
 * @brief Exercise 4 of Controlling Program Flow Lesson C++ Basic Course
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * @paragraph Exercise 4
 * 
 * Given a vector of integers vec, determine how many integers are present before you see the value -99 . 
 * Note, it's possible -99  is not in the vector! If -99  is not in the vector then the result will be equal to the number of elements in the vector.
 * The final result should be stored in an integer variable named count .
*/

#include<bits/stdc++.h>
using namespace std;

int count_numbers( const vector<int> &vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    int count = 0;

    // Iterate through the vector until -99 is encountered or the end of the vector is reached
    for (long unsigned int i = 0; i < vec.size() && vec[i] != -99; ++i) 
    {
        count++;
    }
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT MODIFY THE CODE BELOW THIS LINE----
    return count;
}

//main function
int main() {
   int in;
   vector<int> vec;
   
   // user can add element as much as they want. Enter any non-integer to end the loop!
   while(cin>>in)
   { 
       vec.push_back(in);
   }
   for(auto &p : vec)
   {
      cout<<p<<" ";
   }
   cout<<endl;
   
   cout << "Number of Elements before -99: " << count_numbers(vec) << endl;
   
   return 0;
}
