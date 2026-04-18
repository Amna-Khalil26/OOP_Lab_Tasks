#include <iostream>
using namespace std;

// Class Definition
class Student {
private:
    int id;
    string name;
    float marks;

public:
    // Setter function
    void setData(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }

    // Display function
    void display() {
        cout << "ID    : " << id << endl;
        cout << "Name  : " << name << endl;
        cout << "Marks : " << marks << endl;
    }
};

int main() {
    Student s1, s2;

    s1.setData(101, "Amna Khalil", 89.5);
    s2.setData(102, "Ali Hassan", 76.0);

    cout << "\n--- Student 1 ---\n";
    s1.display();

    cout << "\n--- Student 2 ---\n";
    s2.display();

    return 0;
}