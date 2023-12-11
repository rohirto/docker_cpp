/**
 * @file lvalue_rvalue.cpp
 * @author rohirto
 * @brief demo code to explain concepts of lvalue and rvalue
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @paragraph: Explanation
 * 1. “l-value” refers to a memory location that identifies an object. 
 * 2. “r-value” refers to the data value that is stored at some address in memory. 
 * 3. References in C++ are nothing but the alternative to the already existing variable. They are declared using the ‘&’ before the name of the variable.
 * 
 * int a = 10;
 *
 * // Declaring lvalue reference
 * int& lref = a;
 * 
 * // Declaring rvalue reference
 * int&& rref = 20;
 * 
 */

// C++ program to illustrate the
// lvalue and rvalue

#include <iostream>
using namespace std;

// Driver Code
int main()
{
	// Declaring the variable
	int a{ 10 };

	// Declaring reference to
	// already created variable
	int& b = a;

	// Provision made to display
	// the boolean output in the
	// form of True and False
	// instead of 1 and
	cout << boolalpha;

	// Comparing the address of both the
	// variable and its reference and it
	// will turn out to be same
	cout << (&a == &b) << endl;

    /**
     * @brief code will print True as both the variable are pointing to the same memory location. b is just an alternative name to the memory assigned 
     * to the variable a. The reference declared in the above code is lvalue reference (i.e., referring to variable in the lvalue) similarly the 
     * references for the values can also be declared.
     */

    

	return 0;
}
