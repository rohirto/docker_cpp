// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    vector<Checking_Account> chk_accounts;
    chk_accounts.push_back(Checking_Account {} );
    chk_accounts.push_back(Checking_Account {"Charmendaer"} );
    chk_accounts.push_back(Checking_Account {"Squirtle", 2000} );
    chk_accounts.push_back(Checking_Account {"Bulbusaur", 5000} );

    display(chk_accounts);
    deposit(chk_accounts, 1000);
    withdraw(chk_accounts,800);
    deposit(chk_accounts,1000);
    withdraw(chk_accounts, 2000);

    vector<Trust_Account> t_accounts;
    t_accounts.push_back(Trust_Account {} );
    t_accounts.push_back(Trust_Account {"Hulk"} );
    t_accounts.push_back(Trust_Account {"Thor", 2000} );
    t_accounts.push_back(Trust_Account {"Iron Man", 50000000,5.0} );

    display(t_accounts);
    deposit(t_accounts, 1000000);
    withdraw(t_accounts, 2000000);
    deposit(t_accounts, 2000000);
    withdraw(t_accounts, 2000000);
    deposit(t_accounts, 50000001);
    withdraw(t_accounts, 2000000);
    deposit(t_accounts, 1000000);
    withdraw(t_accounts, 2000000);

    

    return 0;
}

