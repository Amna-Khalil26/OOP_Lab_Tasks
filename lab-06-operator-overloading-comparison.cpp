#include <iostream>
using namespace std;

class Bill {
private:
    int amount;

public:
    Bill(int a = 0) {
        amount = a;
    }

    bool operator==(const Bill& b) {
        return amount == b.amount;
    }

    void display() {
        cout << "Bill Amount: " << amount << endl;
    }
};

int main() {
    Bill b1(500);
    Bill b2(500);
    Bill b3(700);

    b1.display();
    b2.display();

    if (b1 == b2)
        cout << "Bills are equal" << endl;
    else
        cout << "Bills are different" << endl;

    b3.display();

    return 0;
}