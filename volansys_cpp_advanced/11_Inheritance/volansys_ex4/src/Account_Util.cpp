#include <iostream>
#include "Account_Util.h"

// Displays Account objects in a  vector of Account objects 
void display(const std::vector<Account> &accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}


// Helper functions for Savings Account class

// Displays Savings Account objects in a  vector of Savings Account objects 
void display(const std::vector<Savings_Account> &accounts) {
    std::cout << "\n=== Savings Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraw(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}

/**
 * @brief Checking Accounts display
 * 
 * @param accounts 
 */
void display(const std::vector<Checking_Account> &accounts) {
    std::cout << "\n=== Checking Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}


/**
 * @brief Deposit Function for Checking Account, uses base class function
 * 
 * @param accounts 
 * @param amount 
 */
void deposit(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Checking Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

/**
 * @brief Helper Function to withdraw amount from checking accounts, tx fee if amount greater than eq to 1000
 * 
 * @param accounts 
 * @param amount 
 */
void withdraw(std::vector<Checking_Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Checking Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (amount >= 1000)
        {
            if (acc.withdraw((amount+150)))
                std::cout << "Withdrew " << amount << " from " << acc <<  " Tx Fee 150" << std::endl;
            else
                std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
        }
        else
        {
            if (acc.withdraw(amount))
                std::cout << "Withdrew " << amount << " from " << acc << std::endl;
            else
                std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
        }
    } 
}


/**
 * @brief Displays Savings Account objects in a  vector of Savings Account objects 
 * 
 * @param accounts 
 */
void display(const std::vector<Trust_Account> &accounts) {
    std::cout << "\n=== Trust Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

/**
 * @brief Deposits supplied amount to each Savings Account object in the vector
 * 
 * @param accounts 
 * @param amount 
 */
void deposit(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Trust Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
        {
            std::cout << "Deposited " << amount << " to " << acc ;
            if(amount > 50000000)
            {
                std::cout << " With Bonus of 5000";
            }
            std::cout << std::endl;
        }

        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

/**
 * @brief Withdraw supplied amount from each Savings Account object in the vector
 * 
 * @param accounts 
 * @param amount 
 */
void withdraw(std::vector<Trust_Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Trust Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}
