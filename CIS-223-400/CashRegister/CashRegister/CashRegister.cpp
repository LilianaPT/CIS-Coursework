#include "CashRegister.h"

using namespace std;

//Default Constructor
CashRegister::CashRegister() {
	quantityPurchased = 0;
	unitPrice = 0.0;
	subtotal = 0.0;
	tax = 0.0;
	total = 0.0;
}

//Calculates financial totals and updates the InventoryItem's stock
void CashRegister::processPurchase(InventoryItem& item, int qty) {
	quantityPurchased = qty;

	//1.Calculate unit price with 30% profit markup
	unitPrice = item.getCost() * (1.0 + PROFIT_MARKUP);
	//2.Calculate subtotal
	subtotal = unitPrice * quantityPurchased;
	//3. Calculate 6% sales tax and total
	tax = subtotal * TAX_RATE;
	total = subtotal + tax;
	//4. Update the inventory stock on hand
	item.setUnits(item.getUnits() - quantityPurchased);
}