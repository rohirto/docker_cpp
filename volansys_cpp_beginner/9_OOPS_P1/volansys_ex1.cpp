/**
 * @file volansys_ex1.cpp
 * @author rohit S
 * @brief Challenge 8 of C++ Basic Course
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Challenge 8
 * Implement a vector replacement that operates only on integers, vectorOfInt (you don't need to 
 * use templates like the normal STL). Your class should have the following interface
 *
 *	• A no-argument constructor that allocates a 32 element vector
 *	• A constructor that takes an initial size as the argument
 *	• A method get, taking an index as returning the value at that index
 *	• A method set, that takes an index and a value, and sets the value at that index
 *	• A method pushback that adds an element to the end of the array, resizing if necessary
 *	• A method pushfront that adds an element to the beginning of the array
 *	• A Copy constructor and assignment operator
 *
 * Your class should not leak memory; any memory it allocates must be deleted. Try to think carefully 
 * about how your class can be misused, and how you should handle them. 
 *
 * What do you do if a user gives a negative initial size? 
 *      If user gives a negative initial size then compiler will catch error of negative array index during dynamic memory allocation
 * What about accessing a negative index?
 *      Compiler throws an error
 * 
 */

#include <iostream>

using namespace std;


/**
 * @brief Vector Implementation Class
 * @class vectorOfInt
 * 
 */
class vectorOfInt
{
private: 
    int *vec;           /**< pointer to dynamic Array */
    size_t size;        /**< Current size of array */
    size_t capacity;    /**< Capacity of the vector -> 32 defined by the requirement */
    
public:
    /**
     * @brief Construct a new vector Of Int object
     * 
     */
    vectorOfInt()
    {
        capacity = 32;
        size = 0;
        vec = new int[capacity];

        cout << "Object Initialized with no param" << endl;
    }

    /**
     * @brief Construct a new vector Of Int object (Param Constructurtor)
     * 
     * @param s 
     */
    explicit vectorOfInt(int s)  //Advised by the static tool analyzer
    {
        size = 0;
        capacity = s;
        vec = new int[capacity];

        cout << "Objecy Initialized with capacity: " << capacity << endl;
    }

  
    /**
     * @brief Construct a new vector Of Int object
     * 
     * @param v 
     * @paragraph Copy Constructor
     *  Copy Constructor -> needed when any object of this class is copied to another object to this class
     *  eg. vecOfInt v1;
     * vectorOfInt v2 = v1;   -> Here copy happens, but instead of copy blatantly (which includes sensitive pointers, we override the constructor                            
     *                            with copy contructor to define  a safe way to copy, ie to allocate new memory to new object)
     *
     */
    vectorOfInt(const vectorOfInt& v)
    {
        cout << "Copying the Object thru Copy Constructor" << endl;
        capacity = v.capacity;
        size = v.size;
        vec = new int[capacity];
        std::copy(v.vec, v.vec + size, vec);
    }


    /**
     * @brief Assignement Operator Implemenation
     * 
     * @param v 
     * @return vectorOfInt& 
     * @paragraph Assignment Operator Function
     *  Assignment Operator - This operator is called when an already initialized object is assigned a new value from another existing object. 
     *  eg, vecOfInt v1,v2;
     *  v2 = v1;    --> Note how this is different than copy constructor
     *  It does not create a separate memory block or new memory space.
     */
    vectorOfInt& operator=(const vectorOfInt& v) 
    {
        cout << "Assigning Data through assignment operator" << endl;
        if(this != &v)  //if this(v2) is not equal to v1 (the vector which will be assigned)
        {
            delete[] vec;
            capacity = v.capacity;
            size = v.size;

            vec = new int[capacity];
            std::copy(v.vec,v.vec + size, vec);

        }
        return *this;
    }

    /**
     * @brief Destroy the vector Of Int object
     * 
     */
    ~vectorOfInt()
    {
        delete[] vec;
        cout << "Object deleted, memory freed!" << endl;
    }

    /**
     * @brief Get the vector element at index
     * 
     * @param index 
     * @return int vector value, else throw an error
     */
    int get(size_t index)
    {
        if (static_cast <int> (index) < 0 || index >= size)
        {
            throw std::out_of_range("Index out of bounds.");
        }
        return vec[index];
    }
    
    /**
     * @brief Set the vector value at index
     * 
     * @param index to be set
     * @param value of the vector
     */
    void set(size_t index, int value)
    {
        size = index + 1;
        if (static_cast <int> (index) < 0 || index >= size)
        {
            throw std::out_of_range("Index out of bounds.");
        }
        vec[index] = value;
        
    }


    /**
     * @brief Pushback the value at the end of vector, irrespective of the capacity of vector, if capacity exceeds then resize the vector
     * 
     * @param value 
     */
    void pushback(int value)
    {
        if (size == capacity) 
        {
            resize();
        }
        vec[size++] = value;
    }

   
    /**
     * @brief Pushfront the value at the end of vector, irrespective of the capacity of vector, if capacity exceeds then resize the vector
     * 
     * @param value 
     */
    void pushfront(int value) 
    {
        if (size == capacity) 
        {
            resize();
        }
        // Shift existing elements to make room for the new element at the beginning
        for (size_t i = size; i > 0; --i) 
        {
            vec[i] = vec[i - 1];
        }
        vec[0] = value;
        ++size;
    }

    /**
     * @brief Method to print the vector in its current form
     * 
     */
    void print_vec(void)
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
        
    }

private:
    /**
     * @brief Helper method to resize the vector
     * 
     */
    void resize()
    {
        capacity *= 2;
        int *newData = new int[capacity];
        std::copy(vec, vec + size, newData);
        delete[] vec;
        vec = newData;
    }
};

/**
 * @brief Main function
 * 
 * @return int 
 */
int main()
{
    vectorOfInt v;

    v.set(0,1);
    

    for(int i = 0 ; i < 40; i++)
    {
        v.pushback(i);
    }

    for(int i = 0 ; i < 40; i++)
    {
        v.pushfront(100 - i);
    }

    v.print_vec();

    vectorOfInt v1 = v;  //Copy Constructor
    v1.print_vec();

    vectorOfInt v2;

    v2 = v1;     //Assignment Operator
    v2.print_vec();

    return 0;
}