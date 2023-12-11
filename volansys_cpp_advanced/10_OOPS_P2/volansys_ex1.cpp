/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 1 of OOP Part 2 of C++ Advanced Course
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 1
 * 
 * Given the Dog class , add a Copy constructor.
 * 
 * The copy constructor should copy the attributes from one object to another.
 * Also, please display, "Copy Constructor" to cout in the body of your copy constructor. Do not follow the output statement with '\n' or endl
 * 
 * The copy constructor should allow us to create  Dog objects as follows:
 * 
 * Dog spot {"Spot", 5};   // Overloaded constuctor
 * Dog twin {spot};        // Copy constructor, twin will be a copy of spot
 * 
 * 
 * Please add your code to the Dog.h file.
 */

#include <string>
#include <iostream>

using namespace std;

class Dog {
private:
    string name;
    int age;
public:
     Dog(): name(""), age(0) {}  // Default constructor, notice used constructor delegation syntax over here and elsewhere
     
//---- Overloaded CONSTRUCTOR
    Dog(const string& n, int a): name(n), age(a) {}

//---- COPY CONSTRUCTOR 
    Dog(const Dog& other): name(other.name), age(other.age) 
    {
        cout << "Copy Constructor";
    }


    string get_name() 
	{
		return name; 
	}
    
	void set_name(string n) 
	{
		name = n; 
	}
    
	int get_age() 
	{
		return age; 
	}
    
	void set_age(int a) 
	{ 
		age = a;
	}
    
	int get_dog_years() 
	{ 
		return age * 7; 
	}
    
	string speak() 
	{ 
		return "Woof";
	}
};

int main()
{
	Dog spot {"Spot", 5};   // Overloaded constuctor
	Dog twin {spot};        // Copy constructor, twin will be a copy of spot
    
	cout << "Dog name: " << spot.get_name() << endl;
	cout << "Dog age: " << spot.get_age() << endl;
	cout << "Dog name: " << twin.get_name() << endl;
	cout << "Dog name: " << twin.get_name() << endl;
	
    return 0;
}