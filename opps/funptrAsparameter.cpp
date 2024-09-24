// C++ Program for demonstrating
// function pointer as pointer
//We use function pointers to pass callbacks to other functions, 
//store them in data structures, and invoke them later.

#include <iostream>
using namespace std;
 
const int a = 15;
const int b = 2;
 
// Function for Multiplication
int multiply() { return a * b; }
 
// Function containing function pointer
// as parameter
void print(int (*funcptr)())
{
    cout << "The value of the product is: " << funcptr()
         << endl;
}
 
// Driver Function
int main()
{
    print(multiply);
    return 0;
}
