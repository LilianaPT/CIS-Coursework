/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 14
Problem Number: 4
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/10/2026

Purpose: The purpose of this program is to manage and calculate the 
total pay for 7 employees using an object-oriented approach.
********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

class Payroll {
private: 
    double hourlyRate;
    double hoursWorked;
    double totalPay;

public:
    Payroll();
    Payroll(double rate, double hours);

    void setHourlyRate(double rate);
    void setHoursWorked(double hours);
    void calculateTotalPay();
    void input(istream& in);
    void output(ostream& out) const;

    double getHourlyRate() const;
    double getHoursWorked() const;
    double getTotalPay() const;

};

int main()
{
    const int NUM_EMPLOYEES = 7;
    Payroll employees[NUM_EMPLOYEES];

    cout << "Enter the hours worked and pay rate for 7 employees: " << endl;

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        double rate, hours;

        cout << "Employee #" << (i + 1) << " pay rate: ";
        cin >> rate;

        //Input validation for hours
        do {
            cout << "Employee #" << (i + 1) << " hours worked: ";
            cin >> hours;
            if (hours > 60) {
                cout << "Invalid input. Hours worked cannot exceed 60." << endl;
            }
        } while (hours > 60);

        //Update the object in the array
        employees[i].setHourlyRate(rate);
        employees[i].setHoursWorked(hours);
        employees[i].calculateTotalPay();
    }

    cout << "\nTotal pay: " << endl;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Employee #" << (i + 1) << ":    ";
        employees[i].output(cout);
        cout << endl;
    }

    cout << "\nPress any key to continue. . .";
    cin.ignore();
    cin.get();

    return 0;
}

//Default Constructor
Payroll::Payroll() {
    hourlyRate = 0.0;
    hoursWorked = 0.0;
    totalPay = 0.0;
}

//Constructor with arguments
Payroll::Payroll(double rate, double hours) {
    hourlyRate = rate;
    hoursWorked = hours;
    calculateTotalPay();
}

//Setters (Mutators)
void Payroll::setHourlyRate(double rate) {
    hourlyRate = rate;
}
void Payroll::setHoursWorked(double hours) {
    hoursWorked = hours;
}

//Getters (Accessors)
double Payroll::getHourlyRate() const {
    return hourlyRate;
}
double Payroll::getHoursWorked() const {
    return hoursWorked;
}
double Payroll::getTotalPay() const {
    return totalPay;
}

//Calculate total pay
void Payroll::calculateTotalPay() {
    totalPay = hourlyRate * hoursWorked;
}

//Input function with stream parameter
void Payroll::input(istream& in) {
    in >> hourlyRate >> hoursWorked;
    //Apply validation immediately after input
    if (hoursWorked > 60) {
        cout << "Warning: Hours cannot exceed 60. Setting to 60." << endl;
        hoursWorked = 60;
    }
    calculateTotalPay();
}

//Output function with stream parameter
void Payroll::output(ostream& out) const {
    out << fixed << setprecision(2) << totalPay;
}