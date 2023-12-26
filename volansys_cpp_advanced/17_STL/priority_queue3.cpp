/**
 * @file priority_queue3.cpp
 * @author rohirto
 * @brief Demo of push pop in priority queues
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// C++ Program to demonstrate various
// method/function in Priority Queue
#include <iostream>
#include <queue>
using namespace std;

// Implementation of priority queue
void showpq(const priority_queue<int>& gq)
{
	priority_queue<int> g = gq;
	while (!g.empty()) {
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	priority_queue<int> gquiz;
	// used in inserting the element
	gquiz.push(10);
	gquiz.push(30);
	gquiz.push(20);
	gquiz.push(5);
	gquiz.push(1);

	cout << "The priority queue gquiz is : ";
	
	// used for highlighting the element
	showpq(gquiz);

	// used for identifying the size 
	// of the priority queue
	cout << "\ngquiz.size() : " << 
			gquiz.size();
	// used for telling the top element 
	// in priority queue
	cout << "\ngquiz.top() : " << 
			gquiz.top();

	// used for popping the element 
	// from a priority queue
	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showpq(gquiz);

	return 0;
}
