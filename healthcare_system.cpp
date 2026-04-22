#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int    id;
    string name;
    int    age;
    string gender;

public:

    Person(int i, string n, int a, string g)
        : id(i), name(n), age(a), gender(g) {}

    virtual ~Person() {}

    int    getID()     const { return id; }
    string getName()   const { return name; }
    int    getAge()    const { return age; }
    string getGender() const { return gender; }

    void setID(int i)        { id = i; }
    void setName(string n)   { name = n; }
    void setAge(int a)       { age = a; }
    void setGender(string g) { gender = g; }

    virtual void display() const {
        cout << " ID        : " << id     << endl;
        cout << " Name      : " << name   << endl;
        cout << " Age       : " << age    << endl;
        cout << " Gender    : " << gender << endl;
    }
};

class Patient : public Person {
private:
    string disease;
    string contact;
    string bloodGroup;
    string assignedDoctor;  

public:
   
    Patient(int i, string n, int a, string g,
            string d, string c, string b)
        : Person(i, n, a, g),
          disease(d), contact(c), bloodGroup(b),
          assignedDoctor("Not Assigned") {}

  
    ~Patient() {
        cout << " [Patient record removed: " << getName() << "]\n";
    }

    string getDisease()       const { return disease; }
    string getContact()       const { return contact; }
    string getBloodGroup()    const { return bloodGroup; }
    string getAssignedDoctor()const { return assignedDoctor; }

    void setDisease(string d)       { disease = d; }
    void setContact(string c)       { contact = c; }
    void setBloodGroup(string b)    { bloodGroup = b; }
    void setAssignedDoctor(string d){ assignedDoctor = d; }

    void display() const override {
        cout << "\n========================================\n";
        cout << "         PATIENT DETAILS\n";
        cout << "========================================\n";
        Person::display();
        cout << " Disease        : " << disease        << endl;
        cout << " Contact        : " << contact        << endl;
        cout << " Blood Group    : " << bloodGroup     << endl;
        cout << " Assigned Doctor: " << assignedDoctor << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    int    experience;       
    double consultationFee;

public:

    Doctor(int i, string n, int a, string g,
           string s, int exp, double fee)
        : Person(i, n, a, g),
          specialization(s), experience(exp), consultationFee(fee) {}

    
    ~Doctor() {
        cout << " [Doctor record removed: " << getName() << "]\n";
    }

    string getSpecialization() const { return specialization; }
    int    getExperience()     const { return experience; }
    double getFee()            const { return consultationFee; }

    void setSpecialization(string s) { specialization = s; }
    void setExperience(int e)        { experience = e; }
    void setFee(double f)            { consultationFee = f; }

    void display() const override {
        cout << "\n========================================\n";
        cout << "         DOCTOR DETAILS\n";
        cout << "========================================\n";
        Person::display();
        cout << " Specialization : " << specialization  << endl;
        cout << " Experience     : " << experience << " years\n";
        cout << " Consultation Fee: Rs." << consultationFee << endl;
    }
};

class Appointment {
private:
    int    appointmentID;
    string patientName;
    string doctorName;
    string date;
    string time;
    string roomNo;

public:

    Appointment() {
        appointmentID = 0;
        patientName   = "Unknown";
        doctorName    = "Unknown";
        date          = "Not Set";
        time          = "Not Set";
        roomNo        = "Not Assigned";
    }

    Appointment(int id, string pName, string dName,
                string d, string t, string r) {
        appointmentID = id;
        patientName   = pName;
        doctorName    = dName;
        date          = d;
        time          = t;
        roomNo        = r;
    }

    ~Appointment() {}
    
    int    getAppointmentID() const { return appointmentID; }
    string getPatientName()   const { return patientName; }
    string getDoctorName()    const { return doctorName; }
    string getDate()          const { return date; }
    string getTime()          const { return time; }
    string getRoomNo()        const { return roomNo; }

