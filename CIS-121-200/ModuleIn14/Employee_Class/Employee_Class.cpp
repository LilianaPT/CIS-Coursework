/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 14
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/10/2026

Purpose: Manage and display organizational data using a custom Employee
Class. This program is designed to showcase the ability to create objects
with varying levels of initial data, it also utilize mutator functions
to update employee records.
********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    Employee(string n, int id, string dept, string pos);
    Employee(string n, int id);
    Employee();
    
    void setName(string n);
    void setIdNumber(int id);
    void setDepartment(string dept);
    void setPosition(string pos);
    string getName() const;
    int getIdNumber() const;
    string getDepartment() const;
    string getPosition() const;
};

//Function prototype to display employee data
void displayEmployee(const Employee& emp);

int main()
{
    //Creating the three objects using the various constructors
    //Using the first constructor
    Employee emp1("Susan Mayers", 47899, "Accounting", "Vice President");

    //Using the second argument
    Employee emp2("Mark Jones", 39119);
    emp2.setDepartment("IT");
    emp2.setPosition("Programmer");

    //Using the default third constructor
    Employee emp3;
    emp3.setName("Joy Rogers");
    emp3.setIdNumber(81774);
    emp3.setDepartment("Manufacturing");
    emp3.setPosition("Engineer");

    //Display the table header
    cout << left << setw(20) << "Name" << setw(15) << "ID Number"
        << setw(20) << "Department" << setw(20) << "Position" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    //Display each employee
    displayEmployee(emp1);
    displayEmployee(emp2);
    displayEmployee(emp3);


    return 0;
}

// Constructor that accepts name, id, department, and position.
Employee::Employee(string n, int id, string dept, string pos) {
    name = n;
    idNumber = id;
    department = dept;
    position = pos;
}

//Constructor that accepts name and id (dept and pos are empty).
Employee::Employee(string n, int id) {
    name = n;
    idNumber = id;
    department = "";
    position = "";
}

//Default constructor
Employee::Employee() {
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

//Mutators (Setters)
void Employee::setName(string n) {
    name = n;
}
void Employee::setIdNumber(int id) {
    idNumber = id;
}
void Employee::setDepartment(string dept) {
    department = dept;
}
void Employee::setPosition(string pos) {
    position = pos;
}

//Accessors (Getters)
string Employee::getName() const {
    return name;
}
int Employee::getIdNumber() const {
    return idNumber;
}
string Employee::getDepartment() const {
    return department;
}
string Employee::getPosition() const {
    return position;
}

//Helper function to keep main() clean
void displayEmployee(const Employee& emp) {
    cout << left << setw(20) << emp.getName()
        << setw(15) << emp.getIdNumber()
        << setw(20) << emp.getDepartment()
        << setw(20) << emp.getPosition() << endl;
}