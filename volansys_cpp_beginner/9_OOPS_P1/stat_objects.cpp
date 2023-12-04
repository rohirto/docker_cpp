// CPP program to illustrate
// class objects as static
#include <iostream>
using namespace std;
 
class GfG {
    int i = 0;
 
public:
    GfG()
    {
        i = 0;
        cout << "Inside Constructor\n";
    }
 
    ~GfG() { cout << "Inside Destructor\n"; }
};
 
int main()
{
    int x = 0;
    if (x == 0) {
        static GfG obj;  //If static keyword is not used then the scope of the object  remains in the if block only, but as we are using static keyword,
                         // The scope of the object will be till the end of the program
    }
    cout << "End of main\n";
}