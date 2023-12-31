/**
 * @file partition2.cpp
 * @author rohirto
 * @brief Demo of stable_partition and partition_point
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * In the below code, even and odd elements are partitioned and in the increasing order (sorted). Not always in increasing order 
 * though, here the elements (even and odd) appeared in increased order so is the result after partition. if vect would 
 * have been { 2,1,7,8,6,5 } after stable_partition() it would be  { 2,8,6,1,7,5 }. The order of appearance is maintained.
 * 
 */

// C++ code to demonstrate the working of 
// stable_partition() and partition_point()
#include<iostream>
#include<algorithm> // for partition algorithm
#include<vector> // for vector
using namespace std;
int main()
{
	// Initializing vector
	vector<int> vect = { 2, 1, 5, 6, 8, 7 };
	
	// partitioning vector using stable_partition()
	// in sorted order
	stable_partition(vect.begin(), vect.end(), [](int x)
	{
		return x%2 == 0;	 
	});
	
	// Displaying partitioned Vector
	cout << "The partitioned vector is : ";
	for (int &x : vect) cout << x << " ";
	cout << endl;
	
	// Declaring iterator
	vector<int>::iterator it1;
	
	// using partition_point() to get ending position of partition
	auto it = partition_point(vect.begin(), vect.end(), [](int x)
	{
		return x%2==0;
	});
	
	// Displaying partitioned Vector
	cout << "The vector elements returning true for condition are : ";
	for ( it1= vect.begin(); it1!=it; it1++)
	cout << *it1 << " ";
	cout << endl;
	
	return 0;
	
}
