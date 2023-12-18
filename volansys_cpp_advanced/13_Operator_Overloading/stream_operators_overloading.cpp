/**
 * @file stream_operators_overloading.cpp
 * @author Demo of Stream Operators '>>' '<<' Overloading in Cpp
 * @brief 
 * @version 0.1
 * @date 2023-12-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;

class Complex
{
private:
	int real, imag;
public:
	Complex(int r = 0, int i =0)
	{ real = r; imag = i; }
	friend ostream & operator << (ostream &out, const Complex &c);  //Need friend keyword to access the private mem of this class
                                                                    // the & after ostream indicates that the function returns a reference to an ostream object. 
                                                                    // This is a common practice in C++ when overloading the stream insertion (<<) operator.
	friend istream & operator >> (istream &in, Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
	out << c.real;
	out << "+i" << c.imag << endl;
	return out;
}

istream & operator >> (istream &in, Complex &c)
{
	cout << "Enter Real Part ";
	in >> c.real;
	cout << "Enter Imaginary Part ";
	in >> c.imag;
	return in;
}

int main()
{
Complex c1;
cin >> c1;
cout << "The complex object is ";
cout << c1;
return 0;
}
