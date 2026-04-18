#include <iostream>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

// Derived Class
class Student : public Person {
private:
    int rollNo;

public:
    void setStudent(int r) {
        rollNo = r;
    }

    void displayStudent() {
        displayPerson(); // calling base class function
        cout << "Roll No : " << rollNo << endl;
    }
};

int main() {
    Student s;

    s.setPerson("Amna Khalil", 20);
    s.setStudent(123);

    cout << "\n--- Student Details ---\n";
    s.displayStudent();

    return 0;
}