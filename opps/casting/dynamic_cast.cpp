/*
The dynamic_cast operator is mainly used to perform downcasting 
(converting a pointer/reference of a base class to a derived class).
 It ensures type safety by performing a runtime check to verify the validity of the conversion.

 If the conversion is not possible, dynamic_cast returns a null pointer (for pointer conversions) 
 or throws a bad_cast exception (for reference conversions).
*/
// C++ program to illustrate the dynamic_cast
#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    virtual void speak() const
    {
        cout << "Animal speaks." << endl;
    }
};

// Derived Class
class Dog : public Animal {
public:
    void speak() const override
    {
        cout << "Dog barks." << endl;
    }
};

// Derived Class
class Cat : public Animal {
public:
    void speak() const override
    {
        cout << "Cat meows." << endl;
    }
};

int main()
{
    // base class pointer to derived class object
    Animal* animalPtr = new Dog();

    // downcasting
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);

    // checking if the typecasting is successfull
    if (dogPtr) {
        dogPtr->speak();
    }
    else {
        cout << "Failed to cast to Dog." << endl;
    }

    // typecasting to other dervied class
    Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
    if (catPtr) {
        catPtr->speak();
    }
    else {
        cout << "Failed to cast to Cat." << endl;
    }

    delete animalPtr;
    return 0;
}