#include<iostream>
#include<string>
using namespace std;

// PERSON CLASS 
class Person{
protected:
    string name;
    int age;
    string gender;
    string contact;

public:
    Person(string name="",int age=0,string gender="",string contact=""){
        this->name=name;
        this->age=age;
        this->gender=gender;
        this->contact=contact;
    }
//	setter
    void setname(string name){this->name=name;}
    void setage(int age){this->age=age;}
    void setgender(string gender){this->gender=gender;}
    void setcontact(string contact){this->contact=contact;}
//	getter
    string getname() const{return name;}
    int getage() const{return age;}
    string getgender() const{return gender;}
    string getcontact() const{return contact;}

    virtual void display() const {
        cout<<"Name    : "<<name<<endl;
        cout<<"Age     : "<<age<<endl;
        cout<<"Gender  : "<<gender<<endl;
        cout<<"Contact : "<<contact<<endl;
    }

    virtual ~Person(){}
};


// PASSENGER CLASS INHERIT FROM PASSENGER
class Passenger: public Person{
private:
    string passportNo;
    string nationality;

public:
    Passenger():Person("Unknown",0,"Unknown","Unknown"){
        passportNo="Not Available";
        nationality="Not Available";
    }

    Passenger(string name,int age,string gender,string contact,string nation,string p)
    :Person(name,age,gender,contact)
    {
        passportNo=p;
        nationality=nation;
    }
//	setters
    void setpassportno(string p){passportNo=p;}
    void setnationality(string nation){nationality=nation;}
//	getters
    string getpassportno() const{return passportNo;}
    string getnationality() const{return nationality;}

    void display() const {
        cout<<"\n-------- PASSENGER INFO --------\n";
        Person::display();
        cout<<"Passport No : "<<passportNo<<endl;
        cout<<"Nationality : "<<nationality<<endl;
    }

    ~Passenger(){}
};


//FLIGHT CLASS
class Flight{
private:
    string flightNo;
    string source;
    string destination;
    int totalSeats;
    int bookedSeats;

public:
    Flight(string f="",string s="",string d="",int t=0){
        flightNo=f;
        source=s;
        destination=d;
        totalSeats=t;
        bookedSeats=0;
    }
//	setters
    void setflightno(string f){flightNo=f;}
    void setsource(string s){source=s;}
    void setdestination(string d){destination=d;}
    void settotalSeats(int t){totalSeats=t;}
//	getters
    string getFlightNo() const{return flightNo;}
    string getsource() const{return source;}
    string getdestination() const{return destination;}
    int gettotalseats() const{return totalSeats;}
    int getBookedSeats() const{return bookedSeats;}


    int getAvailableSeats() const{
        return totalSeats-bookedSeats;
    }
    
    bool bookSeat(){
        if(bookedSeats<totalSeats){
            bookedSeats++;
            return true;
        }
        return false;
    }
    
    bool cancelSeat(){
        if(bookedSeats>0){
            bookedSeats--;
            return true;
        }
        return false;
    }

    virtual void displayInfo() const{
        cout<<"Flight No        : "<<flightNo<<endl;
        cout<<"Route            : "<<source<<" -> "<<destination<<endl;
        cout<<"Total Seats      : "<<totalSeats<<endl;
        cout<<"Booked Seats     : "<<bookedSeats<<endl;
        cout<<"Available Seats  : "<<getAvailableSeats()<<endl;
    }

    virtual ~Flight(){}
};


//DOMESTIC FLIGHT INHERIT FROM FLIGHT
class DomesticFlight: public Flight{
private:
    int price;
public:
    DomesticFlight(string f="",string s="",string d="",int t=0,int p=0)
    :Flight(f,s,d,t),price(p){}
//  GETTER AND SETTER
    void setprice(int p){price=p;}
    int getprice() const{return price;}

    void displayInfo() const {
        cout<<"\n-------- DOMESTIC FLIGHT --------\n";
        Flight::displayInfo();
        cout<<"Price (PKR)      : "<<price<<endl;
    }

    ~DomesticFlight(){}
};

//INTERNATIONAL FLIGHT INHERIT FROM FLIGHT

