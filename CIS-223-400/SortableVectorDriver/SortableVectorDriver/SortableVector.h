#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H

#include "SimpleVector.h"

template <class T>
class SortableVector : public SimpleVector<T> {
public:
	//Default constructor
	SortableVector() : SimpleVector<T>() 
	{ }
	
	//Constructor that sets the array size
	SortableVector(int size) : SimpleVector<T>(size) 
	{ }

	//Copy Constructor
	SortableVector(const SortableVector &obj) : SimpleVector<T>(obj) 
	{ }

	//Sorts the elements in ascending order
	void sort();
};

//sort function. Uses the selection sort algorithm to
//arrange the elements in ascending order
template <class T>
void SortableVector<T>::sort() {
	int n = this->size();

	for (int start = 0; start < n - 1; start++) {
		int minIndex = start;
		T minValue = (*this)[start];

		//Find the smallest element in the unsorted part
		for (int index = start + 1; index < n; index++) {
			if ((*this)[index] < minValue) {
				minValue = (*this)[index];
				minIndex = index;
			}
		}

		//Swap it into position
		(*this)[minIndex] = (*this)[start];
		(*this)[start] = minValue;
	}
}

#endif // !SORTABLEVECTOR_H
