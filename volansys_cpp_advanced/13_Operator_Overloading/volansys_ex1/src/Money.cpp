/*
Given the provided Money class,  please add the overloaded equality operators == and !=

These overloaded operators should return a bool and should be implemented as member functions.

Given 2 Money objects, consider them to be equal if both the rupees and paisa attributes are the same for both objects.

First, add the overloaded operator function declarations to the Money class declaration in Money.h

Second, add the overloaded operator function definitions in Money.cpp

These overloaded functions should not modify the objects in any way.
*/
#include "Money.h"

Money::Money(int rupees, int paisa) : rupees{rupees}, paisa{paisa} {}

Money::Money(int total) : rupees {total/100}, paisa{total%100}  {}
   

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----
bool Money::operator==(const Money& other)
{
    if(this->rupees == other.rupees && this->paisa == other.paisa)
    {   
        return true;

    }
    return false;

}

bool Money::operator!=(const Money& other)
{
    if(this->rupees != other.rupees && this->paisa != other.paisa)
    {   
        return true;

    }
    return false;
}

//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----