// Including Header Files
#include <iostream>
#include <conio.h>

using namespace std;

// Functions Prototypes

void addContact();
void searchContact();
void help();
void exit();

// Start of Main Function

int main()
{
    int userChoice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t1- Add Contact\n\t2- Search Contact\n\t3- Help\n\t4- Exit\n\t --> ";
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
            exit();
        default:
            cout << "\n\n\n\tError! , Please Press Any Key to Continue...";
            getch();
            main();
    }
    return 0;
}