class InternationalFlight: public Flight{
private:
    int price;
    string visa;
public:
    InternationalFlight(string f="",string s="",string d="",int t=0,int p=0,string v="")
    :Flight(f,s,d,t),price(p),visa(v) {}
   
//	setter
    void setprice(int p){price=p;}
    void setvisa(string v){visa=v;}
//	getter
    int getprice() const{return price;}
    string getvisa() const{return visa;}

    void displayInfo() const {
        cout<<"\n-------- INTERNATIONAL FLIGHT --------\n";
        Flight::displayInfo();
        cout<<"Price (PKR)      : "<<price<<endl;
        cout<<"Visa Requirement : "<<visa<<endl;
    }

    ~InternationalFlight(){}
};


//BOOKING CLASS
class Booking{
private:
    string bookingID;
    Passenger passenger;
    Flight* flight;
    bool active;

public:
    Booking():bookingID(""),flight(NULL),active(false){}
    
    Booking(string id, Passenger p, Flight* f)
    :bookingID(id), passenger(p), flight(f), active(false)
    {
        if(flight != NULL){
            if(flight->bookSeat()){
                active=true;
            }
            else{
                cout<<"\nNo seats available! Booking failed.\n";
                flight=NULL;
            }
        }
    }

    Booking(const Booking& b)
    :bookingID(b.bookingID),
     passenger(b.passenger),
     flight(b.flight),
     active(b.active)
    {}

    Booking& operator=(const Booking& b){
        if(this != &b){
            bookingID = b.bookingID;
            passenger = b.passenger;
            flight    = b.flight;
            active    = b.active;
        }
        return *this;
    }

    void setBookingID(string id){bookingID=id;}
    void setPassenger(Passenger p){passenger=p;}

    void setFlight(Flight* f){
        if(f != NULL){
            if(f->bookSeat()){
                flight=f;
                active=true;
            }
            else{
                cout<<"\nNo seats available!\n";
            }
        }
    }

    string getBookingID() const{return bookingID;}
    bool getStatus() const{return active;}
    Flight* getFlight() const{return flight;}

    void cancelBooking(){
        if(!active){
            cout<<"\nBooking already cancelled!\n";
            return;
        }
        active=false;
        if(flight != NULL){
            flight->cancelSeat();
        }
        cout<<"\nBooking Cancelled Successfully!\n";
    }

    bool operator==(const Booking& b) const{
        return bookingID == b.bookingID;
    }

    void displayInfo() const{
        cout<<"\n========== BOOKING ==========\n";
        cout<<"Booking ID : "<<bookingID<<endl;
        passenger.display();
        if(flight != NULL){
            flight->displayInfo();
        }
        else{
            cout<<"\nFlight : Not Assigned / Cancelled\n";
        }
        cout<<"Status     : "<<(active ? "Active" : "Cancelled")<<endl;
        cout<<"=============================\n";
    }
};


//HELPER FUNCTION 
string intToStr(int n){
    if(n==0) return "0";
    string result="";
    bool negative=false;
    if(n<0){negative=true;n=-n;}
    while(n>0){
        char c = '0' + (n % 10);
        result = c + result;
        n /= 10;
    }
    if(negative) result = "-" + result;
    return result;
}

//AIRLINE SYSTEM controll claasses and main class 
class AirlineSystem{
private:
    Flight*  flights[12];
    Booking  bookings[100];
    int      flightCount;
    int      bookingCount;
    int      cancelledCount;
    static int nextID;

    string toLower(string s) const{
        for(int i=0; i<(int)s.length(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i] + 32;
            }
        }
        return s;
    }

