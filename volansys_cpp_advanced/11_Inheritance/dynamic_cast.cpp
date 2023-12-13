/**
 * @file dynamic_cast.cpp
 * @author rohirto
 * @brief Demo of Dynamic Casting in C++
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

// Base class
class Base {
public:
    virtual ~Base() {}  // Ensure a virtual destructor for polymorphism
};

// Derived class 1
class Derived1 : public Base {
public:
    void specificFunction1() {
        std::cout << "Function specific to Derived1\n";
    }
};

// Derived class 2
class Derived2 : public Base {
public:
    void specificFunction2() {
        std::cout << "Function specific to Derived2\n";
    }
};

int main() {
    // Create objects of derived classes
    Derived1 derived1;
    Derived2 derived2;

    // Base class pointer pointing to derived objects
    Base* basePtr1 = &derived1;
    Base* basePtr2 = &derived2;

    // Using dynamic_cast to check the actual type
    Derived1* castedDerived1 = dynamic_cast<Derived1*>(basePtr1);
    Derived2* castedDerived2 = dynamic_cast<Derived2*>(basePtr2);

    // Check the results of dynamic_cast and call specific functions
    if (castedDerived1) {
        std::cout << "Pointer is of type Derived1\n";
        castedDerived1->specificFunction1();
    } else {
        std::cout << "Pointer is not of type Derived1\n";
    }

    if (castedDerived2) {
        std::cout << "Pointer is of type Derived2\n";
        castedDerived2->specificFunction2();
    } else {
        std::cout << "Pointer is not of type Derived2\n";
    }

    return 0;
}
