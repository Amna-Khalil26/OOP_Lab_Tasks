#include<iostream>
using namespace std;

class Course{
private:
    int courseID;
    string courseName;
    int creditHours;

public:
    void inputCourse(){
        cout<<"Enter Course ID: ";
        cin>>courseID;

        cin.ignore();

        cout<<"Enter Course Name: ";
        getline(cin,courseName);

        cout<<"Enter Credit Hours: ";
        cin>>creditHours;
    }

    int getCreditHours(){
        return creditHours;
    }

    string getCourseName(){
        return courseName;
    }

    void displayCourse(){
        cout<<"Course ID      : "<<courseID<<endl;
        cout<<"Course Name    : "<<courseName<<endl;
        cout<<"Credit Hours   : "<<creditHours<<endl;
    }
};

class Student{
private:
    int id;
    string name;
    string department;
    Course courses[3];

public:
    void inputStudent(){

        cout<<"Enter Student ID: ";
        cin>>id;

        cin.ignore();

        cout<<"Enter Student Name: ";
        getline(cin,name);

        cout<<"Enter Department: ";
        getline(cin,department);

        cout<<"\nEnter Course Details\n";

        for(int i=0;i<3;i++){
            cout<<"\nCourse "<<i+1<<endl;
            courses[i].inputCourse();
        }
    }

    int totalCreditHours(){
        int total=0;

        for(int i=0;i<3;i++){
            total+=courses[i].getCreditHours();
        }

        return total;
    }

    void displayStudent(){

        cout<<"\n=====================================\n";
        cout<<"       STUDENT INFORMATION\n";
        cout<<"=====================================\n";

        cout<<"Student ID : "<<id<<endl;
        cout<<"Name       : "<<name<<endl;
        cout<<"Department : "<<department<<endl;

        cout<<"\nRegistered Courses\n";

        for(int i=0;i<3;i++){
            cout<<"\nCourse "<<i+1<<endl;
            courses[i].displayCourse();
        }

        cout<<"\nTotal Credit Hours : "<<totalCreditHours()<<endl;
    }
};

int main(){

    Student s;

    s.inputStudent();

    s.displayStudent();

    return 0;
}