    void setDate(string d)   { date = d; }
    void setTime(string t)   { time = t; }
    void setRoomNo(string r) { roomNo = r; }

    void display() const {
        cout << "\n========================================\n";
        cout << "         APPOINTMENT DETAILS\n";
        cout << "========================================\n";
        cout << " Appointment ID : " << appointmentID << endl;
        cout << " Patient        : " << patientName   << endl;
        cout << " Doctor         : " << doctorName    << endl;
        cout << " Date           : " << date          << endl;
        cout << " Time           : " << time          << endl;
        cout << " Room No        : " << roomNo        << endl;
    }
};

class Bill {
private:
    string patientName;
    double consultationFee;
    double medicineFee;
    double labCharges;

public:
   
    Bill(string name, double c, double m, double l)
        : patientName(name), consultationFee(c),
          medicineFee(m), labCharges(l) {}

    ~Bill() {}
    string getPatientName()    const { return patientName; }
    double getConsultationFee()const { return consultationFee; }
    double getMedicineFee()    const { return medicineFee; }
    double getLabCharges()     const { return labCharges; }
    double getTotal()          const {
        return consultationFee + medicineFee + labCharges;
    }

    void setConsultationFee(double c) { consultationFee = c; }
    void setMedicineFee(double m)     { medicineFee = m; }
    void setLabCharges(double l)      { labCharges = l; }

    Bill operator+(const Bill& b) const {
        return Bill(
            patientName + " & " + b.patientName,
            consultationFee + b.consultationFee,
            medicineFee     + b.medicineFee,
            labCharges      + b.labCharges
        );
    }

    bool operator==(const Bill& b) const {
        return getTotal() == b.getTotal();
    }
    void display() const {
        cout << "\n========================================\n";
        cout << "         BILLING DETAILS\n";
        cout << "========================================\n";
        cout << " Patient          : " << patientName     << endl;
        cout << "----------------------------------------\n";
        cout << " Consultation Fee : Rs." << consultationFee << endl;
        cout << " Medicine Fee     : Rs." << medicineFee     << endl;
        cout << " Lab Charges      : Rs." << labCharges      << endl;
        cout << "----------------------------------------\n";
        cout << " TOTAL BILL       : Rs." << getTotal()      << endl;
        cout << "========================================\n";
    }
};

class HospitalSystem {
private:

    Patient**     patients;
    Doctor**      doctors;
    Appointment** appointments;
    Bill**        bills;

    int patientCount;
    int doctorCount;
    int appointmentCount;
    int billCount;

    static const int MAX = 10;

public:
   
    HospitalSystem() {
        patients     = new Patient*[MAX];
        doctors      = new Doctor*[MAX];
        appointments = new Appointment*[MAX];
        bills        = new Bill*[MAX];

        patientCount     = 0;
        doctorCount      = 0;
        appointmentCount = 0;
        billCount        = 0;

        cout << "\n [Hospital System Initialized]\n";
    }

    ~HospitalSystem() {
        cout << "\n========================================\n";
        cout << "   Releasing Hospital System Memory...\n";
        cout << "========================================\n";

        for (int i = 0; i < patientCount;     i++) delete patients[i];
        for (int i = 0; i < doctorCount;      i++) delete doctors[i];
        for (int i = 0; i < appointmentCount; i++) delete appointments[i];
        for (int i = 0; i < billCount;        i++) delete bills[i];

        delete[] patients;
        delete[] doctors;
        delete[] appointments;
        delete[] bills;
    }

    void registerPatient(int id, string name, int age, string gender,
                         string disease, string contact, string blood) {
        if (patientCount >= MAX) {
            cout << " [Error] Patient limit reached!\n";
            return;
        }
        patients[patientCount++] = new Patient(id, name, age, gender,
                                               disease, contact, blood);
        cout << "\n [Patient Registered: " << name << "]\n";
    }

