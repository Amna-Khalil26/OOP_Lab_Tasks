#include<iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v) {
        value = v;
    }

    friend void show(Number n);
};

void show(Number n) {
    cout << "Value: " << n.value << endl;
}

int main() {
    Number n(50);
    show(n);
    return 0;
}