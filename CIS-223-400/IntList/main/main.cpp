//Driver program to demonstrate the IntList class

#include <iostream>
#include "IntList.h"

using namespace std;

int main()
{
    IntList list;

    //Append nodes
    cout << "Appending 10, 20, 30, 40:" << endl;
    list.appendNode(10);
    list.appendNode(20);
    list.appendNode(30);
    list.appendNode(40);
    list.print();

    //Insert in sorted order
    cout << "\nInserting 25 in order:" << endl;
    list.insertNode(25);
    list.print();

    //Delete by value
    cout << "\nDeleting 10:" << endl;
    list.deleteNode(10);
    list.print();

    //Search
    cout << "\nSearching for 30: ";
    int pos = list.search(30);
    if (pos != -1)
        cout << "found at position " << pos << endl;
    else
        cout << "not found" << endl;

    cout << "Searching for 99: ";
    pos = list.search(99);
    if (pos != -1)
        cout << "found at position " << pos << endl;
    else
        cout << "not found" << endl;

    //Insert at a specific position
    cout << "\nInserting 5 at position 0:" << endl;
    list.insert(5, 0);
    list.print();

    cout << "Inserting 35 at position 4:" << endl;
    list.insert(35, 4);
    list.print();

    //Copy constructor
    cout << "\nMaking a copy of the list:" << endl;
    IntList copy(list);
    cout << "Copy:      ";
    copy.print();

    //Remove from a specific position
    cout << "\nRemoving position 2 from the original:" << endl;
    list.removeByPos(2);
    cout << "Original: ";
    list.print();
    cout << "Copy:     ";
    copy.print();           //copy is unchanged

    cout << "\nThe destructor will free both lists when main ends." << endl;
    
    return 0;
}