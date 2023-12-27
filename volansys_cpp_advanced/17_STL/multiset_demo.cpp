/**
 * @file multiset_demo.cpp
 * @author rohirto
 * @brief Demo of Multiset in STL
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 * Insertion of Elements- O(log N)
 * Accessing Elements – O(log N)
 * Deleting Elements- O(log N)
 * 
 * For removing multiple intsances 
 * Time Complexity: O(max(Σ(log(i)),(K+log(n))), where i is the size of multiset at the time of insertion,  
 * K is the total count of integers of the value passed, n is the size of multiset.
 * Auxiliary Space: O(1).
 * 
 */

// CPP Program to demonstrate the 
// implementation of multiset
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	// empty multiset container
	multiset<int, greater<int> > gquiz1;  //descending

	// insert elements in random order
	gquiz1.insert(40);
	gquiz1.insert(30);
	gquiz1.insert(60);
	gquiz1.insert(20);
	gquiz1.insert(50);

	// 50 will be added again to
	// the multiset unlike set
	gquiz1.insert(50);
	gquiz1.insert(10);

	// printing multiset gquiz1
	multiset<int, greater<int> >::iterator itr;
	cout << "\nThe multiset gquiz1 is : \n";
	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;

	// assigning the elements from gquiz1 to gquiz2
	multiset<int> gquiz2(gquiz1.begin(), gquiz1.end()); //Ascending

	// print all elements of the multiset gquiz2
	cout << "\nThe multiset gquiz2 \n"
			"after assign from gquiz1 is : \n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;

	// remove all elements up to element
	// with value 30 in gquiz2
	cout << "\ngquiz2 after removal \n"
			"of elements less than 30 : \n";
	gquiz2.erase(gquiz2.begin(), gquiz2.find(30));
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}

	// remove all elements with value 50 in gquiz2
	int num;
	num = gquiz2.erase(50);
	cout << "\ngquiz2.erase(50) : \n";
	cout << num << " removed \n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << endl;

	// lower bound and upper bound for multiset gquiz1
	cout << "\ngquiz1.lower_bound(40) : \n"
		<< *gquiz1.lower_bound(40) << endl;
	cout << "gquiz1.upper_bound(40) : \n"
		<< *gquiz1.upper_bound(40) << endl;

	// lower bound and upper bound for multiset gquiz2
	cout << "gquiz2.lower_bound(40) : \n"
		<< *gquiz2.lower_bound(40) << endl;
	cout << "gquiz2.upper_bound(40) : \n"
		<< *gquiz2.upper_bound(40) << endl;


    //CPP Code to remove an element from multiset which have
    // same value
    multiset<int> a;
    a.insert(10);
    a.insert(10);
    a.insert(10);
 
    // it will give output 3
    cout << a.count(10) << endl;
 
    // removing single instance from multiset
 
    // it will remove only one value of
    // 10 from multiset
    a.erase(a.find(10));
 
    // it will give output 2
    cout << a.count(10) << endl;
 
    // removing all instance of element from multiset
    // it will remove all instance of value 10
    a.erase(10);
 
    // it will give output 0 because all
    // instance of value is removed from
    // multiset
    cout << a.count(10) << endl;

	return 0;
}
