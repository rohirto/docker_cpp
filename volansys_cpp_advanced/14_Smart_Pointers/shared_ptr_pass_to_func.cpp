/**
 * @file shared_ptr_pass_to_func.cpp
 * @author rohirto
 * @brief Shared pointer pass to function demo
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <memory>

using namespace std;

void f(shared_ptr<int> sp){

    cout<< sp.use_count()<<endl; // sp is a shared owner.
}

int main(){
  auto sp1 = make_shared<int>(5);
  cout<< sp1.use_count()<<endl; // 1
  f(sp1); // 2
  cout<< sp1.use_count()<<endl; // 1 : the shared pointer in f() destructed.
}