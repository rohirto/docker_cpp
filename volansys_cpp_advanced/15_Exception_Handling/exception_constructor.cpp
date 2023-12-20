/**
 * @file exception_constructor.cpp
 * @author rohirto
 * @brief Demo of exception handling within constructor
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;

class demo {
	int num;

public:
	demo(int x)
	{
		try {

			if (x == 0)
				// catch block would be called
				throw "Zero not allowed ";

			num = x;
			show();
		}

		catch (const char* exp) {
			cout << "Exception caught \n ";
			cout << exp << endl;
		}
	}

	void show()
	{
		cout << "Num = " << num << endl;
	}
};

int main()
{

	// constructor will be called
	demo(0);
	cout << "Again creating object \n";
	demo(1);
}
