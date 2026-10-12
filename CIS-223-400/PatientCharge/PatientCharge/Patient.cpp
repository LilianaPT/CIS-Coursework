#include "Patient.h"

using namespace std;

//Patient Default Constructor
Patient::Patient() {
	firstName = "";
	middleName = "";
	lastName = "";
	address = "";
	city = "";
	state = "";
	zipCode = "";
	phoneNumber = "";
	emergencyName = "";
	emergencyPhone = "";
}

//Patient with parameters Constructor
Patient::Patient(string fName, string mName, string lName,
	string addr, string c, string st, string zip, string phone,
	string eName, string ePhone) {
	firstName = fName;
	middleName = mName;
	lastName = lName;
	address = addr;
	city = c;
	state = st;
	zipCode = zip;
	phoneNumber = phone;
	emergencyName = eName;
	emergencyPhone = ePhone;
}