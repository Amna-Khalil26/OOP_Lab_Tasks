#include <iostream>
using namespace std;

// Base Class
class Shape {
public:
    // Virtual function
    virtual void draw() {
        cout << "Drawing a Shape" << endl;
    }
};

// Derived Class 1
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Derived Class 2
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    // Base class pointer
    Shape* s;

    Circle c;
    Rectangle r;

    // Pointing to Circle object
    s = &c;
    s->draw();

    // Pointing to Rectangle object
    s = &r;
    s->draw();

    return 0;
}