    void addDoctor(int id, string name, int age, string gender,
                   string spec, int exp, double fee) {
        if (doctorCount >= MAX) {
            cout << " [Error] Doctor limit reached!\n";
            return;
        }
        doctors[doctorCount++] = new Doctor(id, name, age, gender,
                                            spec, exp, fee);
        cout << "\n [Doctor Added: " << name << "]\n";
    }

    // -- 3. Assign Doctor to Patient --------------------------
    void assignDoctor(int patientID, int doctorID) {
        Patient* p = findPatient(patientID);
        Doctor*  d = findDoctor(doctorID);

        if (!p) { cout << " [Error] Patient not found!\n"; return; }
        if (!d) { cout << " [Error] Doctor not found!\n";  return; }

        p->setAssignedDoctor(d->getName());
        cout << "\n [Doctor " << d->getName()
             << " assigned to " << p->getName() << "]\n";
    }

    // -- 4. Create Appointment --------------------------------
    void createAppointment(int appID, int patientID, int doctorID,
                           string date, string time, string room) {
        if (appointmentCount >= MAX) {
            cout << " [Error] Appointment limit reached!\n";
            return;
        }
        Patient* p = findPatient(patientID);
        Doctor*  d = findDoctor(doctorID);

        string pName = p ? p->getName() : "Unknown";
        string dName = d ? d->getName() : "Unknown";

        appointments[appointmentCount++] =
            new Appointment(appID, pName, dName, date, time, room);

        cout << "\n [Appointment Created for " << pName << "]\n";
    }

    // -- 5. Generate Bill -------------------------------------
    void generateBill(int patientID, double medFee, double labFee) {
        Patient* p = findPatient(patientID);
        if (!p) { cout << " [Error] Patient not found!\n"; return; }

        // Find doctor fee
        double docFee = 0;
        for (int i = 0; i < doctorCount; i++) {
            if (doctors[i]->getName() == p->getAssignedDoctor()) {
                docFee = doctors[i]->getFee();
                break;
            }
        }

        bills[billCount++] = new Bill(p->getName(), docFee, medFee, labFee);
        cout << "\n [Bill Generated for " << p->getName() << "]\n";
    }

    // -- 6. Display Patient Record ----------------------------
    void displayPatientRecord(int patientID) {
        Patient* p = findPatient(patientID);
        if (!p) { cout << " [Error] Patient not found!\n"; return; }
        p->display();
    }

    // -- 7. Display All Records -------------------------------
    void displayAll() {
        cout << "\n\n============================================\n";
        cout << "         ALL HOSPITAL RECORDS\n";
        cout << "============================================\n";

        cout << "\n>>> PATIENTS (" << patientCount << ")";
        for (int i = 0; i < patientCount; i++) patients[i]->display();

        cout << "\n>>> DOCTORS (" << doctorCount << ")";
        for (int i = 0; i < doctorCount; i++) doctors[i]->display();

        cout << "\n>>> APPOINTMENTS (" << appointmentCount << ")";
        for (int i = 0; i < appointmentCount; i++) appointments[i]->display();

        cout << "\n>>> BILLS (" << billCount << ")";
        for (int i = 0; i < billCount; i++) bills[i]->display();
    }

    // -- 8. Display Combined Bill (operator+ demo) ------------
    void displayCombinedBill() {
        if (billCount < 2) {
            cout << " [Info] Need at least 2 bills to combine.\n";
            return;
        }
        Bill combined = *bills[0] + *bills[1];
        cout << "\n========================================\n";
        cout << "     COMBINED BILL (Operator + Demo)\n";
        cout << "========================================\n";
        combined.display();
    }

