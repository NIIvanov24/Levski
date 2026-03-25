#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <fstream>
#include "Question.h"
#include "Test.h"
using namespace std;

vector<int>    allScores;
vector<string> allNames;
vector<int>    allGrades;
vector<int>    allMaxScores;

// ── Color macros ────────────────────────────────────────────────────
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"

// ── Helpers ─────────────────────────────────────────────────────────

// Waits for the user to press Enter.
void pauseScreen()
{
    cout << "\n  Press ENTER to return to the menu...";
    cin.ignore();
    cin.get();
}

// Prints a colored title header.
void printHeader(const string& title, const string& color)
{
    cout << BBLUE << "==============================\n" << RESET;
    cout << color << "  " << title << "\n" << RESET;
    cout << BBLUE << "==============================\n\n" << RESET;
}


// ════════════════════════════════════════════════════════════════════
//  STUDY MATERIALS
// ════════════════════════════════════════════════════════════════════

// Shows the study materials menu and topic notes.
void showStudyMaterials()
{
    int subChoice;
    do
    {
        system("cls");
        cout << BBLUE << "==============================\n" << RESET;
        cout << BGREEN << "       STUDY MATERIALS        \n" << RESET;
        cout << BBLUE << "==============================\n\n" << RESET;
        cout << BGREEN << "  1. Mathematics\n" << RESET;
        cout << BGREEN << "  2. English\n" << RESET;
        cout << BGREEN << "  3. Chemistry\n" << RESET;
        cout << BGREEN << "  4. Biology\n" << RESET;
        cout << BGREEN << "  5. Physics\n" << RESET;
        cout << BGREEN << "  6. C++ Programming\n" << RESET;
        cout << BRED << "  7. Back\n\n" << RESET;
        cout << BYELLOW << "  Choice: " << RESET;
        cin >> subChoice;

        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); continue; }

        system("cls");

        if (subChoice == 1)
        {
            printHeader("MATHEMATICS", BLUE);
            cout << YELLOW << "  BASIC OPERATIONS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  + Addition       : 5 + 3 = 8\n" << RESET;
            cout << BYELLOW << "  - Subtraction    : 9 - 4 = 5\n" << RESET;
            cout << BYELLOW << "  * Multiplication : 6 * 7 = 42\n" << RESET;
            cout << BYELLOW << "  / Division       : 10 / 2 = 5\n\n" << RESET;
            cout << BYELLOW << "  IMPORTANT FORMULAS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  Area of square       : a * a\n" << RESET;
            cout << BYELLOW << "  Area of rectangle    : a * b\n" << RESET;
            cout << BYELLOW << "  Square root          : sqrt(16) = 4\n\n" << RESET;
            cout << BYELLOW << "  POWERS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  2^1=2, 2^2=4, 2^3=8, 2^4=16\n" << RESET;
            cout << BYELLOW << "  3^1=3, 3^2=9, 3^3=27\n" << RESET;
            pauseScreen();
        }
        else if (subChoice == 2)
        {
            printHeader("ENGLISH", RED);
            cout << BYELLOW << "  VERB TENSES\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  Present Simple : He GOES to school\n" << RESET;
            cout << BYELLOW << "  Past Simple    : He WENT to school\n" << RESET;
            cout << BYELLOW << "  Present Cont.  : He IS GOING to school\n\n" << RESET;
            cout << BYELLOW << "  VERB 'to be'\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  I am  / You are / He-She-It is\n" << RESET;
            cout << BYELLOW << "  We are / They are\n\n" << RESET;
            cout << BYELLOW << "  IRREGULAR VERBS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  go  -> went  -> gone\n" << RESET;
            cout << BYELLOW << "  eat -> ate   -> eaten\n" << RESET;
            cout << BYELLOW << "  run -> ran   -> run\n" << RESET;
            cout << BYELLOW << "  see -> saw   -> seen\n\n" << RESET;
            cout << BYELLOW << "  SYNONYMS / ANTONYMS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  big = large  |  big  <-> small\n" << RESET;
            cout << BYELLOW << "  fast = quick |  hot  <-> cold\n" << RESET;
            pauseScreen();
        }
        else if (subChoice == 3)
        {
            printHeader("CHEMISTRY", BYELLOW);
            cout << BYELLOW << "  IMPORTANT CHEMICAL FORMULAS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  H2O  - Water\n" << RESET;
            cout << BYELLOW << "  NaCl - Table Salt\n" << RESET;
            cout << BYELLOW << "  CO2  - Carbon Dioxide\n" << RESET;
            cout << BYELLOW << "  O2   - Oxygen\n" << RESET;
            cout << BYELLOW << "  H2   - Hydrogen\n" << RESET;
            cout << BYELLOW << "  HCl  - Hydrochloric Acid\n" << RESET;
            cout << BYELLOW << "  NH3  - Ammonia\n" << RESET;
            cout << BYELLOW << "  CH4  - Methane\n" << RESET;
            cout << BYELLOW << "  O3   - Ozone\n\n" << RESET;
            cout << BYELLOW << "  pH SCALE\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  0-6  : Acid\n" << RESET;
            cout << BYELLOW << "  7    : Neutral (water)\n" << RESET;
            cout << BYELLOW << "  8-14 : Base\n\n" << RESET;
            cout << BYELLOW << "  CHEMICAL SYMBOLS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  H=Hydrogen  O=Oxygen\n" << RESET;
            cout << BYELLOW << "  C=Carbon    N=Nitrogen  Na=Sodium\n" << RESET;
            pauseScreen();
        }
        else if (subChoice == 4)
        {
            printHeader("BIOLOGY", BMAGENTA);
            cout << BRED << "  THE CELL\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  - Basic unit of life: CELL\n" << RESET;
            cout << BYELLOW << "  - Nucleus     : controls cell activity\n" << RESET;
            cout << BYELLOW << "  - Mitochondria: produces energy (ATP)\n" << RESET;
            cout << BYELLOW << "  - Ribosome    : produces proteins\n" << RESET;
            cout << BYELLOW << "  - Vacuole     : stores water/waste\n\n" << RESET;
            cout << BYELLOW << "  THE HUMAN BODY\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  - Heart       : 4 chambers, pumps blood\n" << RESET;
            cout << BYELLOW << "  - Lungs       : gas exchange (O2 / CO2)\n" << RESET;
            cout << BYELLOW << "  - Bones       : 206 in adult human body\n" << RESET;
            cout << BYELLOW << "  - Red blood cells : carry oxygen\n" << RESET;
            cout << BYELLOW << "  - White blood cells: fight infections\n\n" << RESET;
            cout << BYELLOW << "  PHOTOSYNTHESIS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  CO2 + H2O + light -> O2 + glucose\n\n" << RESET;
            cout << BYELLOW << "  GENETICS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  - DNA = Deoxyribonucleic Acid\n" << RESET;
            cout << BYELLOW << "  - Human cells have 46 chromosomes\n" << RESET;
            cout << BYELLOW << "  - Genes carry hereditary information\n" << RESET;
            pauseScreen();
        }
        else if (subChoice == 5)
        {
            printHeader("PHYSICS", BWHITE);
            cout << BLUE << "  UNITS OF MEASUREMENT\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  Force    : Newton  (N)\n" << RESET;
            cout << BYELLOW << "  Energy   : Joule   (J)\n" << RESET;
            cout << BYELLOW << "  Power    : Watt    (W)\n" << RESET;
            cout << BYELLOW << "  Current  : Ampere  (A)\n" << RESET;
            cout << BYELLOW << "  Voltage  : Volt    (V)\n" << RESET;
            cout << BYELLOW << "  Resistance: Ohm   (Ohm)\n\n" << RESET;
            cout << BYELLOW << "  NEWTON'S LAWS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  1st: Object stays at rest unless acted upon\n" << RESET;
            cout << BYELLOW << "  2nd: F = m * a\n" << RESET;
            cout << BYELLOW << "  3rd: Every action has an equal reaction\n\n" << RESET;
            cout << BYELLOW << "  IMPORTANT FACTS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  Speed of light : 300 000 km/s\n" << RESET;
            cout << BYELLOW << "  Speed formula  : s = d / t\n" << RESET;
            cout << BYELLOW << "  Boiling point of water: 100 degrees C\n" << RESET;
            cout << BYELLOW << "  Freezing point of water: 0 degrees C\n" << RESET;
            cout << BYELLOW << "  Gravity on Earth: 9.8 m/s^2\n\n" << RESET;
            cout << BYELLOW << "  ENERGY TYPES\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  Kinetic  : energy of moving objects\n" << RESET;
            cout << BYELLOW << "  Potential: stored energy (height)\n" << RESET;
            pauseScreen();
        }
        else if (subChoice == 6)
        {
            printHeader("C++ PROGRAMMING", BCYAN);
            cout << BYELLOW << "  BASIC STRUCTURE\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  #include <iostream>\n" << RESET;
            cout << BYELLOW << "  using namespace std;\n" << RESET;
            cout << BYELLOW << "  int main() {\n" << RESET;
            cout << BYELLOW << "      cout << \"Hello World\";\n" << RESET;
            cout << BYELLOW << "      return 0;\n" << RESET;
            cout << BYELLOW << "  }\n\n" << RESET;
            cout << BYELLOW << "  DATA TYPES\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  int    : integer (4 bytes)\n" << RESET;
            cout << BYELLOW << "  double : decimal number\n" << RESET;
            cout << BYELLOW << "  char   : single character\n" << RESET;
            cout << BYELLOW << "  string : text\n" << RESET;
            cout << BYELLOW << "  bool   : true / false\n\n" << RESET;
            cout << BYELLOW << "  CONTROL STRUCTURES\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  if / else if / else\n" << RESET;
            cout << BYELLOW << "  for (int i=0; i<n; i++)\n" << RESET;
            cout << BYELLOW << "  while (condition)\n" << RESET;
            cout << BYELLOW << "  do { ... } while (condition);\n\n" << RESET;
            cout << BYELLOW << "  COMMENTS\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  // Single-line comment\n" << RESET;
            cout << BYELLOW << "  /* Multi-line comment */\n\n" << RESET;
            cout << BYELLOW << "  CLASSES\n" << RESET;
            cout << BBLUE << "  ==============================\n" << RESET;
            cout << BYELLOW << "  class MyClass {\n" << RESET;
            cout << BYELLOW << "  public:\n" << RESET;
            cout << BYELLOW << "      int x;\n" << RESET;
            cout << BYELLOW << "  };\n" << RESET;
            cout << BYELLOW << "  Pointer member access: ptr->member\n" << RESET;
            pauseScreen();
        }

    } while (subChoice != 7);
}


