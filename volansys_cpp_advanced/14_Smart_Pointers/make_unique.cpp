/**
 * @file make_unique.cpp
 * @author rohirto
 * @brief Demo of making unique_ptr using make_unique
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <memory>
#include <iostream>
using namespace std;

struct Person{
  Person(string n):Name(n){}
  ~Person(){cout<<"Deleted!";}
  string Name;
};

int main(){
    auto p = make_unique<Person>("Jack"); // Person constructor is called.
    return 0;
}