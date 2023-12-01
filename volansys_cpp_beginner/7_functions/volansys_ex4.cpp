/**
 * @file volansys_ex4.cpp
 * @author rohit S
 * @brief Exercise 4 of Functions lesson C++ Basic Course
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 4
 * In this exercise you will create a program that calculates the total_amount of money that will be accumulated if you 
 * start with a paisa and double it everyday for n number of days.
 * 
 * E.g.
 * 
 * Day 1: Rs 0.01
 * 
 * Day 2: Rs 0.02
 * 
 * Day 3: Rs 0.04
 * 
 * . . .
 * 
 * . . .
 * 
 * . . .
 * 
 * Day 16: Rs 327.68
 * 
 * Day 17: Rs 655.36
 * 
 * Day 18: Rs 1310.72
 * 
 * For this program, assume that all money will be represented as a double value and so a paisa will be represented as 0.01.
 * 
 * Begin by completing the function prototype a_paisa_doubled_everyday which is passed an int and a double.
 * 
 * Now that the function prototype is declared, at the bottom of the file define the function.
 * 
 * The function should return the total_amount accumulated after n number of days. For example, if n = 18, the function should return 1310.72. 
 * The function should be able to calculate the total_amount for any number of days starting with any amount however the default amount should be a paisa.
 * 
 * Now, from the function body of amount_accumulated, declare and initialize the variable total_amount by calling the a_paisa_doubled_everyday 
 * function for n = 25 days.
 * 
 * Note: Make sure your logic checks for a base case and doesn't recurse forever.
 * 
 */

#include <iostream>
#include <iomanip>
using namespace std;

int function_activation_count {0};

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION PROTOTYPE BELOW THIS LINE----

double a_paisa_doubled_everyday(int , double = 0.01);  //Default condition in prototype

//----WRITE THE FUNCTION PROTOTYPE ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void amount_accumulated() {
//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION CALL BELOW THIS LINE----
double total_amount  = a_paisa_doubled_everyday(25);

    
//----WRITE THE FUNCTION CALL ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout <<  "If I start with a paisa and doubled it every day for 25 days, I will have Rs" << setprecision(10) << total_amount;
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION DEFINITION BELOW THIS LINE----

double a_paisa_doubled_everyday(int n, double amount) { //Default arg in prototype, here not needed
    function_activation_count++;
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE THE FUNCTION BODY BELOW THIS LINE----

    if(n == 1) //Base Condition
    {
        return amount;
    }
    else
    {
        return(a_paisa_doubled_everyday(n-1,2*amount));  //Do recursion for n days, double the amount
    }
    
    
    //----WRITE THE FUNCTION BODY ABOVE THIS LINE----
    //DO NOT MODIFY THE CODE BELOW THIS LINE----
}

int test_function_activation_count() {
    return function_activation_count;
}

int main() {
    
	amount_accumulated();
    
	cout << "function_activation_count: " << function_activation_count << endl;
    
	return 0;
}