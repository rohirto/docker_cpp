/**
 * @file hierrarchial_inheritance.cpp
 * @author rohirto
 * @brief Demo of hierrachial inheritance
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to implement 
// Hierarchical Inheritance 
#include <iostream> 
using namespace std; 

// base class 
class Vehicle { 
public: 
	Vehicle() { cout << "This is a Vehicle\n"; } 
}; 

// first sub class 
class Car : public Vehicle { 
}; 

// second sub class 
class Bus : public Vehicle { 
}; 

// main function 
int main() 
{ 
	// Creating object of sub class will 
	// invoke the constructor of base class. 
	Car obj1; 
	Bus obj2; 
	return 0; 
}
