#ifndef FEETINCHES_H
#define FEETINCHES_H

class FeetInches {
private:
	int feet;
	int inches;
	void simplify();	//Simplify the exesive inches to feet

public:
	FeetInches(int f = 0, int i = 0) {
		feet = f;
		inches = i;
		simplify();
	}

	void setFeet(int f) { feet = f; }
	void setInches(int i) { inches = i; simplify(); }

	int getFeet() const { return feet; }
	int getInches() const { return inches; }

	//Conversion of feet and inches to a decimal value in feets
	double toDecimalFeet() const {
		return feet + (inches / 12.0);
	}

	//Multiply function
	FeetInches multiply(const FeetInches& obj) const {
		double areaSqFeet = this->toDecimalFeet() * obj.toDecimalFeet();
		int totalInches = static_cast<int>(areaSqFeet * 144.0 + 0.5);
		return FeetInches(0, totalInches);
	}
};

inline void FeetInches::simplify() {
	if (inches >= 12) {
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0) {
		feet -= (abs(inches) / 12) + 1;
		inches = 12 - (abs(inches) % 12);
	}
}

#endif // !FEETINCHES_H