#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Declare the struct
struct TruckInfo {
    string driverName;
    string truckNumber;
    int distanceCovered;
    int fuelConsumed;
};

// Function prototypes
int loadTruckInfo(TruckInfo trucks[], int maxTrucks);
void viewTruckInfo(TruckInfo trucks[], int numTrucks);
void swapTruckInfo(TruckInfo trucks[], int numTrucks);
void editTruckInfo(TruckInfo trucks[], int numTrucks);
void saveTruckInfo(TruckInfo trucks[], int numTrucks);

int main() {
    const int MAX_TRUCKS = 20;
    TruckInfo trucks[MAX_TRUCKS];
    int numTrucks = 0;
    int choice;

    // --- Load truck information from file ---
    numTrucks = loadTruckInfo(trucks, MAX_TRUCKS);

    do {
        cout << "\n===== Truck Fuel Usage Rating System =====" << endl;
        cout << "1. View Truck Info" << endl;
        cout << "2. Swap Truck Info" << endl;
        cout << "3. Edit Truck Info" << endl;
        cout << "4. Save Excellent Rating Info" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewTruckInfo(trucks, numTrucks);
                break;
            case 2:
                swapTruckInfo(trucks, numTrucks);
                break;
            case 3:
                editTruckInfo(trucks, numTrucks);
                break;
            case 4:
                saveTruckInfo(trucks, numTrucks);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}


int loadTruckInfo(TruckInfo trucks[], int maxTrucks)
{
    ifstream inFile("truckInfo.txt", ios::in);

    if (inFile.fail())
    {
        cerr << "There was an error opening the file" << endl;
    }

    int counter = 0;
    string distance;
    string fuel;

    while (getline(inFile, trucks[counter].driverName, ';'))
    {
        getline(inFile, trucks[counter].truckNumber, ';');
        getline(inFile, distance, ';');
        getline(inFile, fuel);

        trucks[counter].distanceCovered = stoi(distance);
        trucks[counter].fuelConsumed = stoi(fuel);

        counter++;
    }

    inFile.close();

    return counter;

}


void viewTruckInfo(TruckInfo trucks[], int numTrucks)
{
    cout << endl;
    cout << "    Name of Driver    " << setw(15) << "    Track Number     " << setw(15) << "    Distance Covered    " << setw(14) << "    Fuel Consumed    " << setw(15) << "       Performance Rating   " << setw(15) << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;


    string rating;



    for (int i = 0; i < numTrucks; i++)
    {
        if (trucks[i].fuelConsumed <= 20)
        {
            rating = "Excellent Fuel Usuage";
        }else{
            rating = "Poor Fuel Usage";
        }


        cout << i + 1 << "        " << left << setw(15) << trucks[i].driverName << "       " << left << setw(15) << trucks[i].truckNumber << "       " << left << setw(15) << trucks[i].distanceCovered << "          " << left << setw(15) << trucks[i].fuelConsumed << "   " << left << setw(15) << rating << " " << endl;
    }
}

void swapTruckInfo(TruckInfo trucks[], int numTrucks)
{
    TruckInfo temp;

    int swapP1;
    int swapP2;
    int swap1;
    int swap2;

    cout << "Enter the number of the truck (first) to swap: ";
    cin >> swapP1;

    cout << "Enter the number of the truck (second) to swap: ";
    cin >> swapP2;

    swap1 = swapP1 - 1;
    swap2 = swapP2 - 1;

    temp = trucks[swap1];
    trucks[swap1] = trucks[swap2];
    trucks[swap2] = temp;

    cout << "Trucks were swapped." << endl;

}

void editTruckInfo(TruckInfo trucks[], int numTrucks)
{
    int truckNum;


    cout << "Enter the number of the truck information to edit: ";
    cin >> truckNum;

    int truckPos = truckNum - 1;

    char answer1;
    char answer2;
    int distance;
    int fuel;
    string truckNumber;

    cout << "Truck Number: ";
    cin >> truckNumber;


    if (truckNumber == trucks[truckPos].truckNumber)
    {
        cout << "Do you want to change the distance travelled (Y or N): ";
        cin >> answer1;

        if (answer1 == 'y' || answer1 == 'Y')
        {
            cout << "Enter the new distance travelled: ";
            cin >> distance;

            trucks[truckPos].distanceCovered = distance;
        }

        cout << "Do you want to change the quantity of the fuel used (Y or N): ";
        cin >> answer2;

        if (answer2 == 'y' || answer2 == 'Y')
        {
            cout << "Enter the new quantity of fuel used: ";
            cin >> fuel;

            trucks[truckPos].fuelConsumed = fuel;
        }
    }else{

        cout << "Invalid truck number." << endl;
    }
}

void saveTruckInfo(TruckInfo trucks[], int numTrucks)
{
    ofstream outFile("ExellentRating.txt", ios :: out);

    for (int i = 0; i < numTrucks; i++)
    {
        if (trucks[i].fuelConsumed <= 20 && trucks[i].distanceCovered >= 100)
        {
            outFile << trucks[i].driverName << "#" << trucks[i].truckNumber << endl;
        }
    }

    outFile.close();

    cout << "Information susccesfully saved to the file: " << endl;

}



