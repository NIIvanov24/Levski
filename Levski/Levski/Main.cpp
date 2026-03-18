#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Functions.h"
#include "Question.h"
#include "Test.h"
using namespace std;

int main()
{
    int choice;

    do
    {
        system("cls");
        cout << "==============================\n";
        cout << "   ELECTRONIC SCHOOL SYSTEM   \n";
        cout << "==============================\n\n";
        cout << "  1. Study Materials\n";
        cout << "  2. Exercises\n";
        cout << "  3. Take Test\n";
        cout << "  4. Statistics\n";
        cout << "  5. Exit\n";
        cout << "\n  Choice: ";
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
            cout << "\n  Goodbye!\n\n";
            break;
        default:
            cout << "\n  Invalid choice! Try again.\n";
            break;
        }

    } while (choice != 5);

    return 0;
}
