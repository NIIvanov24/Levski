#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question
{
public:

    string text;
    string category;

    string optionA;
    string optionB;
    string optionC;
    string optionD;

    char correctAnswer;

    int points;

    void displayQuestion();
};

#endif