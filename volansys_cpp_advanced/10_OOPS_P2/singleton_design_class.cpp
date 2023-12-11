/**
 * @file singleton_design_class.cpp
 * @author rohirto
 * @brief Singleton design class implementation
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @paragraph Singleton Design
 * The singleton pattern is one of the simplest design patterns. Sometimes we need to have only one instance of our class 
 * for example a single DB connection shared by multiple objects as creating a separate DB connection for every object may be costly. 
 * Similarly, there can be a single configuration manager or error manager in an application that handles all problems instead of creating 
 * multiple managers. The singleton pattern is a design pattern that restricts the instantiation of a class to one object. Let’s see various 
 * design options for implementing such a class. If you have a good handle on static class variables and access modifiers this should not 
 * be a difficult task.
 * 
 * Explanation:
 * 
 * The constructor, copy constructor, and assignment operator are declared as private to prevent external instantiation and copying of the singleton class.
 * 
 * The getInstance static method is responsible for providing access to the single instance of the class. It uses a static local variable to ensure that only one instance is created.
 * 
 * The main function demonstrates how to access and use the singleton instance.
 * Remember that the implementation of a singleton pattern involves more considerations in a multithreaded environment to ensure thread safety. In such cases, additional mechanisms like mutex or double-checked locking may be needed.
 * 
 */

#include <iostream>

class Singleton {
private:
    // Private constructor to prevent instantiation from outside
    Singleton() {}

    // Private copy constructor to prevent copying
    Singleton(const Singleton&);

    // Private assignment operator to prevent assignment
    Singleton& operator=(const Singleton&);

public:
    // Static method to get the instance of the singleton class
    static Singleton& getInstance() {
        // Static instance of the singleton class
        static Singleton instance;
        return instance;
    }

    // Other member functions of the class

    void displayMessage() {
        std::cout << "Singleton class instance is created." << std::endl;
    }
};

int main() {
    // Access the singleton instance
    Singleton& singletonInstance = Singleton::getInstance();

    // Use the singleton instance
    singletonInstance.displayMessage();

    return 0;
}

