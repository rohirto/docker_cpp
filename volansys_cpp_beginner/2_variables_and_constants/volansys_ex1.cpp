/**
 * @file volansys_ex1.cpp
 * @author your name (you@domain.com)
 * @brief Exercise 1 of Lesson 2 of C++ Basic Course
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 1
 * 
 * Excercise 1: Write code that creates a profile for a new employee at a company.
 * You must declare a total of THREE variables, each of a different type, to represent the employee's name, age, and hourly_wage.
 * You must initialize the hourly_wage to 23.50. In order to set the values for name and age you must use 
 * cin and the extraction operator >> to allow the employee to enter their name and age in that order separated by a single space.
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int age;
    float hourly_wage = 23.50;

    cout << " Enter name, age and hourly wage separated by single space" << endl;
    cin >> name >> age ;

     // Display the employee profile
    cout << "\nEmployee Profile:\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Hourly Wage: Rs" << hourly_wage << "\n";


    return 0;
}