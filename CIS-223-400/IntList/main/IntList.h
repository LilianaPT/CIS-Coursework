//Specification file for the IntList class

#ifndef INTLIST_H
#define INTLIST_H

class IntList {
private:
	//Declare a structure for the list
	struct ListNode {
		int value;
		struct ListNode* next;
	};

	ListNode* head;				//List head pointer

	//Destroy function
	void destroy();

public:
	//Constructor
	IntList();

	//Copy constructor
	IntList(const IntList& obj);

	//Destructor
	~IntList();

	//List operations
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void print();
	int search(int);
	void insert(int, int);
	void removeByPos(int);
};

#endif