/**
 * @file demo_smart_ptrs2.cpp
 * @author rohirto
 * @brief Demo of Smart Pointers where -> operator is overloaded
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;
// A generic smart pointer class
template <class T>
class Smartpointer {
   T *p; // Actual pointer
   public:
      // Constructor
      Smartpointer(T *ptr = NULL) {
         p = ptr;
      }
   // Destructor
   ~Smartpointer() {
      delete(p);
   }
   // Overloading de-referencing operator
   T & operator * () {
      return *p;
   }
   // Over loading arrow operator so that members of T can be accessed
   // like a pointer
   T * operator -> () {
      return p;
   }
};

// Function to demonstrate the overloaded arrow operator
template <class T>
void demonstrateArrowOperator(Smartpointer<T>& sp) {
   // Accessing members of T using the arrow operator
   cout << "Value using arrow operator: " << sp->getValue() << endl;
}


class ExampleClass {
   int value;
public:
   ExampleClass(int val) : value(val) {}
   int getValue() const {
      return value;
   }
};

int main() {
   Smartpointer<int> p(new int());
   *p = 26;
   cout << "Value is: "<<*p;

   Smartpointer<ExampleClass> p1(new ExampleClass(42));

   // Accessing members of ExampleClass using the arrow operator in the main function
   cout << "Value is: " << p1->getValue() << endl;

   // Demonstrate the overloaded arrow operator in a separate function
   demonstrateArrowOperator(p1);

   
   return 0;
}