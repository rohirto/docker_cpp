/**
 * @file I_Printable.cpp
 * @author Class Implementation I Printable 
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */

#include "I_Printable.h"

std::ostream &operator<<(std::ostream &os, const I_Printable &obj){
    os << "[Account: " << obj.name << ": " << obj.balance << "]";
    return os;
}