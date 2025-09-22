#ifndef MISSION_H
#define MISSION_H

#include "territory.h"

void assignMission(char *destination, char *missions[], int totalMissions);
int checkMission(char *mission, Territory *map, int n);
void showMission(char *mission);

#endif
