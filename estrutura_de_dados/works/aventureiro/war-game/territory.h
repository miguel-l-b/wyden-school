#ifndef TERRITORY_H
#define TERRITORY_H

typedef struct {
    char name[30];
    char color[10];
    int troops;
} Territory;

Territory* createMap(int n);
void registerTerritories(Territory *map, int n);
void showMap(Territory *map, int n);
void attack(Territory *attacker, Territory *defender);
void freeMap(Territory *map);

#endif
