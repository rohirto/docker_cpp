/**
 * @file named_constructor_idiom.cpp
 * @author rohirto
 * @brief Demo of named constructor Idiom
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// CPP program to demonstrate 
// named constructor idiom 
#include <iostream> 
#include <cmath> 
using namespace std; 
class Point  
{ 
    private: 
    float x1, y1; 
    Point(float x, float y) 
    { 
        x1 = x; 
        y1 = y; 
    }; 
public: 

    //Static Methods:
    //Two static methods, Polar and Rectangular, are provided to create Point instances with polar and rectangular coordinates, respectively.
    //These methods utilize the private constructor to initialize the coordinates.
    // polar(radius, angle) 
    static Point Polar(float, float);  
      
    // rectangular(x, y) 
    static Point Rectangular(float, float);  
    void display(); 
}; 
  
// utility function for displaying of coordinates 
void Point :: display() 
{ 
    cout << "x :: " << this->x1 <<endl; 
    cout << "y :: " << this->y1 <<endl; 
} 
  
// return polar coordinates 
Point Point :: Polar(float x, float y) 
{ 
    return Point(x*cos(y), x*sin(y)); 
} 
  
// return rectangular coordinates 
Point Point :: Rectangular(float x, float y) 
{ 
    return Point(x,y); 
} 
int main() 
{ 
    // Polar coordinates 
    Point pp = Point::Polar(5.7, 1.2); 
    cout << "polar coordinates \n"; 
    pp.display(); 
      
    // rectangular coordinates 
    Point pr = Point::Rectangular(5.7,1.2); 
    cout << "rectangular coordinates \n"; 
    pr.display(); 
    return 0; 
} 