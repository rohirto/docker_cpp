/**
 * @file Checking_Account.cpp
 * @author rohit S
 * @brief Checking Account class implementation
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */

#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance): Account(name,balance){

}



std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance;
    return os;
}