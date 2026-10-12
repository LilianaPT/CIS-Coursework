
#include <iostream>
#include <iomanip>
#include"Patient.h"
#include"Procedure.h"

using namespace std;

int main()
{
    //Instantiate Patient object with sample data
    Patient patient("Brandon", "Adam", "Johnson",
        "123 Apple Ln", "New York", "New York", "07020",
        "123-456-7890", "Mary", "123-987-6543");

    //Instantiate three Procedure  objects with sample data
    Procedure proc1("Physical Exam", "09/29/25", "Dr. Irvine", 250.00);
    Procedure proc2("X-ray", "09/29/25", "Dr. Jamison", 500.00);
    Procedure proc3("Blood test", "09/29/25", "Dr. Smith", 200.00);

    //Display Patient Information
    cout << "Patient Info\n\n";
    cout << "First: " << patient.getFirstName() << endl;
    cout << "Middle: " << patient.getMiddleName() << endl;
    cout << "Last: " << patient.getLastName() << endl;
    cout << "Address: " << patient.getAddress() << endl;
    cout << "City: " << patient.getCity() << endl;
    cout << "State: " << patient.getState() << endl;
    cout << "ZIP Code: " << patient.getZipCode() << endl;
    cout << "Phone: " << patient.getPhoneNumber() << endl;
    cout << "Emergency Contact Name: " << patient.getEmergencyName() << endl;
    cout << "Emergency Number: " << patient.getEmergencyPhone() << "\n" << endl;

    cout << "--------------------------------------------------------------------------------------\n";

    //Format output for charges table
    cout << fixed << setprecision(2);
    //Table Header
    cout << left << setw(30) << "Procedure #1"
        << setw(30) << "Procedure #2"
        << setw(30) << "Procedure #3" << "\n";
    cout << "--------------------------------------------------------------------------------------\n";
    //Procedure Names
    cout << left << setw(30) << ("Procedure Name: " + proc1.getProcedureName())
        << setw(30) << ("Procedure Name: " + proc2.getProcedureName())
        << setw(30) << ("Procedure Name: " + proc3.getProcedureName()) << "\n";
    //Dates
    cout << left << setw(30) << ("Date: " + proc1.getProcedureDate())
        << setw(30) << ("Date: " + proc2.getProcedureDate())
        << setw(30) << ("Date: " + proc3.getProcedureDate()) << "\n";
    //Practitioners
    cout << left << setw(30) << ("Practitioner: " + proc1.getPractitionerName())
        << setw(30) << ("Practitioner: " + proc2.getPractitionerName())
        << setw(30) << ("Practitioner: " + proc3.getPractitionerName()) << "\n";
    //Charges
    cout << left << setw(30) << ("Charge: " + to_string(proc1.getCharge()).substr(0, 6))
        << setw(30) << ("Charge: " + to_string(proc2.getCharge()).substr(0, 6))
        << setw(30) << ("Charge: " + to_string(proc3.getCharge()).substr(0, 6)) << "\n";
    cout << "--------------------------------------------------------------------------------------\n";

    //Total Charges
    double totalCharges = proc1.getCharge() + proc2.getCharge() + proc3.getCharge();
    cout << "Total Charges: $" << totalCharges << "\n";

    return 0;
}


