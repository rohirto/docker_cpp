/**
 * @file inner_product_demo.cpp
 * @author rohirto
 * @brief Demo of inner product in stl
 * @version 0.1
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// CPP Program to demonstrate inner_product()
#include <functional>
#include <iostream>
#include <numeric>
using namespace std;

int fun(int x, int y) { return x - y; }

int fun1(int x, int y) { return x + y; }

// Driver Code
int main()
{
	int var = 200;
	int a[] = { 10, 15, 20 };
	int b[] = { 1, 3, 5 };

	cout << "\nResult using inner_product ";

	// inner_product with default method
	cout << inner_product(a, a + 3, b, var);

	// inner_product with pre-defined function
	cout << "\nResult using inner_product with pre-defined "
			"function: ";
	cout << inner_product(a, a + 3, b, var, minus<int>(),
						divides<int>());

	// inner_product with user defined function
	cout << "\nResult using inner_product with "
			"user-defined function: ";
	cout << inner_product(a, a + 3, b, var, fun, fun1);

	return 0;
}
