/**
 * @file friend_func_diff_operands.cpp
 * @author rohirto
 * @brief Demo of Friend function implementation when operands are of different data types
 * @version 0.1
 * @date 2023-12-18
 * 
 * @copyright Copyright (c) 2023
 * 
 * Note that when operands are of the same datatypes, you have to implement only one friend func, but when diff types operands, we need 2 types of friend func,
 * depending on the order:
 * friend operator+(Datatype 1, Datatype 2) => Friend func 1
 * friend operator+(Datatype 2, Datatype 1) => Friend func 2
 * 
 */

#include <iostream>

class Cents
{
private:
	int m_cents {};

public:
	Cents(int cents) : m_cents{ cents } { }

	// add Cents + int using a friend function
	friend Cents operator+(const Cents& c1, int value);

	// add int + Cents using a friend function
	friend Cents operator+(int value, const Cents& c1);


	int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, int value)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return c1.m_cents + value;
}

// note: this function is not a member function!
Cents operator+(int value, const Cents& c1)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return c1.m_cents + value;
}

int main()
{
	Cents c1{ Cents{ 4 } + 6 }; //Friend func 1
	Cents c2{ 6 + Cents{ 4 } }; //friend Func 2

	std::cout << "I have " << c1.getCents() << " cents.\n";
	std::cout << "I have " << c2.getCents() << " cents.\n";

	return 0;
}