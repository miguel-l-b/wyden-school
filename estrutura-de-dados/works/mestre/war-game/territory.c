#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "territory.h"

Territory* createMap(int n) {
    Territory *map = (Territory*) calloc(n, sizeof(Territory));
    if (!map) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return map;
}

void registerTerritories(Territory *map, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n=== Cadastro do território %d ===\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", map[i].name);
        printf("Cor do exército: ");
        scanf(" %[^\n]", map[i].color);
        printf("Número de tropas: ");
        scanf("%d", &map[i].troops);
    }
}

void showMap(Territory *map, int n) {
    printf("\n🌍 Estado atual do mapa:\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %s | Exército: %s | Tropas: %d\n",
               i, map[i].name, map[i].color, map[i].troops);
    }
}

void attack(Territory *attacker, Territory *defender) {
    if (strcmp(attacker->color, defender->color) == 0) {
        printf("\n⚠️ Não é possível atacar um território da mesma cor!\n");
        return;
    }

    if (attacker->troops <= 1) {
        printf("\n⚠️ O atacante precisa de mais de 1 tropa!\n");
        return;
    }

    int diceAttacker = (rand() % 6) + 1;
    int diceDefender = (rand() % 6) + 1;

    printf("\n🎲 %s (%s) rolou %d\n", attacker->name, attacker->color, diceAttacker);
    printf("🎲 %s (%s) rolou %d\n", defender->name, defender->color, diceDefender);

    if (diceAttacker > diceDefender) {
        printf("\n🔥 %s conquistou %s!\n", attacker->name, defender->name);
        strcpy(defender->color, attacker->color);
        defender->troops = attacker->troops / 2;
        attacker->troops -= defender->troops;
    } else {
        printf("\n🛡️ %s resistiu ao ataque!\n", defender->name);
        attacker->troops--;
    }
}

void freeMap(Territory *map) {
    free(map);
}
