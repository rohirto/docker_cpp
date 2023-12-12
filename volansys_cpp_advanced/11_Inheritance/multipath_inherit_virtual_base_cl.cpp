/**
 * @file multipath_inherit_virtual_base_cl.cpp
 * @author rohirto
 * @brief Demo of Avoiding multipath inheritance ambiguity using virtual base classes
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream> 

using namespace std;

class ClassA 
{ 
public: 
	int a; 
}; 

class ClassB : virtual public ClassA 
{ 
public: 
	int b; 
}; 

class ClassC : virtual public ClassA 
{ 
public: 
	int c; 
}; 

class ClassD : public ClassB, public ClassC 
{ 
public: 
	int d; 
}; 

int main() 
{ 
	ClassD obj; 

	obj.a = 10;	 // Statement 3 
	obj.a = 100;	 // Statement 4 

	obj.b = 20; 
	obj.c = 30; 
	obj.d = 40; 

	cout << "\n a : " << obj.a; 
	cout << "\n b : " << obj.b; 
	cout << "\n c : " << obj.c; 
	cout << "\n d : " << obj.d << '\n'; 
}
