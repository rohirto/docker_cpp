/**
 * @file template_smart_pointers.cpp
 * @author rohirto
 * @brief Example of using templates (generic data type), with smart pointers
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to demonstrate the working of Template and
// overcome the issues which we are having with pointers
#include <iostream>
using namespace std;
 
// A generic smart pointer class
template <class T> class SmartPtr {
    T* ptr; // Actual pointer
public:
    // Constructor
    explicit SmartPtr(T* p = NULL) { ptr = p; }
 
    // Destructor
    ~SmartPtr() { delete (ptr); }
 
    // Overloading dereferencing operator
    T& operator*() { return *ptr; }
 
    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }
};
 
int main()
{
    SmartPtr<int> ptr(new int()); //Using templates as int
    *ptr = 20;
    cout << *ptr << endl;

    SmartPtr<double> ptr1(new double()); //using templates as double
    *ptr1 = 20.11;
    cout << *ptr1;
    return 0;
}