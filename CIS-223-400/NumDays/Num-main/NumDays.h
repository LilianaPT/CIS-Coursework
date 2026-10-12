#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
private:
	double hours;
	double days;

	//Helper function to update days whenever hours change
	void calculateDays();

public:
	//Constructor
	NumDays(double h = 0.0);

	//Mutator and Accessor functions
	void setHours(double h);
	double getHours() const;
	double getDays() const;

	//Overloaded Addition and Substraction operators
	NumDays operator+(const NumDays& right) const;
	NumDays operator-(const NumDays& right) const;

	//Overloaded Prefix and Postfix Increment (++ adds 1 hour)
	NumDays operator++();		//Prefix ++
	NumDays operator++(int);	//Postfix ++ (dummy int)

	//Overloaded Prefix and Postfix Decrement (-- subtract 1 hour)
	NumDays operator--();		//Prefix --
	NumDays operator--(int);	//Postfix -- (dummy int)
};

#endif // !NUMDAYS_H