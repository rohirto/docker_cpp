/**
 * @file custom_deleter.cpp
 * @author rohirto
 * @brief demo of custom deleter in cpp
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <memory>
using namespace std;
 
//Custom deleter function declaration
void my_deleter(int* ptr){
    cout << "Deleting integer pointer with value: " << *ptr << endl;
    delete ptr;
    cout << "Delete Successful.";
}
 
 
int main()
{
    //int type smart pointer object
    shared_ptr<int> ptr {new int{5}, my_deleter};
    
    return 0;
}