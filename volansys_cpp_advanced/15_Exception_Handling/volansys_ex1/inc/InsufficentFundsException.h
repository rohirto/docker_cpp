/**
 * @file InsufficentFundsException.h
 * @author rohit S
 * @brief Header file for Insufficent class Exception class
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */

#ifndef __INSUFFICENT_FUNDS_EXCEPTION_H__
#define __INSUFFICENT_FUNDS_EXCEPTION_H__


#include <exception>

class InsufficentFundsException: public std::exception{
public:
    InsufficentFundsException(){}
    ~InsufficentFundsException(){}
    const char* what() const noexcept override{
        return "Insufficent Funds Error";
    }

};

#endif
