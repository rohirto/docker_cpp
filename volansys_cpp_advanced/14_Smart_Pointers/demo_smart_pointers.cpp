/**
 * @file demo_smart_pointers.cpp
 * @author rohirto
 * @brief Demo of Smart Pointers
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to demonstrate the working of Smart Pointer
#include <iostream>
using namespace std;

class SmartPtr {
	int* ptr; // Actual pointer
public:
	// Constructor: Refer https:// www.geeksforgeeks.org/g-fact-93/
	// for use of explicit keyword
	explicit SmartPtr(int* p = NULL) { ptr = p; }

	// Destructor
	~SmartPtr() { delete (ptr); }

	// Overloading dereferencing operator
	int& operator*() { return *ptr; }
};

int main()
{
	SmartPtr ptr(new int());
	*ptr = 20;
	cout << *ptr;

	// We don't need to call delete ptr: when the object
	// ptr goes out of scope, the destructor for it is automatically
	// called and destructor does delete ptr.

	return 0;
}
