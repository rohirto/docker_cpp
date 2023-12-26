/**
 * @file array_demo.cpp
 * @author rohirto
 * @brief Demo of C++ Arrays in stl, this are different than C styled arrays
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ code to demonstrate working of array,
// at() and get()
#include<iostream>
#include<array> // for array, at()
#include<tuple> // for get()
using namespace std;
int main()
{
	// Initializing the array elements
	array<int,6> ar = {1, 2, 3, 4, 5, 6};

	// Printing array elements using at()
	cout << "The array elements are (using at()) : ";
	for ( int i=0; i<6; i++)
	    cout << ar.at(i) << " ";
	cout << endl;

	// Printing array elements using get()
	cout << "The array elements are (using get()) : ";
	cout << get<0>(ar) << " " << get<1>(ar) << " ";
	cout << get<2>(ar) << " " << get<3>(ar) << " ";
	cout << get<4>(ar) << " " << get<5>(ar) << " ";
	cout << endl;

	// Printing array elements using operator[]
	cout << "The array elements are (using operator[]) : ";
	for ( int i=0; i<6; i++)
	    cout << ar[i] << " ";
	cout << endl;



    // C++ code to demonstrate working of
    // front() and back()
     // Printing first element of array
    cout << "First element of array is : ";
    int &a=ar.front();
    cout <<a<< endl;
 
    // Printing last element of array
    cout << "Last element of array is : ";
    int &b=ar.back();
    cout << b << endl;
      
    //change first and last element of array using these references
    a=10; //now 1 change to 10
    b=60; //now 6 change to 60
     
    //lets print array now 
    cout<<"array after updating first and last element \n";
    for (auto x: ar)
    {
      cout<<x<<" ";
    }
    cout<<endl;



    // C++ code to demonstrate working of
    // size() and max_size()
     // Printing number of array elements
    cout << "The number of array elements is : ";
    cout << ar.size() << endl;
 
    // Printing maximum elements array can hold
    cout << "Maximum elements array can hold is : ";
    cout << ar.max_size() << endl;



    // C++ code to demonstrate working of swap()

    // Initializing 2nd array
    array<int,6> ar1 = {7, 8, 9, 10, 11, 12};
 
    // Printing 1st and 2nd array before swapping
    cout << "The first array elements before swapping are : ";
    for (int i=0; i<6; i++)
        cout << ar[i] << " ";
    cout << endl;
    cout << "The second array elements before swapping are : ";
    for (int i=0; i<6; i++)
        cout << ar1[i] << " ";
    cout << endl;
 
    // Swapping ar1 values with ar
    ar.swap(ar1);
 
    // Printing 1st and 2nd array after swapping
    cout << "The first array elements after swapping are : ";
    for (int i=0; i<6; i++)
        cout << ar[i] << " ";
    cout << endl;
    cout << "The second array elements after swapping are : ";
    for (int i=0; i<6; i++)
        cout << ar1[i] << " ";
    cout << endl;

	return 0;

}
