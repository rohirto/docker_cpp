/**
 * @file set_demo.cpp
 * @author rohirto
 * @brief Demo of working of set in STL
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 * Time complexity: O(N) // N is the size of the set.
 * Auxiliary Space: O(N)
 * 
 * The time complexities for doing various operations on sets are:
 * Insertion of Elements – O(log N)
 * Deletion of Elements – O(log N)
 * 
 */

// C++ Program to Demonstrate
// the basic working of STL
#include <iostream>
#include <set>

using namespace std;

int main()
{
	std::set<char> a;
	a.insert('G');
	a.insert('F');
	a.insert('G');  //repeated character, not unique
    //The reason it printed only F and G is that set does not take multiple same values it only accepts a unique value. 
    //We can use Multiset if we want to store multiple same values.


    // Print the set, by default set sorted in ascending order
    cout << "Ascending Order (Default): ";
	for (auto& str : a) {
		std::cout << str << ' ';
	}
	std::cout << '\n';


    //Descending order set
    set<int, greater<int> > s1;
    s1.insert(10);
    s1.insert(5);
    s1.insert(12);
    s1.insert(4);
    
    cout << "Descending Order : ";
    for (auto i : s1) {
        cout << i << ' ';
    }

    cout << '\n';


	return 0;
}
