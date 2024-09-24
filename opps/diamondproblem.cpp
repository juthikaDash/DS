#include<iostream>
using namespace std;
class A {
public:
    void fun() { cout << "A::fun()" << endl; }
};

class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};

int main() {
    D d;
    d.fun(); // Now this is unambiguous
    return 0;
}