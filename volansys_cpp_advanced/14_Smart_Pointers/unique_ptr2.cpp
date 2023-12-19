/**
 * @file unique_ptr2.cpp
 * @author rohirto
 * @brief Factory Example of unique pointers
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<memory>
using namespace std;

struct Base{};
struct Derived:Base{};

std::unique_ptr<Base> create(int option)
{   
    if (option == 0)
        return make_unique<Base>();
    else if (option==1)
        return make_unique<Derived>();
    else
        throw runtime_error("Wrong option.");
}
int main(){
    
    auto p = create(1);
    return 0;
}