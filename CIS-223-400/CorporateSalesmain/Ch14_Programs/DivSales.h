#ifndef DIVSALES_H
#define DIVSALES_H

class DivSales {
private:
	double quarterSales[4];						//Array with four elements for holding sales figures
	static double totalCorporateSales;			//Private static variable for total corporate sales

public:
	//Constructor
	DivSales();

	//Member function to add sales for 4 quarters
	void addSales(double q1, double q2, double q3, double q4);

	//Member function to get sales for a specific quarter (0-3)
	double getQuarterSales(int quarter) const;

	//Static member function to retrieve total corporate sales
	static double getTotalCorporateSales();
};

#endif // !DIVSALES_H

