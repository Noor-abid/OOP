#include <iostream>
#include <string>
using namespace std;

// Base Class for common properties
class Person {
public:
    string name;
    string contactInfo;

    Person(const string& n, const string& contact) {
        name = n;
        contactInfo = contact;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << ", Contact Info: " << contactInfo << endl;
    }
};

class MedicalRecord {
public:
    string diagnosis;
    string treatmentHistory[10];
    string prescriptions[10];
    int treatmentCount = 0;
    int prescriptionCount = 0;

    void addDiagnosis(const string& diag) {
        diagnosis = diag;
    }

    void addTreatment(const string& treatment) {
        if (treatmentCount < 10) {
            treatmentHistory[treatmentCount++] = treatment;
        } else {
            cout << "Treatment history is full!" << endl;
        }
    }

    void addPrescription(const string& prescription) {
        if (prescriptionCount < 10) {
            prescriptions[prescriptionCount++] = prescription;
        } else {
            cout << "Prescription history is full!" << endl;
        }
    }

    void viewRecord() {
        cout << "Diagnosis: " << diagnosis << endl;
        cout << "Treatment History: ";
        for (int i = 0; i < treatmentCount; i++) {
            cout << treatmentHistory[i] << ", ";
        }
        cout << endl;
        cout << "Prescriptions: ";
        for (int i = 0; i < prescriptionCount; i++) {
            cout << prescriptions[i] << ", ";
        }
        cout << endl;
    }
};

// Bill Class for handling the payment functionality
class Bill {
public:
    float amountDue;
    bool isPaid;

    Bill() : amountDue(0.0), isPaid(false) {}

    void generateBill(float amount) {
        amountDue = amount;
        isPaid = false;
        cout << "Bill generated with amount: Rs" << amountDue << endl;
    }

    void displayBill() {
        cout << "Amount Due: Rs" << amountDue << endl;
        if (isPaid) {
            cout << "Payment Status: Paid" << endl;
        } else {
            cout << "Payment Status: Pending" << endl;
        }
    }

    void payBill() {
        if (isPaid) {
            cout << "The bill is already paid." << endl;
        } else {
            string paymentMethod;
            cout << "Enter payment method (Credit Card/PayPal/Other): ";
            getline(cin, paymentMethod);  // User input for payment method
            cout << "Processing payment via " << paymentMethod << "..." << endl;
            isPaid = true;
            cout << "Payment successful!" << endl;
        }
    }
};

// Derived class for Patient
class Patient : public Person {
public:
    int patientID;
    int age;
    string gender;
    string address;
    MedicalRecord* medicalRecord; // patient Has-A medical record (aggregation)
    string appointmentDate;
    string reminderMessage;
    Bill bill; // Patient Has-A Bill for online payment

    Patient(int id, const string& n, int a, const string& g, const string& addr, const string& contact)
        : Person(n, contact) {
        patientID = id;
        age = a;
        gender = g;
        address = addr;
        medicalRecord = new MedicalRecord();
    }

    void registerPatient() {
        cout << "Patient " << name << " registered successfully!" << endl;
    }

    void updateDetails(const string& n, int a, const string& g, const string& addr, const string& contact) {
        name = n;
        age = a;
        gender = g;
        address = addr;
        contactInfo = contact;
        cout << "Patient details updated for " << name << "!" << endl;
    }

    void setAppointmentDate(const string& date) {
        appointmentDate = date;
        reminderMessage = "Reminder: Your appointment will be on " + appointmentDate + ".";
    }

    void rescheduleAppointment(const string& newDate) {
        appointmentDate = newDate;
        reminderMessage = "Reminder: Your appointment has been rescheduled to " + appointmentDate + ".";
        cout << "Appointment rescheduled to " << appointmentDate << endl;
    }

    void displayReminder() {
        if (!appointmentDate.empty()) {
            cout << reminderMessage << endl;
        } else {
            cout << "No appointment set for " << name << "." << endl;
        }
    }

    void viewMedicalRecord() {
        if (medicalRecord) {
            medicalRecord->viewRecord();
        } else {
            cout << "No medical record available." << endl;
        }
    }

    void displayDetails() {
        Person::displayDetails();
        cout << "Patient ID: " << patientID << ", Age: " << age << ", Gender: " << gender << ", Address: " << address << endl;
        viewMedicalRecord();
        displayReminder();
        bill.displayBill();  // Display the bill for the patient
    }

    void generateBill(float amount) {
        bill.generateBill(amount); // Generate the bill with the given amount
    }

    void payBill() {
        bill.payBill();  // Allow the patient to pay the bill
    }
};

// Doctor class with availability functionality
class Doctor : public Person {
public:
    int doctorID;
    string specialization;
    string availableDates[5];  // A simple list of available dates
    int appointmentCount = 0;

    Doctor(int id, const string& n, const string& spec, const string& contact) : Person(n, contact) {
        doctorID = id;
        specialization = spec;
    }

    void setAvailability(const string& date) {
        for (int i = 0; i < 5; i++) {
            if (availableDates[i].empty()) {
                availableDates[i] = date;
                cout << "Doctor " << name << " is available on " << date << "." << endl;
                return;
            }
        }
        cout << "No availability for Doctor " << name << " on this date." << endl;
    }

