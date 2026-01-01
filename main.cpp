#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <limits>

using namespace std;

struct Order
{
    string orderID;
    string customerName;
    double totalPrice;
    string orderStatus;
};


void DisplayOrders(Order arrOrder[], int counter)
{
    cout << "==================================================================== " << endl;
    cout << "| " << "No." << left << setw(3) << "  | " << "Order ID" << left << setw(5) << "   |  " << "Customer Name" << "  | " << "Total Price" << left << setw(6) << fixed << setprecision(2) << "  |" << "Status" << left << setw(3) << "    |    " << endl;
    cout << "==================================================================== " << endl;

    for (int i = 0; i < counter; i++)
    {
        cout << "|  " << i + 1 << left << setw(3) << "  | " << arrOrder[i].orderID << left << setw(5) << "   |  " << arrOrder[i].customerName
        << "  |  R " << arrOrder[i].totalPrice << "  |  " << arrOrder[i].orderStatus << left << setw(3) << "    |   " << endl;
    }

}

string compileOrderID(Order arrOrder[], int counter)
{
    string orderID;
    int num = counter + 1;
    string numstr = to_string(num);
    int sPos = arrOrder[counter].customerName.find(" ");
    string letters;

    // Remember
    if (sPos != string::npos){
        letters = arrOrder[counter].customerName.substr(sPos + 1, 3);
    }else{

        letters = arrOrder[counter].customerName.substr(0, 3);

    }


    for (int i = 0; i < letters.length(); i++)
    {
        letters[i] = toupper(letters[i]);

    }

    orderID = letters + "_" + "00" + numstr;

    return orderID;

}


void removeOrder(Order arrOrder[], int &counter)
{
    int del;
    cout << "Select the number of the order you want to remove: ";
    cin >> del;

    while (del < 1 || del > counter) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number, Please enter valid number: ";
        cin >> del;
    }

    cout << endl;
    cout << "Order " << arrOrder[del - 1].orderID << " has been removed." << endl;

    for (int i = del - 1; i < counter -1; i++)
    {
        arrOrder[i].customerName = arrOrder[i + 1].customerName;
        arrOrder[i].totalPrice = arrOrder[i + 1].totalPrice;
        arrOrder[i].orderID = arrOrder[i + 1].orderID;
        arrOrder[i].orderStatus = arrOrder[i + 1].orderStatus;

    }

    counter--;
}


void addOrder(Order arrOrder[], int &counter)
{

    cout << "Enter the customer name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, arrOrder[counter].customerName);

    cout << "Enter the total price: ";
    cin >> arrOrder[counter].totalPrice;

    cout << "Enter the order status (Pending, Shipped, Delivered): ";
    cin >> arrOrder[counter].orderStatus;

    arrOrder[counter].orderID = compileOrderID(arrOrder, counter);

    counter++;


}


int main()
{
    int option;
    int counter = 0;
    size_t const SIZE = 100;
    Order arrOrder[SIZE];


    do
    {
        cout << "1. Display list of orders " << endl;
        cout << "2. Remove an order " << endl;
        cout << "3. Add an order " << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
            case 1: {

                DisplayOrders(arrOrder, counter);
                break;

            }

            case 2: {

                removeOrder(arrOrder, counter);
                break;

            }


            case 3: {

                addOrder(arrOrder, counter);
                break;

            }


            case 4: {

                cout << "Exiting Program...." << endl;
                break;

            }


            default : {

                cout << "Invalid option." << endl;
                cout << "Please choose the correct option." << endl;
                break;

            }

        }


    }while(option != 4);

    return 0;
}
