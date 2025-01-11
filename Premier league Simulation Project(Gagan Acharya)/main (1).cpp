#include "main.h"
#include "Club.h"
#include <iostream>
#include <ctime>
std::string code[20] = {"ARS", "AST", "BHA", "BOU", "BUR", "CHE", "EVE", "LEI", "LIV", "MNC",
                        "MNU", "NEW", "NOR", "PAL", "SHU", "SOT", "TOT", "WAT", "WHU", "WOL"};
std::string name[20] = {"Arsenal            ", "Aston Villa     ", "Brighton        ", "Bournemouth     ", "Burnley         ", "Chelsea         ",
                        "Everton            ", "Leicester City  ", "Liverpool       ", "Manchester City     ", "Manchester United",
                        "Newcastle United", "Norwich City       ", "Crystal Palace  ", "Sheffield United", "Southampton     ",
                        "Tottenham Hotspur", "Watford           ", "West Ham United     ", "Wolverhampton Wanderers"};
int strength[20] = {6, 4, 2, 4, 4, 6, 5, 5, 6, 7, 6, 4, 3, 4, 3, 4, 6, 3, 4, 2};
int leagueRounds[20][20] =
    {0, 1, 21, 3, 23, 5, 25, 7, 27, 9, 29, 11, 31, 13, 33, 15, 35, 17, 37, 19,
     20, 0, 3, 23, 5, 25, 7, 27, 9, 29, 11, 31, 13, 33, 15, 35, 17, 37, 19, 21,
     2, 22, 0, 5, 25, 7, 27, 9, 29, 11, 31, 13, 33, 15, 35, 17, 37, 19, 20, 4,
     22, 4, 24, 0, 7, 27, 9, 29, 11, 31, 13, 33, 15, 35, 17, 37, 19, 20, 2, 25,
     4, 24, 6, 26, 0, 9, 29, 11, 31, 13, 33, 15, 35, 17, 347, 19, 20, 2, 22, 8,
     24, 6, 26, 8, 28, 0, 11, 31, 13, 33, 15, 35, 17, 37, 19, 20, 2, 22, 4, 29,
     6, 26, 8, 28, 10, 30, 0, 13, 33, 15, 35, 17, 37, 19, 20, 2, 22, 4, 24, 12,
     26, 8, 28, 10, 30, 12, 32, 0, 15, 35, 17, 37, 19, 20, 2, 22, 4, 24, 6, 33,
     8, 28, 10, 30, 12, 32, 14, 34, 0, 17, 37, 19, 20, 2, 22, 4, 24, 6, 26, 16,
     28, 10, 30, 12, 32, 14, 34, 16, 36, 0, 19, 20, 2, 22, 4, 24, 6, 26, 8, 37,
     10, 30, 12, 32, 14, 34, 16, 36, 18, 38, 0, 2, 22, 4, 24, 6, 26, 8, 28, 1,
     30, 12, 32, 14, 34, 16, 36, 18, 38, 1, 21, 0, 4, 24, 6, 26, 8, 28, 10, 22,
     12, 32, 14, 34, 16, 36, 18, 38, 1, 21, 3, 23, 0, 6, 26, 8, 28, 10, 30, 5,
     32, 14, 34, 16, 36, 18, 38, 1, 21, 3, 23, 5, 25, 0, 8, 28, 10, 30, 12, 26,
     14, 34, 16, 36, 18, 38, 1, 21, 3, 23, 5, 25, 7, 27, 0, 10, 30, 12, 32, 9,
     34, 16, 36, 18, 38, 1, 21, 3, 23, 5, 25, 7, 27, 9, 29, 0, 12, 32, 14, 30,
     16, 36, 18, 38, 1, 21, 3, 23, 5, 25, 7, 27, 9, 29, 11, 31, 0, 14, 34, 13,
     36, 18, 38, 1, 21, 3, 23, 5, 25, 7, 27, 9, 29, 11, 31, 13, 33, 0, 16, 34,
     18, 38, 1, 21, 3, 23, 5, 25, 7, 27, 9, 29, 11, 31, 13, 33, 15, 35, 0, 17,
     38, 2, 23, 6, 27, 10, 31, 14, 35, 18, 20, 3, 24, 7, 28, 11, 32, 15, 36, 0};

