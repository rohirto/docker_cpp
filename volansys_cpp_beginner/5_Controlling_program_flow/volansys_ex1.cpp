/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 2 of Controlling Prgram Flow Lesson C++ Basic Course
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * @paragraph Exercise 2
 * 
 * Write a switch statement that displays the name of the day of the week given the day code.
 * Given the following day codes, your program should display the day of the week using a cout statement. No '\n ' or endl  should be used.
 *
 * Day Code        Display
 * --------        ------------------------
 *   0            Sunday
 *   1            Monday
 *   2            Tuesday
 *   3            Wednesday
 *   4            Thursday
 *   5            Friday
 *   6            Saturday
 * other          Error - illegal day code
 * 
 */

#include <iostream>
#include <string>

//Macros
#define SUNDAY      "Sunday"
#define MONDAY      "Monday"
#define TUESDAY     "Tuesday"
#define WEDNESDAY   "Wednesday"
#define THURSDAY    "Thursday"
#define FRIDAY      "Friday"
#define SATURDAY    "Saturday"
#define OTHER       "Error - illegal day code"

using namespace std;

string display_day(int day_code) 
{
    //----WRITE YOUR CODE BELOW THIS LINE----
    string day;
    switch(day_code)
    {
        case 0:
            day = SUNDAY;
            break;
        case 1:
            day = MONDAY;
            break;
        case 2:
            day = TUESDAY;
            break;
        case 3:
            day = WEDNESDAY;
            break;
        case 4:
            day = THURSDAY;
            break;
        case 5:
            day = FRIDAY;
            break;
        case 6:
            day = SATURDAY;
            break;
        default:
            day = OTHER;
            break;
    }

    return day; 
    //----WRITE YOUR CODE ABOVE THIS LINE----
}

int main()
{
	int dayCode{0};
	cout << "Enter the day_code" << endl;
	cin >> dayCode;
	cout << display_day(dayCode);
	return 0;
}