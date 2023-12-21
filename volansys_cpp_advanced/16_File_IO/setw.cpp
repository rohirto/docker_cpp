/**
 * @file setw.cpp
 * @author rohirto
 * @brief Demo of setw function to format the output of cout 
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    //In this example, std::setw(10) is used before each value to set the width of the field to 10 characters. 
    //This ensures that each column has a consistent width, making the output more readable and organized.
    std::cout << std::setw(10) << "Name" << std::setw(10) << "Age" << std::setw(10) << "Salary" << std::endl;
    std::cout << std::setw(10) << "John" << std::setw(10) << 25 << std::setw(10) << 50000 << std::endl;
    std::cout << std::setw(10) << "Alice" << std::setw(10) << 30 << std::setw(10) << 60000 << std::endl;


    //Alignment

    /**
     * setw(10) sets the width of the field to 10 characters for each value.
     * setiosflags(std::ios::left) aligns the content to the left within the field.
     * setiosflags(std::ios::right) aligns the content to the right within the field.
     * 
     */

    std::cout << std::setw(10) << std::setiosflags(std::ios::left) << "LeftAlign";
    std::cout << std::setw(10) << std::setiosflags(std::ios::right) << "RightAlign" << std::endl;


    //Changing the padding character
    //Using setfill
    std::cout << std::setw(10) << std::setfill('*') << 42 << std::endl;
    std::cout << std::setw(10) << std::setfill('-') << "Hello" << std::endl;
    std::cout << std::setw(15) << std::setfill('@') << 123.45 << std::endl;


    //setf
     // Using setf to set specific formatting flags
    std::cout.setf(std::ios::hex | std::ios::showbase);

    // Output in hexadecimal with the '0x' prefix
    std::cout << "Hexadecimal: " << 255 << std::endl;

    // Clearing a formatting flag using unsetf
    std::cout.unsetf(std::ios::hex);

    // Output in the default decimal format
    std::cout << "Decimal: " << 255 << std::endl;


    return 0;
}