    // -- 9. Compare Bills (operator== demo) ------------------
    void compareBills() {
        if (billCount < 2) {
            cout << " [Info] Need at least 2 bills to compare.\n";
            return;
        }
        bool same = (*bills[0] == *bills[1]);
        cout << "\n [Bill Comparison]: Bills are "
             << (same ? "EQUAL" : "NOT EQUAL") << ".\n";
    }

private:
    // Helper: find patient by ID
    Patient* findPatient(int id) {
        for (int i = 0; i < patientCount; i++)
            if (patients[i]->getID() == id) return patients[i];
        return nullptr;
    }

    // Helper: find doctor by ID
    Doctor* findDoctor(int id) {
        for (int i = 0; i < doctorCount; i++)
            if (doctors[i]->getID() == id) return doctors[i];
        return nullptr;
    }
};


// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "=============================================\n";
    cout << "       SMART HEALTHCARE PATIENT &\n";
    cout << "           BILLING SYSTEM\n";
    cout << "     BS-CS Semester 2 | OOP Project\n";
    cout << "=============================================\n";

    // Create Hospital System (dynamic memory)
    HospitalSystem hospital;

    // -- Register Patients ------------------------------------
    hospital.registerPatient(101, "Amna Khalil",   20, "Female",
                             "Flu",      "0300-1234567", "B+");
    hospital.registerPatient(102, "Ali Hassan",    35, "Male",
                             "Diabetes", "0301-9876543", "O+");
    hospital.registerPatient(103, "Sara Nawaz",    28, "Female",
                             "Migraine", "0312-5556789", "A-");

    // -- Add Doctors ------------------------------------------
    hospital.addDoctor(201, "Dr. Muhammad",  45, "Male",
                       "General Physician", 20, 500.0);
    hospital.addDoctor(202, "Dr. Ayesha",    38, "Female",
                       "Neurologist",       12, 1500.0);

    // -- Assign Doctors ---------------------------------------
    hospital.assignDoctor(101, 201);   // Amna -> Dr. Muhammad
    hospital.assignDoctor(102, 201);   
    hospital.assignDoctor(103, 202);   

    hospital.createAppointment(301, 101, 201,
                               "12-Apr-2026", "10:30 AM", "Room-5");
    hospital.createAppointment(302, 103, 202,
                               "12-Apr-2026", "02:00 PM", "Room-9");

    hospital.generateBill(101, 800.0,  500.0);   // Amna
    hospital.generateBill(103, 600.0, 1200.0);   // Sara

    hospital.displayAll();


    hospital.displayCombinedBill();   
    hospital.compareBills();          

    cout << "\n=============================================\n";
    cout << "         THANK YOU - VISIT AGAIN!\n";
    cout << "=============================================\n";

    return 0;  // ~HospitalSystem() auto-called here
}#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int id;
    string name;
    int age;
    string gender;

public:
    Person(int i, string n, int a, string g) : id(i), name(n), age(a), gender(g) {}
    virtual ~Person() {}

    int    getID()     const { return id; }
    string getName()   const { return name; }
    int    getAge()    const { return age; }
    string getGender() const { return gender; }

    void setID(int i)        { id = i; }
    void setName(string n)   { name = n; }
    void setAge(int a)       { age = a; }
    void setGender(string g) { gender = g; }

    virtual void display() const {
        cout << " ID     : " << id     << endl;
        cout << " Name   : " << name   << endl;
        cout << " Age    : " << age    << endl;
        cout << " Gender : " << gender << endl;
    }
};

class Patient : public Person {
private:
    string disease;
    string contact;
    string bloodGroup;
    string assignedDoctor;

public:
    Patient(int i, string n, int a, string g, string d, string c, string b)
        : Person(i, n, a, g), disease(d), contact(c), bloodGroup(b), assignedDoctor("Not Assigned") {}

    ~Patient() {}

    string getDisease()        const { return disease; }
    string getContact()        const { return contact; }
    string getBloodGroup()     const { return bloodGroup; }
    string getAssignedDoctor() const { return assignedDoctor; }

