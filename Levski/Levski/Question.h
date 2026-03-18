#pragma once
#ifndef QUESTION_H
#define QUESTION_H
//question.h
#include <vector>
#include <iostream>
#include <string>
using namespace std;

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
