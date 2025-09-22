#ifndef TERRITORY_H
#define TERRITORY_H

typedef struct {
    char name[30];
    char cor[10];
    int troops;
} Territory;

void inputTerritory(struct Territory *territory, int indice);

#endif