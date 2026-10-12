/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Assn 3
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/17/2026

Purpose: Develop a C++ application to automate the grading of 
multiple-choice exams for a class of up to 30 students. The program 
must compare student answers against a master key, calculate 
individual percentages and pass/fail statuses, and generate a 
comprehensive 'GradeReport.txt' file that includes individual results
and class-wide statistics (average, highest, and lowest scores).
********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_QUESTIONS = 20;
const int MAX_STUDENTS = 30;

void readFile(string fileName, char answers[], int size);
void compareAnswers(char correct[], char student[], int size, int missed[], int& numMissed);
void displayResults(char correct[], char student[], int missed[], int size, int numMissed);
double calcPercentage(int numMissed, int size);
void writeReport(string studentFile, char correct[], char student[], int missed[], int numMissed, int size, bool isFirst);

int main()
{
    char correctKey[NUM_QUESTIONS];
    string studentFiles[MAX_STUDENTS];
    int numStudents;
    double totalPercentage = 0;
    int highestScore = -1, lowestScore = NUM_QUESTIONS + 1, validStudentCount = 0;
    string bestStudent, worstStudent;


    readFile("CorrectAnswers.txt", correctKey, NUM_QUESTIONS);

    ifstream listFile("StudentList.txt");
    if (!listFile) {
        cout << "Error: Could not open StudentList.txt file" << endl;
        exit(1);
    }

    listFile >> numStudents;

    if (numStudents > MAX_STUDENTS) {
        cout << "Error: Student count exceeds maximum limit of 30." << endl;
        exit(1);
    }

    for (int i = 0; i < numStudents; i++) {
        listFile >> studentFiles[i];
    }
    listFile.close();

    for (int i = 0; i < numStudents; i++) {
        char studentAnswers[NUM_QUESTIONS];
        int missedQuestions[NUM_QUESTIONS];
        int numMissed = 0;

        ifstream testFile(studentFiles[i]);
        if (!testFile) {
            cout << "\nWarning: Could not open " << studentFiles[i] << ". Skipping student." << endl;
            continue;
        }
        testFile.close();

        //Grade the Student
        readFile(studentFiles[i], studentAnswers, NUM_QUESTIONS);
        compareAnswers(correctKey, studentAnswers, NUM_QUESTIONS, missedQuestions, numMissed);

        //Display to screen
        cout << "\nGrading: " << studentFiles[i] << endl;
        displayResults(correctKey, studentAnswers, missedQuestions, NUM_QUESTIONS, numMissed);

        //Write to report
        writeReport(studentFiles[i], correctKey, studentAnswers, missedQuestions, numMissed, NUM_QUESTIONS, (validStudentCount == 0));

        //Track stats
        int score = NUM_QUESTIONS - numMissed;
        double pct = calcPercentage(numMissed, NUM_QUESTIONS);
        totalPercentage += pct;
        validStudentCount++;

        if (score > highestScore) {
            highestScore = score;
            bestStudent = studentFiles[i];
        }
        if (score < lowestScore) {
            lowestScore = score;
            worstStudent = studentFiles[i];
        }
    }

    //Final Summary
    if (validStudentCount > 0) {
        double classAvg = totalPercentage / validStudentCount;

        //Display Summary on Screen
        cout << "\n=================================\n";
        cout << "CLASS GRADE REPORT\n";
        cout << "===================================\n";
        cout << fixed << setprecision(2);
        cout << "Class Average: " << classAvg << "%\n";
        cout << "Highest Score: " << highestScore << " / 20 (" << bestStudent << ")\n";
        cout << "Lowest Score: " << lowestScore << " / 20 (" << lowestScore << ")\n";
        cout << "==========================================\n";
        cout << "Grade report written to GradeReport.txt" << endl;

        //Append Summary to File
        ofstream report("GradeReport.txt", ios::app);
        report << "\n======================================\n";
        report << "CLASS GRADE REPORT\n";
        report << "=========================================\n";
        report << "Class Average: " << classAvg << "%\n";
        report << "Highest Score: " << highestScore << " / 20 (" << bestStudent << ")\n";
        report << "Lowest Score: " << lowestScore << " / 20 (" << lowestScore << ")\n";
        report << "==========================================\n";
        report.close();
    }

    return 0;
}

void readFile(string fileName, char answers[], int size) {
    ifstream file(fileName);
    if (!file) {
        cout << "Error: Could not open " << fileName << endl;
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        file >> answers[i];
    }
    file.close();
}

void compareAnswers(char correct[], char student[], int size, int missed[], int& numMissed) {
    numMissed = 0;
    for (int i = 0; i < size; i++) {
        if (student[i] != correct[i]) {
            missed[numMissed] = i - 1;
            numMissed++;
        }
    }
}

double calcPercentage(int numMissed, int size) {
    return ((double)(size - numMissed) / size) * 100.0;
}

void displayResults(char correct[], char student[], int missed[], int size, int numMissed) {
    int missedIdx;
    double pct;

    cout << "Q#  Student Answer  Correct Answer" << endl;
    cout << "--- --------------  --------------" << endl;

    missedIdx = 0;
    for (int i = 0; i < size; i++) {
        cout << setw(2) << (i + 1) << "         " << student[i];

        if (missedIdx < numMissed && missed[missedIdx] == (i + 1)) {
            cout << "       --> " << correct[i] << endl;
            missedIdx++;
        }
        else {
            cout << "             " << correct[i] << endl;
        }
    }

    pct = calcPercentage(numMissed, size);
    cout << "\nCorrect Questions: " << (size - numMissed) << " / " << size << endl;
    cout << fixed << setprecision(2) << "Percentage: " << pct << "%" << endl;
    cout << "Result: " << (pct >= 70.0 ? "PASSED" : "FAILED") << endl;

}

void writeReport(string studentFile, char correct[], char student[], int missed[], int numMissed, int size, bool isFirst) {
    ofstream report;

    if (isFirst) {
        report.open("GradeReport.txt", ios::trunc);
    }
    else {
        report.open("GradeReport.txt", ios::app);
    }

    report << "\nGrading: " << studentFile << endl;
    report << "Q#  Student Answer  Correct Answer" << endl;
    report << "--- --------------  --------------" << endl;

    int missedIdx = 0;
    for (int i = 0; i < size; i++) {
        report << setw(2) << (i + 1) << "           " << student[i];
        if (missedIdx < numMissed && missed[missedIdx] == (i + 1)) {
            report << "         --> " << correct[i] << endl;
            missedIdx++;
        }
        else {
            report << "           " << correct[i] << endl;
        }
    }

    double pct = calcPercentage(numMissed, size);
    report << "\nCorrect Questions: " << (size - numMissed) << " / " << size << endl;
    report << fixed << setprecision(2) << "Percentage: " << pct << "%" << endl;
    report << "Result: " << (pct >= 70.0 ? "PASSED" : "FAILED") << endl;
    report << "----------------------------------------" << endl;

    report.close();
}
