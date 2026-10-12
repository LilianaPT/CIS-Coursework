#ifndef PATIENT_H
#define PATIENT_H

#include<string>
using namespace std;

class Patient {
private:
	string firstName;
	string middleName;
	string lastName;
	string address;
	string city;
	string state;
	string zipCode;
	string phoneNumber;
	string emergencyName;
	string emergencyPhone;

public:
	//Constructor
	Patient();
	Patient(string fName, string mName, string lName,
		string addr, string c, string st, string zip,
		string phone, string eName, string ePhone);

	//Mutators (Setters)
	void setFirstName(const string& fName) { firstName = fName; }
	void setMiddleName(const string& mName) { middleName = mName; }
	void setLastName(const string& lName) { lastName = lName; }
	void setAddress(const string& addr) { address = addr; }
	void setCity(const string& c) { city = c; }
	void setState(const string& st) { state = st; }
	void setZipCode(const string& zip) { zipCode = zip; }
	void setPhoneNumber(const string& phone) { phoneNumber = phone; }
	void setEmergencyName(const string& eName) { emergencyName = eName; }
	void setEmergencyPhone(const string& ePhone) { emergencyPhone = ePhone; }

	//Accessors (Getters)
	string getFirstName() const { return firstName; }
	string getMiddleName() const { return middleName; }
	string getLastName() const { return lastName; }
	string getAddress() const { return address; }
	string getCity() const { return city; }
	string getState() const { return state; }
	string getZipCode() const { return zipCode; }
	string getPhoneNumber() const { return phoneNumber; }
	string getEmergencyName() const { return emergencyName; }
	string getEmergencyPhone() const { return emergencyPhone; }	
};

#endif