#include "KossCoMembership.h"
#include <cctype>

//Define the static variables/constants
int KossCoMembership::memberCount = 0;
const double KossCoMembership::GOLDSTAR_FEE = 50.0;
const double KossCoMembership::EXECUTIVE_FEE = 90.0;
const double KossCoMembership::GOLDSTAR_START_POINTS = 500.0;
const double KossCoMembership::EXECUTIVE_START_POINTS = 1000.0;
const double KossCoMembership::GOLDSTAR_RATE = 1.0;
const double KossCoMembership::EXECUTIVE_RATE = 1.5;
const double KossCoMembership::POINTS_PER_DOLLAR = 100.0;

// Constructors
//Default constructor for a basic Goldstar member
KossCoMembership::KossCoMembership() {
	name = "Unknown";
	age = MIN_AGE;
	setMembershipType("Goldstar");				//sets fee and starting points
	memberCount++;
}

//Constructor with arguments
KossCoMembership::KossCoMembership(string n, int a, string type) {
	name = n;
	setAge(a);
	setMembershipType(type);					//sets fee and starting points
	memberCount++;
}

//Copy constructor: copies an existing member's record
//It does NOT add to the count because it is the same, not a new one.
KossCoMembership::KossCoMembership(const KossCoMembership& other) {
	name = other.name;
	age = other.age;
	membershipType = other.membershipType;
	fee = other.fee;
	points = other.points;
}

// Mutators
void KossCoMembership::setName(string n) {
	name = n;
}
void KossCoMembership::setAge(int a) {
	if (a >= MIN_AGE) {
		age = a;
	}
	else {
		age = MIN_AGE;				//safety net; main() validates before this
	}
}

//Sets the type, fee, and starting points balance
void KossCoMembership::setMembershipType(string type) {
	membershipType = formatType(type);

	if (membershipType == "Executive") {
		fee = EXECUTIVE_FEE;
		points = EXECUTIVE_START_POINTS;
	}
	else {
		membershipType = "Goldstar";
		fee = GOLDSTAR_FEE;
		points = GOLDSTAR_START_POINTS;
	}
}

//Accessors
string KossCoMembership::getName() const { return name; }
int KossCoMembership::getAge() const { return age; }
string KossCoMembership::getMembershipType() const { return membershipType; }
double KossCoMembership::getFee() const { return fee; }
double KossCoMembership::getPoints() const { return points; }
int KossCoMembership::getMemberCount() { return memberCount; }

//Points functions
double KossCoMembership::getRate() const {
	if (membershipType == "Executive")
		return EXECUTIVE_RATE;
	return GOLDSTAR_RATE;
}

//Every dollar spent earns points at the member's rate
void KossCoMembership::purchase(double amount) {
	if (amount > 0)
		points += amount * getRate();
}

//Returns take points away at the same rate (balance never goes below 0)
void KossCoMembership::returnItem(double amount) {
	if (amount > 0) {
		points -= amount * getRate();
		if (points < 0)
			points = 0;
	}
}

//100 points = $1.00. Balance goes back to 0 after redeeming
double KossCoMembership::redeem() {
	double dollars = points / POINTS_PER_DOLLAR;
	points = 0;
	return dollars;
}

//Helpers
//Turns "goldstar", "GOLDSTAR", etc. into "Goldstar" / "Executive"
string KossCoMembership::formatType(string type) {
	string lower = "";
	for (int i = 0; i < (int)type.length(); i++) {
		lower += tolower(type[i]);
	}
	if (lower == "goldstar")
		return "Goldstar";
	if (lower == "executive")
		return "Executive";

	return type;
}

bool KossCoMembership::isValidType(string type) {
	string t = formatType(type);
	return (t == "Goldstar" || t == "Executive");
}