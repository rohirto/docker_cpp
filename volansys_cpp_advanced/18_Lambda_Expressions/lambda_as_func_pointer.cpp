/**
 * @file lambda_as_func_pointer.cpp
 * @author rohirto
 * @brief Demo of using lambda as func pointer
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <type_traits>
int main()
{
    auto funcPtr = +[] {};
    static_assert(std::is_same<decltype(funcPtr), void (*)()>::value);

    //You can force the compiler to generate lambda as a function pointer rather than closure by adding + in front of it, as shown above. 
}