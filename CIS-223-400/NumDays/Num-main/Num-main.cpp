#include <iostream>
#include "NumDays.h"

using namespace std;

int main() {
	//25 hours = 3.125 days; 15 hours = 1.875 days
	NumDays One(25.0);
	NumDays Two(15.0);
	NumDays Three;
	NumDays Four;

	cout << "One: " << One.getDays() << endl;
	cout << "Two: " << Two.getDays() << endl;

	//Testing overloaded + operator (25 + 15 = 40 hours = 5 days)
	Three = One + Two;
	cout << "Three: " << Three.getDays() << endl;

	//Testing Postfix ++
	Four = Three++;
	cout << "Four = Three++: " << Four.getDays() << endl;

	//Testing Prefix ++
	Four = ++Three;
	cout << "Four = ++Three: " << Four.getDays() << endl;

	//Testing Postfix --
	Four = Three--;
	cout << "Four = Three--: " << Four.getDays() << endl;

	//Testing Prefix --
	Four = --Three;
	cout << "Four = --Three: " << Four.getDays() << endl;
}