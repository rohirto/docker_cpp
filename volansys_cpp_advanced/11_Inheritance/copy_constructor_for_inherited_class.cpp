/**
 * @file copy_constructor_for_inherited_class.cpp
 * @author rohirto
 * @brief Demo of how to implement copy constructor for Derived class and Base class
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

// Base class with a copy constructor
class Base {
public:
    int data;

    // Default constructor
    Base() : data(0) {
        std::cout << "Base default constructor called." << std::endl;
    }

    // Copy constructor
    Base(const Base& other) : data(other.data) {
        std::cout << "Base copy constructor called." << std::endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Default constructor
    Derived() {
        std::cout << "Derived default constructor called." << std::endl;
    }

    // Copy constructor
    Derived(const Derived& other) : Base(other) {
        std::cout << "Derived copy constructor called." << std::endl;
    }
};

int main() {
    // Create objects of the derived class
    Derived obj1;

    // Copy constructor of the base class is called when creating obj2
    Derived obj2 = obj1;

    return 0;
}
