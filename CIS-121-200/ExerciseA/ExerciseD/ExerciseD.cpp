#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
    int quantity;                    //It holds the number of items the user entered
    double price, totalCost;        // It hold the price and total cost

    //Ask the user to enter the data
    cout << "How many items did you buy? ";
    cin >> quantity;
    cout << "Enter the item price: $";
    cin >> price;

    //Calculates total cost
    totalCost = quantity * price; 

    //This formula perform exactly the same that is displayed below about rounding into 2 decimals points.
    //If you use this formula all program will follow this format
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //This is for set up spacing and align the variables that we are looking to print
    cout << setw(15) << "Price" << setw(12) << "Quantity" << endl;
    cout << fixed << showpoint << setprecision(2) << setw(15) << price << setw(12) << quantity << endl;
    //Display the result
    cout << fixed << showpoint << setprecision(2)           //Function to round in 2 decimals the result, we can change the number to any number for decimals
        << "\nTotal cost: $" << totalCost << endl;

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
