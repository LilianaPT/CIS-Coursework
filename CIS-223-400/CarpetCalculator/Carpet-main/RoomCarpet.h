#ifndef ROOMCARPET_H
#define ROOMCARPET_H

#include "RoomDimension.h"

class RoomCarpet {
private:
	RoomDimension dimension; //Aggregation: obj RoomDimension like atribute
	double costPerSqFoot;

public:
	RoomCarpet(const RoomDimension &dim, double cost) : dimension(dim), costPerSqFoot(cost){}

	//Return the total cost times the area for the prices of square feet.
	double getTotalCost() const {
		return dimension.getAreaInSquareFeet() * costPerSqFoot;
	}
};

#endif // !ROOMCARPET_H