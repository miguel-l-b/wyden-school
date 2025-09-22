#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "territory.h"

int main() {
    srand(time(NULL));

    int n;
    printf("Digite o número de territórios: ");
    scanf("%d", &n);

    Territory *map = createMap(n);

    registerTerritories(map, n);

    int option;
    do {
        printf("\n====== MENU ======\n");
        printf("1 - Mostrar mapa\n");
        printf("2 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);

        if (option == 1) {
            showMap(map, n);
        } else if (option == 2) {
            int a, d;
            showMap(map, n);
            printf("\nEscolha o índice do território atacante: ");
            scanf("%d", &a);
            printf("Escolha o índice do território defensor: ");
            scanf("%d", &d);

            if (a >= 0 && a < n && d >= 0 && d < n) {
                attack(&map[a], &map[d]);
                showMap(map, n);
            } else {
                printf("⚠️ Índice inválido!\n");
            }
        } else if (option != 0) {
            printf("❌ Opção inválida!\n");
        }

    } while (option != 0);

    freeMap(map);
    printf("\n👋 Jogo encerrado.\n");

    return 0;
}
