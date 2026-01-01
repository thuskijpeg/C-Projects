#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Machine {
    string name;
    double cost;
    string orders; // 10-digit string
};

// Function prototypes
int readFromFile(Machine machines[], int maxSize);
void displayMachines(Machine machines[], int numRecords);
int calcTotalOrders(string orders);
void displaySummary(Machine machines[], int numRecords);
int writeToFile(Machine machines[], int numRecords);
void addData();
double calcTotalCost(double cost, string orders);
void displayCostReport(Machine machines[], int numRecords);
void displayMenu();

int main() {
    const int MAX_MACHINES = 50;
    Machine machines[MAX_MACHINES];
    int numRecords = 0;
    int choice = 0;

    numRecords = readFromFile(machines, MAX_MACHINES);

    while (true) {
        displayMenu();
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                displayMachines(machines, numRecords);
                break;
            case 2:
                displaySummary(machines, numRecords);
                break;
            case 3: {
                int saved = writeToFile(machines, numRecords);
                cout << saved << " items with less that 30 orders saved to low_num_orders.txt" << endl;
                break;
            }
            case 4:
                addData();
                // reload data after adding
                numRecords = readFromFile(machines, MAX_MACHINES);
                break;
            case 5:
                displayCostReport(machines, numRecords);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose 1-6." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}

// Reads file and fills array. Uses eof() as part of loop as required.
// Returns number of records read.
int readFromFile(Machine machines[], int maxSize) {
    ifstream infile;
    infile.open("orders_log.txt");
    if (!infile.is_open()) {
        cout << "Error opening orders_log.txt" << endl;
        return 0;
    }

    string line;
    int count = 0;

    // Required to use eof() as part of while loop
    while (!infile.eof()) {
        getline(infile, line);
        if (line.length() == 0) {
            // skip empty lines (this also prevents adding an empty record)
            continue;
        }

        // find commas
        size_t pos1 = line.find(',');
        size_t pos2 = string::npos;
        if (pos1 != string::npos) {
            pos2 = line.find(',', pos1 + 1);
        }

        if (pos1 == string::npos || pos2 == string::npos) {
            // bad line format, skip
            continue;
        }

        string name = line.substr(0, pos1);
        string costStr = line.substr(pos1 + 1, pos2 - (pos1 + 1));
        string orders = line.substr(pos2 + 1);

        // trim possible spaces (simple trim - remove leading/trailing spaces)
        while (name.length() > 0 && name[0] == ' ') {
            name = name.substr(1);
        }
        while (name.length() > 0 && name[name.length()-1] == ' ') {
            name = name.substr(0, name.length()-1);
        }

        try {
            double cost = stod(costStr);
            if (count < maxSize) {
                machines[count].name = name;
                machines[count].cost = cost;
                machines[count].orders = orders;
                count = count + 1;
            } else {
                // array full
                break;
            }
        } catch (...) {
            // conversion failed - skip this line
            continue;
        }
    }

    infile.close();
    return count;
}

// Display all machines neatly
void displayMachines(Machine machines[], int numRecords) {
    cout << endl;
    cout << "Name" << setw(13) << "Cost" << setw(15) << "Orders" << endl;
    cout << "---------------------------------------------" << endl;

    int i = 0;
    while (i < numRecords) {
        cout << left << setw(14) << machines[i].name;
        cout << right << fixed << setprecision(2) << setw(10) << machines[i].cost;
        cout << setw(12) << machines[i].orders << endl;
        i = i + 1;
    }
}

// Sum digits of the orders string (no range-based loops)
int calcTotalOrders(string orders) {
    int total = 0;
    int i = 0;
    while (i < (int)orders.length()) {
        char c = orders[i];
        if (c >= '0' && c <= '9') {
            int val = c - '0';
            total = total + val;
        }
        i = i + 1;
    }
    return total;
}

// Display each machine's total orders and grand total
void displaySummary(Machine machines[], int numRecords) {
    cout << endl;
    cout << "Machine" << setw(12) << "Total Orders" << endl;
    cout << "------------------------------" << endl;

    int grandTotal = 0;
    int i = 0;
    while (i < numRecords) {
        int total = calcTotalOrders(machines[i].orders);
        cout << left << setw(14) << machines[i].name;
        cout << right << setw(6) << total << endl;
        grandTotal = grandTotal + total;
        i = i + 1;
    }

    cout << endl;
    cout << "Grand Total Orders: " << grandTotal << endl;
}

// Write machines with total orders < 30 to low_num_orders.txt
// Returns number of items saved
int writeToFile(Machine machines[], int numRecords) {
    ofstream outfile;
    outfile.open("low_num_orders.txt");
    if (!outfile.is_open()) {
        cout << "Error creating low_num_orders.txt" << endl;
        return 0;
    }

    // heading
    outfile << left << setw(15) << "Name" << setw(12) << "Cost" << setw(15) << "Total Orders" << endl;
    outfile << "----------------------------------------" << endl;

    int saved = 0;
    int i = 0;
    while (i < numRecords) {
        int total = calcTotalOrders(machines[i].orders);
        if (total < 30) {
            outfile << left << setw(15) << machines[i].name;
            outfile << right << fixed << setprecision(2) << setw(10) << machines[i].cost;
            outfile << setw(15) << total << endl;
            saved = saved + 1;
        }
        i = i + 1;
    }

    outfile.close();
    return saved;
}

// Append new machine data to orders_log.txt with validation on orders string
void addData() {
    string name;
    double cost;
    string orders;

    cout << "Enter machine name: ";
    getline(cin, name);

    cout << "Enter manufacturing cost: ";
    // read cost; if invalid input, clear and keep prompting
    while (true) {
        string costLine;
        getline(cin, costLine);
        try {
            cost = stod(costLine);
            break;
        } catch (...) {
            cout << "Invalid cost. Enter manufacturing cost: ";
        }
    }

    cout << "Enter 10-digit orders string: ";
    while (true) {
        getline(cin, orders);
        // validate length
        if ((int)orders.length() != 10) {
            cout << "Invalid input. Orders string must be exactly 10 digits." << endl;
            cout << "Enter again please: ";
            continue;
        }
        // validate digits only
        bool allDigits = true;
        int i = 0;
        while (i < (int)orders.length()) {
            if (orders[i] < '0' || orders[i] > '9') {
                allDigits = false;
                break;
            }
            i = i + 1;
        }
        if (!allDigits) {
            cout << "Invalid input. Orders string must be exactly 10 digits." << endl;
            cout << "Enter again please: ";
            continue;
        }
        break;
    }

    // append to file
    ofstream outfile;
    outfile.open("orders_log.txt", ios::app);
    if (!outfile.is_open()) {
        cout << "Error opening orders_log.txt for appending." << endl;
        return;
    }

    // Format: Name,cost,orders
    outfile << name << "," << fixed << setprecision(2) << cost << "," << orders << endl;

    outfile.close();
    cout << "New data appended to orders_log.txt" << endl;
}

// Calculate total manufacturing cost for a machine
double calcTotalCost(double cost, string orders) {
    int totalOrders = calcTotalOrders(orders);
    double totalCost = totalOrders * cost;
    return totalCost;
}

// Display report with Machine, Total Orders, Cost per Item, Total Cost
void displayCostReport(Machine machines[], int numRecords) {
    cout << endl;
    cout << left << setw(12) << "Machine" << setw(15) << "Total Orders" << setw(15) << "Cost/Item" << "Total Cost" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    int i = 0;
    while (i < numRecords) {
        int totalOrders = calcTotalOrders(machines[i].orders);
        double totalCost = calcTotalCost(machines[i].cost, machines[i].orders);

        cout << left << setw(12) << machines[i].name;
        cout << right << setw(8) << totalOrders << "   ";
        cout << fixed << setprecision(2) << setw(10) << machines[i].cost << "   ";
        cout << fixed << setprecision(2) << setw(10) << totalCost << endl;

        i = i + 1;
    }
}

// Simple menu display
void displayMenu() {
    cout << "--- Factory Machine Order Tracker Menu ---" << endl;
    cout << "1. View Data" << endl;
    cout << "2. Show Summary" << endl;
    cout << "3. Save Low Orders" << endl;
    cout << "4. Add Data" << endl;
    cout << "5. Manufacturing Cost" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}
