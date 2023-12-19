/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 1 of smart pointers C++ Advance
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 1
 * Write a program that defines a class with two data members, a user-defined constructor, and one member function.
 *
 * Create a unique pointer to an object of a class.
 * 
 * Use the smart pointer to access the member function.
 * 
 */

#include <iostream>
#include <memory>

class MyClass
{
	//----WRITE YOUR CODE BELOW THIS LINE----
private:
    int a;  //Data mem
    int b;
public:
    MyClass(int aa, int bb):a(aa),b(bb){}  //User defined constructor

    void print(){std::cout << a  << " "<< b << std::endl;}
	//----WRITE YOUR CODE ABOVE THIS LINE----
};
int main()
{
	//----WRITE YOUR CODE BELOW THIS LINE----

    std::unique_ptr<MyClass> myPtr(new MyClass(1,2)); //declaration of unique pointer

    myPtr->print();  //Using pointer to access the member function

	//----WRITE YOUR CODE ABOVE THIS LINE----
}