    void viewAvailability() {
        cout << "Doctor " << name << " availability: ";
        for (int i = 0; i < 5; i++) {
            if (!availableDates[i].empty()) {
                cout << availableDates[i] << " ";
            }
        }
        cout << endl;
    }

    void assignToPatient(Patient* patient, const string& date) {
        patient->appointmentDate = date;
        cout << "Doctor " << name << " is assigned to patient " << patient->name << " on " << date << "." << endl;
    }

    void autoAssignTreatmentAndPrescription(Patient* patient) {
        string treatment, prescription;

        if (patient->medicalRecord->diagnosis == "Flu") {
            treatment = "Rest and fluids";
            prescription = "Paracetamol 500mg";
        }
        else if (patient->medicalRecord->diagnosis == "High Blood Pressure") {
            treatment = "Blood pressure management";
            prescription = "Beta blockers";
        }
        else if (patient->medicalRecord->diagnosis == "Migraine") {
            treatment = "Pain relief";
            prescription = "Ibuprofen";
        }
        else {
            treatment = "General treatment";
            prescription = "General prescription";
        }

        patient->medicalRecord->addTreatment(treatment);
        patient->medicalRecord->addPrescription(prescription);

        cout << "For diagnosis: " << patient->medicalRecord->diagnosis << endl;
        cout << "Assigned Treatment: " << treatment << endl;
        cout << "Assigned Prescription: " << prescription << endl;
    }

    void displayDetails() {
        Person::displayDetails();
        cout << "Doctor ID: " << doctorID << ", Specialization: " << specialization << endl;
    }
};

// Receptionist class
class Receptionist : public Person {
public:
    int receptionistID;

    Receptionist(int id, const string& n, const string& contact)
        : Person(n, contact), receptionistID(id) {}

    void assignDoctor(Patient* patient) {
        string diagnosis;
        cout << "Enter diagnosis for patient " << patient->name << ": ";
        getline(cin, diagnosis);

        patient->medicalRecord->addDiagnosis(diagnosis);

        if (diagnosis == "Flu") {
            cout << "Assigned to Dr. Basit (General Medicine)." << endl;
        }
        else if (diagnosis == "High Blood Pressure") {
            cout << "Assigned to Dr. Nimra (Cardiology)." << endl;
        }
        else if (diagnosis == "Migraine") {
            cout << "Assigned to Dr. Zara (Neurology)." << endl;
        }
        else {
            cout << "No doctor found for this diagnosis." << endl;
            return;
        }
    }

    void displayDetails() {
        Person::displayDetails();
        cout << "Receptionist ID: " << receptionistID << endl;
    }
};

// Main function
int main() {
    Doctor doctor1(1, "Dr. Basit", "General Medicine", "123-456-7890");
    Doctor doctor2(2, "Dr. Nimra", "Cardiology", "234-567-8901");
    Doctor doctor3(3, "Dr. Zara", "Neurology", "345-678-9012");

    doctor1.setAvailability("2025-02-15");
    doctor1.setAvailability("2025-02-16");
    doctor2.setAvailability("2025-02-15");
    doctor3.setAvailability("2025-02-16");

    Receptionist receptionist(1, "XYZ", "987-654-3210");

    Patient patient1(101, "Noor", 30, "Female", "123 St", "555-1234");
    Patient patient2(102, "Hamdan", 40, "Male", "456 St", "555-5678");
    Patient patient3(103, "Sara", 25, "Female", "789 St", "555-8765");

    // Registering patients
    patient1.registerPatient();
    patient2.registerPatient();
    patient3.registerPatient();
    cout << endl;

    // Using updateDetails to modify patient1's information
    patient1.updateDetails("Noor Fatima Abid", 31, "Female", "123 ABC St", "555-9999");
    cout << endl;

    // Assigning doctor based on the diagnosis entered by the receptionist
    receptionist.assignDoctor(&patient1);
    doctor1.assignToPatient(&patient1, "2025-02-15");
    doctor1.autoAssignTreatmentAndPrescription(&patient1);
    patient1.setAppointmentDate("2025-02-15");
    cout << endl;

    receptionist.assignDoctor(&patient2);
    doctor2.assignToPatient(&patient2, "2025-02-15");
    doctor2.autoAssignTreatmentAndPrescription(&patient2);
    patient2.setAppointmentDate("2025-02-15");
    cout << endl;

    receptionist.assignDoctor(&patient3);
    doctor3.assignToPatient(&patient3, "2025-02-16");
    doctor3.autoAssignTreatmentAndPrescription(&patient3);
    patient3.setAppointmentDate("2025-02-16");
    cout << endl;

    // Reschedule appointment for patient1
    patient1.rescheduleAppointment("2025-02-16");

    // Generate and pay bills for patients
    patient1.generateBill(1000.0);
    patient2.generateBill(1500.0);
    patient3.generateBill(20000.0);
    cout << endl;

    // Pay bills for the patients
    patient1.payBill();
    patient2.payBill();
    patient3.payBill();
    cout << endl;
    
    // Displaying appointment reminders and details
    patient1.displayDetails();
    cout << endl;
    patient2.displayDetails();
    cout << endl;
    patient3.displayDetails();

    return 0;
}