// ════════════════════════════════════════════════════════════════════
//  EXERCISES
// ════════════════════════════════════════════════════════════════════

// Shows practice questions for each subject.
void showExercises()
{
    int subChoice;
    do
    {
        system("cls");
        cout << BBLUE << "==============================\n" << RESET;
        cout << BWHITE << "          EXERCISES           \n" << RESET;
        cout << BBLUE << "==============================\n\n" << RESET;
        cout << BRED << "  1. Mathematics\n" << RESET;
        cout << BYELLOW << "  2. English\n" << RESET;
        cout << BGREEN << "  3. Chemistry\n" << RESET;
        cout << BMAGENTA << "  4. Biology\n" << RESET;
        cout << BCYAN << "  5. Physics\n" << RESET;
        cout << RED << "  6. C++ Programming\n" << RESET;
        cout << YELLOW << "  7. Back\n\n" << RESET;
        cout << GREEN << "  Choice: " << RESET;
        cin >> subChoice;

        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); continue; }
        if (subChoice < 1 || subChoice > 7) continue;
        if (subChoice == 7) break;

        vector<pair<string, string>> exercises;

        if (subChoice == 1)
        {
            exercises.push_back({ "What is 8 * 7?",                  "56" });
            exercises.push_back({ "What is 15 - 6?",                 "9" });
            exercises.push_back({ "Square root of 25?",              "5" });
            exercises.push_back({ "What is 100 / 4?",                "25" });
            exercises.push_back({ "What is 3^3?",                    "27" });
        }
        else if (subChoice == 2)
        {
            exercises.push_back({ "Past tense of 'go'?",             "went" });
            exercises.push_back({ "Plural of 'child'?",              "children" });
            exercises.push_back({ "Synonym of 'big'?",               "large" });
            exercises.push_back({ "Antonym of 'hot'?",               "cold" });
            exercises.push_back({ "Past tense of 'eat'?",            "ate" });
        }
        else if (subChoice == 3)
        {
            exercises.push_back({ "Chemical formula of water?",      "H2O" });
            exercises.push_back({ "Chemical formula of salt?",       "NaCl" });
            exercises.push_back({ "What is the pH of pure water?",   "7" });
            exercises.push_back({ "What gas do plants produce?",     "O2" });
            exercises.push_back({ "Chemical formula of ammonia?",    "NH3" });
        }
        else if (subChoice == 4)
        {
            exercises.push_back({ "What is the basic unit of life?",           "cell" });
            exercises.push_back({ "How many chambers does the heart have?",    "4" });
            exercises.push_back({ "How many bones in the adult human body?",   "206" });
            exercises.push_back({ "What is the powerhouse of the cell?",       "mitochondria" });
            exercises.push_back({ "How many chromosomes do human cells have?", "46" });
        }
        else if (subChoice == 5)
        {
            exercises.push_back({ "What is the unit of force?",               "newton" });
            exercises.push_back({ "What is the speed of light? (km/s)",       "300000" });
            exercises.push_back({ "What is the unit of electric current?",    "ampere" });
            exercises.push_back({ "What is the boiling point of water? (C)",  "100" });
            exercises.push_back({ "What is the unit of power?",               "watt" });
        }
        else if (subChoice == 6)
        {
            exercises.push_back({ "Which function starts a C++ program?",        "main" });
            exercises.push_back({ "Which header is needed for cout?",            "iostream" });
            exercises.push_back({ "What symbol starts a single-line comment?",   "//" });
            exercises.push_back({ "What keyword defines a class in C++?",        "class" });
            exercises.push_back({ "What operator accesses a member via pointer?","->" });
        }

        int  correct = 0;
        bool exitedEarly = false;

        for (int i = 0; i < (int)exercises.size(); i++)
        {
            system("cls");
            string question = exercises[i].first;
            string answer = exercises[i].second;

            cout << BBLUE << "==============================\n" << RESET;
            cout << BYELLOW << "  Exercise " << (i + 1) << " of " << exercises.size() << "\n" << RESET;
            cout << BBLUE << "==============================\n\n" << RESET;
            cout << BYELLOW << "  " << question << "\n\n" << RESET;
            cout << BRED << "  Type '0' to go back to the menu.\n\n" << RESET;
            cout << BGREEN << "  Answer: " << RESET;

            string userAnswer;
            cin >> userAnswer;

            if (userAnswer == "0") { exitedEarly = true; break; }

            string ua = userAnswer, ans = answer;
            for (char& c : ua)  c = (char)tolower((unsigned char)c);
            for (char& c : ans) c = (char)tolower((unsigned char)c);

            system("cls");
            if (ua == ans)
            {
                cout << BGREEN << "\n  *** CORRECT! ***\n" << RESET;
                correct++;
            }
            else
            {
                cout << BRED << "\n  --- WRONG! The correct answer is: " << answer << " ---\n" << RESET;
            }
            cout << BYELLOW << "\n  Score: " << correct << "/" << (i + 1) << "\n" << RESET;
            cout << "\n  Press ENTER for the next exercise...";
            cin.ignore();
            cin.get();
        }

        if (exitedEarly) continue;

        system("cls");
        cout << BBLUE << "==============================\n" << RESET;
        cout << CYAN << "       EXERCISE RESULT        \n" << RESET;
        cout << BBLUE << "==============================\n\n" << RESET;
        cout << BGREEN << "  Correct answers: " << correct << " of " << (int)exercises.size() << "\n" << RESET;
        double pct = ((double)correct / (double)exercises.size()) * 100.0;
        cout << BCYAN << "  Percentage: " << fixed << setprecision(1) << pct << "%\n\n" << RESET;

        if (pct == 100.0) cout << BGREEN << "  Excellent! Perfect score!\n" << RESET;
        else if (pct >= 60)    cout << BYELLOW << "  Good job! Keep studying!\n" << RESET;
        else                   cout << BRED << "  Review the study materials and try again!\n" << RESET;

        pauseScreen();

    } while (subChoice != 7);
}


