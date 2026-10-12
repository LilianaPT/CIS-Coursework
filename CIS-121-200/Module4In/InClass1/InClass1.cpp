// InClass1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

int main()
{
	//Variable declaration
	int choice, balance = 10000;
	int deposit;

	do {
		//Display menu
		cout << "\tMenu\n";
		cout << "1. Check Balance\n" <<
			"2. Make Deposit\n" <<
			"3. Exit \n";
		cout << endl;
		cout << "Choose one option from the menu (1-3): "; //Ask the user to enter a choice
		cin >> choice; //Read the user choice

		switch (choice) {
		case 1:
			cout << "\nYour balance is " << balance << endl;
			break;
		case 2:
			cout << "Enter the amount you want to deposit: ";
			cin >> deposit;
			balance += deposit;
			break;
		case 3: 
			cout << "\nThank you! Good Bye" << endl; 
			break;
		default: cout << "\nInvalid choice, please select a valid choice from (1 - 3)." << endl;
		}
		_getch();
		system("cls"); //Cleaning the screen
	} while (choice != 3);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
