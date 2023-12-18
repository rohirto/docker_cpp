#include <iostream>
#include "Account_Util.h"

void display(const std::vector<Account *> &accounts)
{
    // Check dynmaic cast
    for (const auto &acc : accounts)
    {
        if (Savings_Account *sa = dynamic_cast<Savings_Account *>(acc))
        {
            std::cout << "\n=== Savings Accounts=====================================" << std::endl;
            sa->print(std::cout);
        }
        else if (Checking_Account *ca = dynamic_cast<Checking_Account *>(acc))
        {
            std::cout << "\n=== Checking Accounts=====================================" << std::endl;
            ca->print(std::cout);
        }
        else if (Trust_Account *ta = dynamic_cast<Trust_Account *>(acc))
        {
            std::cout << "\n=== Trust Accounts=====================================" << std::endl;

            ta->print(std::cout);
        }
    }
}

void deposit(std::vector<Account *> &accounts, double amount)
{
    // Check dynmaic cast
    for (const auto &acc : accounts)
    {
        if (Savings_Account *sa = dynamic_cast<Savings_Account *>(acc))
        {
            std::cout << "\n=== Depositing to Savings Accounts===========================" << std::endl;

            if (sa->deposit(amount))
            {
                std::cout << "Deposited " << amount << " to " ;
                sa->print(std::cout);
            }
                
            else
            {
                std::cout << "Failed Deposit of " << amount << " to ";
                sa->print(std::cout);

            }
                
        }
        else if (Checking_Account *ca = dynamic_cast<Checking_Account *>(acc))
        {
            std::cout << "\n=== Depositing to Checking Accounts===========================" << std::endl;

            if (ca->Account::deposit(amount))
            {
                std::cout << "Deposited " << amount << " to ";
                ca->print(std::cout);


            }
                
            else
            {
                std::cout << "Failed Deposit of " << amount << " to ";
                ca->print(std::cout);

            }
                
        }
        else if (Trust_Account *ta = dynamic_cast<Trust_Account *>(acc))
        {
            std::cout << "\n=== Depositing to Trust Accounts===========================" << std::endl;

            if (ta->deposit(amount))
            {
                std::cout << "Deposited " << amount << " to " ;
                ta->print(std::cout);

            }
                
            else
            {
                std::cout << "Failed Deposit of " << amount << " to " ;
                ta->print(std::cout);

            }
                
        }
    }
}

void withdraw(std::vector<Account *> &accounts, double amount)
{
    // Check dynmaic cast
    for (const auto &acc : accounts)
    {
        if (Savings_Account *sa = dynamic_cast<Savings_Account *>(acc))
        {
            std::cout << "\n=== Withdrawing from Savings Accounts=======================" << std::endl;

            if (sa->Account::withdraw(amount))
            {
                std::cout << "Withdrew " << amount << " from " ;
                sa->print(std::cout);

            }
                
            else
            {
                std::cout << "Failed Withdrawal of " << amount << " from " ;
                sa->print(std::cout);

            }
                
        }
        else if (Checking_Account *ca = dynamic_cast<Checking_Account *>(acc))
        {
            std::cout << "\n=== Withdraw from Checking Accounts===========================" << std::endl;

            if (ca->withdraw(amount))
            {
                std::cout << "Withdrew " << amount << " from " ;
                ca->print(std::cout);

            }
                
            else
            {
                std::cout << "Failed Withdrawal of " << amount << " from " ;
                ca->print(std::cout);

            }
                
        }
        else if (Trust_Account *ta = dynamic_cast<Trust_Account *>(acc))
        {
            std::cout << "\n=== Withdraw from Trust Accounts===========================" << std::endl;

            if (ta->withdraw(amount))
            {
                std::cout << "Withdrew " << amount << " from " ;
                ta->print(std::cout);

            }
                
            else
            {
                std::cout << "Failed Withdrawal of " << amount << " from " ;
                ta->print(std::cout);

            }
                
        }
    }
}

// // Displays Account objects in a  vector of Account objects
// void display(const std::vector<Account> &accounts) {
//     std::cout << "\n=== Accounts===========================================" << std::endl;
//     for (const auto &acc: accounts)
//         std::cout << acc << std::endl;
// }

