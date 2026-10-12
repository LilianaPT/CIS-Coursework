#ifndef PAYROLL_H
#define PAYROLL_H

#include<iostream>

using namespace std;

class Payroll {
private:
	double hourlyRate;
	double hoursWorked;
	double totalPay;
public:
	//Constructors
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

#endif 
