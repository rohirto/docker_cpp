/**
 * @file Trust_Account.cpp
 * @author rohit S
 * @brief Trust Account Class implementation
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */

#include "Trust_Account.h"

/**
 * @brief Construct a new Trust_Account::Trust_Account object
 * 
 * @param name 
 * @param balance 
 * @param int_rate 
 */
Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance,int_rate}{
        no_of_tx = 0;
}

/**
 * @brief Deposit Method which overides the Savings Account Method, if dep amount greater than thresh then bonus
 * 
 * @param amount 
 * @return true Success deposit
 * @return false Non success deposit
 */
bool Trust_Account::deposit(double amount) {
    if(amount > 50000000)
    {
        amount = amount+5000;
    }
    return Savings_Account::deposit(amount);
}

/**
 * @brief Withdraw Method which overrides Savings Account Method, allows only 3 transactions
 * 
 * @param amount 
 * @return true 
 * @return false 
 */
bool Trust_Account::withdraw(double amount)
{
    if (no_of_tx < 3)
    {
        if (Savings_Account::withdraw(amount))
        {
            ++no_of_tx;
            return true;
        }
    }
    return false;
}

/**
 * @brief To enable << operator on our object
 * 
 * @param os 
 * @param account 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}