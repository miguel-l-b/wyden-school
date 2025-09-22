#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    Queue q;
    initQueue(&q);

    // inicializa fila com 5 peças
    for (int i = 0; i < MAX_QUEUE; i++) {
        enqueue(&q);
    }

    int option;
    Piece removed;

    do {
        displayQueue(&q);

        printf("\n====== MENU ======\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (dequeue(&q, &removed)) {
                    printf("\n🎮 Você jogou a peça [%c %d]\n", removed.name, removed.id);
                }
                break;
            case 2:
                if (enqueue(&q)) {
                    printf("\n✅ Nova peça adicionada à fila!\n");
                }
                break;
            case 0:
                printf("\n👋 Saindo do jogo...\n");
                break;
            default:
                printf("\n❌ Opção inválida, tente novamente.\n");
        }

    } while (option != 0);

    return 0;
}
