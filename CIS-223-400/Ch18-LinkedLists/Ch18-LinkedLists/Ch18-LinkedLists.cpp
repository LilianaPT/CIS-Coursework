#include <iostream>

using namespace std;

struct Alphabets {
    char letter;
    Alphabets* link;
};

Alphabets* head = nullptr;

void AppendNodes(char c) {
    Alphabets* newLetter, * nodeptr;
    newLetter = new Alphabets;
    newLetter->letter = 'A';
    newLetter->link = nullptr;
    
    if (!head)
        head = newLetter;
    else
        nodeptr = head;
    while (nodeptr->link != nullptr) {
        nodeptr = nodeptr->link;
    }
    nodeptr->link = newLetter;
}

int main()
{
    return 0;
}
