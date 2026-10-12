// Monthly-Budget.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

struct MonthlyBudget {
	double housing, utilities,
		householdExpenses, transportation,
		food, medical, insurance, entertainment,
		clothing, miscellaneous;
};

//Function where the user input the actual amount spents.
void getMonthlyInfo(MonthlyBudget &spent) {
	cout << "Enter the amount spent for housing: ";
	cin >> spent.housing;
	cout << "Enter the amount spent for utilities: ";
	cin >> spent.utilities;
	cout << "Enter the amount spent for household expenses: ";
	cin >> spent.householdExpenses;
	cout << "Enter the amount spent for transportation: ";
	cin >> spent.transportation;
	cout << "Enter the medical expenses: ";
	cin >> spent.medical;
	cout << "Enter the amount spent for insurance: ";
	cin >> spent.insurance;
	cout << "Enter the amount spent for entertainment: ";
	cin >> spent.entertainment;
	cout << "Enter the amount spent for clothing: ";
	cin >> spent.clothing;
	cout << "Enter the miscellaneous expenses: ";
	cin >> spent.miscellaneous;
}

//Function where display the table and the information from budget and amount spent.
void displayReport(const MonthlyBudget& budget, const MonthlyBudget& spent) {
	cout << left << setw(18) << "Category"
		<< right << setw(10) << "Budgeted" << setw(10)
		<< "Spent" << setw(14) << "Over(-)/Under" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << left << setw(18) << "Housing" << right << setw(10) << fixed 
		<< setprecision(2) << budget.housing << setw(10) << spent.housing << setw(14) 
		<< (budget.housing - spent.housing) << endl;
	cout << left << setw(18) << "Utilities" << right << setw(10) << fixed
		<< setprecision(2) << budget.utilities << setw(10) << spent.utilities << setw(14)
		<< (budget.utilities - spent.utilities) << endl;
	cout << left << setw(18) << "Household" << right << setw(10) << fixed
		<< setprecision(2) << budget.householdExpenses << setw(10) << spent.householdExpenses << setw(14)
		<< (budget.householdExpenses - spent.householdExpenses) << endl;
	cout << left << setw(18) << "Transportation" << right << setw(10) << fixed
		<< setprecision(2) << budget.transportation << setw(10) << spent.transportation << setw(14)
		<< (budget.transportation - spent.transportation) << endl;
	cout << left << setw(18) << "Medical" << right << setw(10) << fixed
		<< setprecision(2) << budget.medical << setw(10) << spent.medical << setw(14)
		<< (budget.medical - spent.medical) << endl;
	cout << left << setw(18) << "Insurance" << right << setw(10) << fixed
		<< setprecision(2) << budget.insurance << setw(10) << spent.insurance << setw(14)
		<< (budget.insurance - spent.insurance) << endl;
	cout << left << setw(18) << "Entertainment" << right << setw(10) << fixed
		<< setprecision(2) << budget.entertainment << setw(10) << spent.entertainment << setw(14)
		<< (budget.entertainment - spent.entertainment) << endl;
	cout << left << setw(18) << "Clothing" << right << setw(10) << fixed
		<< setprecision(2) << budget.clothing << setw(10) << spent.clothing << setw(14)
		<< (budget.clothing - spent.clothing) << endl;
	cout << left << setw(18) << "Miscellaneous" << right << setw(10) << fixed
		<< setprecision(2) << budget.miscellaneous << setw(10) << spent.miscellaneous << setw(14)
		<< (budget.miscellaneous - spent.miscellaneous) << endl;

	//Calculation of totals
	double totalBudget = budget.housing + budget.utilities + budget.householdExpenses +
		budget.transportation + budget.medical + budget.insurance + budget.entertainment +
		budget.clothing + budget.miscellaneous;

	double totalSpent = spent.housing + spent.utilities + spent.householdExpenses +
		spent.transportation + spent.medical + spent.insurance + spent.entertainment +
		spent.clothing + spent.miscellaneous;

	double totalDifference = totalBudget - totalSpent;

	if (totalDifference < 0) {
		cout << "For the month you are over budget by $" << fixed << setprecision(2) << totalDifference << endl;
	}
	else {
		cout << "For the month you are under budget by $" << fixed << setprecision(2) << totalDifference << endl;
	}
}

int main()
{
   //Monthly budget defined
	MonthlyBudget budget = {
		500.00,
		150.00,
		65.00,
		50.00,
		250.00,
		30.00,
		100.00,
		150.00,
		75.00,
		50.00
	};

	MonthlyBudget spent;

	//Calling the first function
	getMonthlyInfo(spent);
	cout << endl;

	//Calling the second function
	displayReport(budget, spent);

	return 0;
}

