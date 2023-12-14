/**
 * @file volansys_ex_56.cpp
 * @author rohit S
 * @brief Extra Challenges of Inheritance Lesson C++ Advance
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Extra Challenge 6
 * All the banks operating in India are controlled by RBI. RBI has set a well defined guideline (e.g. minimum interest rate, 
 * minimum balance allowed, maximum withdrawal limit etc) which all banks must follow. 
 * 
 * For example, suppose RBI has set minimum interest rate applicable to a saving bank account to be 4% annually; 
 * however, banks are free to use 4% interest rate or to set any rates above it.
 *
 * Write a program to implement bank functionality in the above scenario. 
 * Note: Create few classes namely Customer, Account, RBI (Base Class) and few derived classes (SBI, ICICI, PNB etc). 
 * Assume and implement required member variables and functions in each class.
 *
 * Hint:
 * 
 */
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Customer
{
private:
    string name;

public:
    string get_name(){return name;}
    void set_name(const string& s)
    {
        name = s;
    }
};
class Account
{
private:
    int acc_no;
    string acc_type;
    double balance;

public:
    Account():acc_no(0),acc_type(move("Savings")),balance(0){}
    int get_acc_no(){return acc_no;}
    string get_acc_type(){return acc_type;}

    void set_acc_no(int a)
    {
        acc_no = a;
    }

    void set_acc_type(const string& s)
    {
        acc_type = s;
    }

    bool deposit(double amount)
    {
        balance+=amount;
        return true;
    }

    bool withdraw(double amount)
    {
        if(amount < balance)
        {
            balance -=amount;
            return true;
        }
        return false;
    }

    double get_balance(){return balance;}


};
class RBI
{
    Customer c; // hasA relationship
    Account a;  // hasA relationship

protected:
    double interest_rate;
    double withdraw_limit;

public:
    RBI(double ir, double wl, const string& name, int acc_no, const string& acc_type):interest_rate(ir), withdraw_limit(wl)
    {
        c.set_name(name);
        a.set_acc_no(acc_no);
        a.set_acc_type(acc_type);
    }
    double GetInterestRate() {return interest_rate;}
    double GetWithdrawalLimit() {return withdraw_limit;}

    void deposit(double amount)
    {
        if(a.deposit(amount))
        {
            cout << " Deposit in Bank Acc no " << a.get_acc_no() <<" Amount: "<<fixed << setprecision(2) << amount<< " Success! \n"; 
        } 
        else
        {
            cout << " Deposit in Bank Acc no " << a.get_acc_no() << " FAILED! \n"; 
        }
        
    }
    void withdraw(double amount)
    {
        if(amount < withdraw_limit)
        {
            if (a.withdraw(amount))
            {
                cout << " Withdraw in Bank Acc no " << a.get_acc_no() << " Amount: "<<fixed << setprecision(2) << amount << " Success! \n";
            }
            else
            {
                cout << " Withdraw in Bank Acc no " << a.get_acc_no() << " FAILED! \n";
            }
        }
        else
        {
            cout << "Withdraw Limit exceeded!\n";
        }
    }

    void acc_details()
    {
        cout << "\nBank Details:\tAcc No: " << a.get_acc_no() << "\nAcc name: " << c.get_name() << "\t Interest Rate: " << RBI::GetInterestRate()
        << "\n Withdrawal Limit: " << RBI::GetWithdrawalLimit() << "\n Balance: " <<fixed << setprecision(2) << a.get_balance() <<endl;
    }
};
class SBI : public RBI
{
    
    // Use RBI functionality or define own functionality.

public:
    SBI(const string& name, int acc_no, const string& acc_type, double ir, double wl):RBI(ir,wl,name, acc_no,acc_type)
    {
        

    }
};
class ICICI : public RBI
{

public:
    ICICI(const string& name, int acc_no, const string& acc_type, double ir, double wl):RBI(ir,wl, name, acc_no, acc_type)
    {

    }

};

int main()
{
    SBI rohirto("rohirto",123,"Savings", 4, 100000);
    ICICI wer("wer",1234,"Current", 2, 20000);

    rohirto.deposit(1000000);
    wer.withdraw(100);

    rohirto.acc_details();


    return 0;
}