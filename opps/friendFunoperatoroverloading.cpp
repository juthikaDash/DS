#include<iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    friend Complex operator+(const Complex& c1, const Complex& c2);
    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex a(3, 4);
    Complex b(5, 6);
    Complex c = a + b;
    c.display();  // Output: 8 + 10i
    return 0;
}