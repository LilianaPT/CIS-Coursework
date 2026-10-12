// InventoryProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Structure to store date information
struct Date {
    int month, day, year;
};

//Structure to store inventory item records
struct Inventory {
    char itemDescription[50];
    int handQty;
    double wholesaleCost, retailCost;
    Date dateAdded;
};

//Function to validate date ranges and leap years
bool isValidDate(int m, int d, int y) {
    if (y < 2000 || y > 2100) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d>31) return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    if (m == 2) {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (isLeap && d > 29) return false;
        if (isLeap && d > 28) return false;
    }

    return true;
}
//Function to add a new inventory record to te binary file
void addRecord() {
    //Open file in binary append mode
    ofstream outFile("inventory.dat", ios::out | ios::binary | ios::app);
    if (!outFile) {
        cout << "Error opening inventory file for writing." << endl;
        return;
    }

    Inventory item;
    cin.ignore(); //Clear newline buffer

    cout << "\nEnter Item Description: ";
    cin.getline(item.itemDescription, 50);

    //Input validation for quantity (must be >= 0)
    do {
        cout << "Enter Quantity on Hand: ";
        cin >> item.handQty;
        if (item.handQty < 0) cout << "Quantity cannot be less than 0\n";
    } while (item.handQty < 0);
    //Input validation for wholesale cost and retail cost (must be >= 0)
    do {
        cout << "Enter Wholesale Cost: ";
        cin >> item.wholesaleCost;
        if (item.wholesaleCost < 0) cout << "Wholesale cost cannot be negative\n";
    } while (item.wholesaleCost < 0);

    do {
        cout << "Enter Retail Cost: ";
        cin >> item.retailCost;
        if (item.retailCost < 0) cout << "Retail cost cannot be negative\n";
    } while (item.retailCost < 0);

    //Input validation for date added
    do {
        cout << "Enter Date Added ( MM DD YYYY): ";
        cin >> item.dateAdded.month >> item.dateAdded.day >> item.dateAdded.year;
        if (!isValidDate(item.dateAdded.month, item.dateAdded.day, item.dateAdded.year)) {
            cout << "Invalid date. Please enter a valid date (Year 2000-2100).\n";
        }
    } while (!isValidDate(item.dateAdded.month, item.dateAdded.day, item.dateAdded.year));

    //Write structure to binary file and close
    outFile.write(reinterpret_cast<char*>(&item), sizeof(Inventory));
    outFile.close();
    cout << "Record added successfully.\n";
}

//Function to display a specific record from the binary file
void displayRecord() {
    ifstream inFile("inventory.dat", ios::in | ios::binary);
    if (!inFile) {
        cout << "No inventory file was found or error opening file\n";
        return;
    }
    //Determine total number of records stored in the file
    inFile.seekg(0, ios::end);
    long numBytes = inFile.tellg();
    long numRecords = numBytes / sizeof(Inventory);

    if (numRecords == 0) {
        cout << "The inventory file is empty\n";
        inFile.close();
        return;
    }

    cout << "\nThere are " << numRecords << " record(s) in the file" << endl;
    long recordNum;
    cout << "Enter record number to display (1 to " << numRecords << "): ";
    cin >> recordNum;

    if (recordNum < 1 || recordNum > numRecords) {
        cout << "Invalid record number." << endl;
        inFile.close();
        return;
    }

    Inventory item;
    //Move get pointer to the requested record position and read it
    inFile.seekg((recordNum - 1) * sizeof(Inventory), ios::beg);
    inFile.read(reinterpret_cast<char*>(&item), sizeof(Inventory));
    inFile.close();

    //Format output with 2 decimal places for currency.
    cout << fixed << setprecision(2);
    cout << "\n--- Record #" << recordNum << " ---\n";
    cout << "Description:    " << item.itemDescription << "\n";
    cout << "Quantity:       " << item.handQty << "\n";
    cout << "Wholesale Cost: $" << item.wholesaleCost << "\n";
    cout << "Retail Cost:    $" << item.retailCost << "\n";
    cout << "Date Added:     " << item.dateAdded.month << "/" << item.dateAdded.day << "/" << item.dateAdded.year << endl;
}

