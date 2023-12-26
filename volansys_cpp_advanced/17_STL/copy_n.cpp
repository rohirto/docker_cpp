/**
 * @file copy_n.cpp
 * @author rohirto
 * @brief Demo of copy_n function in cpp
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * Time Complexity: O(n)
 * Auxiliary Space: O(n)
 */

// C++ code to demonstrate working of copy_n()
#include<iostream>
#include<algorithm> // for copy_n()
using namespace std;
int main()
{
	// Initializing array
	int ar[6] = {1, 2, 3, 4, 5, 6};

	// Declaring second array
	int ar1[6];

	// Using copy_n() to copy contents
	copy_n(ar, 6, ar1);

	// Displaying the copied array
	cout << "The new array after copying is : ";
	for (int i=0; i<6 ; i++)
	cout << ar1[i] << " ";

	return 0;

}
