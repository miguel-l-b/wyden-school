#ifndef TETRIS_H
#define TETRIS_H

#define QUEUE_SIZE 5
#define STACK_SIZE 3

typedef struct {
    char name;
    int id;
} Piece;

Piece generatePiece();

void enqueue(Piece queue[], int *front, int *rear, Piece p);
Piece dequeue(Piece queue[], int *front, int *rear);

int push(Piece stack[], int *top, Piece p);
Piece pop(Piece stack[], int *top);

void showQueue(Piece queue[], int front, int rear);
void showStack(Piece stack[], int top);

#endif
