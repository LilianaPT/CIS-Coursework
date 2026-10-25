/*Chapter 16 - Program 3: SortableVector Class Template
Driver program that tests the SortableVector class template.*/

#include <iostream>
#include <string>
#include "SortableVector.h"

using namespace std;

//Displays every element of a SortableVector
template <class T>
void display(SortableVector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int SIZE = 6;

    //Test with int
    SortableVector<int> intTable(SIZE);
    int intValues[SIZE] = { 42, 7, 19, 3, 88, 15 };
    for (int i = 0; i < SIZE; i++)
        intTable[i] = intValues[i];

    cout << "int vector  before sorting: ";
    display(intTable);
    intTable.sort();
    cout << "int vector after sorting: ";
    display(intTable);
    cout << endl;

    //Test with double
    SortableVector<double> doubleTable(SIZE);
    double doubleValues[SIZE] = { 3.3, 1.1, 5.5, 2.2, 6.6, 4.4 };
    for (int i = 0; i < SIZE; i++)
        doubleTable[i] = doubleValues[i];

    cout << "double vector before sorting: ";
    display(doubleTable);
    doubleTable.sort();
    cout << "double vector after sorting: ";
    display(doubleTable);
    cout << endl;

    //Test with string
    SortableVector<string> stringTable(SIZE);
    string stringValues[SIZE] = { "pear", "apple", "mango",
                                  "kiwi", "banana", "cherry" };
    for (int i = 0; i < SIZE; i++)
        stringTable[i] = stringValues[i];

    cout << "string vector before sorting: ";
    display(stringTable);
    stringTable.sort();
    cout << "string vector after sorting: ";
    display(stringTable);
    cout << endl;
    
    return 0;
}