    void setDisease(string d)        { disease = d; }
    void setContact(string c)        { contact = c; }
    void setBloodGroup(string b)     { bloodGroup = b; }
    void setAssignedDoctor(string d) { assignedDoctor = d; }

    void display() const override {
        cout << "\n========================================\n";
        cout << "           PATIENT DETAILS\n";
        cout << "========================================\n";
        Person::display();
        cout << " Disease : " << disease        << endl;
        cout << " Contact : " << contact        << endl;
        cout << " Blood   : " << bloodGroup     << endl;
        cout << " Doctor  : " << assignedDoctor << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    int    experience;
    double consultationFee;

public:
    Doctor(int i, string n, int a, string g, string s, int exp, double fee)
        : Person(i, n, a, g), specialization(s), experience(exp), consultationFee(fee) {}

    ~Doctor() {}

    string getSpecialization() const { return specialization; }
    int    getExperience()     const { return experience; }
    double getFee()            const { return consultationFee; }

    void setSpecialization(string s) { specialization = s; }
    void setExperience(int e)        { experience = e; }
    void setFee(double f)            { consultationFee = f; }

    void display() const override {
        cout << "\n========================================\n";
        cout << "           DOCTOR DETAILS\n";
        cout << "========================================\n";
        Person::display();
        cout << " Specialization : " << specialization          << endl;
        cout << " Experience     : " << experience << " years"  << endl;
        cout << " Fee            : Rs." << consultationFee      << endl;
    }
};

class Appointment {
private:
    int    appointmentID;
    string patientName;
    string doctorName;
    string date;
    string time;
    string roomNo;

public:
    Appointment() : appointmentID(0), patientName("Unknown"), doctorName("Unknown"),
                    date("Not Set"), time("Not Set"), roomNo("Not Assigned") {}

    Appointment(int id, string pName, string dName, string d, string t, string r)
        : appointmentID(id), patientName(pName), doctorName(dName), date(d), time(t), roomNo(r) {}

    ~Appointment() {}

    int    getAppointmentID() const { return appointmentID; }
    string getPatientName()   const { return patientName; }
    string getDoctorName()    const { return doctorName; }
    string getDate()          const { return date; }
    string getTime()          const { return time; }
    string getRoomNo()        const { return roomNo; }

    void setDate(string d)   { date = d; }
    void setTime(string t)   { time = t; }
    void setRoomNo(string r) { roomNo = r; }

    void display() const {
        cout << "\n========================================\n";
        cout << "         APPOINTMENT DETAILS\n";
        cout << "========================================\n";
        cout << " Appointment ID : " << appointmentID << endl;
        cout << " Patient        : " << patientName   << endl;
        cout << " Doctor         : " << doctorName    << endl;
        cout << " Date           : " << date          << endl;
        cout << " Time           : " << time          << endl;
        cout << " Room No        : " << roomNo        << endl;
    }
};

class Bill {
private:
    string patientName;
    double consultationFee;
    double medicineFee;
    double labCharges;

public:
    Bill(string name, double c, double m, double l)
        : patientName(name), consultationFee(c), medicineFee(m), labCharges(l) {}

    ~Bill() {}

    string getPatientName()     const { return patientName; }
    double getConsultationFee() const { return consultationFee; }
    double getMedicineFee()     const { return medicineFee; }
    double getLabCharges()      const { return labCharges; }
    double getTotal()           const { return consultationFee + medicineFee + labCharges; }

    void setConsultationFee(double c) { consultationFee = c; }
    void setMedicineFee(double m)     { medicineFee = m; }
    void setLabCharges(double l)      { labCharges = l; }

    Bill operator+(const Bill& b) const {
        return Bill(patientName + " & " + b.patientName,
                    consultationFee + b.consultationFee,
                    medicineFee + b.medicineFee,
                    labCharges + b.labCharges);
    }

    bool operator==(const Bill& b) const {
        return getTotal() == b.getTotal();
    }

