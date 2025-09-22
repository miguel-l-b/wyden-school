#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    q->nextId = 0;
    srand(time(NULL));
}

Piece generatePiece(Queue *q) {
    char types[] = {'I', 'O', 'T', 'L'};
    Piece p;
    p.name = types[rand() % 4];
    p.id = q->nextId++;
    return p;
}

int enqueue(Queue *q) {
    if (q->count == MAX_QUEUE) {
        printf("\n⚠️ A fila está cheia! Não é possível inserir nova peça.\n");
        return 0;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->items[q->rear] = generatePiece(q);
    q->count++;
    return 1;
}

int dequeue(Queue *q, Piece *removed) {
    if (q->count == 0) {
        printf("\n⚠️ A fila está vazia! Não há peças para jogar.\n");
        return 0;
    }

    *removed = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE;
    q->count--;
    return 1;
}

void displayQueue(Queue *q) {
    printf("\n📦 Fila de peças (%d/%d):\n", q->count, MAX_QUEUE);

    if (q->count == 0) {
        printf("A fila está vazia.\n");
        return;
    }

    int index = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("[%c %d] ", q->items[index].name, q->items[index].id);
        index = (index + 1) % MAX_QUEUE;
    }
    printf("\n");
}
