/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Mega Challenge of C++ Basics Course
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Mega Challenge
 * 
 * This challenge involves writing a bank account program using C++. Your program should display the depositor’s name, 
 * account number, account type, and balance. 
 *
 * You must also feature functions that display the name, allow the withdrawal, assign the initial values, 
 * and deposit the requested amount. As well as implement the features to calculate simple interest quarter bases, 
 * show mini statement of 5 transections.
 * 
 * The correct answer must include the right variables, classes, objects, clear comments, and relevant member functions 
 * so the bank program will run correctly.
 * 
 * Define a class to represent a bank account.
 * 
 * Data members:
 * 1) Name of the depositor
 * 2) Account number
 * 3) Type of account
 * 4) Balance amount in the account.
 * 
 * Member functions:
 * 1) To assign initial values
 * 2) To deposit an amount
 * 3) To withdraw an amount after checking the balance
 * 4) To display name and balance
 * 5) To display Interest in given quarter
 * 6) To display mini statement last 5 transections
 * 
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Debug{
public:
template <typename T>
void display_red(T str)
{
    cout << "\033[1;31m" << str << "\033[0m\n";
}
template <typename T>
void display_green(T str)
{
    cout << "\033[1;32m" << str << "\033[0m\n";
}
template <typename T>
void display_yellow(T str)
{
    cout << "\033[1;33m" << str << "\033[0m\n";
}
template <typename T>
void display_blue(T str)
{
    cout << "\033[1;34m" << str << "\033[0m\n";
}
void display_decorator()
{
    cout << "===============================\n";
}

Debug()
{
	cout << "Debug Object Created" << endl;
}

~Debug()
{
	cout << "Debug Object Destroyed" << endl;
}

//Friend Class Declaration
friend class bank_account;

};

class bank_account{

	struct transactions
	{
		char nature_of_transaction; /**< 'd' Debit, 'c' Credit */
		double amount;				/**< Amount involved in transaction*/
		double rem_bal;				/**< Remaining balance */
	};
	static int i;

private:
	string depositor_name {}; 		/**< Depositor name*/
	int account_number;				/**< account number */
	char type_of_account; 			/**< 'S' Savings, 'C' Current */
	double balance;					/**< Balance in the account*/
	//struct transactions t[5];		/**< Last 5 transactions */
	vector <transactions> t;		/**< Last 5 Transactions */

public:
bank_account(Debug& d)
{
	balance = 0;
	d.display_decorator();
	d.display_yellow("BANK PROGRAM");
	d.display_green("1. Enter Account number: ");
	account_number = get_account_no(d);
	d.display_green("2. Enter type of account (S for Savings, C for Cuurent)");
	type_of_account = get_acc_type(d);
	d.display_green("Enter Depositor's Name: ");
	while(!get_dep_name(d,depositor_name))
	{
		d.display_red("Invalid name, try again!");
	}
	
}

void deposit(Debug& d)
{
	double amount;
	d.display_decorator();
	d.display_green("Enter an Amount to deposit: ");
	while(!get_double(d,amount))
	{
		d.display_red("Invalid Amount Try Again! (q to quit the transaction)");
	}
	if(amount != -1) //Valid Amount was recieved
	{
		balance += amount;
		update_transactions('c',amount);
	}
	else
		d.display_red("Transaction Cancelled!");
}

void withdraw(Debug& d)
{
	double amount;
	d.display_decorator();
	d.display_blue("Present Balance : ");
	d.display_yellow(balance);
	d.display_green("Enter the amount you wish to withdraw: ");
	while(!get_double(d,amount))
	{
		d.display_red("Invalid Amount Try Again!(q to quit)");
	}
	if(amount == -1)  //Transaction cancelled by user
	{
		d.display_red("Transaction Cancelled!");
	}
	else if(balance > amount)
	{
		balance -=amount;
		d.display_yellow("Amount Successfully Withdrawn!");
		d.display_blue("Remaining Balance: ");
		d.display_green(balance);
		update_transactions('d',amount);
	}
	else
	{
		d.display_red("Insufficent Balance");
		d.display_green(balance);
	}
	

}
void acc_info(Debug& d)
{
	d.display_decorator();
	d.display_yellow("Account name: ");
	d.display_green(depositor_name);
	d.display_yellow("Account Balance: ");
	d.display_green(balance);
}

void display_si(Debug& d)
{
	// double si = (balance*)
}
void mini_statement(Debug& d)
{
	d.display_decorator();
	d.display_yellow("Last 5 Transactions: ");
	cout << "Cr/Dd"<<"\t"<<"Amount"<<"\t"<<"Rem Bal"<<endl;

	for(const transactions& i: t)
	{

		cout << i.nature_of_transaction << "\t" << i.amount << "\t" << i.rem_bal << endl;
	}
}

private:
void Display_menu(Debug& d)
{
	
	

}
char get_acc_type(Debug& d)
{
    char choice;
	do
	{
		cin >> choice;
		choice = toupper(choice);

		if(choice != 'C' && choice != 'S')
		{
			d.display_red("Invalid Input");
			d.display_green("Try Again: ");
		}
	} while (choice != 'C' && choice != 'S');
    return choice;

}
int get_account_no(Debug& d)
{
	int a;
	cin >> a;
	while(!cin.good())
    {
        d.display_red("Invalid Input");
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        d.display_yellow("Try Again: ");
        cin >> a;
    }
	return a;
}

bool get_dep_name(Debug& d, string& s)
{
	getline(cin >> ws,s);

	for(size_t i = 0; i < s.size(); i++)
	{
		if(isdigit(s[i]))
		{
			//There is a number
			return false;
		}
	}
	return true;
}

bool get_double(Debug& d, double& num)
{
	string input_msg {};
    getline(cin >> ws,input_msg);

	// Parse the input string
    istringstream iss(input_msg);

	while (!iss.eof())
	{
		if(iss.peek() == 'q')
		{
			//Quit
			num = -1;
			return true;
		}
		else if(isalpha(iss.peek()))
		{
			return false;
		}
		else
		{
			iss >> num;
		}
	}
	return true;
}

void update_transactions(char nature, double amount)
{
	if(t.size() > 4)
	{
		t.erase(t.begin());
	}
	struct transactions temp;

	temp.nature_of_transaction = nature;
	temp.amount = amount;
	temp.rem_bal = balance;

	t.push_back(temp);

}


};

int bank_account::i = 0;

int main() {
	Debug debug;
	bank_account account(debug);

	while(1)
	{
		char c;
		debug.display_decorator();
		debug.display_yellow("1. deposit an amount\n2. withdraw an amount\n3. display name and balance\n4. display Interest in given quarter\n5. display mini statement last 5 transections");
		cin >> c;

		switch (c)
		{
		case '1':
			account.deposit(debug);
			break;
		case '2':
			account.withdraw(debug);
			break;
		case '3':
			account.acc_info(debug);
			break;
		case '4':
			break;
		case '5':
			account.mini_statement(debug);
			break;
		default:
			debug.display_red("Invalid Input!");
			break;
		}
	}

	

	return 0;
}