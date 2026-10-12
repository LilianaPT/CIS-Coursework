#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include "InventoryItem.h"

using namespace std;

class CashRegister {
private:
	int quantityPurchased;
	double unitPrice;
	double subtotal;
	double tax;
	double total;

	const double PROFIT_MARKUP = 0.30; //30% profit
	const double TAX_RATE = 0.06;	   // 6% sales tax
public:
	//Constructor
	CashRegister();

	//Process Transaction
	void processPurchase(InventoryItem& item, int qty);

	//Accessors
	double getSubtotal() const { return subtotal; }
	double getTax() const { return tax; }
	double getTotal() const { return total; }
	int getQuantityPurchased()const { return quantityPurchased; }
};

#endif 
