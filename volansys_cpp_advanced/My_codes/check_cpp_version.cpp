/**
 * @file check_cpp_version.cpp
 * @author rohirto
 * @brief Code to check c++ version
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 * Run the code, the output value will tell which c++ version you are using
 * 
 * C++98/03: 199711L
 * C++11: 201103L
 * C++14: 201402L
 * C++17: 201703L
 * C++20: 202002L
 * C++23: Expected to be 202300L
 * 
 */

#include <iostream>

int main() {
    std::cout << "C++ Standard Version: " << __cplusplus << std::endl;
    return 0;
}
