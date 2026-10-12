#include "DivSales.h"

//Definition of the static member variable outside the class
double DivSales::totalCorporateSales = 0.0;

//Default Constructor
DivSales::DivSales() {
	for (int i = 0; i < 4; i++) {
		quarterSales[i] = 0.0;
	}
}

//Function to set sales and add to static corporate total
void DivSales::addSales(double q1, double q2, double q3, double q4) {
	quarterSales[0] = q1;
	quarterSales[1] = q2;
	quarterSales[2] = q3;
	quarterSales[3] = q4;

	//Add total of the four arguments to static variable
	totalCorporateSales += (q1 + q2 + q3 + q4);
}

//Function to return sales for a specific quarter (subscript 0 to 3)
double DivSales::getQuarterSales(int quarter) const {
	if (quarter >= 0 && quarter < 4) {
		return quarterSales[quarter];
	}
	return 0.0;
}

//Static member function returning total corporate sales
double DivSales::getTotalCorporateSales() {
	return totalCorporateSales;
}