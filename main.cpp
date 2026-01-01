#include <iostream>

using namespace std;



void inputData(int *pValues, int *pCounter)
{
    for (int k = 0; k < *pCounter; k++)
    {
        cout << "Enter Value: ";
        cin >> *(pValues + k);
    }

}

void displayData(int *pValues, int *pCounter)
{
    cout << "Content of the array" << endl;

    for (int k = 0; k < *pCounter; k++)
    {
        cout << *(pValues + k) << " ";
    }
}


int findValue(int *pValues, int *pCounter, int *pValue)
{
    int count = 0;
    int *pCount = &count;

    for (int i = 0; i < *pCounter; i++)
    {
        if (*(pValues + i) == *pValue)
        {
            (*pCount)++;
        }

    }

    return *pCount;

}

int main()
{
    int values[10];
    int *pValues = values;

    int counter = 10;
    int *pCounter = &counter;

    int value;
    int *pValue = &value;

    int times;
    int *pTimes = &times;

    inputData(values, &counter);
    displayData(values, &counter);

    cout << endl;

    cout << "Enter a value: ";
    cin >> *pValue;

    cout << endl;

    *pTimes = findValue(values, &counter, &value);

    cout << "The value of " << *pValue << " occurs " << *pTimes << " in the array." << endl;

    return 0;

}
