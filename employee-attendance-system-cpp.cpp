#include<iostream>
using namespace std;

class Employee {
private:
    string name;
    int attendance[30];

public:

    void data() {
        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "\nEnter Attendance for 30 Days\n";
        cout << "1 = Present | 0 = Absent\n\n";

        for(int i = 0; i < 30; i++) {
            cout << "Day " << i + 1 << ": ";
            cin >> attendance[i];
        }
    }

    int totalPresent() {
        int count = 0;

        for(int i = 0; i < 30; i++) {
            if(attendance[i] == 1) {
                count++;
            }
        }

        return count;
    }

    int totalAbsent() {
        int count = 0;

        for(int i = 0; i < 30; i++) {
            if(attendance[i] == 0) {
                count++;
            }
        }

        return count;
    }

    double percentage() {
        return (totalPresent() / 30.0) * 100;
    }

    void display() {

        cout << "\n========== Attendance Report ==========\n";

        cout << "Employee Name      : " << name << endl;
        cout << "Total Present Days : " << totalPresent() << endl;
        cout << "Total Absent Days  : " << totalAbsent() << endl;
        cout << "Attendance %       : " << percentage() << "%" << endl;

        cout << "\nDaily Attendance:\n";

        for(int i = 0; i < 30; i++) {

            cout << "Day " << i + 1 << " : ";

            if(attendance[i] == 1) {
                cout << "Present";
            }
            else {
                cout << "Absent";
            }

            cout << endl;
        }
    }
};

int main() {

    Employee e;

    e.data();
    e.display();

    return 0;
}