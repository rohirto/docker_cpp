/**
 * @file distance.cpp
 * @author rohirto
 * @brief demo of distance in STL
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to demonstrate working of distance()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Initializing vector with array values
	int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n);

	// Return distance of first to maximum element
	cout << "Distance between first to max element: "; 
	cout << distance(vect.begin(),
					max_element(vect.begin(), vect.end()));
	return 0;
}
