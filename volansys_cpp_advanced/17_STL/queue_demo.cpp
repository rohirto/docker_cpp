/**
 * @file queue_demo.cpp
 * @author rohirto
 * @brief Demo of queue in STL
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * The time and space complexities of the operations in this code are as follows:

print_queue function:

Time complexity: O(n), where n is the number of elements in the queue.
Space complexity: O(n), where n is the number of elements in the queue.
q1.push(1), q1.push(2), q1.push(3), q2.push(4), q2.push(5), q2.push(6):

Time complexity: O(1) for each push operation.
Space complexity: O(n), where n is the total number of elements in both queues.
q1.swap(q2):

Time complexity: O(1) for each swap operation.
Space complexity: O(1), as this operation only swaps the internal pointers of the two queues.
q1.empty():

Time complexity: O(1), as this operation simply checks if the queue is empty.
Space complexity: O(1), as no extra space is used for this operation.
Overall, the time and space complexities of this code are reasonable and efficient for typical use cases.


 * 
 */

// CPP code to illustrate Queue in 
// Standard Template Library (STL)
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(const queue<int>& gq)
{
	queue<int> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(20);
	gquiz.push(30);

	cout << "The queue gquiz is : ";
	showq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.front() : " << gquiz.front();
	cout << "\ngquiz.back() : " << gquiz.back();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showq(gquiz);

    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
 
    cout << "The first queue is : ";
    showq(q1);

    queue<int> q2;
    q2.push(4);
    q2.push(5);
    q2.push(6);

    cout << "The second queue is : ";
    showq(q2);

    q1.swap(q2);
       
      cout << "After swapping, the first queue is : ";
    showq(q1);
      cout << "After swapping the second queue is : ";
    showq(q2);
   
      cout<<q1.empty();  //returns false since q1 is not empty

	return 0;
}
