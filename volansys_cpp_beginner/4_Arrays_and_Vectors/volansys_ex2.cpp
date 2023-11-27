/**
 * @file volansys_ex2.cpp
 * @author your name (you@domain.com)
 * @brief Exercise 2 of Arrays and Vetors of C++ basic
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 *
 * @brief Implement different operations on a vector A.
 *
 * @paragraph Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * Then T test cases follow. The first line of input contains an integer Q denoting
 * the number of queries. Then in the next line are Q space-separated queries.
 * A query can be of five types:
 * 1. a x (Adds an element x to the vector A at the end)
 * 2. b (Sorts the vector A in ascending order)
 * 3. c (Reverses the vector A)
 * 4. d (Prints the size of the vector)
 * 5. e (Prints space-separated values of the vector)
 * 6. f (Sorts the vector A in descending order)
 *
 * @paragraph Output:
 * The output for each test case will be space-separated integers denoting
 * the results of each query.
 *
 * @paragraph Constraints:
 * 1 <= T <= 100
 * 1 <= Q <= 100
 *
 * @paragraph Example:
 * @code
 * Input
 * 2
 * 6
 * a 4 a 6 a 7 b c e
 * 4
 * a 55 a 11 d e
 *
 * Output
 * 7 6 4
 * 2 55 11
 * @endcode
 *
 * @paragraph Explanation:
 * For the first test case:
 * There are six queries. Queries are performed in this order
 * 1. a 4 { Vector has 4 }
 * 2. a 7 {vector has 7 }
 * 3. a 6 {vector has 6}
 * 4. b {sorts the vector in ascending order, vector now is 5 6 7}
 * 5. c {reverse the vector}
 * 6. e {prints the element of the vectors 7 6 4}
 *
 * For the second test case:
 * There are four queries. Queries are performed in this order
 * 1. a 55 (vector A has 55}
 * 2. a 11 (vector A has 55, 11}
 * 3. d (prints the size of the vector A, i.e., 2)
 * 4. e (prints the elements of the vector A, i.e., 55 11)
 *
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for std::sort

using namespace std;

void  add_to_vector(vector<int> &A,int x);

void sort_vector_asc(vector<int> &A);

void reverse_vector(vector<int> &A);

int size_of_vector(vector<int> &A);

void sort_vector_desc(vector<int> &A);

void print_vector(vector<int> &A);

int main() {
	int t;  // T denoting the number of test cases.
	cin>>t;
	while(t--)
	{
		vector<int> A;
		int q; //integer Q denoting the number of queries.
		cin>>q;
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='a') //a x (Adds an element x to the vector A at the end)
			{
				int x;
				cin>>x;
				add_to_vector(A,x);
			}
			if(c=='b') // b (Sorts the vector A in ascending order)
			{
				sort_vector_asc(A);
			}
			if(c=='c') //c (Reverses the vector A)
			{
				reverse_vector(A);
			}
			if(c=='d') //d (Prints the size of the vector)
			{
				cout<<size_of_vector(A)<<" ";
			}
			if(c=='e') // e (Prints space-separated values of the vector)
			{
				print_vector(A);
				
			}
			if(c=='f') //f (Sorts the vector A in descending order)
			{
				sort_vector_desc(A);
			}
			
		}
cout<<endl;
	}
	return 0;
}


//You are required to complete below methods

//inserts an element x at 
//the back of the vector A
void add_to_vector(vector<int> &A,int x)
{
	//Your code here
    A.push_back(x);
}

//sort the vector A in ascending order
void sort_vector_asc(vector<int> &A)
{
	//Your code here
    std::sort(A.begin(), A.end());

}

//reverses the vector A
void reverse_vector(vector<int> &A)
{
	//Your code here
    // Use std::reverse to reverse the vector
    std::reverse(A.begin(), A.end());

}

//returns the size of the vector  A
int size_of_vector(vector<int> &A)
{
	//Your code here
    return A.size();
}

//sorts the vector A in descending order
void sort_vector_desc(vector<int> &A)
{
	//Your code here
    // Use std::sort with a custom comparator to sort the vector in descending order
    std::sort(A.begin(), A.end(), std::greater<int>());
}

//prints space separated 
//elements of vector A
void print_vector(vector<int> &A)
{
	//Your code here
    // Output the elements of the vector
    for (const int& num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}