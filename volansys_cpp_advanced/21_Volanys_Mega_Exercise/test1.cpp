#include <iostream>
#include <thread>
#include <chrono>

void printMessage() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Printed while waiting for input on std::cin!" << std::endl;
}

int main() {
    // Start a separate thread to print a message
    std::thread printThread(printMessage);

    std::cout << "Enter something: ";
    
    // Main thread waits for user input
    std::string userInput;
    std::cin >> userInput;

    // Join the print thread before exiting
    printThread.join();

    return 0;
}
