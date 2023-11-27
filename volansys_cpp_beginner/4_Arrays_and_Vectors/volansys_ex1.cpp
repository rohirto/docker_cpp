/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Exercise 1 of Arrays and Vectors C++ Basic
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 * @paragraph Exercise 1
 * 
 * You are provided with a vector of N integers. Then, you are given 2 queries. 
 * For the first query, you are provided with 1 integer, which denotes a position in the vector. 
 * The value at this position in the vector needs to be erased. 
 * The next query consists of 2 integers denoting a range of the positions in the vector. 
 * The elements which fall under that range should be removed. 
 * The second query is performed on the updated vector which we get after performing the first query.
 *
 * Input Format
 * 
 * The first line of the input contains an integer N.
 * The next line contains N space separated integers(1-based index).
 * The third line contains a single integer x,denoting the position of an element that should be removed from the vector.
 * The fourth line contains two integers a and b denoting the range that should be erased from the vector inclusive of a 
 * and exclusive of b.
 *
 * Constraints
 *
 * 1 <= N <= 10^5
 * 1 <= x <= N
 * 1 <= a <= b <= N
 *
 * Output Format
 *
 * Print the size of the vector in the first line and the elements of the vector after the two erase operations in the
 * second line separated by space.
 *
 * Example:
 *
 * Input
 *
 * 6
 * 1 4 6 2 8 9
 * 2
 * 2 4
 *
 * Output
 *
 * 3
 * 1 8 9
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N;
    std::cin >> N;

    // Input vector of N integers
    std::vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    // First query: Remove element at position x
    int x;
    std::cin >> x;
    numbers.erase(numbers.begin() + x - 1); // Adjust for 1-based index

    // Second query: Remove elements in the range [a, b)
    int a, b;
    std::cin >> a >> b;
    numbers.erase(numbers.begin() + a - 1, numbers.begin() + b - 1); // Adjust for 1-based index

    // Output the size of the vector and its elements
    std::cout << numbers.size() << "\n";
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
   
    return 0;
}