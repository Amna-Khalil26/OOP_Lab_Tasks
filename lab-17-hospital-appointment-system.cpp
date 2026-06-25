#include<iostream>
using namespace std;

class Appointment{
private:
    string patientName;
    string doctorName;
    string date;
    string time;

public:
    void input(){
        cout<<"Enter Patient Name: ";
        cin>>patientName;

        cout<<"Enter Doctor Name: ";
        cin>>doctorName;

        cout<<"Enter Appointment Date: ";
        cin>>date;

        cout<<"Enter Appointment Time: ";
        cin>>time;
    }

    void display(){
        cout<<"\nAppointment Details\n";
        cout<<"Patient Name: "<<patientName<<endl;
        cout<<"Doctor Name: "<<doctorName<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Time: "<<time<<endl;
    }

    void reschedule(){
        cout<<"\nEnter New Date: ";
        cin>>date;

        cout<<"Enter New Time: ";
        cin>>time;

        cout<<"Appointment Rescheduled Successfully\n";
    }
};

int main(){
    Appointment a;

    a.input();

    cout<<"\nOriginal Appointment\n";
    a.display();

    a.reschedule();

    cout<<"\nUpdated Appointment\n";
    a.display();

    return 0;
}