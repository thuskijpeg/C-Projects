#include <iostream>
#include <iomanip>

using namespace std;

struct Order
{
    string item;
    int price;
    int numOfItems;
};

void displayOrders(Order arrOrder[], int totalPrice, int counter)
{
    cout << "====ORDERS=====" << endl;
    cout <<left << setw(5) << "Item" << "    |   " << right << setw(5) << "Price" << endl;

    for (int i = 0; i < counter; i++)
    {


    }

}

int main()
{
    const int MAX = 10;
    Order arrOrder[MAX];
    int counter = 0;
    int totalPrice = 0;

    do
    {
        cout << "Enter the name of the item: ";
        cin >> arrOrder[counter].item;
        cout << "Enter the price of item: ";
        cin >> arrOrder[counter].price;
        cout << "Enter the number of item ordered: ";
        cin >> arrOrder[counter].numOfItems;

        totalPrice +=  arrOrder[counter].price;


    }while(arrOrder[counter].item != "X" && counter < MAX);

    displayOrders(arrOrder, totalPrice, counter)


    return 0;
}
