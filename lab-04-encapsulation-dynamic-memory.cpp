#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name;
    float *marks;   // dynamic memory

public:
    // Constructor
    Student(int i, string n, float m) {
        id = i;
        name = n;

        marks = new float;   // dynamic allocation
        *marks = m;
    }

    void display() {
        cout << "ID    : " << id << endl;
        cout << "Name  : " << name << endl;
        cout << "Marks : " << *marks << endl;
    }

    // Destructor
    ~Student() {
        delete marks;
        cout << "Memory released for " << name << endl;
    }
};

int main() {
    Student s1(101, "Amna", 88.5);
    Student s2(102, "Ali", 76.0);

    cout << "\n--- Student 1 ---\n";
    s1.display();

    cout << "\n--- Student 2 ---\n";
    s2.display();

    return 0;
}