// ════════════════════════════════════════════════════════════════════
//  START TEST
// ════════════════════════════════════════════════════════════════════

// Starts the main test and saves the result.
void startTest()
{
    system("cls");
    cout << BBLUE << "==============================\n" << RESET;
    cout << BWHITE << "          TAKE A TEST         \n" << RESET;
    cout << BBLUE << "==============================\n\n" << RESET;

    string name;
    cout << MAGENTA << "  Enter your name: " << RESET;
    cin.ignore();
    getline(cin, name);
    if (name.empty()) name = "Student";

    system("cls");
    cout << BBLUE << "==============================\n" << RESET;
    cout << MAGENTA << "  Hello, " << name << "!\n" << RESET;
    cout << BBLUE << "==============================\n\n" << RESET;
    cout << RED << "  The test contains 20 questions.\n" << RESET;
    cout << RED << "  Answer with A, B, C or D.\n" << RESET;
    cout << BRED << "  Type '0' at any question to quit the test.\n" << RESET;
    cout << GREEN << "  Good luck!\n\n" << RESET;
    cout << GREEN << "  Press ENTER to start..." << RESET;
    cin.get();

    Test test;
    test.loadQuestions();
    test.generateTest();

    int score = test.startTest();

    if (score == -1)
    {
        system("cls");
        cout << BBLUE << "==============================\n" << RESET;
        cout << BYELLOW << "     TEST CANCELLED           \n" << RESET;
        cout << BBLUE << "==============================\n\n" << RESET;
        cout << BRED << "  You exited the test early.\n" << RESET;
        cout << BRED << "  No result has been saved.\n\n" << RESET;
        pauseScreen();
        return;
    }

    int    maxScore = test.getMaxScore();
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
    cout << BBLUE << "==============================\n" << RESET;
    cout << BYELLOW << "           RESULT             \n" << RESET;
    cout << BBLUE << "==============================\n\n" << RESET;
    cout << CYAN << "  Student    : " << name << "\n" << RESET;
    cout << CYAN << "  Points     : " << score << " / " << maxScore << "\n" << RESET;
    cout << CYAN << "  Percentage : " << fixed << setprecision(1) << percent << "%\n" << RESET;
    cout << CYAN << "  Grade      : " << grade << "  " << stars << "\n\n" << RESET;

    if (grade == 6) cout << BGREEN << "  Excellent result! Well done!\n" << RESET;
    else if (grade == 5) cout << BYELLOW << "  Very good! Keep it up!\n" << RESET;
    else if (grade == 4) cout << BYELLOW << "  Good! You can do better!\n" << RESET;
    else if (grade == 3) cout << BRED << "  Poor. Review the material!\n" << RESET;
    else                 cout << BRED << "  Insufficient. Study more!\n" << RESET;

    allNames.push_back(name);
    allScores.push_back(score);
    allGrades.push_back(grade);
    allMaxScores.push_back(maxScore);

    pauseScreen();
}


