
#include <iostream>
#include"Payroll.h"
#include<iomanip>

using namespace std;

int main()
{
    const int NUM_EMPLOYEES = 7;
    Payroll employees[NUM_EMPLOYEES];

    cout << "Enter the hours worked and pay rate for 7 employees: " << endl;
    cout << endl;

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        double rate, hours;
        
        cout << "Employee " << (i + 1) << ": " << endl;
        cout << "Enter hourly rate ($/hr): ";
        cin >> rate;

        //Input validation for hours
        do {
            cout << "Enter hours worked (0-60): ";
            cin >> hours;
            if (hours > 60) {
                cout << "Invalid input. Hours worked cannot exceed 60." << endl;
            }
        } while (hours > 60);

        cout << endl;
        //Update the object in the array
        employees[i].setHourlyRate(rate);
        employees[i].setHoursWorked(hours);
        employees[i].calculateTotalPay();
    }

    //Accumalative variable for the total week
    double totalWeek = 0.0;

    //Display table of the seven employees
    cout << "--- Gross Pay Summary ---";
    cout << fixed << setprecision(2) << endl;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Employee " << (i + 1) << " | "
            << " Rate: $" << employees[i].getHourlyRate() << " | "
            << " Hours: " << static_cast<int>(employees[i].getHoursWorked()) << " | "
            << "Gross: $"; 
        employees[i].output(cout);
        cout << endl;

        totalWeek += employees[i].getTotalPay();
    }

    cout << "Total payroll for week: $" << totalWeek << endl;
    cout << "\nPress any key to continue. . .";
    cin.ignore();
    cin.get();

    return 0;
}

