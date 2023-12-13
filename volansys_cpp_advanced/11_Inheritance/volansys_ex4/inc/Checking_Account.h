/**
 * @file Checking_Account.h
 * @author rohit S
 * @brief header file for checking account class
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */

#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_Account: public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);  //declares a friend function operator<< that can access
                                                                                        // private members of Checking_Account. This is often used
                                                                                        // for stream insertion (output) operators.
private:
//def_name, def_balance, and def_int_rate are private static constexpr members used as default values for the constructor parameters.
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;

protected:
    static constexpr double withdrawal_fee = 150;

public:
    Checking_Account(std::string name = def_name, double balance =def_balance);
    //Inherits deposit from account
    //Inherits withdraw from account

};


#endif