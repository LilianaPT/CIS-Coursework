#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include<string>
using namespace std;

class InventoryItem {
private:
	string description;
	double cost;
	int units;
public:
	//Constructors
	InventoryItem();
	InventoryItem(string desc, double c, int u);

	//Setters (Mutators)
	void setDescription(string d) { description = d; }
	void setCost(double c) { cost = c; }
	void setUnits(int u) { units = u; }

	//Accessors (Getters)
	string getDescription() const { return description; }
	double getCost() const { return cost; }
	int getUnits() const { return units; }
};

#endif 
