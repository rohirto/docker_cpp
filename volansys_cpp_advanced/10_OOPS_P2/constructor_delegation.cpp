/**
 * @file constructor_delegation.cpp
 * @author rohirto
 * @brief Example of Constructor Delegation to reduce redundant code
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// Program to demonstrate constructor delegation
// in C++
#include <iostream>
using namespace std;
class A {
    int x, y, z;
 
public:
    A()
    {
        x = 0;
        y = 0;
        z = 0;
    }
 
    // Constructor delegation 
    A(int z) : A()
    {
        this->z = z; // Only update z
    }
 
    void show()
    {
        cout << x << '\n'
             << y << '\n'
             << z;
    }
};
int main()
{
    A obj(3);
    obj.show();
    return 0;
}