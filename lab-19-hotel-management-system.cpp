#include<iostream>
using namespace std;

class Hotel{
private:
    int roomNo;
    string customerName;
    int days;
    double roomRent;
    bool booked;

public:
    Hotel(){
        roomNo=0;
        customerName="";
        days=0;
        roomRent=0;
        booked=false;
    }

    void addRoom(int no,double rent){
        roomNo=no;
        roomRent=rent;
        booked=false;
    }

    int getRoomNo(){
        return roomNo;
    }

    bool isBooked(){
        return booked;
    }

    void bookRoom(){

        if(booked){
            cout<<"Room Already Booked\n";
            return;
        }

        cin.ignore();

        cout<<"Enter Customer Name: ";
        getline(cin,customerName);

        cout<<"Enter Number of Days: ";
        cin>>days;

        booked=true;

        cout<<"Room Booked Successfully\n";
    }

    void checkOut(){

        if(!booked){
            cout<<"Room is Empty\n";
            return;
        }

        cout<<"\n========== BILL ==========\n";
        cout<<"Customer Name : "<<customerName<<endl;
        cout<<"Room Number   : "<<roomNo<<endl;
        cout<<"Days Stayed   : "<<days<<endl;
        cout<<"Room Rent     : "<<roomRent<<endl;
        cout<<"Total Bill    : "<<roomRent*days<<endl;

        booked=false;
        customerName="";
        days=0;

        cout<<"\nCustomer Checked Out Successfully\n";
    }

    void display(){

        cout<<"\nRoom Number : "<<roomNo<<endl;
        cout<<"Rent        : "<<roomRent<<endl;

        if(booked){
            cout<<"Status      : Booked"<<endl;
            cout<<"Customer    : "<<customerName<<endl;
            cout<<"Days        : "<<days<<endl;
        }
        else{
            cout<<"Status      : Available"<<endl;
        }
    }

};

int main(){

    Hotel rooms[5];

    rooms[0].addRoom(101,2500);
    rooms[1].addRoom(102,3000);
    rooms[2].addRoom(103,3500);
    rooms[3].addRoom(104,4000);
    rooms[4].addRoom(105,5000);

    int choice;
    int room;

    do{

        cout<<"\n========== HOTEL MANAGEMENT ==========\n";
        cout<<"1. Display Rooms\n";
        cout<<"2. Book Room\n";
        cout<<"3. Check Out\n";
        cout<<"4. Exit\n";

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice){

        case 1:

            for(int i=0;i<5;i++){
                rooms[i].display();
            }

            break;

        case 2:

            cout<<"Enter Room Number: ";
            cin>>room;

            for(int i=0;i<5;i++){

                if(rooms[i].getRoomNo()==room){
                    rooms[i].bookRoom();
                }

            }

            break;

        case 3:

            cout<<"Enter Room Number: ";
            cin>>room;

            for(int i=0;i<5;i++){

                if(rooms[i].getRoomNo()==room){
                    rooms[i].checkOut();
                }

            }

            break;

        case 4:

            cout<<"Thank You!\n";
            break;

        default:

            cout<<"Invalid Choice\n";

        }

    }while(choice!=4);

    return 0;
}