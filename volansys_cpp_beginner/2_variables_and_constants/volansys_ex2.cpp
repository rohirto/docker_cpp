/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Challenge 1 of Lesson 2 of C++ Basic Course
 * @version 0.1
 * @date 2023-11-27
 *
 * @copyright Copyright (c) 2023 Volansys Technologies
 *
 * @paragraph Challenge 1
 * This is a pretty simple challenge. In this case, Pankaj owns a carpet cleaning company. He has two charges to clean the carpet. One for small rooms and one for large rooms.
 * Here he charges Rs 2500 for small rooms and Rs 3500 for large rooms.
 * The CGST and SGST tax rate are 6% and 6% respectively and estimates are valid for 30 days.
 * So what you need to do here is prompt the user both for how many small rooms they want to be cleaned and how many large rooms they want to be cleaned and then provide an estimate that looks something like this.
 * For instance; Number of small rooms: 3, number of large rooms: 1.
 * The price per small room is Rs 2500
 * The price per large room is Rs 3500
 * Calculate the cost. Calculate the tax and then come up with a total estimate
 * and tell them that the estimate is valid for 30 days.
 * 
 * So hopefully that makes a lot of sense.
 * 
 * Here's a sample run that you can see.
 * 
 * ========================================================================
 * 
 * Hello, welcome to Pankaj's Carpet Cleaning Service.
 * 
 * How many small rooms would you like to clean? 3
 * How many large rooms would you like cleaned? 1
 * 
 * Estimate for carpet cleaning service
 * Number of small rooms: 3
 * Number of large rooms: 1
 * Price per small room: Rs 2500
 * Price per large room: Rs 3500
 * Cost: Rs 11000
 * CGST: Rs 660
 * SGST: 660
 * ===============================
 * Total estimate: Rs 12320
 * This estimate is valid for 30 days
 * ========================================================================
 * 
 * All right. So give it a shot, take your time. I'm sure you'll do it just fine.
 *
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int small_rooms, large_rooms, cost, cgst, sgst;
    cout << "========================================================================" << endl;
    cout << "\n";
    cout << "Hello, welcome to Pankaj's Carpet Cleaning Service." <<endl;
    cout << "\n";
    cout << "How many small rooms would you like to clean? ";
    cin >> small_rooms;
    cout << "\n";
    cout << "How many large rooms would you like cleaned? ";
    cin >> large_rooms;
    cout << "\n" << endl;

    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_rooms <<endl;
    cout << "Number of large rooms: " << large_rooms << endl;
    cout << "Price per small room: Rs 2500" << endl;
    cout << "Price per large room: Rs 3500" << endl;

    cost = (small_rooms*2500 + large_rooms*3500);
    cgst = cost*0.06;
    sgst = cost*0.06;

    cout << "Cost: Rs " << cost << endl;
    cout << "CGST: Rs " << cgst << endl;
    cout << "SGST: Rs " << sgst << endl;
    cout << "===============================" << endl;
    cout << "Total estimate: Rs "<< (cost + cgst + sgst) << endl;
    cout << "This estimate is valid for 30 days" << endl;
    cout << "========================================================================" << endl;


    return 0;
}