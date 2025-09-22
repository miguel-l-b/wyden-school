#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tetris.h"

int main() {
    srand(time(NULL));

    Piece queue[QUEUE_SIZE];
    Piece stack[STACK_SIZE];
    int front = -1, rear = -1, top = -1;

    for (int i = 0; i < QUEUE_SIZE; i++) {
        enqueue(queue, &front, &rear, generatePiece());
    }

    int option;
    do {
        printf("\n=== TETRIS STACK AVANÇADO ===\n");
        showQueue(queue, front, rear);
        showStack(stack, top);

        printf("\nOpções disponíveis:\n");
        printf("1 - Jogar peça da frente da fila\n");
        printf("2 - Enviar peça da fila para a pilha de reserva\n");
        printf("3 - Usar peça da pilha de reserva\n");
        printf("4 - Trocar peça da frente da fila com o topo da pilha\n");
        printf("5 - Trocar os 3 primeiros da fila com as 3 peças da pilha\n");
        printf("0 - Sair\n");
        printf("Opção escolhida: ");
        scanf("%d", &option);

        if (option == 1) {
            if (front == -1) printf("⚠️ Fila vazia!\n");
            else {
                Piece played = dequeue(queue, &front, &rear);
                printf("🎮 Peça jogada: [%c %d]\n", played.name, played.id);
                enqueue(queue, &front, &rear, generatePiece());
            }
        }
        else if (option == 2) {
            if (front == -1) printf("⚠️ Fila vazia!\n");
            else {
                Piece toReserve = dequeue(queue, &front, &rear);
                if (push(stack, &top, toReserve))
                    printf("💾 Peça [%c %d] enviada para reserva!\n", toReserve.name, toReserve.id);
                else printf("⚠️ Pilha cheia! Não foi possível enviar.\n");
                enqueue(queue, &front, &rear, generatePiece());
            }
        }
        else if (option == 3) {
            if (top == -1) printf("⚠️ Pilha vazia!\n");
            else {
                Piece used = pop(stack, &top);
                printf("🎯 Peça da reserva usada: [%c %d]\n", used.name, used.id);
            }
        }
        else if (option == 4) {
            if (swapFrontWithTop(queue, front, stack, top))
                printf("🔄 Troca realizada entre frente da fila e topo da pilha!\n");
            else printf("⚠️ Troca impossível!\n");
        }
        else if (option == 5) {
            if (swapThree(queue, front, stack, top))
                printf("🔄 Troca realizada entre os 3 primeiros da fila e 3 da pilha!\n");
            else printf("⚠️ Troca múltipla impossível! Certifique-se de que há pelo menos 3 peças em ambos.\n");
        }

    } while (option != 0);

    printf("\n👋 Jogo encerrado.\n");
    return 0;
}
