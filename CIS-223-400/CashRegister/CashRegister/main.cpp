
#include <iostream>
#include<iomanip>
#include"InventoryItem.h"
#include"CashRegister.h"

using namespace std;

int main()
{
	const int NUM_ITEMS = 2;

	//Inventory setup
	InventoryItem items[NUM_ITEMS] = {
		InventoryItem("Widget", 10.0,100),
		InventoryItem("Gadget", 15.5, 50)
	};

	//Display available inventory
	cout << "Available inventory:\n";
	for (int i = 0; i < NUM_ITEMS; i++) {
		cout << (i + 1) << items[i].getDescription() << " ($" << items[i].getCost() << "), Stock: " << items[i].getUnits() << endl;
	}

	cout << endl;

	int choice, quantity;
	cout << "Select an item to purchase (1 or 2): ";
	cin >> choice;

	cout << "Enter quantity: ";
	cin >> quantity;

	//Poiner to selected inventory item
	InventoryItem* selectedItem = nullptr;
	if (choice == 1) {
		//selectedItem = &item1;
		selectedItem = &items[0];
	}
	else if (choice == 2) {
		//selectedItem = &item2;
		selectedItem = &items[1];
	}
	else {
		cout << "Invalid choice.\n";
		return 1;
	}

	//Process purchase with CashRegister
	CashRegister reg;
	reg.processPurchase(*selectedItem, quantity);

	//Output formatted
	cout << "Item: " << selectedItem->getDescription() << endl;
	cout << "Quantity: " << reg.getQuantityPurchased() << endl;
	cout << "Subtotal: $" << reg.getSubtotal() << endl;
	cout << "Tax: $" << reg.getTax() << endl;
	cout << "Total: $" << reg.getTotal() << endl;
	cout << endl;

	//Display updated stock
	cout << "Updated inventory:\n";
	cout << selectedItem->getDescription() << " Stock: " << selectedItem->getUnits() << endl;
}
