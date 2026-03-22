#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Functions.h"
#include "Question.h"
#include "Test.h"
using namespace std;
//main.cpp
//More bright colors for headings and important info
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"
//Basic colors for regular text
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
int main()
{
    int choice;

    do
    {
        system("cls");
        cout << BBLUE << "=============================================================\n";
        cout << BBLUE << "|||       ||||||||  |||        |||  ||||||||  |||   ||| |||||\n";
        cout << BBLUE << "|||       |||        |||      |||  |||        |||  |||   |||\n";
        cout << BBLUE << "|||       |||         |||    |||   |||        ||| |||    |||\n";
        cout << BBLUE << "|||       |||||||     |||    |||   |||||||||  ||||       |||\n";
        cout << BBLUE << "|||       |||           ||| |||          |||  ||| |||    |||\n";
        cout << BBLUE << "|||       |||           ||| |||          |||  |||  |||   |||\n";
        cout << BBLUE << "||||||||  ||||||||        |||      ||||||||   |||   ||| |||||\n";
        cout << BBLUE << "=============================================================\n";
        cout << BGREEN << "                  ELECTRONIC SCHOOL SYSTEM   \n";
        cout << BBLUE << "=============================================================\n\n";
        cout << BGREEN << "  1. Study Materials\n" << RESET;
        cout << BGREEN << "  2. Exercises\n" << RESET;
        cout << BGREEN << "  3. Take Test\n" << RESET;
        cout << BGREEN << "  4. Statistics\n" << RESET;
        cout << BRED << "  5. Exit\n" << RESET;
        cout << BYELLOW << "\n  Choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1: showStudyMaterials(); break;
        case 2: showExercises();      break;
        case 3: startTest();          break;
        case 4: showStatistics();     break;
        case 5:
            system("cls");
            cout << BMAGENTA <<"\n  Goodbye!\n\n";
            break;
        default:
            cout << BRED <<"\n  Invalid choice! Try again.\n";
            break;
        }

    } while (choice != 5);

    return 0;
}
