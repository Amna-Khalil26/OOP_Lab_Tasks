#include<iostream>
using namespace std;

class Student{
private:
    string name;
    int marks[5];

public:
    void input(){
        cout<<"Enter Student Name: ";
        cin>>name;

        for(int i=0;i<5;i++){
            cout<<"Enter Marks "<<i+1<<": ";
            cin>>marks[i];
        }
    }

    int total(){
        int sum=0;

        for(int i=0;i<5;i++){
            sum+=marks[i];
        }

        return sum;
    }

    double percentage(){
        return total()/5.0;
    }

    void grade(){
        double per=percentage();

        if(per>=80)
            cout<<"Grade: A\n";
        else if(per>=70)
            cout<<"Grade: B\n";
        else if(per>=60)
            cout<<"Grade: C\n";
        else
            cout<<"Grade: Fail\n";
    }

    void display(){
        cout<<"\nStudent: "<<name<<endl;
        cout<<"Total Marks: "<<total()<<endl;
        cout<<"Percentage: "<<percentage()<<"%"<<endl;

        grade();
    }
};

int main(){
    Student s;

    s.input();
    s.display();

    return 0;
}