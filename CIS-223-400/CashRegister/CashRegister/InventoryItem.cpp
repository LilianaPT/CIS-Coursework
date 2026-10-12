#include "InventoryItem.h"

using namespace std;

//Default Constructor
InventoryItem::InventoryItem() {
	description = "";
	cost = 0.0;
	units = 0;
}

//Constructor with parameters
InventoryItem::InventoryItem(string desc, double c, int u) {
	description = desc;
	cost = c;
	units = u;
}