int main()
{
    srand(time(0));
    Club club[20];

    for (int i = 0; i < 20; i++)
    {
        club[i] = Club(i, code[i], name[i], strength[i]);
    }
    while (1)
    {
        int choice = MainMenu();
        switch (choice)
        {
        case 1:
            Clublist(club);
            break;
        case 2:
            Fixtures(club);
            break;
        case 3:
            NextRound(club);
            break;
        case 4:
            TeamStanding(club);
            break;
        case 5:
            CurrentStanding(club);
            break;
        case 6:
            return 0;
        default:
            std::cout << "Please select between 1 to 6" << std::endl;
        }
    }
    return 0;
}

int MainMenu()
{
    int choice;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "        LEAGUE MENU             " << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1) Clubs" << std::endl;
    std::cout << "2) Fixtures" << std::endl;
    std::cout << "3) Simulate Next Round" << std::endl;
    std::cout << "4) Results - Single Club" << std::endl;
    std::cout << "5) Current Standing" << std::endl;
    std::cout << "6) Exit" << std::endl;
    // std::cout << endl;
    std::cout << "Enter Your Choice - ";
    std::cin >> choice;
    return choice;
}

void Clublist(Club *club)
{
    std::cout << "Code"
              << "\t"
              << "Name"
              << "\t"
                 "\t"
                 "\t"
              << "Strength" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        std::cout << club[i].getCodename() << "\t";
        std::cout << club[i].getName() << '\t';
        std::cout << club[i].getStrength() << std::endl;
    }
}

void Fixtures(Club *club)
{
    int round;
    std::cout << "\nEnter the round number (1 - 38): ";
    std::cin >> round;
    std::cout << "\nPremier League Fixtures" << std::endl;
    std::cout << "Round " << round << ":\n";
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int team1 = club[i].getCode();
            int team2 = club[j].getCode();
            if (leagueRounds[team1][team2] == round)
                std::cout << "    " << club[team1].getCodename() << "  -  " << club[team2].getCodename() << std::endl;
        }
    }
}

void NextRound(Club *club)
{
    int round;
    std::cout << "\nEnter the round number (1 - 38): ";
    std::cin >> round;
    std::cout << "      "
              << "\nResults of Round   " << round << std::endl;
    std::cout << "-----------------------" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int team1 = club[i].getCode();
            int team2 = club[j].getCode();
            if (leagueRounds[team1][team2] == round)
            {
                int score1 = club[team1].getScore();
                int score2 = club[team2].getScore();

                if (score1 > score2)
                {
                    club[team1].updateWins();
                    club[team2].updateLosses();
                }
                else if (score1 < score2)
                {
                    club[team1].updateLosses();
                    club[team2].updateWins();
                }
                else
                {
                    club[team1].updateDraws();
                    club[team2].updateDraws();
                }
                club[team1].updateRounds();
                club[team2].updateRounds();
                club[team1].updateGoals(score1, score2);
                club[team2].updateGoals(score2, score1);
                club[team1].addRecord(score1, score2, club[team2].getCodename(), round);
                club[team2].addRecord(score2, score1, club[team1].getCodename(), round);
                std::cout << "      " << club[team1].getCodename() << "   " << score1 << "  -  " << score2 << "    " << club[team2].getCodename() << std::endl;
            }
        }
    }
}

void swap(Club *xp, Club *yp)
{
    Club temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Club arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            if (!(arr[j] >= arr[j + 1]))
                swap(&arr[j], &arr[j + 1]);
    }
}

void CurrentStanding(Club club[])
{
    int round;
    std::cout << "\nEnter the round number (1 - 38): ";
    std::cin >> round;
    std::cout << "      "
              << "\nCurrent Standing after round  #" << round << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "Club"
              << "  "
              << "Rounds"
              << "  "
              << " Wins"
              << "   "
              << "Draws"
              << "  "
              << "Losses"
              << "    "
              << "Goals"
              << "  "
              << "Diff"
              << "    "
              << "Pts" << std::endl;
    bubbleSort(club, 20);

    for (int i = 0; i < 20; i++)
    {
        club[i].display();
    }
}

void TeamStanding(Club *club)
{
    std::string cCode;
    int rs, re;
    std::cout << "Enter club code";
    std::cin >> cCode;
    std::cout << "\n"
              << "Enter the starting round:";
    std::cin >> rs;
    std::cout << "\n"
              << "Enter the ending round:";
    std::cin >> re;
    std::cout << "Results of" << cCode << "from Round" << rs << " to " << re << std::endl;
    for (int i = 0; i < 20; i++)
    {
        if (cCode == club[i].getCodename())
        {
            club[i].printRecords(rs, re);
        }
    }
}