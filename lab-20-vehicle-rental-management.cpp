#include<iostream>
using namespace std;

class Vehicle{
private:
    int vehicleID;
    string model;
    string company;
    double rentPerDay;
    bool available;
    string customerName;
    int days;

public:

    Vehicle(){
        vehicleID=0;
        model="";
        company="";
        rentPerDay=0;
        available=true;
        customerName="";
        days=0;
    }

    void addVehicle(int id,string m,string c,double rent){
        vehicleID=id;
        model=m;
        company=c;
        rentPerDay=rent;
        available=true;
    }

    int getID(){
        return vehicleID;
    }

    void display(){

        cout<<"\n=================================="<<endl;
        cout<<"Vehicle ID : "<<vehicleID<<endl;
        cout<<"Model      : "<<model<<endl;
        cout<<"Company    : "<<company<<endl;
        cout<<"Rent/Day   : Rs. "<<rentPerDay<<endl;

        if(available)
            cout<<"Status     : Available"<<endl;
        else{
            cout<<"Status     : Rented"<<endl;
            cout<<"Customer   : "<<customerName<<endl;
            cout<<"Days       : "<<days<<endl;
        }
    }

    void rentVehicle(){

        if(!available){
            cout<<"Vehicle Already Rented"<<endl;
            return;
        }

        cin.ignore();

        cout<<"Enter Customer Name: ";
        getline(cin,customerName);

        cout<<"Enter Number of Days: ";
        cin>>days;

        available=false;

        cout<<"Vehicle Rented Successfully"<<endl;
    }

    void returnVehicle(){

        if(available){
            cout<<"Vehicle is Already Available"<<endl;
            return;
        }

        double bill=days*rentPerDay;

        cout<<"\n========== RENTAL BILL =========="<<endl;
        cout<<"Customer Name : "<<customerName<<endl;
        cout<<"Vehicle Model : "<<model<<endl;
        cout<<"Days          : "<<days<<endl;
        cout<<"Rent Per Day  : "<<rentPerDay<<endl;
        cout<<"Total Bill    : Rs. "<<bill<<endl;

        available=true;
        customerName="";
        days=0;

        cout<<"\nVehicle Returned Successfully"<<endl;
    }

};

int main(){

    Vehicle vehicles[5];

    vehicles[0].addVehicle(101,"Civic","Honda",5000);
    vehicles[1].addVehicle(102,"Corolla","Toyota",4500);
    vehicles[2].addVehicle(103,"Sportage","KIA",7000);
    vehicles[3].addVehicle(104,"City","Honda",4800);
    vehicles[4].addVehicle(105,"Yaris","Toyota",4200);

    int choice,id;

    do{

        cout<<"\n========== VEHICLE RENTAL SYSTEM ==========\n";
        cout<<"1. Show Vehicles"<<endl;
        cout<<"2. Rent Vehicle"<<endl;
        cout<<"3. Return Vehicle"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice){

        case 1:

            for(int i=0;i<5;i++){
                vehicles[i].display();
            }

            break;

        case 2:

            cout<<"Enter Vehicle ID: ";
            cin>>id;

            for(int i=0;i<5;i++){

                if(vehicles[i].getID()==id){
                    vehicles[i].rentVehicle();
                }

            }

            break;

        case 3:

            cout<<"Enter Vehicle ID: ";
            cin>>id;

            for(int i=0;i<5;i++){

                if(vehicles[i].getID()==id){
                    vehicles[i].returnVehicle();
                }

            }

            break;

        case 4:

            cout<<"Thank You"<<endl;
            break;

        default:

            cout<<"Invalid Choice"<<endl;

        }

    }while(choice!=4);

    return 0;
}