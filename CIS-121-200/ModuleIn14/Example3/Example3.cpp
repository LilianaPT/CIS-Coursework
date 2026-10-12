// Example3.cpp : Study this for the final, could come a similar question.
//

#include <iostream>

using namespace std;

class Counter
{
public:
	Counter() { count = 0; } // (1)
	Counter(int start) { count = start; } // (2)
	void increment() { count++; }
	void reset() { count = 0; }
	int getCount() { return count; }
private:
	int count;
	bool isNegative() { return count < 0; } // (3)
};

int main()
{
	Counter c1; // (A)
	Counter c2(10); // (B)
	Counter group[3]; // (C)
	c2.increment();
	c2.increment();
	for (int i = 0; i < 3; i++)
		group[i].increment();
	// c1.isNegative(); // (D) commented out
	return 0;
}
