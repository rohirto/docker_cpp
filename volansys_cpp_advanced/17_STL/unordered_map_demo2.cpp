/**
 * @file unordered_map_demo2.cpp
 * @author rohirto
 * @brief Problem based on Unordered Map
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 * Given a string of words, the task is to find the frequencies of the individual words:
 * Input: str = “geeks for geeks geeks quiz practice qa for”;
 * Output: Frequencies of individual words are
 *            (practice, 1)
 *            (for, 2)
 *           (qa, 1)
 *           (quiz, 1)
 *           (geeks, 3)
 *
 */

// C++ program to find freq
// of every word using unordered_map
#include <bits/stdc++.h>
using namespace std;

// Prints frequencies of
// individual words in str
void printFrequencies(const string &str)
{
    // declaring map of <string, int> type,
    // each word is mapped to its frequency
    unordered_map<string, int> wordFreq;

    // breaking input into word using
    // string stream
    // Used for breaking words
    stringstream ss(str);

    // To store individual words
    string word;
    while (ss >> word)
        wordFreq[word]++;

    // now iterating over word, freq pair
    // and printing them in <, > format
    unordered_map<string, int>::iterator p;
    for (p = wordFreq.begin();
         p != wordFreq.end(); ++p)
        cout << "(" << p->first << ", " << p->second << ")\n";
}

// Driver code
int main()
{
    string str = "geeks for geeks geeks quiz "
                 "practice qa for";
    printFrequencies(str);
    return 0;
}
