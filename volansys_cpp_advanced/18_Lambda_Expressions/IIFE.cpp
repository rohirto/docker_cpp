/**
 * @file IIFE.cpp
 * @author rohirto 
 * @brief Demo of  immediately invoked function expression (IIFE), which runs as soon as it is created.
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * Note how adding () after lambda expression declaration leads to immediate execution, thats IIFE
 * Its a technique to use a function declaration as a expression, has its own advantages, good coding practice 
 * 
 */

#include <iostream>

auto main() -> int {

  [](){
    std::cout <<"Hello IIFE" <<"\n";
  }(); // Invoking the lambda immediately, so it'll print "Hello IIFE"

  //The above code works perfectly fine and it is evident that C++ IIFE useful for converting a series of statements into an expression. 
  //This technique uses an anonymous function inside parentheses to convert it from a declaration to an expression, which is executed immediately. 
  //Also note that, everything that you define within the IIFE can only be accessed within the IIFE.

  return 1;
}