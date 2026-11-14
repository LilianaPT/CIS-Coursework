//Implementation file for the IntList class

#include <iostream>
#include "IntList.h"

using namespace std;

//Constructor starts with an empty list.
IntList::IntList() {
	head = nullptr;
}

//Copy constructor makes a new list with its own
//nodes holding the same values as obj.
IntList::IntList(const IntList& obj) {
	head = nullptr;
	ListNode* nodePtr = obj.head;

	while (nodePtr != nullptr) {
		appendNode(nodePtr->value);
		nodePtr = nodePtr->next;
	}
}

//Destructor frees every node.
IntList::~IntList() {
	destroy();
}

//destroy deletes every node in the list.
void IntList::destroy() {
	ListNode* nodePtr = head;
	ListNode* nextNode;

	while (nodePtr != nullptr) {
		nextNode = nodePtr->next;					//save the next node
		delete nodePtr;								//delete the current node
		nodePtr = nextNode;							//move forward
	}
	head = nullptr;
}

//appenNode adds a node with num to the end
void IntList::appendNode(int num) {
	ListNode* newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
	}
	else {
		ListNode* nodePtr = head;
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
}

//insertNode inserts num in sorted (ascending)
//order. Assumes the list is already sorted.
void IntList::insertNode(int num) {
	ListNode* newNode = new ListNode;
	newNode->value = num;

	ListNode* nodePtr = head;
	ListNode* previousNode = nullptr;

	//Find the first node with a value >= num
	while (nodePtr != nullptr && nodePtr->value < num) {
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
	}

	if (previousNode == nullptr) {							//goes in front
		newNode->next = head;
		head = newNode;
	}
	else {													//goes after previousNode
		previousNode->next = newNode;
		newNode->next = nodePtr;
	}
}

//deleteNode removes the first node holding num
void IntList::deleteNode(int num) {
	if (!head)
		return;

	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	if (head->value == num) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;
		while (nodePtr != nullptr && nodePtr->value != num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr) {				//found it
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//print displays every value in the list.
void IntList::print() {
	ListNode* nodePtr = head;

	if (!nodePtr) {
		cout << "(empty list)" << endl;
		return;
	}

	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

//search returns the position of num (0 = first node)
//or -1 if num is not in the list.
int IntList::search(int num) {
	ListNode* nodePtr = head;
	int pos = 0;

	while (nodePtr) {
		if (nodePtr->value == num) {
			return pos;
		}
		nodePtr = nodePtr->next;
		pos++;
	}
	return -1;
}

//insert puts num at position pos (0 = front)
//If pos is past the end, num is added at the end
void IntList::insert(int num, int pos) {
	ListNode* newNode = new ListNode;
	newNode->value = num;

	if (head == nullptr || pos <= 0) {					//goes in front
		newNode->next = head;
		head = newNode;
		return;
	}

	//Move to the node just before position pos
	ListNode* nodePtr = head;
	int count = 0;
	while (count < pos - 1 && nodePtr->next != nullptr) {
		nodePtr = nodePtr->next;
		count++;
	}

	newNode->next = nodePtr->next;
	nodePtr->next = newNode;
}

//removeByPos deletes the node at position pos
//(0 = first node). Does nothing if pos is invalid.
void IntList::removeByPos(int pos) {
	if (head == nullptr || pos < 0) {
		return;
	}

	ListNode* nodePtr;

	if (pos == 0) {							//remove the first node
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		return;
	}

	//Move to the node just before position pos
	ListNode* previousNode = head;
	int count = 0;
	while (count < pos - 1 && previousNode->next != nullptr) {
		previousNode = previousNode->next;
		count++;
	}

	nodePtr = previousNode->next;
	if (nodePtr == nullptr)					//pos is past the end
		return;

	previousNode->next = nodePtr->next;
	delete nodePtr;
}