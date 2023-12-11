/**
 * @file move_constructor.cpp
 * @author rohirto
 * @brief Demo of Move Constructor in cpp
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @paragraph The unnecessary call to the copy constructor is avoided by making the call to the move constructor. 
 * Thus making the code more memory efficient and decreasing the overhead of calling the move constructor.
 */

// C++ program with declaring the
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
	// Declare the raw pointer as
	// the data member of class
	int* data;

public:

	// Constructor
	Move(int d)
	{
		// Declare object in the heap
		data = new int;
		*data = d;
		cout << "Constructor is called for "
			<< d << endl;
	};

	// Copy Constructor
	Move(const Move& source)
		: Move{ *source.data }   // The : Move{ *source.data } part is the member initializer list. It initializes the data members of the Move class, 
                                 // especially the data member, before the constructor body is executed.
                                 // *source.data is used to dereference the data pointer of the source object (source) and obtain the value it points to.
                                 // This value is then used to initialize the data member of the current object (the one being constructed).
                                 // The use of this member initializer list with : Move{ *source.data } is a way to implement a form of copy constructor 
                                 // that performs a deep copy efficiently.
                                 // The syntax : Move{ *source.data } is equivalent to calling the constructor Move(*source.data) to create an object with the specified value.
	{

		// Copying the data by making
		// deep copy
		cout << "Copy Constructor is called -"
			<< "Deep copy for "
			<< *source.data
			<< endl;
	}

	// Move Constructor
	Move(Move&& source)
		: data{ source.data } // The : data{ source.data } part is the member initializer list.
                              // It initializes the data members of the Move class before the constructor body is executed.
                              // source.data is the data member of the source object (source) being moved from.
                              // By assigning data{ source.data }, the ownership of the dynamically allocated memory (if any) 
                              // is transferred from the source object to the object being constructed.
	{

		cout << "Move Constructor for "
			<< *source.data << endl;
		source.data = nullptr;  // source.data is set to nullptr to indicate that ownership has been transferred, and the source object 
                                // should no longer be responsible for freeing the memory.
	}

	// Destructor
	~Move()
	{
		if (data != nullptr)

			// If pointer is not pointing
			// to nullptr
			cout << "Destructor is called for "
				<< *data << endl;
		else

			// If pointer is pointing
			// to nullptr
			cout << "Destructor is called"
				<< " for nullptr "
				<< endl;

		// Free up the memory assigned to
		// The data member of the object
		delete data;
	}
};

// Driver Code
int main()
{
	// Vector of Move Class
	vector<Move> vec;

	// Inserting Object of Move Class
	vec.push_back(Move{ 10 });
	vec.push_back(Move{ 20 });
	return 0;
}
