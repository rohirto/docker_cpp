/**
 * @file iota.cpp
 * @author rohirto
 * @brief Demo of iota in cpp STL
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * Time Complexity: O(n)
 * Auxiliary Space: O(1)
 */

// C++ code to demonstrate working of iota()
#include<iostream>
#include<numeric> // for iota()
using namespace std;
int main()
{
	// Initializing array with 0 values
	int ar[6] = {0};

	// Using iota() to assign values
	iota(ar, ar+6, 20);

	// Displaying the new array
	cout << "The new array after assigning values is : ";
	for (int i=0; i<6 ; i++)
	cout << ar[i] << " ";

	return 0;

}
