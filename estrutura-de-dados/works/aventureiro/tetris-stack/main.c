#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tetris.h"

int main() {
    srand(time(NULL));

    Piece queue[QUEUE_SIZE];
    Piece stack[STACK_SIZE];
    int front = -1, rear = -1;
    int top = -1;

    for (int i = 0; i < QUEUE_SIZE; i++) {
        Piece p = generatePiece();
        enqueue(queue, &front, &rear, p);
    }

    int option;
    do {
        printf("\n=== TETRIS STACK ===\n");
        showQueue(queue, front, rear);
        showStack(stack, top);

        printf("\nOpções de Ação:\n");
        printf("1 - Jogar peça\n");
        printf("2 - Reservar peça\n");
        printf("3 - Usar peça reservada\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &option);

        if (option == 1) {
            if (front == -1) printf("⚠️ Fila vazia!\n");
            else {
                Piece played = dequeue(queue, &front, &rear);
                printf("🎮 Peça jogada: [%c %d]\n", played.name, played.id);
                enqueue(queue, &rear, &rear, generatePiece());
            }
        }
        else if (option == 2) {
            if (front == -1) printf("⚠️ Fila vazia!\n");
            else {
                Piece toReserve = dequeue(queue, &front, &rear);
                if (push(stack, &top, toReserve))
                    printf("💾 Peça [%c %d] reservada!\n", toReserve.name, toReserve.id);
                else
                    printf("⚠️ Pilha cheia! Não é possível reservar.\n");
                enqueue(queue, &rear, &rear, generatePiece());
            }
        }
        else if (option == 3) {
            if (top == -1) printf("⚠️ Pilha vazia!\n");
            else {
                Piece used = pop(stack, &top);
                printf("🎯 Peça da reserva usada: [%c %d]\n", used.name, used.id);
            }
        }

    } while (option != 0);

    printf("\n👋 Jogo encerrado.\n");
    return 0;
}
