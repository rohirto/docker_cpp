/**
 * @file map_demo.cpp
 * @author rohirto
 * @brief Demo of Map in STL
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 * begin and end
 * Time complexity: O(n) where n is the size of map.
 * Auxiliary Space: O(n)
 * 
 * size
 * Time complexity: O(1).
 * 
 * 
 * 
 */

// C++ program to illustrate the begin and end iterator
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	// Create a map of strings to integers
	map<string, int> mp;  //Key value type, map value type

	// Insert some values into the map
	mp["one"] = 1;
	mp["two"] = 2;
	mp["three"] = 3;

	// Get an iterator pointing to the first element in the
	// map
	map<string, int>::iterator it = mp.begin();

	// Iterate through the map and print the elements
	while (it != mp.end()) {
		cout << "Key: " << it->first
			<< ", Value: " << it->second << endl;
		++it;
	}

    // Print the values in the map
    cout << "Key: one, Value: " << mp["one"] << endl;
    cout << "Key: two, Value: " << mp["two"] << endl;
    cout << "Key: three, Value: " << mp["three"] << endl;
 
    // Check if a key is in the map
    if (mp.count("four") > 0) {
        cout << "Key 'four' is in the map" << endl;
    }
    else {
        cout << "Key 'four' is not in the map" << endl;
    }

    // Print the size of the map
    cout << "Size of map: " << mp.size() << endl;



	return 0;
}
