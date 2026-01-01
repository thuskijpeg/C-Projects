#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_TESTS = 5;

struct Student {
    string studentName;
    string studentID;
    int testResults[5];
};

// Function prototypes
int loadStudentInfo(Student students[], int maxStudents);
double calculateAverage(Student s);
void viewStudentInfo(Student students[], int numStudents);
void deleteStudentInfo(Student students[], int &numStudents);
void editStudentInfo(Student students[], int numStudents);
void savePass(Student students[], int numStudents);

int main() {
    const int MAX = 20;
    Student students[MAX];
    int numStudents = 0;
    int choice;

    // Step 1: Load data from file
    // Uncomment after writing loadStudentInfo()
    numStudents = loadStudentInfo(students, MAX);

    do {
        cout << "\n=== Student Academic Performance Tracker ===\n";
        cout << "1. View Student Info\n";
        cout << "2. Delete Student Info\n";
        cout << "3. Edit Student Info\n";
        cout << "4. Save Students Who Passed\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewStudentInfo(students, numStudents);
            break;
        case 2:
            //deleteStudentInfo(students, numStudents);
            break;
        case 3:
            //editStudentInfo(students, numStudents);
            break;
        case 4:
            //savePass(students, numStudents);
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

int loadStudentInfo(Student students[], int maxStudents)
{
    ifstream inFile("studentInfo.txt", ios::in);

    if (inFile.fail())
    {
        cerr << "There was an error opening the file" << endl;
    }

    const int SIZE = 10;

    string marks[SIZE];
    int counter = 0;

    while (getline(inFile, students[counter].studentName, ';'))
    {
        getline(inFile, students[counter].studentID, ';');


        for (int i = 0; i < NUM_TESTS; i++)
        {
            inFile >> students[counter].testResults[i];
        }

        counter++;
    }

    return counter;

}

double calculateAverage(Student s)
{
    double total;
    double average;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        total += s.testResults[i];
    }

    average = total / NUM_TESTS;

    return average;
}

void viewStudentInfo(Student students[], int numStudents)
{
    cout << left << setw(5) << "No." << "  " << setw(10) << "Name" << "          " << setw(12) << "Test Scores" << "    " << right << setw(10) << "Average" << endl;
    cout << "-----------------------------------------------------" << endl;
    string results;
    int counter = 0;
    int mark1;
    int mark2;
    int mark3;
    int mark4;
    int mark5;
    string mark1Str;
    string mark2Str;
    string mark3Str;
    string mark4Str;
    string mark5Str;
    double average;


    for (int i = 0; i < numStudents; i++)
    {
        average = calculateAverage(students[i]);

        while(counter < NUM_TESTS)
        {
            mark1 = students[i].testResults[counter];
            counter++;

            mark2 = students[i].testResults[counter];
            counter++;

            mark3 = students[i].testResults[counter];
            counter++;

            mark4 = students[i].testResults[counter];
            counter++;

            mark5 = students[i].testResults[counter];
            counter++;


        }

        mark1Str = to_string(mark1);
        mark2Str = to_string(mark2);
        mark3Str = to_string(mark3);
        mark4Str = to_string(mark4);
        mark5Str = to_string(mark5);

        results = mark1Str + " " + mark2Str + " " + mark3Str + " " + mark4Str + " " + mark5Str;

        cout << left << setw(5) << i + 1 << "  " << setw(10) << students[i].studentName << "          " << setw(12) << results << "    " << right << setw(10) << average << endl;

    }

}



