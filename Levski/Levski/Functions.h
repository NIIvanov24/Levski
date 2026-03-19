#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include "Question.h"
#include "Test.h"
using namespace std;

vector<int>    allScores;
vector<string> allNames;
vector<int>    allGrades;
vector<int>    allMaxScores;


void pauseScreen()
{
    cout << "\n  Press ENTER to return to the menu...";
    cin.ignore();
    cin.get();
}


void showStudyMaterials()
{
    int subChoice;
    do
    {
        system("cls");
        cout << "==============================\n";
        cout << "       STUDY MATERIALS        \n";
        cout << "==============================\n\n";
        cout << "  1. Mathematics\n";
        cout << "  2. English\n";
        cout << "  3. Chemistry\n";
        cout << "  4. Back\n\n";
        cout << "  Choice: ";
        cin >> subChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        system("cls");

        if (subChoice == 1)
        {
            cout << "==============================\n";
            cout << "         MATHEMATICS          \n";
            cout << "==============================\n\n";
            cout << "  BASIC OPERATIONS\n";
            cout << "  ─────────────────────────────\n";
            cout << "  + Addition       : 5 + 3 = 8\n";
            cout << "  - Subtraction    : 9 - 4 = 5\n";
            cout << "  * Multiplication : 6 * 7 = 42\n";
            cout << "  / Division       : 10 / 2 = 5\n\n";
            cout << "  IMPORTANT FORMULAS\n";
            cout << "  ─────────────────────────────\n";
            cout << "  Area of square       : a * a\n";
            cout << "  Area of rectangle    : a * b\n";
            cout << "  Square root          : sqrt(16) = 4\n\n";
            cout << "  POWERS\n";
            cout << "  ─────────────────────────────\n";
            cout << "  2^1=2, 2^2=4, 2^3=8, 2^4=16\n";
            cout << "  3^1=3, 3^2=9, 3^3=27\n";
            pauseScreen();
        }
        else if (subChoice == 2)
        {
            cout << "==============================\n";
            cout << "           ENGLISH            \n";
            cout << "==============================\n\n";
            cout << "  VERB TENSES\n";
            cout << "  ==============================\n";
            cout << "  Present Simple : He GOES to school\n";
            cout << "  Past Simple    : He WENT to school\n";
            cout << "  Present Cont.  : He IS GOING to school\n\n";
            cout << "  VERB 'to be'\n";
            cout << "  ==============================\n";
            cout << "  I am  / You are / He-She-It is\n";
            cout << "  We are / They are\n\n";
            cout << "  IRREGULAR VERBS\n";
            cout << "  ==============================\n";
            cout << "  go  -> went  -> gone\n";
            cout << "  eat -> ate   -> eaten\n";
            cout << "  run -> ran   -> run\n";
            cout << "  see -> saw   -> seen\n\n";
            cout << "  SYNONYMS / ANTONYMS\n";
            cout << "  ==============================\n";
            cout << "  big = large  |  big  <-> small\n";
            cout << "  fast = quick |  hot  <-> cold\n";
            pauseScreen();
        }
        else if (subChoice == 3)
        {
            cout << "==============================\n";
            cout << "          CHEMISTRY           \n";
            cout << "==============================\n\n";
            cout << "  IMPORTANT CHEMICAL FORMULAS\n";
            cout << "  ==============================\n";
            cout << "  H2O  - Water\n";
            cout << "  NaCl - Table Salt\n";
            cout << "  CO2  - Carbon Dioxide\n";
            cout << "  O2   - Oxygen\n";
            cout << "  H2   - Hydrogen\n";
            cout << "  HCl  - Hydrochloric Acid\n";
            cout << "  NH3  - Ammonia\n";
            cout << "  CH4  - Methane\n";
            cout << "  O3   - Ozone\n\n";
            cout << "  pH SCALE\n";
            cout << "  ==============================\n";
            cout << "  0-6  : Acid\n";
            cout << "  7    : Neutral (water)\n";
            cout << "  8-14 : Base\n\n";
            cout << "  CHEMICAL SYMBOLS\n";
            cout << "  ==============================\n";
            cout << "  H=Hydrogen  O=Oxygen\n";
            cout << "  C=Carbon    N=Nitrogen  Na=Sodium\n";
            pauseScreen();
        }

    } while (subChoice != 4);
}


