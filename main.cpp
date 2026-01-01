#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_STUDENTS = 100;

int main() {
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS];
    int numStudents;

    // Input number of students with validation
    cout << "How many students do you want to input (max 100)? ";
    cin >> numStudents;
    while (numStudents < 1 || numStudents > MAX_STUDENTS) {
        cout << "Invalid number! Enter between 1 and 100: ";
        cin >> numStudents;
    }

    // Input names and scores
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << (i + 1) << " name: ";
        cin >> names[i];
        cout << "Score for " << names[i] << ": ";
        cin >> scores[i];
    }

    // Randomize students order
    srand(time(0));
    for (int i = 0; i < numStudents; i++) {
        int r = rand() % numStudents;
        swap(names[i], names[r]);
        swap(scores[i], scores[r]);
    }

    int choice;
    do {
        // Menu
        cout << "\n====== Menu ======\n";
        cout << "1. Display Students and Scores\n";
        cout << "2. Find Top Scorer\n";
        cout << "3. Swap Student Positions\n";
        cout << "4. Award Bonus Points to Specific Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Display students
            for (int i = 0; i < numStudents; i++) {
                cout << setw(2) << (i + 1) << ". "
                     << setw(10) << names[i]
                     << " - " << scores[i] << " points\n";
            }
        }
        else if (choice == 2) {
            // Find top scorer
            int highest = scores[0];
            for (int i = 1; i < numStudents; i++) {
                if (scores[i] > highest) {
                    highest = scores[i];
                }
            }

            int count = 0;
            for (int i = 0; i < numStudents; i++) {
                if (scores[i] == highest) count++;
            }

            if (count == 1) {
                for (int i = 0; i < numStudents; i++) {
                    if (scores[i] == highest) {
                        cout << "Top scorer is " << names[i]
                             << " with " << scores[i] << " points.\n";
                    }
                }
            } else {
                cout << "There is a tie! " << count << " students have "
                     << highest << " points:\n";
                for (int i = 0; i < numStudents; i++) {
                    if (scores[i] == highest) {
                        cout << " - " << names[i] << "\n";
                    }
                }

                int selected = -1;
                while (true) {
                    int r = rand() % numStudents;
                    if (scores[r] == highest) {
                        selected = r;
                        break;
                    }
                }
                cout << "\nRandomly selected student for a bonus question: "
                     << names[selected] << endl;

                char ans;
                cout << "Did " << names[selected] << " answer correctly? (y/n): ";
                cin >> ans;
                if (ans == 'y' || ans == 'Y') {
                    scores[selected] += 10;
                    cout << "Correct! 10 points awarded. New score for "
                         << names[selected] << ": " << scores[selected] << " points.\n";
                } else {
                    cout << "Incorrect. No bonus awarded.\n";
                }
            }
        }
        else if (choice == 3) {
            // Swap positions
            int pos1, pos2;
            cout << "Current Student List:\n";
            for (int i = 0; i < numStudents; i++) {
                cout << (i + 1) << ". " << setw(10) << names[i]
                     << " - " << scores[i] << " points\n";
            }
            cout << "Enter the number of the FIRST student to swap (1 to " << numStudents << "): ";
            cin >> pos1;
            cout << "Enter the number of the SECOND student to swap (1 to " << numStudents << "): ";
            cin >> pos2;

            if (pos1 >= 1 && pos1 <= numStudents && pos2 >= 1 && pos2 <= numStudents) {
                swap(names[pos1 - 1], names[pos2 - 1]);
                swap(scores[pos1 - 1], scores[pos2 - 1]);
                cout << "Swap successful! Updated Student List:\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << (i + 1) << ". " << setw(10) << names[i]
                         << " - " << scores[i] << " points\n";
                }
            } else {
                cout << "Invalid input\n";
            }
        }
        else if (choice == 4) {
            // Award bonus
            string searchName;
            cout << "Enter the student name to award bonus: ";
            cin >> searchName;

            bool found = false;
            for (int i = 0; i < numStudents; i++) {
                if (names[i] == searchName) {
                    int bonus;
                    cout << "Enter bonus points for " << names[i] << ": ";
                    cin >> bonus;
                    scores[i] += bonus;
                    cout << "Bonus awarded to " << names[i]
                         << ". New score: " << scores[i] << " points.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found. Please make sure you typed the correct name.\n";
            }
        }
        else if (choice == 5) {
            cout << "Exiting program. Goodbye!\n";
        }
        else {
            cout << "Please select between 1-5\n";
        }

    } while (choice != 5);

    return 0;
}
