/**
 * @file shared_ptr_class_mem.cpp
 * @author rohirto
 * @brief Demo of using shared_ptr as class member
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <memory>

using namespace std;

struct Employee{ 
    string Name;
    explicit Employee(const string& name):Name(name){};
};

struct Office{
    shared_ptr<Employee> Manager;

    explicit Office(shared_ptr<Employee> m):Manager(m){}
};

struct CharityTeam{
    shared_ptr<Employee> Volunteer;
    explicit CharityTeam(shared_ptr<Employee> v):Volunteer(v){}
};



int main(){

    auto Jack = make_shared<Employee>("Jack");

    Office office{Jack};

    CharityTeam charityTeam{Jack};

    
    cout<< Jack.use_count()<<endl; // 3 

    //In the example above, Jack is shared among three pointers. Shared pointers take the memory management out of the way of programmers. 
    //We don’t need to think about deleting a pointer, we don’t need to care which object dies first, or which object outlives others.


    
}