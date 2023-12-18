/**
// Challenge
// Polymorphism

You are provided with a completed Account class hierarchy that was completed in previous section.
The provided class hierarchy does not use dynamic polymorphism (it has no virtual functions!)

Your challenge is the following:

1.  Modify the Account class so that it is now an Abstract class by adding the following pure virtual functions:
        virtual bool deposit(double amount) = 0;
        virtual bool withdraw(double amount) = 0;

        Hint: you can implement these functions in the Account class if it makes sense

2. Create an I_Printable class interface as we did in the course and provide functionality so
    all accounts are printable to an ostream using the overloaded insertion operator.
    
        class I_Printable
        {
            friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
        public:
            virtual void print(std::ostream &os) const = 0;
            virtual ~I_Printable() = default;
        };

3. Modify the functions in the Account_Util files so we only have one version of each. For example,

        void display(const std::vector<Account *> &accounts);
        void deposit(std::vector<Account *> &accounts, double amount);
        void withdraw(std::vector<Account *> &accounts, double amount);
        
        Note that the vector is a vector of pointers to Account objects <Account *>
        This is what we need for dynamic polymorphism.
        
4. Test your code with base class pointers as well as local objects.
    I provided a simple main driver that will get you started

Hints: 
    - Reuse existing functionality!!
    - If your class has a virtual function then be sure to implement a virtual destructor. 
       You can have the C++ generate a default destructor for you with:
           virtual ~Class_Name() = default;
    - Take it one step at a time.
    - Start by making the Account class abstract by adding the pure virtual functions.
    
Have fun!!  This is a very, very challenging exercise!
**/

#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts - Not possible now as my class is an abstract class
    // vector<Account* > accounts;
    // accounts.push_back(new Account {});
    // accounts.push_back(new Account {"Larry"});
    // accounts.push_back(new Account {"Moe", 2000} );
    // accounts.push_back(new Account {"Curly", 5000} );
    
    // display(accounts);
    // deposit(accounts, 1000);
    // withdraw(accounts,2000);
    
    // Savings 

    vector<Account* > sav_accounts;
    sav_accounts.push_back(new Savings_Account {} );
    sav_accounts.push_back(new Savings_Account {"Superman"} );
    sav_accounts.push_back(new Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(new Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
   // Checking
   
    vector<Account* > check_accounts;
    check_accounts.push_back(new Checking_Account {} );
    check_accounts.push_back(new Checking_Account {"Kirk"} );
    check_accounts.push_back(new Checking_Account {"Spock", 2000} );
    check_accounts.push_back(new Checking_Account {"Bones", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    vector<Account* > trust_accounts;
    trust_accounts.push_back(new Trust_Account {} );
    trust_accounts.push_back(new Trust_Account {"Athos", 10000, 5.0} );
    trust_accounts.push_back(new Trust_Account {"Porthos", 20000, 4.0} );
    trust_accounts.push_back(new Trust_Account {"Aramis", 30000} );

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
    
     // Clean up allocated memory
    // for (auto acc : accounts)
    //     delete acc;

    for (auto acc : sav_accounts)
        delete acc;

    for (auto acc : check_accounts)
        delete acc;

    for (auto acc : trust_accounts)
        delete acc;

    

    
    return 0;
}