    void display() const {
        cout << "\n========================================\n";
        cout << "           BILLING DETAILS\n";
        cout << "========================================\n";
        cout << " Patient          : " << patientName        << endl;
        cout << "----------------------------------------\n";
        cout << " Consultation Fee : Rs." << consultationFee << endl;
        cout << " Medicine Fee     : Rs." << medicineFee     << endl;
        cout << " Lab Charges      : Rs." << labCharges      << endl;
        cout << "----------------------------------------\n";
        cout << " TOTAL            : Rs." << getTotal()      << endl;
        cout << "========================================\n";
    }
};

class HospitalSystem {
private:
    Patient *p1, *p2, *p3;
    Doctor  *d1, *d2;
    Appointment *a1, *a2;
    Bill *b1, *b2;

public:
    HospitalSystem() {
        p1 = new Patient(101, "Amna Khalil", 20, "Female", "Flu", "0300-1234567", "B+");
        p2 = new Patient(102, "Ali Hassan", 35, "Male", "Diabetes", "0301-9876543", "O+");
        p3 = new Patient(103, "Sara Nawaz", 28, "Female", "Migraine", "0312-5556789", "A-");

        d1 = new Doctor(201, "Dr. Muhammad", 45, "Male", "General Physician", 20, 500.0);
        d2 = new Doctor(202, "Dr. Ayesha", 38, "Female", "Neurologist", 12, 1500.0);

        a1 = new Appointment(301, "Amna Khalil", "Dr. Muhammad", "12-Apr-2026", "10:30 AM", "Room-5");
        a2 = new Appointment(302, "Sara Nawaz", "Dr. Ayesha", "12-Apr-2026", "02:00 PM", "Room-9");

        b1 = new Bill("Amna Khalil", 500.0, 800.0, 500.0);
        b2 = new Bill("Sara Nawaz", 1500.0, 600.0, 1200.0);

        p1->setAssignedDoctor(d1->getName());
        p2->setAssignedDoctor(d1->getName());
        p3->setAssignedDoctor(d2->getName());
    }

    ~HospitalSystem() {
        delete p1; delete p2; delete p3;
        delete d1; delete d2;
        delete a1; delete a2;
        delete b1; delete b2;
    }

    void showAll() {
        cout << "\n============================================\n";
        cout << "               ALL PATIENTS\n";
        cout << "============================================\n";
        p1->display(); p2->display(); p3->display();

        cout << "\n============================================\n";
        cout << "               ALL DOCTORS\n";
        cout << "============================================\n";
        d1->display(); d2->display();

        cout << "\n============================================\n";
        cout << "             ALL APPOINTMENTS\n";
        cout << "============================================\n";
        a1->display(); a2->display();

        cout << "\n============================================\n";
        cout << "               ALL BILLS\n";
        cout << "============================================\n";
        b1->display(); b2->display();

        Bill combined = *b1 + *b2;
        cout << "\n============================================\n";
        cout << "      COMBINED BILL  \n";
        cout << "============================================\n";
        combined.display();

        cout << "\n============================================\n";
        cout << "     BILL COMPARISON  \n";
        cout << "============================================\n";
        if (*b1 == *b2)
            cout << " Bills are EQUAL.\n";
        else
            cout << " Bills are DIFFERENT.\n";

        cout << " Amna's Total : Rs." << b1->getTotal() << endl;
        cout << " Sara's Total : Rs." << b2->getTotal() << endl;
    }
};

int main() {
    cout << "=============================================\n";
    cout << "      SMART HEALTHCARE PATIENT &\n";
    cout << "          BILLING SYSTEM\n";
    cout << "    BS-CS Semester 2 | OOP Midterm\n";
    cout << "=============================================\n";

    HospitalSystem hospital;
    hospital.showAll();

    cout << "\n=============================================\n";
    cout << "         THANK YOU - VISIT AGAIN!\n";
    cout << "=============================================\n";

    return 0;
}