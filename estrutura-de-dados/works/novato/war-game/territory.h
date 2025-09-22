#ifndef TERRITORY_H
#define TERRITORY_H

typedef struct {
    char name[30];
    char cor[10];
    int troops;
} Territory;

void inputTerritory(Territory *territory, int index);
void printTerritory(Territory territory, int index);

#endif