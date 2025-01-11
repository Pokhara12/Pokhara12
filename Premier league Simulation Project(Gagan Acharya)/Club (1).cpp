#include <iostream>
#include "main.h"
#include "Club.h"
#include "string.h"
#include <cstdlib>
#include <ctime>
using namespace std;

extern Club club;

int Club::getCode()
{
  return code;
}

string Club::getCodename()
{
  return codeName;
}

string Club::getName()
{
  return name;
}

int Club::getStrength()
{
  return strength;
}

void Club::setCode(int c)
{
  code = c;
}

int Club::getScore()
{
  int ret = strength;
  int score = (rand() % ret + 1);
  return score;
}

void Club::updateWins()
{
  wins++;
  points = points + 3;
}

void Club::updateLosses()
{
  losses++;
}

void Club::updateDraws()
{
  draws++;
  points = points + 1;
}

void Club::updateRounds()
{
  rounds++;
}

void Club::updateGoals(int score1, int score2)
{
  goalsScored = score1;
  goalsConceded = score2;
}

int Club::getPoints()
{
  return points;
}

void Club::display()
{
  std::cout << codeName << "\t" << rounds << "\t" << wins << "\t" << draws << "\t" << losses << "\t" << goalsScored << ":" << goalsConceded << "\t" << (goalsScored - goalsConceded) << "\t" << points << std::endl;
}

int Club::goalDiff()
{
  int goaldiff = goalsScored - goalsConceded;
  return goaldiff;
}

void Club::addRecord(int rGoalsscored, int rGoalsconceded, std::string rOpponent, int rRound)
{
  Record r(rGoalsscored, rGoalsconceded, rOpponent, rRound);
  records.push_back(r);
}

void Club::printRecords(int rs, int re)
{
  for (int i = 0; i < records.size(); i++)
  {
    if (((records[i].rRound) >= rs) && ((records[i].rRound) <= re))
    {
      std::cout << "Round:" << records[i].rRound << codeName << "  " << records[i].rGoalsscored << " - " << records[i].rGoalsconceded << " - " << records[i].rOpponent << std::endl;
    }
  }
}
