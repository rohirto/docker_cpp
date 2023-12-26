/**
 * @file priority_queue2.cpp
 * @author rohirto
 * @brief demo of min heap priority queue
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to demonstrate
// min heap for priority queue
#include <iostream>
#include <queue>
using namespace std;

void showpq( priority_queue<int, vector<int>, greater<int> > g)
{
	while (!g.empty()) {
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}

void showArray(const int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// Driver Code
int main()
{
	int arr[6] = { 10, 2, 4, 8, 6, 9 };
	priority_queue<int, vector<int>, greater<int> > gquiz(arr, arr + 6);  //Note the declaration here

	cout << "Array: ";
	showArray(arr, 6);

	cout << "Priority Queue : ";
	showpq(gquiz);

	return 0;
}