void showExercises()
{
    int subChoice;
    do
    {
        system("cls");
        cout << "==============================\n";
        cout << "          EXERCISES           \n";
        cout << "==============================\n\n";
        cout << "  1. Mathematics\n";
        cout << "  2. English\n";
        cout << "  3. Chemistry\n";
        cout << "  4. Back\n\n";
        cout << "  Choice: ";
        cin >> subChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (subChoice < 1 || subChoice > 4) continue;
        if (subChoice == 4) break;

        vector<pair<string, string>> exercises;

        if (subChoice == 1)
        {
            exercises.push_back(make_pair(string("What is 8 * 7?"), string("56")));
            exercises.push_back(make_pair(string("What is 15 - 6?"), string("9")));
            exercises.push_back(make_pair(string("Square root of 25?"), string("5")));
            exercises.push_back(make_pair(string("What is 100 / 4?"), string("25")));
            exercises.push_back(make_pair(string("What is 3^3?"), string("27")));
        }
        else if (subChoice == 2)
        {
            exercises.push_back(make_pair(string("Past tense of 'go'?"), string("went")));
            exercises.push_back(make_pair(string("Plural of 'child'?"), string("children")));
            exercises.push_back(make_pair(string("Synonym of 'big'?"), string("large")));
            exercises.push_back(make_pair(string("Antonym of 'hot'?"), string("cold")));
            exercises.push_back(make_pair(string("Past tense of 'eat'?"), string("ate")));
        }
        else if (subChoice == 3)
        {
            exercises.push_back(make_pair(string("Chemical formula of water?"), string("H2O")));
            exercises.push_back(make_pair(string("Chemical formula of salt?"), string("NaCl")));
            exercises.push_back(make_pair(string("What is the pH of pure water?"), string("7")));
            exercises.push_back(make_pair(string("What gas do plants produce?"), string("O2")));
            exercises.push_back(make_pair(string("Chemical formula of ammonia?"), string("NH3")));
        }

        int correct = 0;
        for (int i = 0; i < (int)exercises.size(); i++)
        {
            system("cls");
            string question = exercises[i].first;
            string answer = exercises[i].second;

            cout << "==============================\n";
            cout << "  Exercise " << (i + 1) << " of " << exercises.size() << "\n";
            cout << "==============================\n\n";
            cout << "  " << question << "\n\n";
            cout << "  Answer: ";

            string userAnswer;
            cin >> userAnswer;

            string ua = userAnswer;
            string ans = answer;
            for (int k = 0; k < (int)ua.size(); k++) ua[k] = (char)tolower((unsigned char)ua[k]);
            for (int k = 0; k < (int)ans.size(); k++) ans[k] = (char)tolower((unsigned char)ans[k]);

            system("cls");
            if (ua == ans)
            {
                cout << "\n  *** CORRECT! ***\n";
                correct++;
            }
            else
            {
                cout << "\n  --- WRONG! The correct answer is: " << answer << " ---\n";
            }
            cout << "\n  Score: " << correct << "/" << (i + 1) << "\n";
            cout << "\n  Press ENTER for the next exercise...";
            cin.ignore();
            cin.get();
        }

        system("cls");
        cout << "==============================\n";
        cout << "       EXERCISE RESULT        \n";
        cout << "==============================\n\n";
        cout << "  Correct answers: " << correct << " of " << (int)exercises.size() << "\n";
        double pct = ((double)correct / (double)exercises.size()) * 100.0;
        cout << "  Percentage: " << fixed << setprecision(1) << pct << "%\n\n";

        if (pct == 100.0)   cout << "  Excellent! Perfect score!\n";
        else if (pct >= 60) cout << "  Good job! Keep studying!\n";
        else                cout << "  Review the study materials and try again!\n";

        pauseScreen();

    } while (subChoice != 4);
}


