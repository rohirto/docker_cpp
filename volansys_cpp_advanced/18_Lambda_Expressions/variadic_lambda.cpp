/**
 * @file variadic_lambda.cpp
 * @author rohirto
 * @brief Demo of Variadic Lambda in cpp
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

void print() {}
template <typename First, typename... Rest>
void print(const First &first, Rest &&... args)
{
    std::cout << first << std::endl;
    print(args...);
}


int main()
{
    auto variadic_generic_lambda = [](auto... param) {
        print(param...);
    };
    variadic_generic_lambda(1, "lol", 1.1);
}