// ════════════════════════════════════════════════════════════════════
//  STATISTICS
// ════════════════════════════════════════════════════════════════════

// Shows saved test statistics.
void showStatistics()
{
    system("cls");
    cout << BBLUE << "==============================\n" << RESET;
    cout << BWHITE << "         STATISTICS           \n" << RESET;
    cout << BBLUE << "==============================\n\n" << RESET;

    if (allScores.empty())
    {
        cout << BRED << "  No data yet! Take at least one test.\n" << RESET;
        pauseScreen();
        return;
    }

    int maxS = allScores[0], minS = allScores[0], sum = 0, bestIndex = 0;
    for (int i = 0; i < (int)allScores.size(); i++)
    {
        if (allScores[i] > maxS) { maxS = allScores[i]; bestIndex = i; }
        if (allScores[i] < minS)   minS = allScores[i];
        sum += allScores[i];
    }
    double avg = (double)sum / (double)allScores.size();

    cout << BLUE << "  Tests taken        : " << (int)allScores.size() << "\n" << RESET;
    cout << GREEN << "  Highest score      : " << maxS << "  (" << allNames[bestIndex] << ")\n" << RESET;
    cout << RED << "  Lowest score       : " << minS << "\n" << RESET;
    cout << YELLOW << "  Average score      : " << fixed << setprecision(1) << avg << "\n\n" << RESET;

    cout << BYELLOW << "  Grade distribution:\n" << RESET;
    int g2 = 0, g3 = 0, g4 = 0, g5 = 0, g6 = 0;
    for (int g : allGrades)
    {
        if (g == 2) g2++;
        else if (g == 3) g3++;
        else if (g == 4) g4++;
        else if (g == 5) g5++;
        else if (g == 6) g6++;
    }
    cout << BCYAN << "  Grade 6: " << g6 << "\n" << RESET;
    cout << BLUE << "  Grade 5: " << g5 << "\n" << RESET;
    cout << GREEN << "  Grade 4: " << g4 << "\n" << RESET;
    cout << YELLOW << "  Grade 3: " << g3 << "\n" << RESET;
    cout << BRED << "  Grade 2: " << g2 << "\n\n" << RESET;

    cout << BYELLOW << "  All results:\n" << RESET;
    for (int i = 0; i < (int)allNames.size(); i++)
    {
        double pct = (allMaxScores[i] > 0)
            ? ((double)allScores[i] / (double)allMaxScores[i]) * 100.0 : 0.0;
        cout << "  " << setw(2) << (i + 1) << ". "
            << left << setw(15) << allNames[i]
            << right << setw(4) << allScores[i]
            << YELLOW << "/" << allMaxScores[i]
            << "  (" << fixed << setprecision(0) << pct << "%)"
            << BGREEN << "  Grade: " << allGrades[i] << "\n" << RESET;
    }

    pauseScreen();
}


