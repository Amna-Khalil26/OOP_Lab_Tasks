#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Operator overloading +
    Complex operator + (const Complex &c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);

    Complex c3 = c1 + c2;

    cout << "C1: ";
    c1.display();

    cout << "C2: ";
    c2.display();

    cout << "C1 + C2: ";
    c3.display();

    return 0;
}