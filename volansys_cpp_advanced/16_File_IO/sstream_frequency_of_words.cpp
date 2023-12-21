/**
 * @file sstream_frequency_of_words.cpp
 * @author rohirto
 * @brief Count the frequency of words in a string
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to demonstrate use 
// of stringstream to count 
// frequencies of words.
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include<string>
using namespace std;

void printFrequency(string st)
{
	// Each word it mapped to 
	// it's frequency
	map<string, int>FW;

	// Used for breaking words
	stringstream ss(st); 

	// To store individual words
	string Word; 

	while (ss >> Word)
		FW[Word]++; //For each word, it increments its frequency in the map FW.

	map<string, int>::iterator m;
	for (m = FW.begin(); m != FW.end(); m++)
		cout << m->first << "-> "
			<< m->second << "\n";
}

// Driver code
int main()
{
	string s = "Geeks For Geeks Ide";
	printFrequency(s);
	return 0;
}
