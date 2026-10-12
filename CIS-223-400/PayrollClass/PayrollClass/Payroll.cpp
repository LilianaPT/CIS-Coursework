#include "Payroll.h"
#include<iomanip>

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

//Setter (Mutators)
void Payroll::setHourlyRate(double rate) { hourlyRate = rate; }
void Payroll::setHoursWorked(double hours) { hoursWorked = hours; }

//Getters (Accessors)
double Payroll::getHourlyRate() const { return hourlyRate; }
double Payroll::getHoursWorked() const { return hoursWorked; }
double Payroll::getTotalPay() const { return totalPay; }

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