//
//  question.h
//  TriviaGame
//
//  Created by AKE<3
//
#ifndef QUESTION_H
#define QUESTION_H

#include <string>

using namespace std;

class Question
{
private:
    char question[100];
    char answers[4][50];
    int correctAnswer;
public:
    Question(void);
    Question(string);
    void SetQuestion(string);
    string GetQuestion(void);
    void SetAnswer(int, string);
    string GetAnswer(int);
    void SetCorrectAnswer(int);
    int GetCorrectAnswer(void);
    void Print(void);
};

#endif

