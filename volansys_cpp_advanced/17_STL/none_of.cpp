/**
 * @file none_of.cpp
 * @author rohirto
 * @brief Demo of none_of function in cpp STL
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * Time Complexity: O(n)
 * Auxiliary Space: O(1)
 * 
 */

// C++ code to demonstrate working of none_of()
#include<iostream>
#include<algorithm> // for none_of()
using namespace std;
int main()
{
	// Initializing array
	int ar[6] = {1, 2, 3, 4, 5, 6};

	// Checking if no element is negative
	none_of(ar, ar+6, [](int x){ return x<0; })?
		cout << "No negative elements" :
		cout << "There are negative elements";

	return 0;
}
