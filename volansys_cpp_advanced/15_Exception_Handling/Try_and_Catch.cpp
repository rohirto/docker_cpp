/**
 * @file Try_and_Catch.cpp
 * @author rohirto
 * @brief Demo of Try and Catch using Divide by Zero Example
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// Program to depict use of try catch block 

#include <iostream> 
#include <stdexcept> 
using namespace std; 

// defining CheckDenominator 
float CheckDenominator(float den) 
{ 
	if (den == 0) 
		throw "Error"; 
	else
		return den; 
} // end CheckDenominator 

int main() 
{ 
	float numerator, denominator, result; 
	numerator = 12.5; 
	denominator = 0; 

	// try block 
	try { 

		// calls the CheckDenominator function 
		// by passing a string "Error" 
		if (CheckDenominator(denominator)) { 

			result = (numerator / denominator); 
			cout << "The quotient is "
				<< result << endl; 
		} 
	} 

	// catch block 
	// capable of catching any type of exception 
	catch (...) { 

		// Display a that exception has occurred 
		cout << "Exception occurred" << endl; 
	} 

} // end main 
