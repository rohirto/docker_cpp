/**
 * @file lambda_unevaluated_context.cpp
 * @author rohirto
 * @brief demonstrates the use of lambda functions within the context of template specialization for std::set. 
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * It defines custom comparators for sorting strings based on length and sorting integers based on absolute values.
 * 
 */
#if __cplusplus >= 202002L

#include <cmath>
#include <iostream>
#include <memory>
#include <set>
#include <string>


//Define a function template printContainer to print the elements of a container. It works for any container that supports range-based for loops.
template <typename Cont>
void printContainer(const Cont& cont) {
    for (const auto& c: cont) std::cout << c << "  ";
    std::cout << "\n";
}

int main() {
    
    std::cout << std::endl;

    //Create a std::set of strings named set1 and print its elements.
    std::set<std::string> set1 = {"scott", "Bjarne", "Herb", "Dave", "michael"};
    printContainer(set1);
    
    //Define a type alias SetDecreasing for a std::set of strings with a custom comparator that sorts in decreasing order. 
    //Create an instance set2 and print its elements.
    using SetDecreasing = std::set<std::string, decltype([](const auto& l, const auto& r){ return l > r; })>;           // (1)
    SetDecreasing set2 = {"scott", "Bjarne", "Herb", "Dave", "michael"};
    printContainer(set2);     // (2)

    using SetLength = std::set<std::string, decltype([](const auto& l, const auto& r){ return l.size() < r.size(); })>; // (1)
    SetLength set3 = {"scott", "Bjarne", "Herb", "Dave", "michael"};
    printContainer(set3);     // (2)

    std::cout << std::endl;

    std::set<int> set4 = {-10, 5, 3, 100, 0, -25};
    printContainer(set4);

    using setAbsolute = std::set<int, decltype([](const auto& l, const auto& r){ return  std::abs(l)< std::abs(r); })>; // (1)
    setAbsolute set5 = {-10, 5, 3, 100, 0, -25};
    printContainer(set5);    // (2)
    
    std::cout << "\n\n";
    
}

#else
#error This code requires C++20 or later.
#endif