/**
 * @file passing_unique_ptr_to_func.cpp
 * @author rohirto
 * @brief Example of how to pass a unqiue ptr to a function
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<memory>
using namespace std;

struct A{
    ~A(){cout<<"Deleted.";}
};

void PassIn(std::unique_ptr<A> a)
{
    cout<< "Pointer received."<<'\n';

} // a and its object are deleted.


int main(){
    
    auto x = make_unique<A>();
    PassIn(move(x)) // Pointer received.
    ; // Deleted.
    
    if (!x) cout<< "x is empty."; // true: x is empty.
    
    return 0;
}