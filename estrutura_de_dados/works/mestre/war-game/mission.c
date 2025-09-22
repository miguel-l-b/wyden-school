#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mission.h"

void assignMission(char *destination, char *missions[], int totalMissions) {
    int randomIndex = rand() % totalMissions;
    strcpy(destination, missions[randomIndex]);
}

void showMission(char *mission) {
    printf("\n🎯 Sua missão é: %s\n", mission);
}

int checkMission(char *mission, Territory *map, int n) {
    if (strstr(mission, "3 territórios")) {
        int count = 0;
        char color[10];
        strcpy(color, map[0].color);

        for (int i = 0; i < n; i++) {
            if (strcmp(map[i].color, color) == 0) {
                count++;
                if (count >= 3) return 1;
            }
        }
    }
    else if (strstr(mission, "cor vermelha")) {
        for (int i = 0; i < n; i++) {
            if (strcmp(map[i].color, "vermelho") == 0) {
                return 0;
            }
        }
        return 1;
    }

    return 0;
}
