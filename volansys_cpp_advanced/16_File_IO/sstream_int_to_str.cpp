/**
 * @file sstream_int_to_str.cpp
 * @author rohirto
 * @brief sstream demo of int to string
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to demonstrate the
// use of a stringstream to
// convert int to string
#include <iostream>
#include <sstream>
using namespace std;

// Driver code
int main()
{
	int val=123;

	// object from the class stringstream
	stringstream geek;

	// inserting integer val in geek stream
	geek << val;

	// The object has the value 123
	// and stream it to the string x
	string x;
	geek >> x;

	// Now the string x holds the
	// value 123
	cout<<x+"4"<<endl;
	return 0;
}
