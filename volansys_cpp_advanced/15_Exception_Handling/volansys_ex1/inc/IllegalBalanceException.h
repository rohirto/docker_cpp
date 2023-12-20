#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

#include <exception>

class IllegalBalanceException: std::exception
{
public:
    IllegalBalanceException() {}
    ~IllegalBalanceException() {}

    const char* what() const noexcept override{
        return "Negative Balance Error";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
