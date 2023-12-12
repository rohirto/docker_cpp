/**
 * @file constructor_multiple_base_cl.cpp
 * @author rohirto
 * @brief Demo of How to implement the constructor of Derived class, deriving itself from mutiple base classes
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;

class base1 {
protected:
  int i;
public:
  base1(int x) { i = x; cout << "Constructing base1\n"; }
  ~base1() { cout << "Destructing base1\n"; }
};

class base2 {
protected:
  int k;
public:
  base2(int x) { k = x; cout << "Constructing base2\n"; }
  ~base2() { cout << "Destructing base2\n"; }
};

class derived: public base1, public base2 {
  int j;
public:
  derived(int x, int y, int z): base1(y), base2(z)
     { j = x; cout << "Constructing derived\n"; }

  ~derived() { cout << "Destructing derived\n"; }
  void show() { cout << i << " " << j << " " << k << "\n"; }
};

int main()
{
  derived ob(3, 4, 5);

  ob.show();  // displays 4 3 5

  return 0;
}