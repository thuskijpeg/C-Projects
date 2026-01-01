#include <iostream>
#include <random>
#include <fstream>
#include <string>

using namespace std;



void findLowestTemp(int *pTemp, int *pCounter, int *pLowestTemp, int *pLowestDay)
{
    for (int i = 0; i < *pCounter; i++)
    {
        if (*(pTemp + i) < *pLowestTemp)
        {
            *pLowestTemp = *(pTemp + i);
            *pLowestDay = i + 1;
        }
    }
}


void displayTemp(int *pTemp, int *pCounter)
{
    cout << "List of temperatures" << endl;

    for (int i = 0; i < *pCounter; i++)
    {
        cout << *(pTemp + i) << endl;
    }

}


void populateArray(int *pTemp, int *pCounter, int DAYS)
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(15, 45);

    for (int i = 0; i < DAYS; i++)
    {
        *(pTemp + i) = dist(gen);
        (*pCounter)++;
    }

}

int main()
{
    const int DAYS = 10;
    int temp[DAYS];
    int *pTemp = temp;

    int counter = 0;
    int *pCounter = &counter;

    int lowestTemp = 100;
    int *pLowestTemp = &lowestTemp;

    int lowestDay = 0;
    int *pLowestDay = &lowestDay;

    string text;
    string *pText = &text;

    populateArray(pTemp, pCounter, DAYS);
    displayTemp(pTemp, pCounter);
    findLowestTemp(pTemp, pCounter, pLowestTemp, pLowestDay);

    ofstream outFile;
    outFile.open("lowestTemp.txt", ios::out);

    if (outFile.fail())
    {
        cerr << "There was an error creating a file" << endl;
        return -1;
    }

    *pText = "The lowest temperature was on day " + to_string(*pLowestDay) + " with a temperature of " + to_string(*pLowestTemp);

    outFile << *pText << endl;

    outFile.close();

    cout << endl;
    cout << "Data saved to text file!" << endl;


    return 0;
}
