/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 1 of Polymorphism Lesson C++ Advance
 * @version 0.1
 * @date 2023-12-15
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 1
 * Write a program which demonstrate polymorphism with following example:
 * Create class "shape" with member function calvolume( ). 
 * Derive three classes "cube", "cone" and "cylinder" from the class shape. 
 * Make calvolume( ) as virtual function and redefine this function in the derived classes to calculate the volume of respective shape. 
 * (assume necessary data members for all the classes).
 * 
 */

#include <iostream>
#include <math.h>

using namespace std;

class shape{

public:
    virtual double calvolume()=0;
    virtual ~shape(){};

};


class cube: public shape{
private:
    double side;
public:
    explicit cube(double s):side(s){}
    double calvolume() override { return pow(side,3);} ;
};

class cone: public shape{
private:
    double base;
    double height;
public:
    explicit cone(double b, double h):base(b),height(h){}
    double calvolume() override {return (M_PI*(pow(base,2)*height))/3;} ;
};

class cylinder: public shape{
private:
    double radius;
    double lenght;
public:
    explicit cylinder(double r, double l):radius(r), lenght(l){}
    double calvolume() override {return M_PI*(pow(radius,2)*lenght);} ;
};

int main()
{


    shape *s = new cube(3);
    cout << "Volume of " << "Cube: " << s->calvolume() << endl;
    delete s;

    shape *c = new cone(2,4);
    cout << "Volume of " << "Cone: " << c->calvolume() << endl;
    delete c;

    shape *cy = new cylinder(3,8);
    cout << "Volume of " << "Cylinder: " << cy->calvolume() << endl;
    delete cy;

    return 0;
}
