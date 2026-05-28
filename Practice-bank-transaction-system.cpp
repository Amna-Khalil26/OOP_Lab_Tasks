#include<iostream>
using namespace std;

class Bank {
private:
    int acc_number;
    string name;
    double transaction[5];
    int counter;

public:
    Bank() {
        counter = 0;
        for(int i = 0; i < 5; i++) {
            transaction[i] = 0;
        }
    }

    void data() {
        cout << "Enter account holder name: ";
        cin >> name;

        cout << "Enter account number: ";
        cin >> acc_number;
    }

    void deposit() {
        if(counter < 5) {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;

            transaction[counter] = amount; 
            counter++;

            cout << "Amount deposited successfully!\n";
        } else {
            cout << "Transaction limit reached!\n";
        }
    }

    void withdraw() {
        if(counter < 5) {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            transaction[counter] = -amount;
            counter++;

            cout << "Amount withdrawn successfully!\n";
        } else {
            cout << "Transaction limit reached!\n";
        }
    }

    double balance() {
        double sum = 0;
        for(int i = 0; i < counter; i++) {
            sum += transaction[i];
        }
        return sum;
    }

    void display() {
        cout << "\nAll Transactions:\n";
        for(int i = 0; i < counter; i++) {
            cout << transaction[i] << endl;
        }

        cout << "Current Balance: " << balance() << endl;
    }
};

int main() {
    Bank b;

    b.data();

   
    b.deposit();
    b.withdraw();
    b.deposit();

    b.display();

    return 0;
}