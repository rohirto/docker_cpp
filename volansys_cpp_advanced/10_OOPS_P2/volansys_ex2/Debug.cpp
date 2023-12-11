/**
 * @file Debug.cpp
 * @author rohit S
 * @brief Debug code to display colored elements on terminal
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */

#include "Debug.h"
#include <iostream>

using namespace std;

template <typename T>
void Debug::display_red(T str)
{
    cout << "\033[1;31m" << str << "\033[0m\n";
}

template <typename T>
void Debug::display_green(T str)
{
    cout << "\033[1;32m" << str << "\033[0m\n";
}

template <typename T>
void Debug::display_yellow(T str)
{
    cout << "\033[1;33m" << str << "\033[0m\n";
}

template <typename T>
void Debug::display_blue(T str)
{
    cout << "\033[1;34m" << str << "\033[0m\n";
}

void Debug::display_decorator()
{
    cout << "===============================\n";
}

Debug::Debug()
{
	cout << "Debug Object Created" << endl;
}

Debug::~Debug()
{
	cout << "Debug Object Destroyed" << endl;
}