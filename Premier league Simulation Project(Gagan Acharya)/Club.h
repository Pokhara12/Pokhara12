#ifndef CLUB_H_
#define CLUB_H_

#include <iostream>
#include "string.h"
#include "main.h"
#include <vector>
// #include "fixtures.h"
class Record
{
    public:
    Record()
    {
        rGoalsscored = 0;
        rGoalsconceded = 0;
        rRound = 0;
    }
    Record(int rGoalsscored, int rGoalsconceded, std::string rOpponent, int rRound)
    {
        this -> rGoalsscored = rGoalsscored;
        this -> rGoalsconceded = rGoalsconceded;
        this -> rOpponent = rOpponent;
        this -> rRound = rRound;
    }

    ~Record(){};
    int rGoalsscored;
    int rGoalsconceded;
    std::string rOpponent;
    int rRound;


    private:

};


class Club
{
public:
    Club()
    {
        rounds = 0;
        wins = 0;
        draws = 0;
        losses = 0;
        goals = 0;
        goalsConceded = 0;
        goalsConceded = 0;
        goalsScored = 0;
        points = 0;
    };
    Club(int code, std::string codeName, std::string name, int strength)
    {
        this->code = code;
        this->codeName = codeName;
        this->name = name;
        this->strength = strength;
        rounds = 0;
        wins = 0;
        draws = 0;
        losses = 0;
        goals = 0;
        goalsConceded = 0;
        goalsConceded = 0;
        goalsScored = 0;
        points = 0;
    }

    ~Club(){};

    int check(int n);
    int getCode();
    std::string getCodename();
    std::string getName();
    int getStrength();
    int getScore();
    void updateWins();
    void updateLosses();
    void updateDraws();
    int getPoints();
    void updateRounds();
    void updateGoals(int, int);
    int operator>=(Club c)
    {
        if (points > c.getPoints())
        {
            return 1;
        }
        else if (points == c.getPoints())
        {
            if (goalDiff() > c.goalDiff())
            {
                return 1;
            }
            else
                return 0;
        }
        return 0;
    }
    void display();
    int goalDiff();
    void addRecord(int, int, std::string, int);
    void printRecords(int, int);

    void setCode(int);
    void setName();
    void setCodename();
    int getLeagueRounds(int, int);

    int getRound(int);
    int getWins();
    int getDraws();
    int getLosses();
    int getGoalsconceded();

private:
    int code;
    std::string codeName;
    std::string name;
    int strength;
    int rounds;
    int wins;
    int draws;
    int goals;
    int points;
    int losses;
    int goalsScored;
    int goalsConceded;
    std::vector <Record> records;
};


#endif
