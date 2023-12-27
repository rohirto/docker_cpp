/**
 * @file unordered_multiset_demo2.cpp
 * @author rohirto
 * @brief Demo of deleting one entry from unordered multiset in stl
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to delete one copy from unordered set 
#include <bits/stdc++.h> 
using namespace std; 

// making typedef for short declaration 
typedef unordered_multiset<int>::iterator umit; 

// Utility function to print unordered_multiset 
void printUset(unordered_multiset<int> ums) 
{ 
	// begin() returns iterator to first element of 
	// set 
	umit it = ums.begin(); 
	for (; it != ums.end(); ++it) 
		cout << *it << " "; 
	cout << endl; 
} 

// function to delete one copy of val from set 
void erase_one_entry(unordered_multiset<int>& ums, 
					int val) 
{ 
	// find returns iterator to first position 
	umit it = ums.find(val); 

	// if element is there then erasing that 
	if (it != ums.end()) 
	ums.erase(it); 
} 

// Driver program to check above function 
int main() 
{ 
	// initializing multiset by initializer list 
	unordered_multiset<int> ums ({1, 3, 1, 7, 2, 3, 
								4, 1, 6}); 

	int val = 1; 
	printUset(ums); 
	erase_one_entry(ums, val); 
	printUset(ums); 
}
