/**
 * @file higher_order_returning_lambdas.cpp
 * @author rohirto
 * @brief Demo of Higher-Order Returning Lambda Functions 
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
//Lambda inside a lambda, increasing order
#include <iostream>
const auto less_than = [](auto x) {
    return [x](auto y) {
        return y < x;
    };
};

int main(void)
{
    auto less_than_five = less_than(5);
    std::cout << less_than_five(3) << std::endl;
    std::cout << less_than_five(10) << std::endl;
    return 0;
}

//Going a bit further, lambda functions can also return another lambda function. 
//This will open the doors of endless possibilities for customization, code expressiveness, and compactibility (by the way, there is no word like this) of code.