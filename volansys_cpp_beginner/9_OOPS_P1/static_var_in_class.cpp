

// C++ program to demonstrate static
// variables inside a class
 
#include <iostream>
using namespace std;
 
class GfG {
public:
    static int i;
 
    GfG(){
        // Do nothing
    };
};
 //we have tried to create multiple copies of the static variable i for multiple objects. But this didn’t happen.
 // So, a static variable inside a class should be initialized explicitly by the user using the class name and scope resolution
 // operator outside the class as shown below: 
int GfG::i = 1;

int main()
{
    GfG obj1;
    GfG obj2;
    // obj1.i = 2;  //Will result in error
    // obj2.i = 3;  //Will result in erro
 
    // prints value of i
    cout << obj1.i << " " << obj2.i;
}