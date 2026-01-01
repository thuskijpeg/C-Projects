#include <iostream>
#include <limits>

using namespace std;




void fillArr(int *pVisitors, int &counter, int SIZE)
{
    cout << "Enter the number of visitors for day " << (counter + 1) << ": ";
    cin >> *(pVisitors + counter);

    while(counter < SIZE)
    {
        counter++;

        cout << "Enter the number of visitors for day " << (counter + 1) << ": ";
        cin >> *(pVisitors + counter);
    }

}

void displayArr(int *pVisitors, int *pCounter)
{
    cout << "======List of visitors per day======" << endl;
    for (int i = 0; i < *pCounter; i++)
    {
        cout << "Day " << (i + 1) << ": " << *(pVisitors + i) << endl;
    }

}

void displayLowest(int *pVisitors, int *pCounter, int &lowest, int &lowest_day)
{
    for (int i = 0; i <= *pCounter; i++)
    {
        if (*(pVisitors + i) < lowest)
        {
            lowest = *(pVisitors + i);
            lowest_day = i;

        }
    }

}

void displayHighest(int *pVisitors, int *pCounter, int &highest, int &highest_day)
{
    for (int i = 0; i <= *pCounter; i++)
    {
        if (*(pVisitors + i) > highest)
        {
            highest = *(pVisitors + i);
            highest_day = i;

        }
    }

}





int main()
{
    const int SIZE = 10;
    int arrVisitors[SIZE];
    int *pVisitors = arrVisitors;

    int counter = 0;
    int *pCounter = &counter;

    int highest = numeric_limits<int>::min();
    int lowest = numeric_limits<int>::max();

    int highest_day;
    int lowest_day;

    fillArr(arrVisitors, counter, SIZE);
    cout << endl;
    displayArr(arrVisitors, &counter);
    displayLowest(arrVisitors, &counter, lowest, lowest_day);
    displayHighest(arrVisitors, &counter, highest, highest_day);

    cout << endl;

    cout << "\nDay with the least number of visitors is day " << (lowest_day + 1) << " with " << lowest << " visitors." << endl;
    cout << "\nDay with the most number of visitors is day " << (highest_day + 1) << " with " << highest << " visitors." << endl;


    return 0;
}
