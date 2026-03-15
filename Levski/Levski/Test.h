#pragma once
#ifndef TEST_H
#define TEST_H

#include <vector>
#include "Question.h"

using namespace std;

class Test
{
private:

    vector<Question> questionBank;
    vector<Question> testQuestions;

public:

    void loadQuestions();
    void generateTest();
    int startTest();

};

#endif