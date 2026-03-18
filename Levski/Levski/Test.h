#pragma once
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include "Question.h"

using namespace std;

class Test
{
private:
    vector<Question> questionBank;
    vector<Question> testQuestions;

public:

    void loadQuestions()
    {
        ifstream file("questions.txt");

        if (!file.is_open())
        {
            cout << "  [ERROR] File questions.txt not found!\n";
            cout << "  Make sure the file is in the program folder.\n";
            system("pause");
            return;
        }

        string line;
        Question q;
        bool inQuestion = false;

        while (getline(file, line))
        {
            if (line.empty()) continue;

            if (line.find("QUESTION: ") == 0)
            {
                q = Question();
                q.text = line.substr(10);
                inQuestion = true;
            }
            else if (inQuestion && line.find("CATEGORY: ") == 0)
                q.category = line.substr(10);
            else if (inQuestion && line.find("A: ") == 0)
                q.optionA = line.substr(3);
            else if (inQuestion && line.find("B: ") == 0)
                q.optionB = line.substr(3);
            else if (inQuestion && line.find("C: ") == 0)
                q.optionC = line.substr(3);
            else if (inQuestion && line.find("D: ") == 0)
                q.optionD = line.substr(3);
            else if (inQuestion && line.find("ANSWER: ") == 0)
                q.correctAnswer = toupper(line.substr(8)[0]);
            else if (inQuestion && line.find("POINTS: ") == 0)
            {
                q.points = stoi(line.substr(8));
                questionBank.push_back(q);
                inQuestion = false;
            }
        }

        file.close();
    }

    void generateTest()
    {
        srand((unsigned int)time(0));
        random_shuffle(questionBank.begin(), questionBank.end());
        testQuestions.clear();

        int count = (questionBank.size() < 20) ? (int)questionBank.size() : 20;
        for (int i = 0; i < count; i++)
            testQuestions.push_back(questionBank[i]);
    }

    int startTest()
    {
        int score = 0;
        int total = (int)testQuestions.size();

        for (int i = 0; i < total; i++)
        {
            system("cls");

            // Progress bar
            cout << "\n  [";
            int filled = (int)(((double)i / total) * 20);
            for (int p = 0; p < 20; p++)
                cout << (p < filled ? "=" : " ");
            cout << "]  " << i << "/" << total << " questions\n\n";

            testQuestions[i].displayQuestion(i + 1, total);

            char answer;
            cout << "  Your answer (A/B/C/D): ";
            cin >> answer;
            answer = toupper(answer);

            while (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D')
            {
                cout << "  Invalid input! Enter A, B, C or D: ";
                cin >> answer;
                answer = toupper(answer);
            }

            system("cls");

            if (answer == testQuestions[i].correctAnswer)
            {
                cout << "\n  *** CORRECT! +" << testQuestions[i].points << " points ***\n";
                score += testQuestions[i].points;
            }
            else
            {
                cout << "\n  --- WRONG! Correct answer: " << testQuestions[i].correctAnswer << " ---\n";
            }

            cout << "\n  Current score: " << score << " points\n";
            cout << "\n  Press ENTER for the next question...";
            cin.ignore();
            cin.get();
        }

        return score;
    }

    int getMaxScore()
    {
        int total = 0;
        for (int i = 0; i < (int)testQuestions.size(); i++)
            total += testQuestions[i].points;
        return total;
    }

    int getQuestionCount()
    {
        return (int)testQuestions.size();
    }
};

#endif
