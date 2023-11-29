/**
 * @file volansys_ex5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * @paragraph: Exercise 5
 * Given a vector of integers named vec  that is provided for you, find the sum of the product of all pairs of vector elements.
 * You should declare an integer variable named result  and store the final product in this variable.
 * 
 * For example, given the vector  vec  to be {1, 2 , 3} , the possible pairs are (1,2), (1,3), and (2,3) . 
 * So the result would be (1*2) + (1*3) + (2*3)  which is 11 .

 * Another example:
 * Given the vector vec  to be {2, 4, 6, 8} , the possible pairs are (2,4), (2,6), (2,8), (4,6), (4,8), and (6,8) .
 * So the result would be (2*4) + (2*6) + (2*8) + (4*6) + (4*8) + (6*8) which is 140 .
 * 
 * If the vector is empty or has only 1  element then the result  should be 0 .
 * 
 */



#include <iostream>
#include <vector>
using namespace std;

int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    int result = 0;
    if (vec.size() > 1)
    {
        for (size_t i = 0; i < vec.size(); ++i)
        {
            for (size_t j = i + 1; j < vec.size(); ++j)
            {
                result += vec[i] * vec[j];
            }
        }
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
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
   
   cout << "The sum of the product of all pairs of vector elements: " << calculate_pairs(vec) << endl;
   
   return 0;
}