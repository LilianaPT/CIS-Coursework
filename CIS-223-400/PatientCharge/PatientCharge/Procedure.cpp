#include "Procedure.h"

using namespace std;

//Procedure Default Constructor
Procedure::Procedure() {
	procedureName = "";
	procedureDate = "";
	practitionerName = "";
	charge = 0.0;
}

//Procedure with parameters Constructor
Procedure::Procedure(string name, string date, string practitioner, double chg) {
	procedureName = name;
	procedureDate = date;
	practitionerName = practitioner;
	charge = chg;
}