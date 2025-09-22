#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tetris.h"

Piece generatePiece() {
    Piece p;
    char types[] = {'I','O','T','L'};
    static int nextId = 0;
    p.name = types[rand() % 4];
    p.id = nextId++;
    return p;
}

void enqueue(Piece queue[], int *front, int *rear, Piece p) {
    int nextRear = (*rear + 1) % QUEUE_SIZE;
    queue[nextRear] = p;
    *rear = nextRear;
    if (*front == -1) *front = 0;
}

Piece dequeue(Piece queue[], int *front, int *rear) {
    Piece p = queue[*front];
    if (*front == *rear) *front = *rear = -1;
    else *front = (*front + 1) % QUEUE_SIZE;
    return p;
}

int push(Piece stack[], int *top, Piece p) {
    if (*top >= STACK_SIZE -1) return 0;
    stack[++(*top)] = p;
    return 1;
}

Piece pop(Piece stack[], int *top) {
    return stack[(*top)--];
}

int swapFrontWithTop(Piece queue[], int front, Piece stack[], int top) {
    if (front == -1 || top == -1) return 0;
    Piece temp = queue[front];
    queue[front] = stack[top];
    stack[top] = temp;
    return 1;
}

int swapThree(Piece queue[], int front, Piece stack[], int top) {
    if (front == -1 || top < 2) return 0;
    for (int i = 0; i < 3; i++) {
        int queueIndex = (front + i) % QUEUE_SIZE;
        Piece temp = queue[queueIndex];
        queue[queueIndex] = stack[top - i];
        stack[top - i] = temp;
    }
    return 1;
}

void showQueue(Piece queue[], int front, int rear) {
    printf("\n📦 Fila de peças: ");
    if (front == -1) { printf("(vazia)\n"); return; }
    int i = front;
    do {
        printf("[%c %d] ", queue[i].name, queue[i].id);
        i = (i + 1) % QUEUE_SIZE;
    } while (i != (rear + 1) % QUEUE_SIZE);
    printf("\n");
}

void showStack(Piece stack[], int top) {
    printf("📌 Pilha de reserva (Topo -> Base): ");
    if (top == -1) { printf("(vazia)\n"); return; }
    for (int i = top; i >= 0; i--) printf("[%c %d] ", stack[i].name, stack[i].id);
    printf("\n");
}
