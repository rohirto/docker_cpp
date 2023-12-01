/**
 * @file volansys_ex3.cpp
 * @author rohit S
 * @brief Exercise 3 of Functions Lesson C++ Basic Course
 * @version 0.1
 * @date 2023-12-01 
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 *
 * Create a calculator that takes a number, a basic math operator (+,-,*,/,^), and a second number all from user input, 
 * and have it print the result of the mathematical operation. 
 * The mathematical operations should be wrapped inside of functions.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <type_traits>
#include <cmath>

using namespace std;

template <typename T>
T add(T a, T b) 
{
    static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
    return a + b;
}

template <typename T>
T sub(T a, T b) 
{
    static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
    return a - b;
}

template <typename T>
T mul(T a, T b) 
{
    static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
    return a * b;
}

template <typename T>
T divi(T a, T b) 
{
    static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
    if (b != 0) {
        return a / b;
    }

    std::cerr << "\033[1;31mError: Division by zero.\033[0m" << std::endl;
    // Handle division by zero
    // You might want to return a special value or throw an exception here
    return std::numeric_limits<T>::quiet_NaN();
}

template <typename T>
T xxor(T a, T b) 
{
    static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
    return pow(a,b);
}

void display_red(auto str)
{
    cout << "\033[1;31m" << str << "\033[0m\n";
}
void display_green(auto str)
{
    cout << "\033[1;32m" << str << "\033[0m\n";
}
void display_yellow(auto str)
{
    cout << "\033[1;33m" << str << "\033[0m\n";
}
void display_blue(auto str)
{
    cout << "\033[1;34m" << str << "\033[0m\n";
}
void display_decorator()
{
    cout << "===============================\n";
}

void get_string(double& a, char& op, double& b)
{
    
    string input_msg {};
    getline(cin >> ws,input_msg);
    
    // Parse the input string
    istringstream iss(input_msg);

    while (!iss.eof())
    {
        if (iss.peek() == 'q') // Quit
        {
            iss >> op;
            break;
        }
        else
        {
            iss >> a;

            if(isalpha(a))
            {
                op = 0x00;
                break;
            }

            iss >> op;

            if(op != '+' && op != '-' && op != '*' && op != '/' && op != '^')
            {
                op = 0x00;
                break;
            }

            iss >> b;

            if(isalpha(b))
            {
                op = 0x00;
                break;
            }
        }
    }
    
}


int main() {

    
    do
    {
        display_decorator();
        display_yellow("CALCULATOR\nSupported operations:[+] [-] [*] [/] [^]\n");
        display_yellow("Usage: <num><operator><num>");
        display_decorator();
        display_yellow("Enter the operation(or q to quit): ");
        char c{};
        double a{}, b{}, result{};
        get_string(a, c, b);
        if (c != 0x00)
        {
            
            switch (c)
            {
            case '+':
                result = add(a, b);
                break;
            case '-':
                result = sub(a, b);
                break;
            case '*':
                result = mul(a, b);
                break;
            case '/':
                result = divi(a, b);
                break;
            case '^':
                result = xxor(a,b);
                break;
            case 'q':
                display_red("Exiting Calculator!");
                display_decorator();
                exit(EXIT_SUCCESS);
                break;

            default:
                display_red("Invalid Operator!");
                break;
            }

            display_blue("Result is: ");
            display_green(result);
        }
        else
        {
            //Get string error
            display_red("Invalid Input! please try again!");
        }

    } while (1);

    cout << endl;
    return 0;
}
