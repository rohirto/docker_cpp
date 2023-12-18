/*
Given the provided Money class,  please add the overloaded  + operator so that it will add two Money objects together and return a Money object 
representing their sum.

This overloaded operator should return a Money object and should be implemented as a non-member friend function.

First, add the overloaded operator function declaration to the Money class declaration in Money.h

Second, add the overloaded operator function definition in Money.cpp

This overloaded operator function should not modify the objects in any way.
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
    m4.print();



	//----WRITE YOUR CODE ABOVE THIS LINE----
	return 0;
}
