/*
Given the provided Money class,  please add the overloaded stream insertion  << operator so that it displays a Money object on a output stream as follows.

If the Money object models 1 rupee and 70 paisa, the output should be:

Money amount {1, 70};
std::cout << amount;
rupees: 1 paisa: 70

You need to write the overloaded operator function.

This overloaded operator should return a reference to a std::ostream object and should be implemented as a non-member friend function.

First, add the overloaded friend operator function declaration to the Money class declaration in Money.h

Second, add the overloaded operator function definition in Money.cpp

This overloaded operator function should not modify the Money object in any way.
*/

#include <iostream>
#include "Money.h"

using namespace std;

int main() 
{
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
	//----WRITE YOUR CODE BELOW THIS LINE----

	//	Create and objects of Money class and perform comparison using the overloaded comparison operator
    Money m1(12,23);
    Money m2(11,45);
    Money m3(12,23);

    if(m1 == m2)
    {
        cout << "m1 and m2 are equal\n";
    }
    if(m1 != m2)
    {
        cout << "m1 and m2 are NOT equal\n";
    }
    if(m1 == m3)
    {
        cout << "m1 and m3 are equal\n";
    }
    if(m1 != m3)
    {
        cout << "m1 and m3 are NOT equal\n";
    }

    Money m4{m1+m2};
    
    cout << m4;



	//----WRITE YOUR CODE ABOVE THIS LINE----
	return 0;
}
