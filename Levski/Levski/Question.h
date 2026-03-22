#pragma once
#ifndef QUESTION_H
#define QUESTION_H
//question.h
#include <vector>
#include <iostream>
#include <string>
using namespace std;
//Basic colors for regular text
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

//More bright colors for headings and important info
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"
class Question
{
public:
    string text, category;
    string optionA, optionB, optionC, optionD;
    char correctAnswer;
    int points;

    Question() {}

    Question(string t, string c, string a, string b, string c1, string d, char ans, int p)
    {
        text = t;
        category = c;
        optionA = a;
        optionB = b;
        optionC = c1;
        optionD = d;
        correctAnswer = ans;
        points = p;
    }

    void displayQuestion(int current, int total)
    {
        cout << "==============================\n";
        cout << "  Question " << current << " of " << total << "\n";
        cout << "  Category: " << category << "  |  Points: " << points << "\n";
        cout << "==============================\n\n";
        cout << text << "\n\n";
        cout << "  A) " << optionA << "\n";
        cout << "  B) " << optionB << "\n";
        cout << "  C) " << optionC << "\n";
        cout << "  D) " << optionD << "\n";
        cout << "\n------------------------------\n";
    }
};

#endif
