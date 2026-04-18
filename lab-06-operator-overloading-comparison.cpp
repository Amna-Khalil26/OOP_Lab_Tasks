#include <iostream>
using namespace std;

class Bill {
private:
    int amount;

public:
    Bill(int a = 0) {
        amount = a;
    }

    // Overload ==
    bool operator == (Bill b) {
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

    cout << "\n--- Bill 1 ---\n";
    b1.display();

    cout << "\n--- Bill 2 ---\n";
    b2.display();

    if (b1 == b2)
        cout << "Bill 1 and Bill 2 are EQUAL\n";
    else
        cout << "Bills are DIFFERENT\n";

    cout << "\n--- Bill 3 ---\n";
    b3.display();

    return 0;
}