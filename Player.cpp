//
//  Player.cpp
//  TriviaGame
//
//  Created by AKE<3 on 5/4/26.
//
#include "player.h"
#include <cstring>

Player::Player()
{
    strcpy(name, "");
    score = 0;
}

void Player::SetName(const char playerName[])
{
    strcpy(name, playerName);
}

char* Player::GetName()
{
    return name;
}

void Player::SetScore(int s)
{
    score = s;
}

int Player::GetScore()
{
    return score;
}

void Player::IncrementScore()
{
    score++;
}

void Player::WriteToFile(ofstream& outFile)
{
    outFile.write(reinterpret_cast<char*>(this), sizeof(Player));
}

void Player::ReadFromFile(ifstream& inFile)
{
    inFile.read(reinterpret_cast<char*>(this), sizeof(Player));
}

