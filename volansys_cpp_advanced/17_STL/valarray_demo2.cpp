/**
 * @file valarray_demo2.cpp
 * @author rohirto
 * @brief Demo of valarray shift and cshift
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

// C++ code to demonstrate the working of
// shift() and cshift()
#include<iostream>
#include<valarray> // for valarray functions
using namespace std;
int main()
{
	// Initializing valarray
	valarray<int> varr = { 10, 2, 20, 1, 30 };
	
	// Declaring new valarray
	valarray<int> varr1;
	
	// using shift() to shift elements to left
	// shifts valarray by 2 position
	varr1 = varr.shift(2);
	
	// Displaying elements of valarray after shifting
	cout << "The new valarray after shifting is : ";
	for ( int&x : varr1) cout << x << " ";
	cout << endl;
	
	// using cshift() to circularly shift elements to right
	// rotates valarray by 3 position
	varr1 = varr.cshift(-3);
	
	// Displaying elements of valarray after circular shifting
	cout << "The new valarray after circular shifting is : ";
	for ( int&x : varr1) cout << x << " ";
	cout << endl;

	return 0;
	
}
