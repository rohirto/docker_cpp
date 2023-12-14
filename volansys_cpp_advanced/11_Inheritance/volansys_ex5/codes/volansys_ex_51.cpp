/**
 * @file volansys_ex_51.cpp
 * @author rohit S
 * @brief Extra Challenges of Inheritance Lesson C++ Advance
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Extra challenge 1
 * Create two classes named Mammals and MarineAnimals. Create another class named BlueWhale which inherits both the above classes. Now, create a function in each of these classes which prints "I am mammal", "I am a marine animal" and "I belong to both the categories: Mammals as well as Marine Animals" respectively. Now, create an object for each of the above class and try calling
 * 1 - function of Mammals by the object of Mammal
 * 2 - function of MarineAnimal by the object of MarineAnimal
 * 3 - function of BlueWhale by the object of BlueWhale
 * 4 - function of each of its parent by the object of BlueWhale
 * 
 * 
 * 
 */

#include <iostream>

using namespace std;

class Mammals{
private:

public:
    void call_mammal(){cout << "I am mammal" << endl;}

};

class MarineAnimals{
private:

public:
    void call_marineAnimal(){cout << "I am a marine animal" << endl;}

};

class BlueWhale: public Mammals,public MarineAnimals{
private:

public:
    void call_BlueWhale(){cout << "I belong to both the categories: Mammals as well as Marine Animals" << endl;}

};

int main() 
{
   // Write your code here.
   Mammals m;
   MarineAnimals ma;
   BlueWhale bw;


   //Scenarios

    //Scenario  1 - function of Mammals by the object of Mammal
    m.call_mammal();
    //Scenario 2 - function of MarineAnimal by the object of MarineAnimal
    ma.call_marineAnimal();
    //Scenario 3 - function of BlueWhale by the object of BlueWhale
    bw.call_BlueWhale();
    //Scenario 4 - function of each of its parent by the object of BlueWhale
    bw.call_mammal();
    bw.call_marineAnimal();

    return 0;
}