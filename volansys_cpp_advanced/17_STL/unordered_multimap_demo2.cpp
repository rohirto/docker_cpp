/**
 * @file unordered_multimap_demo2.cpp
 * @author rohirto
 * @brief Demo of deleting a specific instance in a unordered multimap
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// C++ program to erase particular value.
#include <bits/stdc++.h>
using namespace std;

// Utility function to print unordered_multimap
void printUmm(unordered_multimap<string, int>& umm)
{

	// Iterator pointing to first element of unordered_map
	auto it1 = umm.begin();

	for (; it1 != umm.end(); ++it1) {
		cout << "<" << it1->first << ", " << it1->second
			<< "> ";
		cout << endl;
	}
}

int main()
{

	// Initialization by initializer list
	unordered_multimap<string, int> umm{
		{ "apple", 1 }, { "ball", 2 }, { "apple", 10 },
		{ "cat", 7 }, { "dog", 9 }, { "cat", 6 },
		{ "apple", 1 }
	};

	// Iterator pointing to first element of unordered_map
	auto it = umm.begin();

	// Search for an element with value 1
	while (it != umm.end()) {
		if (it->second == 1)
			break;
		it++;
	}

	// Erase the element pointed by iterator it
	if (it != umm.end())
		umm.erase(it);
	
	cout << "After deletion of value 1 from umm" << endl;
	printUmm(umm);

	return 0;
}
