/**
 * @file enum_demo.cpp
 * @author your name (you@domain.com)
 * @brief Demo of Enumerated Types in C++
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ Program to Demonstrate the Functioning of Enumerators 
// with an example of Gender 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	// Defining enum Gender 
	enum Gender { Male, Female }; 

	// Creating Gender type variable 
	Gender gender = Male; 

	switch (gender) { 
	case Male: 
		cout << "Gender is Male"; 
		break; 
	case Female: 
		cout << "Gender is Female"; 
		break; 
	default: 
		cout << "Value can be Male or Female"; 
	} 
	return 0; 
}
