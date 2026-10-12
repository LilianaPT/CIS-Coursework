#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

// ─────────────────────────────────────────
// CLASS DECLARATION
// ─────────────────────────────────────────
class Student
{
public:
	// Constructor
	Student();				// TODO Step 3: define this below with defaults
	Student(string n, double sc1, double sc2, double sc3);
	Student(string n);

	// Set functions (mutators)
	void setName(string n);
	void setScore1(double s);
	void setScore2(double s);
	void setScore3(double s);

	// Get functions (accessors)
	string getName();
	double getScore1();
	double getScore2();
	double getScore3();

	// TODO Step 2b: add a prototype for calcAverage() returning double
	double calcAverage();
	// TODO Step 2c: add a prototype for displayInfo() returning void
	void displayInfo();

private:
	string name;		// student name
	double score1;		// test score 1
	double score2;		// test score 2
	double score3;		// test score 3
};

// ─────────────────────────────────────────
// CLIENT CODE (main)
// ─────────────────────────────────────────

int main()
{
	cout << fixed << setprecision(2) << endl;
	// TODO Step 4a: Create an object of type Student called stu1
	Student stu1;
	// TODO Step 4b: Use set functions to store the data below
	// Name: "Alex Rivera"
	// Score1: 88.5
	// Score2: 91.0
	// Score3: 76.5
	stu1.setName("Alex Rivera");
	stu1.setScore1(88.5);
	stu1.setScore2(91.0);
	stu1.setScore3(76.5);
	// TODO Step 4c: Call displayInfo() on stu1
	stu1.displayInfo();
	// TODO Step 5 (Challenge): Create a second object stu2 with YOUR OWN data
	// and display its information
	Student stu2("Mark Green", 80.5, 88, 92.5);
	stu2.displayInfo();

	//create a third object stu3
	string studentName;
	double quiz1, quiz2, quiz3;

	cout << "Enter the name: ";
	getline(cin, studentName);
	cout << "Enter three quiz scores: ";
	cin >> quiz1 >> quiz2 >> quiz3;

	Student stu3(studentName);
	stu3.setScore1(quiz1);
	stu3.setScore2(quiz2);
	stu3.setScore3(quiz3);

	stu3.displayInfo();

	return 0;
}
// ─────────────────────────────────────────
// MEMBER FUNCTION IMPLEMENTATIONS
// ─────────────────────────────────────────
// Constructor
// TODO Step 3: Implement the constructor.
// Set name to "Unknown", score1/score2/score3 to 0.0
Student::Student()					//default constructor, takes no argument
{
	name = "no name";		// 'unknown'
	score1 = 0.0;		// test score 1
	score2 = 0.0;		// test score 2
	score3 = 0.0;		// test score 3
}

//Constructor takes four arguments...
Student::Student(string n, double sc1, double sc2, double sc3) 
{		
	name = n;			
	score1 = sc1;		
	score2 = sc2;		
	score3 = sc3;	
}

Student::Student(string n)
{
	name = n;
	score1 = 0.0;
	score2 = 0.0;
	score3 = 0.0;
}
// set functions
void Student::setName(string n)
{
	name = n;
}
void Student::setScore1(double s)
{
	if(s >=0)
	score1 = s;
	else {
		cout << "Invalid.\n";
		exit(1);
	}
}
void Student::setScore2(double s)
{
	if (s >= 0)
		score2 = s;
	else {
		cout << "Invalid.\n";
		exit(1);
	}
}
void Student::setScore3(double s)
{
	if (s >= 0)
		score3 = s;
	else {
		cout << "Invalid.\n";
		exit(1);
	}
}

// get functions
string Student::getName()
{
	return name;
}
double Student::getScore1()
{
	return score1;
}
double Student::getScore2()
{
	return score2;
}
double Student::getScore3()
{
	return score3;
}
// TODO Step 2b: Implement calcAverage()
// Returns the average of score1, score2, and score3
double Student::calcAverage()
{
	return (score1 + score2 + score3) / 3.0;
}
// TODO Step 2c: Implement displayInfo()
// Prints name, all three scores, and the average
void Student::displayInfo()
{
	cout << "Student Name: " << name << endl;
	cout << "Score 1: " << score1 << endl;
	cout << "Score 2: " << score2 << endl;
	cout << "Score 3: " << score3 << endl;
	cout << "Average score: " << calcAverage() << endl;
}
