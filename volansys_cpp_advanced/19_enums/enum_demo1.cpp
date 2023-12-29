/**
 * @file enum_demo1.cpp
 * @author rohirto
 * @brief Another Demo of enum in cpp
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ Program to Demonstrate the Functioning of Enumerators 
// with an Example of Year 
#include <bits/stdc++.h> 
using namespace std; 

// Defining enum Year 
enum year { 
	Jan, 
	Feb, 
	Mar, 
	Apr, 
	May, 
	Jun, 
	Jul, 
	Aug, 
	Sep, 
	Oct, 
	Nov, 
	Dec 
}; 

// Driver Code 
int main() 
{ 
	int i; 

	// Traversing the year enum 
	for (i = Jan; i <= Dec; i++) 
		cout << i << " "; 

	return 0; 
}