// Deposits supplied amount to each Account object in the vector
// void deposit(std::vector<Account> &accounts, double amount)
// {
//     std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
//     for (auto &acc : accounts)
//     {
//         if (acc.deposit(amount))
//             std::cout << "Deposited " << amount << " to " << acc << std::endl;
//         else
//             std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
//     }
// }

// Withdraw amount from each Account object in the vector
// void withdraw(std::vector<Account> &accounts, double amount)
// {
//     std::cout << "\n=== Withdrawing from Accounts ==============================" << std::endl;
//     for (auto &acc : accounts)
//     {
//         if (acc.withdraw(amount))
//             std::cout << "Withdrew " << amount << " from " << acc << std::endl;
//         else
//             std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
//     }
// }

// Helper functions for Savings Account class

// // Displays Savings Account objects in a  vector of Savings Account objects
// void display(const std::vector<Savings_Account> &accounts) {
//     std::cout << "\n=== Savings Accounts=====================================" << std::endl;
//     for (const auto &acc: accounts)
//         std::cout << acc << std::endl;
// }

// Deposits supplied amount to each Savings Account object in the vector
// void deposit(std::vector<Savings_Account> &accounts, double amount)
// {
//     std::cout << "\n=== Depositing to Savings Accounts===========================" << std::endl;
//     for (auto &acc : accounts)
//     {
//         if (acc.deposit(amount))
//             std::cout << "Deposited " << amount << " to " << acc << std::endl;
//         else
//             std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
//     }
// }

// Withdraw supplied amount from each Savings Account object in the vector
// void withdraw(std::vector<Savings_Account> &accounts, double amount)
// {
//     std::cout << "\n=== Withdrawing from Savings Accounts=======================" << std::endl;
//     for (auto &acc : accounts)
//     {
//         if (acc.Account::withdraw(amount))
//             std::cout << "Withdrew " << amount << " from " << acc << std::endl;
//         else
//             std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
//     }
// }

// Helper functions for Checking Account class

// // Displays Checking Account objects in a  vector of Checking Account objects
// void display(const std::vector<Checking_Account> &accounts)
// {
//     std::cout << "\n=== Checking Accounts=====================================" << std::endl;
//     for (const auto &acc : accounts)
//         std::cout << acc << std::endl;
// }

// Deposits supplied amount to each Checking Account object in the vector
// void deposit(std::vector<Checking_Account> &accounts, double amount)
// {
//     std::cout << "\n=== Depositing to Checking Accounts===========================" << std::endl;
//     for (auto &acc : accounts)
//     {
//         if (acc.Account::deposit(amount))
//             std::cout << "Deposited " << amount << " to " << acc << std::endl;
//         else
//             std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
//     }
// }

// Withdraw supplied amount from each Checking Account object in the vector
// void withdraw(std::vector<Checking_Account> &accounts, double amount)
// {
//     std::cout << "\n=== Withdrawing from Checking Accounts=======================" << std::endl;
//     for (auto &acc : accounts)
//     {
//         if (acc.withdraw(amount))
//             std::cout << "Withdrew " << amount << " from " << acc << std::endl;
//         else
//             std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
//     }
// }

// Helper functions for Trust Account class

// Displays Trust Account objects in a  vector of Trust Account objects
// void display(const std::vector<Trust_Account> &accounts)
// {
//     std::cout << "\n=== Trust Accounts=====================================" << std::endl;
//     for (const auto &acc : accounts)
//         std::cout << acc << std::endl;
// }

// Deposits supplied amount to each Trust Account object in the vector
// void deposit(std::vector<Trust_Account> &accounts, double amount)
// {
//     std::cout << "\n=== Depositing to Trust Accounts===========================" << std::endl;
//     for (auto &acc : accounts)
//     {
//         if (acc.deposit(amount))
//             std::cout << "Deposited " << amount << " to " << acc << std::endl;
//         else
//             std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
//     }
// }

// // Withdraw supplied amount from each Trust Account object in the vector
// void withdraw(std::vector<Trust_Account> &accounts, double amount)
// {
//     std::cout << "\n=== Withdrawing from Trust Accounts=======================" << std::endl;
//     for (auto &acc : accounts)
//     {
//         if (acc.withdraw(amount))
//             std::cout << "Withdrew " << amount << " from " << acc << std::endl;
//         else
//             std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
//     }
// }