// ════════════════════════════════════════════════════════════════════
//  HOMEWORK
//  - View assigned homework
//  - Add new homework entry
//  - Mark homework as done
//  - Saved to homework.txt
// ════════════════════════════════════════════════════════════════════

// Stores one homework or classwork item.
struct Assignment
{
    string subject;
    string description;
    string dueDate;     // e.g. "2024-06-10"
    bool   done;
};

// Loads assignments from a text file.
vector<Assignment> loadAssignments(const string& filename)
{
    vector<Assignment> list;
    ifstream file(filename);
    if (!file.is_open()) return list;

    string line;
    while (getline(file, line))
    {
        if (line.empty()) continue;
        // Format: SUBJECT|DESCRIPTION|DUEDATE|DONE(0/1)
        Assignment a;
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        if (p1 == string::npos || p2 == string::npos || p3 == string::npos) continue;
        a.subject = line.substr(0, p1);
        a.description = line.substr(p1 + 1, p2 - p1 - 1);
        a.dueDate = line.substr(p2 + 1, p3 - p2 - 1);
        a.done = (line.substr(p3 + 1) == "1");
        list.push_back(a);
    }
    file.close();
    return list;
}

// Saves assignments to a text file.
void saveAssignments(const string& filename, const vector<Assignment>& list)
{
    ofstream file(filename);
    for (const Assignment& a : list)
        file << a.subject << "|" << a.description << "|"
        << a.dueDate << "|" << (a.done ? "1" : "0") << "\n";
    file.close();
}

