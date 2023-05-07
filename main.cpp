// Including Header Files
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

// Functions Prototypes

void addContact();
void searchContact();
void help();
void exit();
void about();
void continueWithError();
void continueWithoutError();
bool checkDigits(string n);
bool checkNumbers(string n);

// Global Variables

string firstName, lastName, phoneNumber;

// Start of Main Function

int main()
{
    int userChoice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t1- Add Contact\n\t2- Search Contact\n\t3- Help\n\t4- About\n\t5- Exit\n\t --> ";
    cin >> userChoice;

    switch (userChoice) {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            about();
            break;
        case 5:
            exit();
        default:
            continueWithError();
    }
    return 0;
}

// End of Main Function

// Functions Bodies

void addContact() {
    ofstream phone("numbers.txt", ios::app);
    system("cls");
    cout << "\n\n\n\tPlease Enter The First Name :";
    cin >> firstName;
    cout << "\n\n\n\tPlease Enter The Last Name :";
    cin >> lastName;
    cout << "\n\n\n\tPlease Enter The Phone Number (The Number Should Consists of 11-Digit) :";
    cin >> phoneNumber;
    if(checkDigits(phoneNumber)) {
        if(checkNumbers(phoneNumber))  {
            if(phone.is_open()) {
                phone << firstName << " " << lastName << " " << phoneNumber << endl;
                cout << "\n\tContact Saved Successfully!";
            }
            else
                cout << "\n\tError! Please Try Again...";
        }
        else
            cout << "\n\tThe Phone Number Should Contain Numbers Only!!";
    }
    else
        cout << "\n\t\tThe Phone Number Should Consists of 11-Digits!!";
    phone.close();
    continueWithoutError();
}

void searchContact() {
    bool found = false;
    ifstream myfile("numbers.txt");
    string name;
    cout << "\n\n\n\tEnter The Name You Want to Search for...";
    cin >> name;
    while(myfile >> firstName >> lastName >> phoneNumber) {
        if(name == firstName || name == lastName) {
            system("cls");
            cout << "\n\n\n\t\t\tContact Details";
            cout << "\n\n\t\tFirst Name : " << firstName;
            cout << "\n\t\tLast Name : " << lastName;
            cout << "\n\t\tPhone Number : " << phoneNumber;
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "\n\n\t\tContact Not Found!!";
    }
    continueWithoutError();
}

void help() {
    cout << "\n\n\n\tPress 1 to Add a New Contact";
    cout << "\n\n\n\tPress 2 to Search for Any Contact";
    cout << "\n\n\n\tPress 3 to Get Help";
    cout << "\n\n\n\tPress 4 to Get Information About The Owner";
    cout << "\n\n\n\tPress 5 to Close The Program";
    continueWithoutError();
}

void exit() {
    system("cls");
    cout << "\n\n\n\t\t\tGood Bye!!";
    exit(1);
}

void continueWithError() {
    cout << "\n\n\n\tError! , Please Press Any Key to Continue...";
    getch();
    main();
}

void continueWithoutError() {
    cout << "\n\n\n\tPlease Press Any Key to Continue...";
    getch();
    main();
}

void about() {
    cout << "\n\n\n\t\t\tThis Application Made By ENG. Ahmed Fatthi";
    continueWithoutError();
}

bool checkDigits(string n) {
    if(n.length() == 11)
        return true;
    else
        return false;
}

bool checkNumbers(string n) {
    bool checker = true;

    for(int i = 0; i < n.length(); i++) {
        if(!(int(n[i]) >=48 && int(n[i]) <=57)) {
            checker = false;
            break;
        }
    }

    if(checker)
        return true;
    else
        return false;
}