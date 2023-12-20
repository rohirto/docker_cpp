/**
 * @file exception_in destructor.cpp
 * @author rohirto
 * @brief Possible Exception in destructor
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<string>

using namespace std;

class Galaxy {

    private:
    string name;

    public:
    Galaxy(string arg_name) {
        name = arg_name;
        std :: cout << "Constructor of " << name << " galaxy got called." << std :: endl; 
    }   
    
    // From C++11 onwards, the destructors default to 'noexcept'
    // Writing a destructor without noexcept(false) would generate a compilation error.
    ~Galaxy() noexcept(false) {
        std :: cout << "Destructor of " << name << " galaxy got called." << std :: endl; 
        try {
            throw 1000000;
        } catch (int e) {
            std :: cout << "Exception " << e << " caught" << std :: endl;
        } catch (...) {
            std :: cout << "Some exception (don't know what :( )" << " caught" << std :: endl;
        }
    }
       
    void Form_Solar_System() {
        std :: cout << "Form solar system for " << name << " galaxy." << std :: endl; 
    }   
};

int main() {
    try {
        Galaxy g1("Milky Way");
        Galaxy g2("Andromeda");
        g1.Form_Solar_System();
        g2.Form_Solar_System();
    } catch (int e) {
        // Note the exception gets caught after stack unwinding is over.
        std :: cout << "Exception " << e << " caught" << std :: endl;
    }   
    return 0;
}