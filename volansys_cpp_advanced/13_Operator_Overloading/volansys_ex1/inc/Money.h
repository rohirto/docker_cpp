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
    
    
    //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
};

#endif //_MONEY_MONEY_H