/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Exercise 2 of Inheritance Lesson of C++ Advance
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 2
 * Area and Perimeter
 * The Area and Perimeter of Rectangle, Square, Circle and Rhombus is to be calculated. 
 * The class Shapes will have the functions read_rectangle(), read_square(), read_circle(), read_rhombus() to reads the inputs for respective side. 
 * The class Area will find the area of different shapes in their respective functions area_rectangle(), area_square(), area_circle(), area_rhombus(). 
 * The class Perimeter will find the perimeter of different shapes in their respective functions perimeter_rectangle(), perimeter_square(), perimeter_circle(), perimeter_rhombus().
 *
 * Input Format:
 * 
 * The first line consist of the length and breadth of the rectangle.
 * 
 * The second line consist of the side of the square.
 *
 * The third line consist of the radius of the circle.
 *
 * The fourth line consist of the two diagonals of the rhombus.
 *
 *
 * Constraints
 *
 * 1<= length, breadth <=10^5
 * 
 * 1<= side <=10^5
 *
 * 1<= radius <= 10^2
 *
 * 1<= diagonals <=10^3
 *
 *
 * Output Format:
 * For each shape, print the Perimeter and Area space separately in separate lines. 
 * The order of shapes being Rectangle, Square, Circle and Rhombus.
 *
 * Note: If the output is in decimal points then print upto 2 decimal places. The value of pi should be taken as 3.14.
 *
 * 
 * Sample:
 * 
 * Input:
 *
 * 4 3
 * 5
 * 2
 * 4 3
 *
 * Output:
 *
 * 14 12
 * 20 25
 * 12.56 12.56
 * 10.00 6.00
 * 
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

#define USER_PI 3.14

/**
 * @brief Shapes class, its the base class
 * 
 */
class Shapes{
private:
    /**
     * @brief Get the ip object
     * 
     * @return true if valid data 
     * @return false if invalid data
     */
    bool get_ip();
    vector<double> result; /**< To store the input from the user into vector and later assign it to indivudual variables */

protected:



public:
    void read_circle();
    void read_rectangle();
    void read_rhombus();
    void read_square();

    double l; /**< Len to rectangle */
    double w; /**< Width of rectangle*/
    double r; /**< Radius*/
    double d1; /**< Diagonal 1 of rhombus*/
    double d2; /**< Diagonal 2 of rhombus*/
    double a; /**< Side of square*/


};

/**
 * @brief Class Area which is derived with puclic access specifier from Base class shapes
 * 
 */
class Area: public Shapes{
private:

protected:

public:
    /**
     * @brief Calculate area of Circle
     * 
     * @return double 
     */
    double area_circle(){return USER_PI*(pow(r,2));}

    /**
     * @brief Calculate Area of rectangle
     * 
     * @return double 
     */
    double area_rectangle(){return l*w;}

    /**
     * @brief Calculate area of Rhombus
     * 
     * @return double 
     */
    double area_rhombus(){return (d1*d2)/2;}

    /**
     * @brief Calculate area of Square
     * 
     * @return double 
     */
    double area_square(){return pow(a,2);}


};

/**
 * @brief Class Perimeter which is a derived class with access specifier protected from Base class shapes
 * 
 */
class Perimeter: protected Shapes{
private:

protected:

public:
    /**
     * @brief Calculate Perimeter of Circle
     * 
     * @return double 
     */
    double perimeter_circle(){return 2*USER_PI*r;}

    /**
     * @brief Calculate Perimeter of Rectangle
     * 
     * @return double 
     */
    double perimeter_rectangle(){return (2*l+2*w);}

    /**
     * @brief Calculate Perimeter of Rhombus
     * 
     * @return double 
     */
    double perimeter_rhombus(){return 2*sqrt((pow(d1,2)+pow(d2,2)));}

    /**
     * @brief Calculate Perimeter of Square
     * 
     * @return double 
     */
    double perimeter_square(){return 4*a;}

    /**
     * @brief Copy data of attributes of area object to perimeter object, needed this because cannot again ask user to enter shapes for this object 
     * as well
     * 
     * @param area Object whose attributes are already initialized
     */
    void copy_data(const Area& area)
    {
        l = area.l;
        w = area.w;
        a = area.a;
        r = area.r;
        d1 = area.d1;
        d2 = area.d2;

    }
};


/**
 * @brief Read the Dimensions of Circle and check if the data is within the lower and upper limits
 * 
 */
void Shapes::read_circle()
{
    if (get_ip() == true)
    {
        if (result[0] >= 1 && result[0] <= 100)
        {
            r = result[0];
        }
    }
}

/**
 * @brief Read the Dimensions of Rectangle and check if the data is within the lower and upper limits
 * 
 */
void Shapes::read_rectangle()
{
    if (get_ip() == true)
    {
        if (result[0] >= 1 && result[0] <= 100000)
        {
            l = result[0];
        }
        if (result[1] >= 1 && result[1] <= 100000)
        {
            w = result[1];
        }
    }
}


/**
 * @brief Read the Dimensions of Rhombus and check if the data is within the lower and upper limits
 * 
 */
void Shapes::read_rhombus()
{
    if (get_ip() == true)
    {
        if (result[0] >= 1 && result[0] <= 100000)
        {
            d1 = result[0];
        }
        if (result[1] >= 1 && result[1] <= 100000)
        {
            d2 = result[1];
        }
    }
}


/**
 * @brief Read the Dimensions of Square and check if the data is within the lower and upper limits
 * 
 */
void Shapes::read_square()
{
    if (get_ip() == true)
    {
        if (result[0] >= 1 && result[0] <= 100000)
        {
            a = result[0];
        }
    }
}

/**
 * @brief Get input from the user and store it in a double vector to be utilized later to extract dimensions
 * 
 * @return true if valid data from user
 * @return false if invalid data from user
 */
bool Shapes::get_ip()
{
    double temp = 0;
    string input_msg {};
    getline(cin>>ws,input_msg);

    // Parse the input string
    istringstream iss(input_msg);

    //Empty the vector
    result.clear();
    // Read doubles from the stringstream

    while (!iss.eof())
    {
        if(isalpha(iss.peek()))
        {
            //Not a valid no
            return false;
        }
        else
		{
			iss >> temp;
            result.push_back(temp);
		}
    }

    return true;

}

/**
 * @brief Main function 
 * 
 * @return int 
 */
int main()
{
    //Write code here
    Area area;
    

    area.read_rectangle();
    area.read_square();
    area.read_circle();
    area.read_rhombus();

    Perimeter perimeter;
    perimeter.copy_data(area);

    // Calculate and print area and perimeter for each shape
    std::cout << std::fixed << std::setprecision(2);
    std::cout << perimeter.perimeter_rectangle() << " " << area.area_rectangle() << std::endl;
    std::cout << perimeter.perimeter_square() << " " << area.area_square() << std::endl;
    std::cout << perimeter.perimeter_circle() << " " << area.area_circle() << std::endl;
    std::cout << perimeter.perimeter_rhombus() << " " << area.area_rhombus() << std::endl;

    return 0;
}