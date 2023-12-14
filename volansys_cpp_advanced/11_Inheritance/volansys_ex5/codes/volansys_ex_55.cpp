/**
 * @file volansys_ex_55.cpp
 * @author rohit S
 * @brief Extra Challenges of Inheritance Lesson of C++ Advance 
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Extra Challenge 5
 * Create a class named Shape with a function that prints "This is a shape". 
 * Create another class named Polygon inheriting the Shape class with the same function that prints "Polygon is a shape". 
 * Create two other classes named Rectangle and Triangle having the same function which prints "Rectangle is a polygon" and "Triangle is a polygon" 
 * respectively. 
 * 
 * Again, make another class named Square having the same function which prints "Square is a rectangle".
 * 
 * 
 * Now, try calling the function by the object of each of these classes.
 * 
 */

#include <iostream>

using namespace std;

class Shape{

public:
    void print()
    {
        cout << "This is a shape\n";
    }
};

class Polygon: public Shape{

public: 
    void print()
    {
        cout << "Polygon is a shape\n";
    }
};

class Rectangle: public Polygon{

public: 
    void print()
    {
        cout << "Rectangle is a polygon\n";
    }

};

class Triangle: public Polygon{

public: 
    void print()
    {
        cout << "Trianle is a polygon\n";
    }

};

class Square: public Rectangle{
public: 
    void print()
    {
        cout << "Square is a Rectangle\n";
    }
};

int main()
{
    Shape shape;
    Polygon polygon;
    Rectangle rectangle;
    Triangle triangle;
    Square square;

    shape.print();
    polygon.print();
    rectangle.print();
    triangle.print();
    square.print();

    return 0;



}