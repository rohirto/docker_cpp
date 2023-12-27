/**
 * @file unordered_multimap_demo.cpp
 * @author rohirto
 * @brief Demo of unordered Multimap in STL
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to demonstrate various function of
// unordered_multimap
#include <bits/stdc++.h>
using namespace std;

// making typedef for short declaration
typedef unordered_multimap<string, int>::iterator unit;

// Utility function to print unordered_multimap
void printUmm(unordered_multimap<string, int> umm)
{
	// begin() returns iterator to first element of map
	unit it = umm.begin();

	for (; it != umm.end(); ++it){
		cout << "<" << it->first << ", " << it->second
			<< "> ";
		cout << endl;
	}
}

// Driver code
int main()
{
	// empty initialization
	unordered_multimap<string, int> umm1;

	// Initialization by initializer list
	unordered_multimap<string, int> umm2(
		{ { "apple", 1 },
		{ "ball", 2 },
		{ "apple", 10 },
		{ "cat", 7 },
		{ "dog", 9 },
		{ "cat", 6 },
		{ "apple", 1 } });  //Duplicate

	// Initialization by assignment operation
	umm1 = umm2;
	printUmm(umm1);

	// empty returns true, if container is empty else it
	// returns false
	if (umm2.empty())
		cout << "unordered multimap 2 is empty\n";
	else
		cout << "unordered multimap 2 is not empty\n";

	// size returns total number of elements in container
	cout << "Size of unordered multimap 1 is "
		<< umm1.size() << endl;

	string key = "apple";

	// find and return any pair, associated with key
	unit it = umm1.find(key);
	if (it != umm1.end()) {
		cout << "\nkey " << key << " is there in unordered "
			<< " multimap 1\n";
		cout << "\none of the value associated with " << key
			<< " is " << it->second << endl;
	}
	else
		cout << "\nkey " << key
			<< " is not there in unordered"
			<< " multimap 1\n";

	// count returns count of total number of pair
	// associated with key
	int cnt = umm1.count(key);
	cout << "\ntotal values associated with " << key
		<< " are " << cnt << "\n\n";

	printUmm(umm2);

	// one insertion by making pair explicitly
	umm2.insert(make_pair("dog", 11));

	// insertion by initializer list
	umm2.insert({ { "alpha", 12 }, { "beta", 33 } });
	cout << "\nAfter insertion of <alpha, 12> and <beta, "
			"33>\n";
	printUmm(umm2);

	// erase deletes all pairs corresponding to key
	umm2.erase("apple");
	cout << "\nAfter deletion of apple\n";
	printUmm(umm2);

	// clear deletes all pairs from container
	umm1.clear();
	umm2.clear();

	if (umm2.empty())
		cout << "\nunordered multimap 2 is empty\n";
	else
		cout << "\nunordered multimap 2 is not empty\n";
}
