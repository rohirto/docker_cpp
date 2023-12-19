/**
 * @file return_from_func_unique_ptr.cpp
 * @author rohirto
 * @brief Example of how to return a unique_ptr from a fnction
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
#include<memory>
using namespace std;

struct A{};

std::unique_ptr<A> PassOut()
{
    auto a =  make_unique<A>();
    return a;
} 


int main(){
    
    auto x = PassOut();

    if (x) cout<< "x has an object."; // true: x has an object.
    
    return 0;
}