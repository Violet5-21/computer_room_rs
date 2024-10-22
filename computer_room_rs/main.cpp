#include <iostream>
#include <string>
#include <iomanip>
#include "global_file.h"

int main()
{
    using namespace std;

    string welcome = " Welcome to the computer room reservation system! ";
    string identification1 = " 1. Student ";
    string identification2 = " 2. Teacher ";
    string identification3 = " 3. Administrator ";
    string exit = " 0. Exit ";
    string reminder = " Please select your identification: ";

    cout << setfill('=') << setw(50+static_cast<int>(welcome.size()/2)) << welcome
        << setw(50-static_cast<int>(welcome.size()/2)) << "\n";
    cout << "\t\t\t" << setfill('-') << setw(53) << "\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(identification1.size()/2)) << identification1
        << setw(26-static_cast<int>(identification1.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(identification2.size()/2)) << identification2
         << setw(26-static_cast<int>(identification2.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(identification3.size()/2)) << identification3
         << setw(26-static_cast<int>(identification3.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(exit.size()/2)) << exit
         << setw(26-static_cast<int>(exit.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t" << setfill('-') << setw(53) << "\n";
    cout << reminder << setfill(' ');

    int select = 0;

    while (cin >> select)
    {
        switch (select)
        {
            case 1:
                log_in(STUDENT_FILE, 1);
                break;
            case 2:
                log_in(TEACHER_FILE, 2);
                break;
            case 3:
                log_in(ADMINISTRATOR_FILE, 3);
                break;
            case 0:
                cout << "Good bye! \n";
                return 0;
            default:
                cout << "Bad select, please try again: ";
                break;
        }
    }
    return 0;
}
