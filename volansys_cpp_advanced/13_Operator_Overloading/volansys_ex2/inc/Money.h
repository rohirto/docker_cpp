#ifndef _MONEY_H
#define _MONEY_H

#include <iostream>


class Money {
    int rupees;
    int paisa;
public:
    Money(int rupees, int paisa);
    Money(int total);


    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR METHOD DECLARATIONS BELOW THIS LINE----
    bool operator==(const Money& other);
    bool operator!=(const Money& other);
    friend Money operator+(const Money& m1, const Money& m2);

    void print();
    
    
    //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
};

#endif //_MONEY_MONEY_H