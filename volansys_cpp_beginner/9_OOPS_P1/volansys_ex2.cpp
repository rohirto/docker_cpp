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
#include <cmath>

using namespace std;


/**
 * @brief Debug class to print statements in colored format on terminal
 * @class Debug
 * 
 */
class Debug{
public:
/**
 * @brief Display a template in red color on terminal
 * 
 * @tparam T 
 * @param str 
 */
template <typename T>
void display_red(T str)
{
    cout << "\033[1;31m" << str << "\033[0m\n";
}

/**
 * @brief Display a template in Green color on terminal
 * 
 * @tparam T 
 * @param str 
 */
template <typename T>
void display_green(T str)
{
    cout << "\033[1;32m" << str << "\033[0m\n";
}

/**
 * @brief Display a template in yellow color on terminal
 * 
 * @tparam T 
 * @param str 
 */
template <typename T>
void display_yellow(T str)
{
    cout << "\033[1;33m" << str << "\033[0m\n";
}

/**
 * @brief Display a template in blue color on terminal
 * 
 * @tparam T 
 * @param str 
 */
template <typename T>
void display_blue(T str)
{
    cout << "\033[1;34m" << str << "\033[0m\n";
}

/**
 * @brief Display the decorator to make output more organized
 * 
 */
void display_decorator()
{
    cout << "===============================\n";
}

/**
 * @brief Construct a new Debug object
 * 
 */
Debug()
{
	cout << "Debug Object Created" << endl;
}

/**
 * @brief Destroy the Debug object
 * 
 */
~Debug()
{
	cout << "Debug Object Destroyed" << endl;
}

//Friend Class Declaration
friend class bank_account;	/**< Friend class Bank account */

};

/**
 * @brief bank account class 
 * @class bank_account
 */
class bank_account{

	/**
	 * @brief struct transactions
	 * 
	 */
	struct transactions
	{
		char nature_of_transaction; /**< 'd' Debit, 'c' Credit */
		double amount;				/**< Amount involved in transaction*/
		double rem_bal;				/**< Remaining balance */
	};


private:
	string depositor_name {}; 		/**< Depositor name*/
	int account_number;				/**< account number */
	char type_of_account; 			/**< 'S' Savings, 'C' Current */
	unsigned int day;				/**< Day of Opening of Acc*/
	unsigned int month; 			/**< Month of opening of Acc*/
	unsigned int year;				/**< Year of opening of account */
	unsigned int no_of_quaters;		/**< No of quaters passed */
	double balance;					/**< Balance in the account*/
	//struct transactions t[5];		/**< Last 5 transactions */
	vector <transactions> t;		/**< Last 5 Transactions */

public:
/**
 * @brief Construct a new bank account object
 * 
 * @param d debug object of class Debug -> for printing purpose
 */
explicit bank_account(Debug& d)
{
	balance = 0;
	d.display_decorator();
	d.display_yellow("BANK PROGRAM");
	d.display_green("1. Enter Account number: ");
	account_number = get_int(d);
	d.display_green("2. Enter type of account (S for Savings, C for Cuurent)");
	type_of_account = get_acc_type(d);
	d.display_green("Enter Depositor's Name: ");
	while(!get_dep_name(d,depositor_name))
	{
		d.display_red("Invalid name, try again!");
	}
	d.display_green("Enter Account Opening Date: ");
	while(!get_date(d,day,month,year))
	{
		d.display_red("Invalid date, try again!");
	}
	
}

/**
 * @brief Deposit method - to depo an amount
 * 
 * @param d debug object of class Debug -> for printing purpose
 */
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

/**
 * @brief Withdraw Method -> to withdraw an amount from account
 * 
 * @param d debug object of class Debug -> for printing purpose
 */
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

/**
 * @brief Method to display account info
 * 
 * @param d debug object of class Debug -> for printing purpose
 */
void acc_info(Debug& d)
{
	d.display_decorator();
	d.display_yellow("Account name: ");
	d.display_green(depositor_name);
	d.display_yellow("Account Balance: ");
	d.display_green(balance);
}

/**
 * @brief Method to calculate Simple Interest for given quater
 * 
 * @param d 
 */
void display_si(Debug& d)
{
	// double si = (balance*)
	// Declare variables

    double principal, rate, interest;

	principal = balance;
	rate = 4;  //4% Interest Rate

	interest = (principal*rate)/400;
	d.display_decorator();
	d.display_yellow("SI for given Quater is: ");
	d.display_green(interest);

}

/**
 * @brief Method to display last 5 transactions to user
 * 
 * @param d debug object of class Debug -> for printing purpose
 */
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
/**
 * @brief Get the acc type method -> savings or cuurent, with error handling
 * 
 * @param d debug object of class Debug -> for printing purpose
 * @return char 'S' or 'C'
 */
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

/**
 * @brief Get the int method -> gets int variable from cin with error handling
 * 
 * @param d debug object of class Debug -> for printing purpose
 * @return int -> valid int variable
 */
int get_int(Debug& d)
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

/**
 * @brief Get the dep name Method -> gets a alpha string from cin, no numerals allowes
 * 
 * @param d debug object of class Debug -> for printing purpose
 * @param s string where cin data will be copied to
 * @return true if valid string received
 * @return false if invalid string received
 */
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

/**
 * @brief Get the double method, get a double variable from cin, no alpha allowed
 * 
 * @param d debug object of class Debug -> for printing purpose
 * @param num variable where cin data will be copied
 * @return true if valid double variable
 * @return false if invalid double variable
 */
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

/**
 * @brief Update transactions method -> to record transactions when withdrwals and deposits happen
 * 
 * @param nature nature of Transcations 'c' -> credit or 'd' -> debit
 * @param amount involved in transactions
 */
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

/**
 * @brief Get the date object
 * 
 * @param d debug object of class Debug -> for printing purpose
 * @param dy day
 * @param m month
 * @param y year
 * @return true If valid input from user
 * @return false If invalid input from user
 */
bool get_date(Debug& d, unsigned int& dy,unsigned int& m,unsigned int& y)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);

	d.display_green("Enter Day of Acc opening(DD): ");
	dy = get_int(d);
	if((dy < 1) || (dy > 31))
	{
		return false;
	}

	d.display_green("Enter Month of Acc opening(MM): ");
	m = get_int(d);
	if((m < 1) || (m > 12))
	{
		return false;
	}

	d.display_green("Enter Year of Acc opening(YYYY): ");
	y = get_int(d);
	if(static_cast<int>(y) > (1900 + ltm->tm_year) || static_cast<int>(y) < 1900)
	{
		return false;
	}
	else if(static_cast<int>(m) > (1 + ltm->tm_mon))
	{
		return false;
	}

	no_of_quaters = ((((1900 + ltm->tm_year) - y)*12)+((1 + ltm->tm_mon) - m))/4;


	return true;
}


};

/**
 * @brief Main function
 * 
 * @return int 
 */
int main() {
	Debug debug;
	bank_account account(debug);
	char c;

	do
	{
		
		debug.display_decorator();
		debug.display_yellow("1. deposit an amount\n2. withdraw an amount\n3. display name and balance\n4. display Interest in given quarter\n5. display mini statement last 5 transections\n (q to quit)");
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
			account.display_si(debug);
			break;
		case '5':
			account.mini_statement(debug);
			break;
		case 'q':
			debug.display_red("Quitting Program");
			break;
		default:
			debug.display_red("Invalid Input!");
			break;
		}
	}while(c != 'q');

	

	return 0;
}