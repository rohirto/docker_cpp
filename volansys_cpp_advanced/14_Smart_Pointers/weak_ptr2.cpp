/**
 * @file weak_ptr2.cpp
 * @author rohirto
 * @brief weak_ptr demo
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <memory>

using namespace std;

struct Person{
    string Name;
    Person(string n):Name(n){}
};

int main(){

    // initial state
    auto teacher = make_shared<Person>("Jack");
    auto coach = teacher;
    weak_ptr<Person> wp = teacher;

    if (auto temp = wp.lock())
        cout<< temp-> Name; //  Jack
    
    // coach is reset
    coach.reset();

    // teacher is reset to Rose
    teacher.reset(new Person("Rose"));

    if (wp.expired()) // true
        cout<< "The old teacher is not there."; 
}