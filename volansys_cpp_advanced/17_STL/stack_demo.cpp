/**
 * @file stack_demo.cpp
 * @author rohirto
 * @brief Demo of Stack container adaptor in STL
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 * Time complexity: The time complexity of this program is O(N), where N is the total number of elements in the stack. 
 * The while loop iterates N times, popping elements from the stack and printing them.
 *
 * Space complexity:The space complexity of this program is O(N), where N is the total number of elements in the stack. 
 * The stack data structure uses space proportional to the number of elements stored in it. In this case, the maximum size of the stack is 5, 
 * so the space complexity is constant and can be considered as O(1) as well.
 * 
 */

#include <iostream> 
#include <stack>
using namespace std;
int main() {
	stack<int> stack;
	stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
	stack.push(22);
	stack.push(24);
	stack.push(25);
	int num=0;
	stack.push(num);
	stack.pop();
	stack.pop();
	stack.pop();

	while (!stack.empty()) {
		cout << stack.top() <<" ";
		stack.pop();
	}
}