void startTest()
{
    system("cls");
    cout << "==============================\n";
    cout << "          TAKE A TEST         \n";
    cout << "==============================\n\n";

    string name;
    cout << "  Enter your name: ";
    cin.ignore();
    getline(cin, name);

    if (name.empty()) name = "Student";

    system("cls");
    cout << "==============================\n";
    cout << "  Hello, " << name << "!\n";
    cout << "==============================\n\n";
    cout << "  The test contains 20 questions.\n";
    cout << "  Answer with A, B, C or D.\n";
    cout << "  Good luck!\n\n";
    cout << "  Press ENTER to start...";
    cin.get();

    Test test;
    test.loadQuestions();
    test.generateTest();

    int score = test.startTest();
    int maxScore = test.getMaxScore();

    double percent = (maxScore > 0) ? ((double)score / (double)maxScore) * 100.0 : 0.0;

    int grade;
    if (percent >= 90) grade = 6;
    else if (percent >= 75) grade = 5;
    else if (percent >= 60) grade = 4;
    else if (percent >= 45) grade = 3;
    else                    grade = 2;

    string stars;
    if (grade == 6) stars = "[******]";
    else if (grade == 5) stars = "[*****-]";
    else if (grade == 4) stars = "[****--]";
    else if (grade == 3) stars = "[***---]";
    else                 stars = "[**----]";

    system("cls");
    cout << "==============================\n";
    cout << "           RESULT             \n";
    cout << "==============================\n\n";
    cout << "  Student    : " << name << "\n";
    cout << "  Points     : " << score << " / " << maxScore << "\n";
    cout << "  Percentage : " << fixed << setprecision(1) << percent << "%\n";
    cout << "  Grade      : " << grade << "  " << stars << "\n\n";

    if (grade == 6) cout << "  Excellent result! Well done!\n";
    else if (grade == 5) cout << "  Very good! Keep it up!\n";
    else if (grade == 4) cout << "  Good! You can do better!\n";
    else if (grade == 3) cout << "  Poor. Review the material!\n";
    else                 cout << "  Insufficient. Study more!\n";

    allNames.push_back(name);
    allScores.push_back(score);
    allGrades.push_back(grade);
    allMaxScores.push_back(maxScore);

    pauseScreen();
}


void showStatistics()
{
    system("cls");
    cout << "==============================\n";
    cout << "         STATISTICS           \n";
    cout << "==============================\n\n";

    if (allScores.empty())
    {
        cout << "  No data yet! Take at least one test.\n";
        pauseScreen();
        return;
    }

    int maxS = allScores[0], minS = allScores[0], sum = 0;
    int bestIndex = 0;

    for (int i = 0; i < (int)allScores.size(); i++)
    {
        if (allScores[i] > maxS) { maxS = allScores[i]; bestIndex = i; }
        if (allScores[i] < minS)   minS = allScores[i];
        sum += allScores[i];
    }

    double avg = (double)sum / (double)allScores.size();

    cout << "  Tests taken        : " << (int)allScores.size() << "\n";
    cout << "  Highest score      : " << maxS << "  (" << allNames[bestIndex] << ")\n";
    cout << "  Lowest score       : " << minS << "\n";
    cout << "  Average score      : " << fixed << setprecision(1) << avg << "\n\n";

    cout << "  Grade distribution:\n";
    int g2 = 0, g3 = 0, g4 = 0, g5 = 0, g6 = 0;
    for (int i = 0; i < (int)allGrades.size(); i++)
    {
        if (allGrades[i] == 2) g2++;
        else if (allGrades[i] == 3) g3++;
        else if (allGrades[i] == 4) g4++;
        else if (allGrades[i] == 5) g5++;
        else if (allGrades[i] == 6) g6++;
    }
    cout << "  Grade 6: " << g6 << "\n";
    cout << "  Grade 5: " << g5 << "\n";
    cout << "  Grade 4: " << g4 << "\n";
    cout << "  Grade 3: " << g3 << "\n";
    cout << "  Grade 2: " << g2 << "\n\n";

    cout << "  All results:\n";
    for (int i = 0; i < (int)allNames.size(); i++)
    {
        double pct = (allMaxScores[i] > 0)
            ? ((double)allScores[i] / (double)allMaxScores[i]) * 100.0
            : 0.0;
        cout << "  " << setw(2) << (i + 1) << ". "
            << left << setw(15) << allNames[i]
            << right << setw(4) << allScores[i]
            << "/" << allMaxScores[i]
            << "  (" << fixed << setprecision(0) << pct << "%)"
            << "  Grade: " << allGrades[i] << "\n";
    }

    pauseScreen();
}

#endif
