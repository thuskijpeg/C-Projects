#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

struct Exhibitor {
    string name;
    string email;
    char category;
    int standNo;
    bool powerRequired;
    double feePaid;
};

// Convert category code to full word
string canonicaliseCategory(char code) {
    code = toupper(code);
    switch (code) {
        case 'R': return "Robotics";
        case 'S': return "Software";
        case 'G': return "Gaming";
        case 'E': return "Education";
        default: return "";
    }
}

// Build an Exhibitor
Exhibitor makeExhibitor(string name, string email, char category, int standNo, bool powerRequired, double feePaid) {
    Exhibitor e;
    e.name = name;
    e.email = email;
    e.category = toupper(category);
    e.standNo = standNo;
    e.powerRequired = powerRequired;
    e.feePaid = feePaid;
    return e;
}

// Print one Exhibitor
void printExhibitor(Exhibitor e) {
    cout << "Name                : " << e.name << endl;
    cout << "Email               : " << e.email << endl;
    cout << "Category            : " << e.category << " (" << canonicaliseCategory(e.category) << ")" << endl;
    cout << "Stand No            : " << e.standNo << endl;
    cout << "Power Required      : " << (e.powerRequired ? "Yes" : "No") << endl;
    cout << "Fee Paid            : R " << fixed << setprecision(2) << e.feePaid << endl;
    cout << "-----------------------------------------------" << endl;
}

// Find exhibitor by stand number
int findByStandNo(Exhibitor arr[], int numOfExhibitors, int standNo) {
    for (int i = 0; i < numOfExhibitors; i++) {
        if (arr[i].standNo == standNo) {
            return i;
        }
    }
    return -1;
}

// Calculate total revenue
double totalRevenue(Exhibitor arr[], int numOfExhibitors) {
    double total = 0;
    for (int i = 0; i < numOfExhibitors; i++) {
        total += arr[i].feePaid;
    }
    return total;
}

// Count exhibitors needing power
int countNeedingPower(Exhibitor arr[], int numOfExhibitors) {
    int count = 0;
    for (int i = 0; i < numOfExhibitors; i++) {
        if (arr[i].powerRequired) {
            count++;
        }
    }
    return count;
}

// 3. Main function
int main() {
    Exhibitor exhibitors[20];
    int num;

    // Ask how many exhibitors
    do {
        cout << "Enter number of exhibitors (1-20): ";
        cin >> num;
        if (num < 1 || num > 20) {
            cout << "Invalid number, try again." << endl;
        }
    } while (num < 1 || num > 20);

    cin.ignore(); // clear newline from input

    // Capture exhibitors
    cout << "\n-- Capture Exhibitors --\n";
    for (int i = 0; i < num; i++) {
        cout << "\nExhibitor " << (i+1) << " of " << num << endl;

        string name, email;
        char category;
        int standNo;
        char powerInput;
        bool powerRequired;
        double feePaid;

        cout << "Name: ";
        getline(cin, name);

        cout << "Email: ";
        getline(cin, email);

        // category validation
        do {
            cout << "Category code (R=Robotics, S=Software, G=Gaming, E=Education): ";
            cin >> category;
            if (canonicaliseCategory(category) == "") {
                cout << "Invalid category, try again." << endl;
            }
        } while (canonicaliseCategory(category) == "");

        // stand number validation
        do {
            cout << "Stand number (1-99, unique): ";
            cin >> standNo;
            if (standNo < 1 || standNo > 99 || findByStandNo(exhibitors, i, standNo) != -1) {
                cout << "Invalid or duplicate stand number, try again." << endl;
            }
        } while (standNo < 1 || standNo > 99 || findByStandNo(exhibitors, i, standNo) != -1);

        // power required validation
        do {
            cout << "Power required (Y/N): ";
            cin >> powerInput;
            powerInput = toupper(powerInput);
            if (powerInput != 'Y' && powerInput != 'N') {
                cout << "Invalid input, try again." << endl;
            }
        } while (powerInput != 'Y' && powerInput != 'N');
        powerRequired = (powerInput == 'Y');

        // fee validation
        do {
            cout << "Fee paid (>= 0.00): R ";
            cin >> feePaid;
            if (feePaid < 0) {
                cout << "Invalid fee, try again." << endl;
            }
        } while (feePaid < 0);

        cin.ignore(); // clear newline for next getline

        exhibitors[i] = makeExhibitor(name, email, category, standNo, powerRequired, feePaid);
    }

    // Display all exhibitors
    cout << "\n================ Exhibitor List ================\n";
    for (int i = 0; i < num; i++) {
        cout << "Exhibitor #" << (i+1) << endl;
        printExhibitor(exhibitors[i]);
    }

    // Show totals
    cout << "Total Revenue: R " << fixed << setprecision(2) << totalRevenue(exhibitors, num) << endl;
    cout << "Exhibitors needing power: " << countNeedingPower(exhibitors, num) << " of " << num << endl;

    return 0;
}
