// Including Header Files
#include <iostream>
#include <conio.h>

using namespace std;

// Functions Prototypes

void addContact();
void searchContact();
void help();
void exit();
void continueWithError();
void continueWithoutError();

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
            continueWithError();
    }
    return 0;
}

// End of Main Function

// Functions Bodies

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