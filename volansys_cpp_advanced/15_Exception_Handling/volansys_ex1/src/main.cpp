/***********************************************************************************************************
For this challenge we want to integrate our own user-defined exception classes into the Account class
hierarchy.

The account classes are provided for you.
Also, the IllegalBalanceException.h file contains the declaration for the IllegalBalanceException class.

What I would like you to do is:
1. Derive IllegalBalanceException from std::exception and implement the what() method to provide an exception message.
   This exception object should be thrown from the Account class constructor if an account object is created with a negative
   balance.

2. Derive InsufficentFundsException from std::exception and implement the what() method to provide an exception message.
   This exception object should be thrown if a withdraw results in a negative balance.
   You should throw this exception object from the Account withdraw method.

That's it - good luck!
Test your code in the main driver.

Have fun and experiment!
************************************************************************************************************/

#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

using namespace std;



int main()
{
   // test your code here

   vector<Savings_Account> sav_accounts;
   try
   {
      sav_accounts.push_back(Savings_Account{});
      sav_accounts.push_back(Savings_Account{"Superman"});
      sav_accounts.push_back(Savings_Account{"Batman", -1}); //Negative balance error, it will not be created
      sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});
   }
   catch (const IllegalBalanceException &e)
   {
      std::cerr << e.what() << '\n';
   }

   display(sav_accounts);

   try
   {
      deposit(sav_accounts, 1000);
      withdraw(sav_accounts, 2000);
   }
   catch (const InsufficentFundsException &e)
   {
      std::cerr << e.what() << '\n';
   }

   // Checking

   vector<Checking_Account> check_accounts;

   try
   {
      check_accounts.push_back(Checking_Account{});
      check_accounts.push_back(Checking_Account{"Kirk"});
      check_accounts.push_back(Checking_Account{"Spock", 2000});
      check_accounts.push_back(Checking_Account{"Bones", 5000});
   }
   catch (const IllegalBalanceException &e)
   {
      std::cerr << e.what() << '\n';
   }

   display(check_accounts);
   try
   {
      deposit(check_accounts, 1000);
      withdraw(check_accounts, 2000);
   }
   catch (const InsufficentFundsException &e)
   {
      std::cerr << e.what() << '\n';
   }

   // Trust

   vector<Trust_Account> trust_accounts;
   try
   {
      trust_accounts.push_back(Trust_Account{});
      trust_accounts.push_back(Trust_Account{"Athos", 10000, 5.0});
      trust_accounts.push_back(Trust_Account{"Porthos", 20000, 4.0});
      trust_accounts.push_back(Trust_Account{"Aramis", 30000});
   }
   catch (const IllegalBalanceException &e)
   {
      std::cerr << e.what() << '\n';
   }

   display(trust_accounts);
   try
   {
      deposit(trust_accounts, 1000);
      withdraw(trust_accounts, 3000);
   }
   catch (const InsufficentFundsException &e)
   {
      std::cerr << e.what() << '\n';
   }

   // Withdraw 5 times from each trust account
   // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
   for (int i = 1; i <= 5; i++)
   {
      try
      {
         withdraw(trust_accounts, 1000);
      }
      catch (const InsufficentFundsException &e)
      {
         std::cerr << e.what() << '\n';
      }
   }

   std::cout << "Program completed successfully" << std::endl;
   return 0;
}
