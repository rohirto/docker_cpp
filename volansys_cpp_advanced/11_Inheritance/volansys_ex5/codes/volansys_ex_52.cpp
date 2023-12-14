/**
 * @file volansys_ex_52.cpp
 * @author rohit S
 * @brief Extra Challenges of Inheritance Lesson C++ Advance
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Extra Challenge 2
 * Make a class named Fruit with a data member to calculate the number of fruits in a basket. Create two other class named Apples 
 * and Mangoes to calculate the number of apples and mangoes in the basket. Print the number of fruits of each type and the total number 
 * of fruits in the basket.
 * 
 */

#include <iostream>

class Fruit 
{
protected:
    int numFruits;

public:
    Fruit() : numFruits(0) {}

    void setNumFruits(int count) 
    {
        numFruits = count;
    }

    int getNumFruits() const 
    {
        return numFruits;
    }
};

class Apples : public Fruit 
{
public:
    void setNumApples(int count) 
    {
        setNumFruits(count);
    }

    int getNumApples() const 
    {
        return getNumFruits();
    }
};

class Mangoes : public Fruit 
{
public:
    void setNumMangoes(int count) 
    {
        setNumFruits(count);
    }

    int getNumMangoes() const 
    {
        return getNumFruits();
    }
};

class Basket 
{
private:
    Apples apples;  //Composition Example
    Mangoes mangoes;

public:
    void setFruitCounts(int numApples, int numMangoes) 
    {
        apples.setNumApples(numApples);
        mangoes.setNumMangoes(numMangoes);
    }

    void displayBasket() const 
    {
        std::cout << "Number of Apples: " << apples.getNumApples() << std::endl;
        std::cout << "Number of Mangoes: " << mangoes.getNumMangoes() << std::endl;
        std::cout << "Total Number of Fruits: " << apples.getNumFruits() + mangoes.getNumFruits() << std::endl;
    }
};

int main() 
{
    Basket basket;

    // Set the number of fruits in the basket
    basket.setFruitCounts(5, 3);

    // Display the contents of the basket
    basket.displayBasket();

    return 0;
}
