/**
 * @file sstream_count_words.cpp
 * @author rohirto
 * @brief Demo of sstream use for counting words from a string
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to count words in 
// a string using stringstream.
#include <iostream>
#include <sstream>
#include<string>
using namespace std;

int countWords(string str)
{
	// Breaking input into word 
	// using string stream

	// Used for breaking words
	stringstream s(str); 

	// To store individual words
	string word; 

	int count = 0;
	while (s >> word)
		count++;
	return count;
}

// Driver code
int main()
{
	string s = "geeks for geeks geeks "
			"contribution placements";
	cout << " Number of words are: " << countWords(s);
	return 0;
}
