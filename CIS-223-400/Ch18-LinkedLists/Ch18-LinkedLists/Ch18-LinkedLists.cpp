#include <iostream>

using namespace std;

struct Alphabets {
    char letter;
    Alphabets* link;
};

Alphabets* head = nullptr;

void AppendNodes(char ch) {
    Alphabets* newLetter, *nodeptr;
    newLetter = new Alphabets;
    newLetter->letter = ch;
    newLetter->link = nullptr;
    
    if (!head)
        head = newLetter;
    else {
        nodeptr = head;
        while (nodeptr->link != nullptr) {
            nodeptr = nodeptr->link;
        }
        nodeptr->link = newLetter;
    }
    
}

void deleteNode(char ch) {
    Alphabets* nptr,*prevptr;
    if (!head) {
        cout << "Empty list";
        return;
    }
    else if (head->link == ch) {
        nptr = head->next;
        delete head;
        head = nptr;
    }
    else {
        while (!nptr && nptr->letter != ch) {
            prevptr = nptr;
            nptr = nptr->link;
            nptr = nptr->link;
        }
    }
    if (!nptr) {
        prevptr->link = NULL;
        delete nptr;
    }
}

void displayLetters() {
    Alphabets* nptr;
    nptr = head;
    while (nptr->link != NULL) {
        cout << nptr->letter;
        nptr = nptr->link;
    }
}

int main()
{
    AppendNodes('A');
    AppendNodes('B');
    displayLetters();

    return 0;
}
