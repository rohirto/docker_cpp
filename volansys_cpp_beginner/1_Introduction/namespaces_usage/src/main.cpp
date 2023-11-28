// Usage in main file
#include <iostream>
#include "mynamespace.h"
#include "math_lib.h"

int main() {
    MyNamespace::variable1 = 42;
    MyNamespace::function1();

    // Using the old version
    std::cout << "Version 1: " << math_lib::add(2, 3) << std::endl;

    // Using the new version
    std::cout << "Version 2: " << math_lib::add(2, 3, 5) << std::endl;

    return 0;
}