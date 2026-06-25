#include<iostream>
using namespace std;

class ElectricityBill{
private:
    string customerName;
    int units;

public:
    void input(){
        cout<<"Enter Customer Name: ";
        cin>>customerName;

        cout<<"Enter Units Consumed: ";
        cin>>units;
    }

    double calculateBill(){
        if(units<=100)
            return units*10;

        else if(units<=200)
            return (100*10)+((units-100)*15);

        else
            return (100*10)+(100*15)+((units-200)*20);
    }

    void display(){
        cout<<"\nCustomer Name: "<<customerName<<endl;
        cout<<"Units Consumed: "<<units<<endl;
        cout<<"Total Bill: Rs. "<<calculateBill()<<endl;
    }
};

int main(){
    ElectricityBill e;

    e.input();
    e.display();

    return 0;
}