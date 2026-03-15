
#include <iostream>
#include <vector>
#include <string>

#include "Question.h"
#include "Test.h"
using namespace std;

//void showStudyMaterials(); - Трябва да се довърши!
//void showExercises(); - Трябва да се довърши!
//void startTest(); - Трябва да се довърши!
//void showStatistics(); - Трябва да се довърши!


int main()
    {
        int choice;

        cout << "==============================" << endl;
        cout << "   ELECTRONIC SCHOOL SYSTEM   " << endl;
        cout << "==============================" << endl;

        do
        {
            cout << "\nMAIN MENU\n";
            cout << "1. Study Materials\n";
            cout << "2. Exercises\n";
            cout << "3. Take Test\n";
            cout << "4. Statistics\n";
            cout << "5. Exit\n";

            cout << "\nEnter choice: ";
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input!\n";
                continue;
            }

            switch (choice)
            {
            case 1:
                //showStudyMaterials();
                break;

            case 2:
                //showExercises();
                break;

            case 3:
                //startTest();
                break;

            case 4:
                //showStatistics();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }

        } while (choice != 5);

        return 0;
    }


