#include<iostream>
using namespace std;

template <class T>
T maximum(T a, T b) {
    if(a > b)
        return a;
    else
        return b;
}

int main() {
    cout << "Maximum Integer: " << maximum(10, 20) << endl;
    cout << "Maximum Double: " << maximum(5.5, 3.2) << endl;

    return 0;
}