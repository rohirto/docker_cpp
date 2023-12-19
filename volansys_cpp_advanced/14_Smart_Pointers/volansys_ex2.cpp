/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Exercise 2 of Smart Pointers lesson C++ Advance
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 2
 * Write a program that defines three shared pointers pointing at the same object of type int.
 * 
 * Create the first pointer through an std::make_shared function.
 * 
 * Create the remaining pointers by copying the first pointer.
 * 
 * Access the pointed-to object through all the pointers.
 */

#include <iostream>
#include <memory>

int main()
{
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
	//----WRITE YOUR CODE BELOW THIS LINE----
    auto sp1 = std::make_shared<int>(5);

    std::shared_ptr<int> sp2 = sp1;
    std::shared_ptr<int> sp3 = sp1;

    std::cout << "sp1: " << *sp1 << std::endl 
                << "sp2: " << *sp2 << std::endl 
                << "sp1: " << *sp3 << std::endl ;
    
    std::cout << "Shared Pointer Use Count: "<< sp1.use_count() << std::endl;

	//----WRITE YOUR CODE ABOVE THIS LINE----
}