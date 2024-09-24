/*
Pointers are used for accessing the resources which are external to the program – like heap memory. 
So, for accessing the heap memory (if anything is created inside heap memory), pointers are used.
 When accessing any external resource we just use a copy of the resource. If we make any changes 
 to it, we just change it in the copied version. But, if we use a pointer to the resource, we’ll 
 be able to change the original resource.
*/
// C++ program to demonstrate the working of Smart Pointer
#include <iostream>
using namespace std;

class SmartPtr {
    int* ptr; // Actual pointer
public:
    // Constructor: Refer
    // https://www.geeksforgeeks.org/g-fact-93/ for use of
    // explicit keyword
    explicit SmartPtr(int* p = NULL) { ptr = p; }

    // Destructor
    ~SmartPtr() { delete (ptr); }

    // Overloading dereferencing operator
    int& operator*() { return *ptr; }
};

int main()
{
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;

    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, the destructor for it is
    // automatically called and destructor does delete ptr.

    return 0;
}
