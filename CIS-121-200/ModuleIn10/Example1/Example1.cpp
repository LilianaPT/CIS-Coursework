// Example1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> // STEP 0: Must include this header
#include <iomanip>

using namespace std;

int main() {

	char letter;

	cout << "Enter a letter: ";
	//cin >> letter;			//>> operator skips all whitespaces
	cin.get(letter);

	cout << "You entered " << letter << endl;


	//// STEP 1: Declare the stream object
	//ifstream inFile;			//ins, input, in_stream, inStream
	//ofstream outFile;			//outs, output, out_stream

	//// STEP 2: Open — connect internal name to physical disk file
	//inFile.open("grades.txt");			//.txt .dat (we can use these two types for files) "grades.txt" should be there
	//outFile.open("results.txt");		//could be created by compiler

	//// STEP 3: Check for open error <-- NEVER skip this step!
	//if (inFile.fail()) {
	//	cout << "Error: cannot open input file.\n";
	//	//return 1;
	//	exit(1);
	//}

	//// STEP 4: Use streams (read/write)
	//int count;
	//int total;
	//int grade;

	////Initialize the variables
	//count = 0;
	//total = 0;
	//inFile >> grade;				//Priming read

	//while (!inFile.eof()) {
	//	count++;
	//	total += grade;
	//	outFile << fixed << setprecision(2) << grade << endl;
	//	inFile >> grade;
	//}
	//
	//outFile << "average = " << (double)total/count << endl;
	////STEP 5: Close the files
	//inFile.close();
	//outFile.close();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
