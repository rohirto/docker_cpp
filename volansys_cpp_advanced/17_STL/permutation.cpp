/**
 * @file permutation.cpp
 * @author rohirto
 * @brief Demo of next_permutation, prev_permutation in cpp
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * A permutation is specified as each of several possible ways in which a set or number of things can be ordered or arranged. 
 * It is denoted as N! where N = number of elements in the range.
 * 
 * The next_permutation algorithm changes the order of the elements in the range [first, last) to the next lexicographic permutation 
 * and returns true. If there is no next_permutation, it arranges the sequence to be the first permutation and returns false.
 * 
 * It is used to rearrange the elements in the range [first, last) into the previous lexicographically-ordered permutation
 */
// C++ program to demonstrate working 
// of next_permutation()
// and prev_permutation()
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

	cout << "Given Vector is:\n";
	for (int i=0; i<n; i++)
		cout << vect[i] << " ";

	// modifies vector to its next permutation order
	next_permutation(vect.begin(), vect.end());
	cout << "\nVector after performing next permutation:\n";
	for (int i=0; i<n; i++)
		cout << vect[i] << " ";

	prev_permutation(vect.begin(), vect.end());
	cout << "\nVector after performing prev permutation:\n";
	for (int i=0; i<n; i++)
		cout << vect[i] << " ";

	return 0;
}
