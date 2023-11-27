/**
 * @file volansys_ex4.cpp
 * @author rohit S
 * @brief Challenge 1 of Arrays and Vector C++ Basic
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @brief Write a C++ program as follows:
 *
 * - Declare 2 empty vectors of integers named vector1 and vector2, respectively.
 * - Add 10 and 20 to vector1 dynamically using push_back.
 * - Display the elements in vector1 using the at() method as well as its size using the size() method.
 * 
 * - Add 100 and 200 to vector2 dynamically using push_back.
 * - Display the elements in vector2 using the at() method as well as its size using the size() method.
 * 
 * - Declare an empty 2D vector called vector_2d.
 *   Remember, that a 2D vector is a vector of vector<int>.
 * 
 * - Add vector1 to vector_2d dynamically using push_back.
 * - Add vector2 to vector_2d dynamically using push_back.
 * 
 * - Display the elements in vector_2d using the at() method.
 * 
 * - Change vector1.at(0) to 1000.
 * 
 * - Display the elements in vector_2d again using the at() method.
 * 
 * - Display the elements in vector1.
 * 
 * - What did you expect? Did you get what you expected? What do you think happened?
 *   -  
 *
 * 
 */
#include <bits/stdc++.h>




using namespace std;

//Func Prototypes
void print_vector(std::vector<int>&A);
void print_2d_vector(std::vector<std::vector<int>>&A);

int main() {
    
    // your solution goes here

    //Part 1
    vector<int> vector1;
    vector<int> vector2;
    vector1.push_back(10);
    vector1.push_back(20);

    print_vector(vector1);
    //Display size
    cout << vector1.size();
    cout <<endl;

    //Part 2
    vector2.push_back(100);
    vector2.push_back(200);
    print_vector(vector2);
    //Display size
    cout << vector2.size();
    cout <<endl;

    //Part 3 - 2D Vector
    // Declare an empty 2D vector called vector_2d
    vector<vector<int>> vector_2d;
     // Add vector1 to vector_2d dynamically using push_back
    vector_2d.push_back(vector1);  //Here we are passing a copy of vector1 in 2D array, thus any change made to vector1 will not be reflected in verctor2d

    // Add vector2 to vector_2d dynamically using push_back
    vector_2d.push_back(vector2);

    //Display elements
    // Display the elements in vector_2d using the at() method and for loops
    print_2d_vector(vector_2d);

    // Change vector1.at(0) to 1000
    vector1.at(0) = 1000; //Vector 1 is modified and vector 2d is not modified

    // Display the elements in vector_2d again using the at() method
    print_2d_vector(vector_2d);

    // Display the elements in vector1
    print_vector(vector1);

    cout << "Here vector 1 is changed but vector 2d is not changed, because in push_back() passes a copy" << endl;

    //Other Method
    // // Change vector1.at(0) to 10
    // vector1.at(0) = 10; 

    // // Iterator for the 2-D vector.
    // vector<vector<int>>::iterator it1 = vector_2d.begin(); //Start of array at it

    // // Iterator for each vector inside the 2-D vector.
    // vector<int>::iterator it2;

    // // Traversing a 2-D vector using iterators.
    // for(it1 = vector_2d.begin();it1 != vector_2d.end();it1++)
    // {
    //     for(it2 = it1->begin();it2 != it1->end();it2++)
    //     {
    //         cout<<*it2<<" ";
    //     }
    //     cout<<endl;
    // }   




    cout << endl;
    return 0;
}

void print_vector(std::vector<int>&A)
{
    for (size_t i = 0; i < A.size(); ++i)
    {
        cout << A.at(i);  //Print using at
        cout << " ";
    }
    cout << endl;

}

void print_2d_vector(std::vector<std::vector<int>>&A)
{
    for (size_t i = 0; i < A.size(); ++i) 
    {
        for (size_t j = 0; j < A[i].size(); ++j) 
        {
            cout << A.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    cout << endl;
}