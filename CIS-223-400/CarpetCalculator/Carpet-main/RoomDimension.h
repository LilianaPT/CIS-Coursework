#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H

#include "FeetInches.h"

class RoomDimension {
private:
	FeetInches length;	//Aggregation: obj FeetInches like attribute
	FeetInches width;	//Aggregation: obj FeetInches like attribute

public:
	RoomDimension(const FeetInches &l, const FeetInches &w) : length(l), width(w){}

	//Return the area that is calculated using multiply function
	FeetInches getArea() const {
		return length.multiply(width);
	}

	//Return the total area in feet square like decimal
	double getAreaInSquareFeet() const {
		return length.toDecimalFeet() * width.toDecimalFeet();
	}
};

#endif // !ROOMDIMENSION_H