/**
 * @file shared_ptr_return.cpp
 * @author rohirto
 * @brief Demo of return from a function shared_ptr
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <memory>

using namespace std;

shared_ptr<int> f(){

    auto sp = make_shared<int>(5);

    return sp;
} 


int main(){

    auto sp1 = f(); 

    // The shared pointer in the function is dead here.
    // But its object is alive and pointed by sp1.
    
    cout<< sp1.use_count()<<endl; // 1
    cout<< *sp1;// 5
}