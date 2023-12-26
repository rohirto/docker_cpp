/**
 * @file priority_queue_demo.cpp
 * @author rohirto
 * @brief Creation of Priority Queue using STL
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ program to demonstrate the use of priority_queue
#include <iostream>
#include <queue>
using namespace std;

// driver code
int main()
{
	int arr[6] = { 10, 2, 4, 8, 6, 9 };  //Note this is c style array, contigious mem allocation

	// defining priority queue
	priority_queue<int> pq;

	// printing array
	cout << "Array: ";
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << endl;
	// pushing array sequentially one by one
	for (int i = 0; i < 6; i++) {
		pq.push(arr[i]);  //The priority queue is there in heap, thus non contigious mem alloc, but priority to top elem
	}

	// printing priority queue
	cout << "Priority Queue: ";
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}

	return 0;
}
