/**
 * @file sort.cpp
 * @author rohirto
 * @brief Demo of default sort in STL
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <algorithm>  //Need this header for sort
#include <iostream> 

int main() 
{ 
	int arr[] = {3, 5, 1, 2, 4}; 

	// Sort the array in ascending order 
	std::sort(std::begin(arr), std::end(arr)); //Will use quick sort by default

	// Print the sorted array 
	for (int i : arr) 
	{ 
		std::cout << i << " "; 
	} 

	

	return 0; 
} 
