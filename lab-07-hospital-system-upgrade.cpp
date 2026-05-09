#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Patient : public Person {
private:
    string disease;

public:
    Patient(string n, int a, string d) : Person(n, a) {
        disease = d;
    }

    void display() override {
        Person::display();
        cout << "Disease: " << disease << endl;
    }
};

int main() {
    Patient p1("Amna Khalil", 20, "Flu");
    p1.display();
    return 0;
}