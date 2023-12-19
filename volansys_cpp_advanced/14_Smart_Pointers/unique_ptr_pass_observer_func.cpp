/**
 * @file unique_ptr_pass_observer_func.cpp
 * @author rohirto
 * @brief example of passing a unique pointer to observer function
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
#include<memory>
using namespace std;

struct Database{
    double GetAverageSalary(){return 1000;};
};

void ShowSalaryDifference(double salary, Database* db)
{
    if (!db) throw runtime_error("Database is null.");
    cout<< salary - db->GetAverageSalary();
} 

void ShowSalaryDifference1(double salary, Database& db)
{
    cout<< salary - db.GetAverageSalary();
} 

int main(){
    
    auto db = make_unique<Database>();
    ShowSalaryDifference(1200, db.get()); // 200, here db.get() returns a raw pointer which is passed to the observer function

    //If we are sure db has an object, we can pass it by reference
    ShowSalaryDifference1(1200,*db); // 200

    
    return 0;
}