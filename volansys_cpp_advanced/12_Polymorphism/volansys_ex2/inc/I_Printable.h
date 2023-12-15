/**
 * @file I_Printable.h
 * @author rohit S
 * @brief Class I_Printable defination 
 * @version 0.1
 * @date 2023-12-15
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */


#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_

#include <iostream>
#include <string>

class I_Printable
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};


#endif