public:
    AirlineSystem(){
        flightCount   = 12;
        bookingCount  = 0;
        cancelledCount= 0;
//      dynamic memory
        flights[0]  = new DomesticFlight("PK101","Peshawar","Karachi",5,9000);
        flights[1]  = new DomesticFlight("PK102","Karachi","Lahore",6,8500);
        flights[2]  = new DomesticFlight("PK103","Islamabad","Peshawar",4,7000);
        flights[3]  = new DomesticFlight("PK104","Lahore","Islamabad",5,6500);
        flights[4]  = new DomesticFlight("PK105","Balochistan","Karachi",3,7500);
        flights[5]  = new DomesticFlight("PK106","Karachi","Quetta",4,8000);
        flights[6]  = new DomesticFlight("PK107","Peshawar","Lahore",5,7200);
        flights[7]  = new InternationalFlight("PK201","Karachi","Dubai",3,50000,"UAE Visa");
        flights[8]  = new InternationalFlight("PK202","Islamabad","Qatar",2,65000,"Qatar Visa");
        flights[9]  = new InternationalFlight("PK203","Lahore","United Kingdom",2,120000,"UK Visa");
        flights[10] = new InternationalFlight("PK204","Karachi","USA",2,200000,"USA Visa");
        flights[11] = new InternationalFlight("PK205","Peshawar","Saudi Arabia",4,80000,"Saudi Visa");
    }

    //VIEW FLIGHTS
    void viewFlights(){
        cout<<"\n========== ALL FLIGHTS ==========\n";
        for(int i=0;i<flightCount;i++){
            cout<<"\nFlight "<<(i+1)<<":";
            flights[i]->displayInfo();
            cout<<"-----------------------------\n";
        }
    }

//	SEARCH FLIGHT 
    void searchFlight(){
        string source, destination;
        if(cin.peek()=='\n') cin.ignore();
        cout<<"\nEnter Source      : ";
        getline(cin, source);
        cout<<"Enter Destination : ";
        getline(cin, destination);
        bool found=false;
        for(int i=0;i<flightCount;i++){
            if(toLower(flights[i]->getsource()) == toLower(source) &&
               toLower(flights[i]->getdestination()) == toLower(destination)){
                flights[i]->displayInfo();
                found=true;
            }
        }
        if(!found) cout<<"\nNo Flight Found for this route.\n";
    }

   
//	BOOK FLIGHT
    void bookFlight(){
        if(bookingCount>=100){
            cout<<"\nBooking Limit Reached!\n";
            return;
        }
        cout<<"\n========== AVAILABLE FLIGHTS ==========\n";
        for(int i=0;i<flightCount;i++){
            cout<<(i+1)<<". "
                <<flights[i]->getFlightNo()
                <<" | "<<flights[i]->getsource()
                <<" -> "<<flights[i]->getdestination()
                <<" | Available Seats: "<<flights[i]->getAvailableSeats()
                <<endl;
        }
        int index;
        cout<<"\nSelect Flight Number (1-"<<flightCount<<") : ";
        cin>>index;
        index--;
        if(index<0 || index>=flightCount){
            cout<<"\nInvalid Flight Number!\n";
            return;
        }
        if(flights[index]->getAvailableSeats()<=0){
            cout<<"\nNo Seats Available on this flight!\n";
            return;
        }
        string name, gender, contact, nationality, passport;
        int age;
        cin.ignore();
        
        cout<<"\n--- Enter Passenger Details ---\n";
        cout<<"Enter Name        : ";
        getline(cin, name);
        cout<<"Enter Age         : ";
        cin>>age;
        while(age<=0){
            cout<<"Invalid Age. Enter Again : ";
            cin>>age;
        }
        cin.ignore();
        cout<<"Enter Gender      : ";
        getline(cin, gender);
        
        cout<<"Enter Contact     : ";
        getline(cin, contact);
        
        cout<<"Enter Nationality : ";
        getline(cin, nationality);
        
        cout<<"Enter Passport No : ";
        getline(cin, passport);
        
        Passenger p(name, age, gender, contact, nationality, passport);
        string id="bk"+intToStr(++nextID);
        
        Booking newBooking(id, p, flights[index]);
        if(newBooking.getStatus()){
            bookings[bookingCount]=newBooking;
            bookingCount++;
            cout<<"\nBooking Successful!\n";
            cout<<"Your Booking ID : "<<id<<endl;
        }
        else{
            cout<<"\nBooking Failed!\n";
        }
    }


