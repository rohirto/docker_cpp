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

    friend std::ostream& operator<<(std::ostream &out, const Money &m);  //Need friend keyword to access the private mem of this class
                                                                    // the & after ostream indicates that the function returns a reference to an ostream object. 
                                                                    // This is a common practice in C++ when overloading the stream insertion (<<) operator.
    
    
    //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
};

#endif //_MONEY_MONEY_H