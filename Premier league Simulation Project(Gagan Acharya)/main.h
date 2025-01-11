#ifndef MAIN_H_
#define MAIN_H_

#include "Club.h"

#include <iostream>

void Clublist(Club *club);
int MainMenu();
void Fixtures(Club *club);
void NextRound(Club *club);
void CurrentStanding(Club *club);
void TeamStanding(Club *club);

#endif // !MAIN_H_