//	CANCEL BOOKING 
    void cancelBooking(){
        string id;
        cout<<"\nEnter Booking ID : ";
        cin>>id;
        bool found=false;
        for(int i=0;i<bookingCount;i++){
            if(bookings[i].getBookingID()==id){
                found=true;
                if(bookings[i].getStatus()){

   				 bookings[i].cancelBooking();

    			cancelledCount++;

    // array shift
    		for(int j=i;j<bookingCount-1;j++){
        	bookings[j]=bookings[j+1];
    }
    // last object empty karo
    	bookings[bookingCount-1]=Booking();
    // booking count decrease
    			bookingCount--;
				}
                else{
                    cout<<"\nBooking Already Cancelled!\n";
                }
                break;
            }
        }
        if(!found) cout<<"\nBooking Not Found!\n";
    }


//	VIEW SINGLE BOOKING 
    void viewBooking(){
        string id;
        cout<<"\nEnter Booking ID : ";
        cin>>id;
        bool found=false;
        for(int i=0;i<bookingCount;i++){
            if(bookings[i].getBookingID()==id){
                bookings[i].displayInfo();
                found=true;
                break;
            }
        }
        if(!found) cout<<"\nBooking Not Found!\n";
    }

//	VIEW ALL BOOKINGS 
    void viewPassengerBookings(){
        if(bookingCount==0){
            cout<<"\nNo Bookings Found!\n";
            return;
        }
        for(int i=0;i<bookingCount;i++){
            bookings[i].displayInfo();
        }
    }


//	VIEW SEATS
    void viewSeats(){
        cout<<"\n========== AVAILABLE SEATS ==========\n";
        for(int i=0;i<flightCount;i++){
            cout<<"Flight : "<<flights[i]->getFlightNo()
                <<" | "<<flights[i]->getsource()
                <<" -> "<<flights[i]->getdestination()
                <<" | Available: "<<flights[i]->getAvailableSeats()
                <<"/"<<flights[i]->gettotalseats()<<endl;
        }
        cout<<"=====================================\n";
    }


//	SUMMARY
    void summary(){
        int activeBookings=0;
        for(int i=0;i<bookingCount;i++){
            if(bookings[i].getStatus()) activeBookings++;
        }
        cout<<"\n========== SYSTEM SUMMARY ==========\n";
        cout<<"Total Flights    : "<<flightCount<<endl;
        cout<<"Total Bookings   : "<<bookingCount<<endl;
        cout<<"Active Bookings  : "<<activeBookings<<endl;
        cout<<"Cancelled        : "<<cancelledCount<<endl;
        cout<<"Booking Capacity : 100"<<endl;
        cout<<"====================================\n";
    }


//	DESTRUCTOR to de-allocate run time memory 
    ~AirlineSystem(){
        for(int i=0;i<flightCount;i++){
            delete flights[i];
            flights[i]=NULL;
        }
        cout<<"\nAirline System Closed. Goodbye!\n";
    }
};
int AirlineSystem::nextID=0;


//	MAIN 
int main(){
    AirlineSystem airline;
    int choice;
    do{
        cout<<"\n========== AIRLINE SYSTEM ==========";
        cout<<"\n 1. View All Flights";
        cout<<"\n 2. Book Flight";
        cout<<"\n 3. Cancel Booking";
        cout<<"\n 4. View Booking";
        cout<<"\n 5. View All Bookings";
        cout<<"\n 6. View Available Seats";
        cout<<"\n 7. System Summary";
        cout<<"\n 8. Search Flight";
        cout<<"\n 0. Exit";
        cout<<"\n=====================================";
        cout<<"\nEnter Choice : ";
        cin>>choice;
        switch(choice){
            case 1:airline.viewFlights();    break;
            case 2:airline.bookFlight();     break;
            case 3:airline.cancelBooking();  break;
            case 4:airline.viewBooking();    break;
            case 5:airline.viewPassengerBookings(); break;
            case 6:airline.viewSeats();      break;
            case 7:airline.summary();        break;
            case 8:airline.searchFlight();   break;
            case 0:cout<<"\nGood Bye!\n";    break;
            default:cout<<"\nInvalid Choice!\n";
        }
    }while(choice!=0);
    return 0;
}
