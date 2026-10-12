#ifndef PROCEDURE_H
#define PROCEDURE_H

#include<string>
using namespace std;

class Procedure {
private:
	string procedureName;
	string procedureDate;
	string practitionerName;
	double charge;

public:
	//Constructor
	Procedure();
	Procedure(string name, string date, string practitioner, double chg);

	//Mutators (Setters)
	void setProcedureName(const string& name) { procedureName = name; }
	void setProcedureDate(const string& date) { procedureDate = date; }
	void setPractitionerName(const string& practitioner) { practitionerName = practitioner; }
	void setCharge(double chg) { charge = chg; }

	//Accessors (Getters)
	string getProcedureName() const { return procedureName; }
	string getProcedureDate() const { return procedureDate; }
	string getPractitionerName() const { return practitionerName; }
	double getCharge() const { return charge; }
};

#endif 

