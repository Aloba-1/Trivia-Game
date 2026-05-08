//
//  main.cpp
//  TriviaGame
//
//  Created by AKE<3
//
#include "question.h"
#include "player.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string FILENAME = "resources/questions.txt";

int main()
{
    const int NUM_QUESTIONS = 10;

    Question questions[NUM_QUESTIONS];

    Player player1;
    Player player2;

    char name[50];
    int answer;

    cout << "Enter Player 1 name: ";
    cin.getline(name, 50);
    player1.SetName(name);
    player1.SetScore(0);

    cout << "Enter Player 2 name: ";
    cin.getline(name, 50);
    player2.SetName(name);
    player2.SetScore(0);

    ifstream inputFile;
    inputFile.open(FILENAME);

    if (!inputFile)
    {
        cout << "Error opening questions.txt" << endl;
        return 1;
    }

    string questionText;
    string answerText;
    int correctAnswer;

    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        getline(inputFile, questionText);
        questions[i].SetQuestion(questionText);

        for (int j = 1; j <= 4; j++)
        {
            getline(inputFile, answerText);
            questions[i].SetAnswer(j, answerText);
        }

        inputFile >> correctAnswer;
        inputFile.ignore();

        questions[i].SetCorrectAnswer(correctAnswer);
    }

    inputFile.close();

    cout << endl;
    cout << "Player 1's Turn: " << player1.GetName() << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << endl;
        cout << questions[i].GetQuestion() << endl;

        for (int j = 1; j <= 4; j++)
        {
            cout << j << ". " << questions[i].GetAnswer(j) << endl;
        }

        cout << "Enter your answer: ";
        cin >> answer;

        if (answer == questions[i].GetCorrectAnswer())
        {
            cout << "Correct!" << endl;
            player1.IncrementScore();
        }
        else
        {
            cout << "Incorrect." << endl;
        }
    }

    cout << endl;
    cout << "Player 2's Turn: " << player2.GetName() << endl;

    for (int i = 5; i < NUM_QUESTIONS; i++)
    {
        cout << endl;
        cout << questions[i].GetQuestion() << endl;

        for (int j = 1; j <= 4; j++)
        {
            cout << j << ". " << questions[i].GetAnswer(j) << endl;
        }

        cout << "Enter your answer: ";
        cin >> answer;

        if (answer == questions[i].GetCorrectAnswer())
        {
            cout << "Correct!" << endl;
            player2.IncrementScore();
        }
        else
        {
            cout << "Incorrect." << endl;
        }
    }

    ofstream outFile;
    outFile.open("players.dat", ios::binary);

    if (!outFile)
    {
        cout << "Error opening players.dat" << endl;
        return 1;
    }

    player1.WriteToFile(outFile);
    player2.WriteToFile(outFile);

    outFile.close();

    cout << endl;
    cout << "Game Results" << endl;
    cout << "------------" << endl;
    cout << player1.GetName() << " scored " << player1.GetScore() << " points." << endl;
    cout << player2.GetName() << " scored " << player2.GetScore() << " points." << endl;

    if (player1.GetScore() > player2.GetScore())
    {
        cout << player1.GetName() << " wins!" << endl;
    }
    else if (player2.GetScore() > player1.GetScore())
    {
        cout << player2.GetName() << " wins!" << endl;
    }
    else
    {
        cout <<"The game is a tie!"<< endl;
    }

    return 0;
}
