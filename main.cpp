#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string name;
    string *pName = &name;

    int daysLate;
    int *pDaysLate = &daysLate;

    int numOfBooks;
    int *pNumOfBooks = &numOfBooks;

    int fine;
    int *pFine = &fine;

    double total;
    double *pTotal = &total;

    cout << "Name of student: ";
    cin >> *pName;

    cout << "Enter the number of days late: ";
    cin >> *pDaysLate;

    cout << "Enter the number of books: ";
    cin >> *pNumOfBooks;

    cout << "Enter the fine per book per day: R";
    cin >> *pFine;

    *pTotal = *pNumOfBooks * *pDaysLate * *pFine;

    cout << endl;

    cout << "Name of student: " << *pName << endl;
    cout << "Number of days late: " << *pDaysLate << endl;
    cout << "Number of books outstanding: " << *pNumOfBooks << endl;
    cout << "Fine per book per day: " << *pFine << endl;
    cout << "Amount due: R" << fixed << setprecision(2) << *pTotal << endl;



}
