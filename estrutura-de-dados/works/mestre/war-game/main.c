#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "territory.h"
#include "mission.h"

int main() {
    srand(time(NULL));

    int n, players;
    printf("Digite o número de territórios: ");
    scanf("%d", &n);

    printf("Digite o número de jogadores: ");
    scanf("%d", &players);

    Territory *map = createMap(n);
    registerTerritories(map, n);

    char *missions[] = {
        "Conquistar 3 territórios seguidos",
        "Eliminar todas as tropas da cor vermelha",
        "Controlar pelo menos 5 territórios",
        "Conquistar qualquer território azul",
        "Manter pelo menos 10 tropas em um território"
    };
    int totalMissions = 5;

    char **playerMissions = (char**) malloc(players * sizeof(char*));
    for (int i = 0; i < players; i++) {
        playerMissions[i] = (char*) malloc(100 * sizeof(char));
        assignMission(playerMissions[i], missions, totalMissions);
        printf("\nJogador %d: ", i + 1);
        showMission(playerMissions[i]);
    }

    int option, a, d;
    int winner = -1;

    do {
        printf("\n====== MENU ======\n");
        printf("1 - Mostrar mapa\n");
        printf("2 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);

        if (option == 1) {
            showMap(map, n);
        }
        else if (option == 2) {
            showMap(map, n);
            printf("\nTerritório atacante (índice): ");
            scanf("%d", &a);
            printf("Território defensor (índice): ");
            scanf("%d", &d);

            if (a >= 0 && a < n && d >= 0 && d < n) {
                attack(&map[a], &map[d]);

                for (int i = 0; i < players; i++) {
                    if (checkMission(playerMissions[i], map, n)) {
                        winner = i;
                        break;
                    }
                }
                if (winner != -1) {
                    printf("\n🏆 Jogador %d venceu cumprindo a missão: %s\n",
                           winner + 1, playerMissions[winner]);
                    break;
                }
            }
        }

    } while (option != 0);

    for (int i = 0; i < players; i++) {
        free(playerMissions[i]);
    }
    free(playerMissions);
    freeMap(map);

    printf("\n👋 Jogo encerrado.\n");
    return 0;
}
