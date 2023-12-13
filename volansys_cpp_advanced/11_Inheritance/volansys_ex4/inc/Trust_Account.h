/**
 * @file Trust_Account.h
 * @author rohit S
 * @brief Trust Account class Header File
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */


#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"

class Trust_Account: public Savings_Account{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
//def_name, def_balance, and def_int_rate are private static constexpr members used as default values for the constructor parameters.
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

protected:
    int no_of_tx;

public:
    Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);
    // Inherits withdraw from base class
};

#endif
