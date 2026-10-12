#include "NumDays.h"

//Private helper to automatically recalculate days (8 hours = 1 day)
void NumDays::calculateDays() {
	days = hours / 8.0;
}

//Constructor
NumDays::NumDays(double h) {
	hours = h;
	calculateDays();
}

//Mutator for hours
void NumDays::setHours(double h) {
	hours = h;
	calculateDays();
}

//Accessor for hours
double NumDays::getHours() const {
	return hours;
}

//Accessor for days
double NumDays::getDays() const {
	return days;
}

//Overloaded + operator
NumDays NumDays::operator+(const NumDays& right) const {
	return NumDays(hours + right.hours);
}

//Overloaded - operator
NumDays NumDays::operator-(const NumDays& right) const {
	return NumDays(hours - right.hours);
}

//Overloaded Prefix ++ operator (++obj)
NumDays NumDays::operator++() {
	++hours;
	calculateDays();
	return *this;
}

//Overloaded Postfix ++ operator (obj++)
NumDays NumDays::operator++(int) {
	NumDays temp(hours);				//Save current state
	hours++;
	calculateDays();
	return temp;						//Return state prior to increment
}

//Overloaded Prefix -- operator (--obj)
NumDays NumDays::operator--() {
	--hours;
	calculateDays();
	return *this;
}

//Overloaded Postfix -- operator (obj--)
NumDays NumDays::operator--(int) {
	NumDays temp(hours);				//Save current state
	hours--;
	calculateDays();
	return temp;						//Return state prior to decrement
}