//
//  Player.h
//  TriviaGame
//
//  Created by AKE<3 
//
#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
using namespace std;

class Player
{
private:
    char name[50];
    int score;

public:
    Player();

    void SetName(const char playerName[]);
    char* GetName();

    void SetScore(int s);
    int GetScore();

    void IncrementScore();

    void WriteToFile(ofstream& outFile);
    void ReadFromFile(ifstream& inFile);
};
#endif