//Function to modify an existing record in the binary file
void changeRecord() {
    fstream file("inventory.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "No inventory file found or error opening file" << endl;
        return;
    }

    //Determine total records
    file.seekg(0, ios::end);
    long numBytes = file.tellg();
    long numRecords = numBytes / sizeof(Inventory);

    if (numRecords == 0) {
        cout << "The inventory file is empty" << endl;
        file.close();
        return;
    }

    cout << "\nThere are " << numRecords << " record(s) in the file" << endl;
    long recordNum;
    cout << "Enter record number to modify (1 to " << numRecords << "): ";
    cin >> recordNum;

    if (recordNum < 1 || recordNum > numRecords) {
        cout << "Invalid record number.\n";
        file.close();
        return;
    }

    Inventory item;
    //Read the current record
    file.seekg((recordNum - 1) * sizeof(Inventory), ios::beg);
    file.read(reinterpret_cast<char*>(&item), sizeof(Inventory));

    //Show current data
    cout << "\nCurrent data for Record #" << recordNum << ":" << endl;
    cout << "1. Description:     " << item.itemDescription << endl;
    cout << "2. Quantity:        " << item.handQty << endl;
    cout << "3. Wholesale Cost: $" << item.wholesaleCost << endl;
    cout << "4. Retail Cost:    $" << item.retailCost << endl;
    cout << "5. Date Added:      " << item.dateAdded.month << "/" << item.dateAdded.day << "/" << item.dateAdded.year << endl;

    cin.ignore();
    cout << "\nEnter new Item Description: ";
    cin.getline(item.itemDescription, 50);

    do {
        cout << "Enter new Quantity on Hand: ";
        cin >> item.handQty;
        if (item.handQty < 0) cout << "Quantity cannot be less than 0" << endl;
    } while (item.handQty < 0);

    do {
        cout << "Enter new Wholesale Cost: ";
        cin >> item.wholesaleCost;
        if (item.wholesaleCost < 0) cout << "Wholesale cost cannot be negative" << endl;
    } while (item.wholesaleCost < 0);

    do {
        cout << "Enter new Retail Cost: ";
        cin >> item.retailCost;
        if (item.retailCost < 0) cout << "Retail cost cannot be negative" << endl;
    } while (item.retailCost < 0);

    do {
        cout << "Enter new Date Added (MM DD YYYY): ";
        cin >> item.dateAdded.month >> item.dateAdded.day >> item.dateAdded.year;
        if (!isValidDate(item.dateAdded.month, item.dateAdded.day, item.dateAdded.year)) {
            cout << "Invalid date. Please enter a valid date (Year 2000-2100)." << endl;
        }
    } while (!isValidDate(item.dateAdded.month, item.dateAdded.day, item.dateAdded.year));

    //Move write pointer back to the exact record position and overwrite it
    file.seekp((recordNum - 1) * sizeof(Inventory), ios::beg);
    file.write(reinterpret_cast<char*>(&item), sizeof(Inventory));
    file.close();
    cout << "Record updated successfully." << endl;
}

int main()
{
    int choice;
    //Main menu loop for the inventory program
    do {
        cout << "\n=== INVENTORY PROGRAM MENU ===\n";
        cout << "1. Add new records to the file\n";
        cout << "2. Display any record in the file\n";
        cout << "3. Change any record in the file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        //Input validation for menu choices
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Enter a number betwee 1 ad 4: ";
            cin >> choice;
        }

        //Execute actions based on user selection
        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecord();
            break;
        case 3:
            changeRecord();
            break;
        case 4:
            cout << "Exiting program\n";
            break;
        }

    } while (choice != 4);
    
    return 0;
}
