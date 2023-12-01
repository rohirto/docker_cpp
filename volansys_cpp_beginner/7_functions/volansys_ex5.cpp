/**
 * @file volansys_ex5.cpp
 * @author rohit S
 * @brief Challenge 6 of C++ Basic Course
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023 Volansys technologies
 * 
 * @paragraph Challenge 6
 * Recall the challenge 4 from "Controlling Program flow" section below.
    Your challenge is to modularize your solution to the challenge 4
    by refactoring your solution so that it uses functions.
    
    You decide how to modularize the program.
    
    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.
    
        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth
        
    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!
    
    Finally,  don't forget to use function prototypes!
    
    Good luck -- I know you can do it!
*/
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!
 */


#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

void display_red(auto str)
{
    cout << "\033[1;31m" << str << "\033[0m\n";
}
void display_green(auto str)
{
    cout << "\033[1;32m" << str << "\033[0m\n";
}
void display_yellow(auto str)
{
    cout << "\033[1;33m" << str << "\033[0m\n";
}
void display_blue(auto str)
{
    cout << "\033[1;34m" << str << "\033[0m\n";
}
void display_decorator()
{
    cout << "===============================\n";
}

void display_menu()
{
    display_green("P - Print numbers\nA - Add a number\nM - Display mean of the numbers\nS - Display the smallest number\nL - Display the largest number\nN - Search Number\nC - Clear the List\nQ - Quit");
    display_blue("Enter your choice: ");
}

char get_choice()
{
    char choice;
    cin >> choice;
    return toupper(choice);

}

void print_numbers(vector<int>& vec)
{
    
    if(vec.size() > 0)
    {
        display_decorator();
        for_each(vec.begin(), vec.end(),[](const auto & elem){display_blue(elem);});
        cout << endl;
        display_decorator();
    }
    else
    {
        display_decorator();
        display_red("[] - the list is empty");
        display_decorator();
    }
}

void add_number(vector<int>& vec)
{
    int a;
    display_decorator();
    display_yellow("Enter a number to add to list");
    cin >> a;
    while(!cin.good())
    {
        display_red("Invalid Input");
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        display_yellow("Enter a number to add to list");
        cin >> a;
    }
    vector<int>::iterator it;
    it = find(vec.begin(), vec.end(), a);
    if(it == vec.end())
    {
        vec.push_back(a);  //If not a dupli entry only then add
        display_yellow(a);
        display_blue("added.");
    }
    else
    {
        display_red("Duplicate entry!");
    }
    
    
    display_decorator();
}

void calculate_mean(vector<int>& vec)
{

    display_decorator();
    if(vec.size() != 0)
    {
        int mean = 0;
        mean = accumulate(vec.begin(),vec.end(), mean);
        mean = mean/vec.size();
        display_yellow(mean);
        
        
    }
    else
    {
        display_red("Unable to calculate the mean - no data");
    }
    display_decorator();
}

void display_smallest(vector<int>& vec)
{
   
    display_decorator();
    if(vec.size()!=0)
    {
        display_yellow("The smallest number is ");
        display_yellow(*min_element(vec.begin(),vec.end()));
    }
    else
    {
        display_red("Unable to determine the smallest number - list is empty");
    }
    display_decorator();
}
void display_largest(vector<int>& vec)
{

    display_decorator();
    if(vec.size()!=0)
    {
        display_yellow("The largest number is ");
        display_yellow(*max_element(vec.begin(),vec.end()));
    }
    else
    {
        display_red("Unable to determine the largest number - list is empty");
    }
    display_decorator();
}
void search_number(vector<int>& vec)
{
    int a;
   
    display_decorator();
    display_yellow("Enter a number to search the list");
    cin >> a;
    while(!cin.good())
    {
        display_red("Invalid Input");
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        display_yellow("Enter a number to search the list");
        cin >> a;
    }
    vector<int>::iterator it;
    it = find(vec.begin(), vec.end(), a);
    if (it != vec.end())
    {
        cout << "Element " << a << " found at position : ";
        cout << it - vec.begin() << " (counting from zero) \n";
    }
    else
        display_red("Element not found.\n\n");

    display_decorator();
}

void clear_list(vector<int>& vec)
{
    display_decorator();
    vec.clear();
    display_red("Cleared the List");
    display_decorator();
}


int main() {

    vector<int> numbers {};
    char selection {};
    
    do {
        // Display menu
        display_menu();
        //Get choice 
        selection = get_choice();

        
        switch (selection)
        {
        case 'P':
            print_numbers(numbers);
            break;
        case 'A':
            add_number(numbers);
            break;
        case 'M':
            calculate_mean(numbers);
            break;
        case 'S':
            display_smallest(numbers);
            break;
        case 'L':
            display_largest(numbers);
            break;
        case 'N':
            search_number(numbers);
            break;
        case 'C':
            clear_list(numbers);
            break;
        case 'Q':
            display_red("GoodBye!");
            break;
        default:
            display_red("Unknown selection, please try again");
            break;
        }
    } while (selection != 'Q');
    
    cout  << endl;
    return 0;
}

