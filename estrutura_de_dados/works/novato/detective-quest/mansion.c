#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mansion.h"

Room* createRoom(const char *name) {
    Room *newRoom = (Room*) malloc(sizeof(Room));
    if (!newRoom) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    strcpy(newRoom->name, name);
    newRoom->left = NULL;
    newRoom->right = NULL;
    return newRoom;
}

void exploreMansion(Room *room) {
    char choice;

    while (room != NULL) {
        printf("\n📍 Você está na sala: %s\n", room->name);

        if (room->left == NULL && room->right == NULL) {
            printf("🚪 Não há mais caminhos a seguir. Fim da exploração!\n");
            break;
        }

        printf("Escolha seu caminho: (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &choice);

        if (choice == 'e') {
            if (room->left != NULL) {
                room = room->left;
            } else {
                printf("⚠️ Não há sala à esquerda!\n");
            }
        } else if (choice == 'd') {
            if (room->right != NULL) {
                room = room->right;
            } else {
                printf("⚠️ Não há sala à direita!\n");
            }
        } else if (choice == 's') {
            printf("\n👋 Você decidiu encerrar a exploração.\n");
            break;
        } else {
            printf("❌ Opção inválida, tente novamente.\n");
        }
    }
}
