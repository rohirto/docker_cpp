/**
 * @file valarray_demo.cpp
 * @author rohirto
 * @brief Demo of valarray apply and sum, max and min
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * Apply and sum
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Max and min
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 */
// C++ code to demonstrate the working of
// apply() and sum()
#include<iostream>
#include<valarray> // for valarray functions
using namespace std;
int main()
{
	// Initializing valarray
	valarray<int> varr = { 10, 2, 20, 1, 30 };
	
	// Declaring new valarray
	valarray<int> varr1 ;
	
	// Using apply() to increment all elements by 5
	varr1 = varr.apply([](int x){return x=x+5;});
	
	// Displaying new elements value
	cout << "The new valarray with manipulated values is : ";
	for (int &x: varr1) cout << x << " ";
	cout << endl;
	
	// Displaying sum of both old and new valarray
	cout << "The sum of old valarray is : ";
	cout << varr.sum() << endl;
	cout << "The sum of new valarray is : ";
	cout << varr1.sum() << endl;

    // Displaying largest element of valarray
    cout << "The largest element of valarray is : ";
    cout << varr.max() << endl;
     
    // Displaying smallest element of valarray
    cout << "The smallest element of valarray is : ";
    cout << varr.min() << endl;

	return 0;
	
}