// Manages homework or classwork entries.
void manageAssignments(const string& title, const string& color,
    const string& filename)
{
    int choice;
    do
    {
        vector<Assignment> list = loadAssignments(filename);

        system("cls");
        cout << BBLUE << "==============================\n" << RESET;
        cout << color << "  " << title << "\n" << RESET;
        cout << BBLUE << "==============================\n\n" << RESET;

        // Shows all saved entries.
        if (list.empty())
            cout << BYELLOW << "  No entries yet.\n\n" << RESET;
        else
        {
            for (int i = 0; i < (int)list.size(); i++)
            {
                string status = list[i].done
                    ? (BGREEN + string("[DONE]  ") + RESET)
                    : (BRED + string("[TODO]  ") + RESET);
                cout << status
                    << BYELLOW << (i + 1) << ". " << RESET
                    << BWHITE << list[i].subject << RESET
                    << " - " << list[i].description
                    << CYAN << "  (Due: " << list[i].dueDate << ")\n" << RESET;
            }
            cout << "\n";
        }

        // Shows the assignment menu.
        cout << BGREEN << "  1. Add new entry\n" << RESET;
        cout << BYELLOW << "  2. Mark as done\n" << RESET;
        cout << BRED << "  3. Delete entry\n" << RESET;
        cout << BWHITE << "  4. Back\n\n" << RESET;
        cout << BCYAN << "  Choice: " << RESET;
        cin >> choice;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); continue; }

        // Adds a new assignment.
        if (choice == 1)
        {
            Assignment a;
            a.done = false;
            cin.ignore();
            system("cls");
            cout << BBLUE << "==============================\n" << RESET;
            cout << color << "  ADD ENTRY\n" << RESET;
            cout << BBLUE << "==============================\n\n" << RESET;

            cout << BCYAN << "  Subject     : " << RESET; getline(cin, a.subject);
            cout << BCYAN << "  Description : " << RESET; getline(cin, a.description);
            cout << BCYAN << "  Due date    : " << RESET; getline(cin, a.dueDate);

            if (a.subject.empty()) a.subject = "General";
            if (a.dueDate.empty()) a.dueDate = "No date";

            list.push_back(a);
            saveAssignments(filename, list);
            cout << BGREEN << "\n  Entry added!\n" << RESET;
            cout << "\n  Press ENTER..."; cin.get();
        }
        // Marks an assignment as done.
        else if (choice == 2)
        {
            if (list.empty()) { cout << BRED << "\n  Nothing to mark.\n" << RESET; cin.ignore(); cin.get(); continue; }
            cout << BCYAN << "\n  Enter number to mark as done (0 to cancel): " << RESET;
            int n; cin >> n;
            if (n >= 1 && n <= (int)list.size())
            {
                list[n - 1].done = true;
                saveAssignments(filename, list);
                cout << BGREEN << "  Marked as done!\n" << RESET;
            }
            cout << "\n  Press ENTER..."; cin.ignore(); cin.get();
        }
        // Deletes an assignment.
        else if (choice == 3)
        {
            if (list.empty()) { cout << BRED << "\n  Nothing to delete.\n" << RESET; cin.ignore(); cin.get(); continue; }
            cout << BCYAN << "\n  Enter number to delete (0 to cancel): " << RESET;
            int n; cin >> n;
            if (n >= 1 && n <= (int)list.size())
            {
                list.erase(list.begin() + (n - 1));
                saveAssignments(filename, list);
                cout << BRED << "  Entry deleted!\n" << RESET;
            }
            cout << "\n  Press ENTER..."; cin.ignore(); cin.get();
        }

    } while (choice != 4);
}

// Opens the homework manager.
void showHomework()
{
    manageAssignments("HOMEWORK", BMAGENTA, "homework.txt");
}

// Opens the classwork manager.
void showClasswork()
{
    manageAssignments("CLASSWORK", BCYAN, "classwork.txt");
}


#endif