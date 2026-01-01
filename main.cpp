#include <iostream>
#include <iomanip>   // for setw, setprecision
#include <string>
using namespace std;

// Function prototypes
void displayData(string* monthsPtr, double* salesPtr, int &size);
double calculateTotal(double* salesPtr, int &size);
double calculateAverage(double* salesPtr, int &size);
int countAboveThreshold(string* monthsPtr, double* salesPtr, int &size, double threshold);
string searchRevenue(string* monthsPtr, double* salesPtr, int &size, double target);
void sortSales(string* monthsPtr, double* salesPtr, int &size);

int main()
{
    // 1) Declare arrays and initialize them
    const int SIZE = 12;
    int size = SIZE;

    double sales[SIZE] = {
        12000.50, 15890.75, 13500.20, 14200.00,
        19200.60, 10500.20, 14800.00, 13900.75,
        16750.80, 15400.60, 14500.30, 17800.25
    };

    string months[SIZE] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    // Pointers to the arrays
    double* salesPtr = sales;
    string* monthsPtr = months;

    // Display original data
    cout << "Original Sales Data:\n";
    displayData(monthsPtr, salesPtr, size);
    cout << endl;

    // Calculate and display average monthly sales
    double avg = calculateAverage(salesPtr, size);
    cout << "Average Monthly Sales: " << fixed << setprecision(2) << avg << "\n\n";

    // Ask user for a threshold, then show months above it
    cout << "Enter a threshold sales revenue: ";
    double threshold;
    cin >> threshold;
    cout << endl;

    int aboveCount = countAboveThreshold(monthsPtr, salesPtr, size, threshold);
    cout << "\nNumber of months with sales above " << fixed << setprecision(2)
         << threshold << ": " << aboveCount << "\n\n";

    // Ask user for a target revenue to search
    cout << "Enter a target sales revenue: ";
    double target;
    cin >> target;
    cout << endl;

    string foundMonth = searchRevenue(monthsPtr, salesPtr, size, target);
    if (foundMonth != "Not found") {
        cout << "Revenue " << fixed << setprecision(2) << target << " found in " << foundMonth << "\n\n";
    } else {
        cout << "Revenue " << fixed << setprecision(2) << target << " not found\n\n";
    }

    // Sort arrays by sales (ascending) and keep months aligned
    sortSales(monthsPtr, salesPtr, size);

    // Display sorted data
    cout << "Sorted Sales Data (by Revenue):\n";
    displayData(monthsPtr, salesPtr, size);
    cout << endl;

    return 0;
}

// Display month names and sales neatly
void displayData(string* monthsPtr, double* salesPtr, int &size)
{
    cout << left << setw(15) << "Month" << right << setw(18) << "Sales Revenue (R.c)" << "\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << *(monthsPtr + i)   // month name
             << right << setw(12) << fixed << setprecision(2) << *(salesPtr + i) << "\n";
    }
}

// Calculate the total sales
double calculateTotal(double* salesPtr, int &size)
{
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += *(salesPtr + i); // pointer arithmetic
    }
    return total;
}

// Calculate the average sales
double calculateAverage(double* salesPtr, int &size)
{
    double total = calculateTotal(salesPtr, size);
    return total / size;
}

// Count months with sales above threshold and display them
int countAboveThreshold(string* monthsPtr, double* salesPtr, int &size, double threshold)
{
    int count = 0;

    cout << "Months with sales above " << fixed << setprecision(2) << threshold << ":\n";
    cout << left << setw(15) << "Month" << right << setw(15) << "Sales Revenue" << "\n";

    for (int i = 0; i < size; i++) {
        if (*(salesPtr + i) > threshold) {
            cout << left << setw(15) << *(monthsPtr + i)
                 << right << setw(12) << fixed << setprecision(2) << *(salesPtr + i) << "\n";
            count++;
        }
    }

    return count;
}

// Search for exact revenue using pointer arithmetic
string searchRevenue(string* monthsPtr, double* salesPtr, int &size, double target)
{
    for (int i = 0; i < size; i++) {
        // pointer arithmetic used in condition
        if (*(salesPtr + i) == target) {
            return *(monthsPtr + i);  // return the matching month
        }
    }
    return "Not found";
}

// Sort sales (ascending) and keep months aligned
void sortSales(string* monthsPtr, double* salesPtr, int &size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            // compare with pointer arithmetic
            if (*(salesPtr + i) > *(salesPtr + j)) {
                // swap sales
                double tempSale = *(salesPtr + i);
                *(salesPtr + i) = *(salesPtr + j);
                *(salesPtr + j) = tempSale;

                // swap months
                string tempMonth = *(monthsPtr + i);
                *(monthsPtr + i) = *(monthsPtr + j);
                *(monthsPtr + j) = tempMonth;
            }
        }
    }
}
