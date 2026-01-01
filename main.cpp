#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void displayArr(string arrNames[], int counter)
{
    cout << "====Names of email addresses=====" << endl;

    for (int i = 0; i < counter; i++){

        cout << i + 1 << ". " << arrNames[i] << endl;
    }
}



int main()
{
    string email;
    const int MAX_SIZE = 10;
    string arrNames[MAX_SIZE];
    char answer;
    int counter = 0;
    string name;
    string surname;
    string nameAndSurname;

    do
    {
        cout << "Enter an email address: ";
        getline(cin, email);

        int atPos = email.find('@');
        int dotPos = email.find('.');

        if (atPos != string::npos)
        {
            cout << "@ characrer found" << endl;

        }else{
            cout << "@ character not found" << endl;

        }

        if (dotPos != string::npos)
        {
            cout << "Dot characrer found" << endl;

        }else{
            cout << "Dot character not found" << endl;

        }

        cout << endl;

        name = email.substr(0, dotPos);
        surname = email.substr(dotPos + 1, atPos - dotPos - 1);

        nameAndSurname = name + " " + surname;

        arrNames[counter] = nameAndSurname;
        counter++;

        cout << endl;
        cout << "Do you want to continue? (Y/N): ";
        cin >> answer;
        cin.ignore();
        cout << endl;


    }while(answer != 'n' && answer != 'N' && counter < MAX_SIZE);

    displayArr(arrNames, counter);

    return 0;


}
