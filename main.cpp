#include <iostream>
#include <random>
#include <string>

using namespace std;

int main()
{
    int idNum;

    cout << "Please enter your staff identifcation number for equipment thermal insulation check: ";
    cin >> idNum;

    if (!(idNum >= 10000 && idNum <= 99999))
    {
        cout << "The staff identifcation number is incorrect" << endl;
        cout << "Exiting program....." << endl;
        return 1;

    }else{
        cout << endl;
        cout << "The staff identification number is correct." << endl;
        cout << "Welcome to the Thermal Insulation System!" << endl;
    }


    int items;
    int temp;
    string material;
    string idNO;
    string type;
    int num1;
    int num2;
    int num3;
    string num1Str;
    string num2Str;
    string num3Str;

    cout << endl;
    cout << "Please indicate the total number of items to check: ";
    cin >> items;
    cout << endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10);

    for (int i = 0; i < items; i++)
    {

        cout << "Enter the temperature (degrees centigrade) of item " << i + 1 << ": ";
        cin >> temp;

        cout << endl;

        if (temp <= 90){
            type = "Y";
            material = "Cotton, silk, or paper";


        }else if (temp > 90 && temp <= 105){
            type = "A";
            material = "Cotton, silk, or paper with impregnated insulation oil";


        }else if (temp > 105 && temp <= 120){
            type = "E";
            material = "Combination of different materials";


        }else if (temp > 120 && temp <= 130){
            type = "B";
            material = "Inorganic material with adhesives";


        }else if (temp > 130 && temp <= 155){
            type = "F";
            material = "Inorganic material with adhesives";


        }else if (temp > 155 && temp <= 180){
            type = "H";
            material = "Inorganic material glued with silicon resin";


        }else if (temp > 180){
            type = "C";
            material = "100% inorganic material";

        }

        num1 = dist(gen);
        num2 = dist(gen);
        num3 = dist(gen);

        num1Str = to_string(num1);
        num2Str = to_string(num2);
        num3Str = to_string(num3);

        idNO = type + num1Str + num2Str + num3Str;

        cout << "=====================================================================" << endl;
        cout << "Identification number: " << idNO << endl;
        cout << "For a temperatire value of " << temp << " degree centigrade, the insulation class is " << type << endl;
        cout << "Material(s) to be used for insulation: " << material << endl;
        cout << "=====================================================================" << endl;
        cout << endl;

    }


    return 0;
}
