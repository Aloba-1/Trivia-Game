//
//  question.cpp
//  TriviaGame
//
//  Created by AKE<3
//
#include "Question.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

Question::Question()
{
    string nullstring="";
    strcpy(question, nullstring.c_str());
    for (int k=0; k<4; k++)
        strcpy(answers[k], nullstring.c_str());
    correctAnswer=0;
}

Question::Question(string FILENAME)
{
    ifstream inputFile;
    inputFile.open(FILENAME);
    string s_line;
    int i_lineNum=0;
    while (getline(inputFile, s_line) && i_lineNum<6)
    {
        switch(i_lineNum%6)
        {
        case 0:
            //strcpy(question, s_line.c_str());
            SetQuestion(s_line);
            break;
        case 1:
            //strcpy(answers[0], s_line.c_str());
            SetAnswer(1, s_line);
            break;
        case 2:
            //strcpy(answers[1], s_line.c_str());
            SetAnswer(2, s_line);
            break;
        case 3:
            //strcpy(answers[2], s_line.c_str());
            SetAnswer(3, s_line);
            break;
        case 4:
            //strcpy(answers[3], s_line.c_str());
            SetAnswer(4, s_line);
            break;
        case 5:
            correctAnswer=stoi(s_line);
            break;
        default:
            cout<<"Incomplete record"<<endl;
        }
        i_lineNum++;
    }
    inputFile.close();
}

void Question::SetQuestion(string q)
{
    strcpy(question, q.c_str());
}

string Question::GetQuestion()
{
return (string )question;
}

void Question::SetAnswer(int num, string ans)
{
    strcpy(answers[num-1], ans.c_str());
}

string Question::GetAnswer(int num)
{
return (string )answers[num-1];
}

void Question::SetCorrectAnswer(int num)
{
    correctAnswer=num;
}

int Question::GetCorrectAnswer()
{
return correctAnswer;
}

void Question::Print(void)
{
    cout<<GetQuestion()<<endl;
    for (int k=0; k<4; k++)
        cout<<GetAnswer(k+1)<<endl;
    cout<<GetCorrectAnswer()<<endl;
}
