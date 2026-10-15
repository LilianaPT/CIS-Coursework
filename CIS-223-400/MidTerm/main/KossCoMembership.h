#ifndef KOSSCOMEMBERSHIP_H
#define KOSSCOMEMBERSHIP_H

#include <string>

using namespace std;

class KossCoMembership {
private:
	string name;				//member name
	int age;					//member age (must be 21 or older)
	string membershipType;		// "Goldstar" or "Executive"
	double fee;					//yearly membership fee
	double points;				//current points balance

	static int memberCount;		//counts how many members were created

public:
	//Membership constants
	static const int MIN_AGE = 21;
	static const double GOLDSTAR_FEE;
	static const double EXECUTIVE_FEE;
	static const double GOLDSTAR_START_POINTS;
	static const double EXECUTIVE_START_POINTS;
	static const double GOLDSTAR_RATE;				//points per dollar
	static const double EXECUTIVE_RATE;				//points per dollar
	static const double POINTS_PER_DOLLAR;			//points needed for $1 when redeeming

	//Constructor
	KossCoMembership();									//no arguments
	KossCoMembership(string n, int a, string type);		//with arguments
	KossCoMembership(const KossCoMembership& other);	//copy constructor

	//Mutators
	void setName(string n);
	void setAge(int a);
	void setMembershipType(string type);

	//Accessors
	string getName() const;
	int getAge() const;
	string getMembershipType() const;
	double getFee() const;
	double getPoints() const;
	static int getMemberCount();

	//Points functions
	double getRate() const;					//1 for Goldstar, 1.5 for Executive
	void purchase(double amount);			//adds points
	void returnItem(double amount);			//substracts points
	double redeem();						//converts points to dollars, resets balance

	//Helpers
	static bool isValidType(string type);
	static string formatType(string type);
};

#endif // !KOSSCOMEMBERSHIP_H

