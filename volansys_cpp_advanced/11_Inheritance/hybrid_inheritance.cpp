/**
 * @file hybrid_inheritance.cpp
 * @author rohirto
 * @brief Demo of hybrid inheritance
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// C++ program for Hybrid Inheritance 

#include <iostream> 
using namespace std; 

// base class 
class Vehicle { 
public: 
	Vehicle() { cout << "This is a Vehicle\n"; } 
}; 

// base class 
class Fare { 
public: 
	Fare() { cout << "Fare of Vehicle\n"; } 
}; 

// first sub class 
class Car : public Vehicle { 
}; 

// second sub class 
class Bus : public Vehicle, public Fare { 
}; 

// main function 
int main() 
{ 
	// Creating object of sub class will 
	// invoke the constructor of base class. 
	Bus obj2; 
	return 0; 
}
