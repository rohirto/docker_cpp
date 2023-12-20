/**
 * @file exception_handling_smart_ptrs.cpp
 * @author rohirto
 * @brief Using Smart pointers and exception handling to catch exceptions durong dynamic mem alloc
 * @version 0.1
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>

using namespace std;

class SomeClass
{
public:
    SomeClass() {}
    ~SomeClass(){};
};

typedef boost::shared_ptr<SomeClass> pSomeClass;
typedef boost::shared_ptr<char> pChar;
typedef boost::shared_array<char> charBuff;

class MyException
{
public:
    MyException(string str)
    {
        msg = str;
    }
    void printerrmsg()
    {
        cout << msg.c_str() << endl;
    }

private:
    string msg;
};
class A
{
private:
    int i;
    pChar m_ptrChar;
    pSomeClass m_ptrSomeClass;
    charBuff m_pcharBuff;

    // if exception is thrown in the constructor of A, i will be destroyed by stack unwinding
    // and the thrown exception will be caught
public:
    A() : m_ptrChar(new char), m_ptrSomeClass(new SomeClass), m_pcharBuff(new char[100])
    {
        i = 10;
        throw MyException("Exception at A's constructor");
    }
};

int main()
{
    try
    {
        A objA;
    }
    catch (MyException &e)
    {
        e.printerrmsg();
    }
    return 1;
}