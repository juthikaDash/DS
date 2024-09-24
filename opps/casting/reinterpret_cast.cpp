/**
 * The reinterpret_cast operator is used to convert the pointer to any other type of pointer. 
 * It does not perform any check whether the pointer converted is of the same type or not.
 */
// C++ program to illustrate the reinterpret_cast
#include <iostream>
using namespace std;

int main()
{
    int number = 10;
    // Store the address of number in numberPointer
    int* numberPointer = &number;

    // Reinterpreting the pointer as a char pointer
    char* charPointer
        = reinterpret_cast<char*>(numberPointer);

    // Printing the memory addresses and values
    cout << "Integer Address: " << numberPointer << endl;
    cout << "Char Address: "
         << reinterpret_cast<void*>(charPointer) << endl;

    return 0;
}