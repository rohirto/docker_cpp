/**
 * @file transform_arrays_demo.cpp
 * @author rohirto
 * @brief Demo if adding 2 arrays in a single line of coce using arrays
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// Using transform() in STL to add two arrays
#include <bits/stdc++.h>
using namespace std;

int main()
{
int arr1[] = {1, 2, 3};
int arr2[] = {4, 5, 6};
int n = sizeof(arr1)/sizeof(arr1[0]);
int res[n];

// Single line code to add arr1[] and arr2[] and
// store result in res[]
transform(arr1, arr1+n, arr2, res, 
    plus<int>());  //plus Unary operation//plus is defined in std

for (int i=0; i<n; i++)
	cout << res[i] << " ";
}
