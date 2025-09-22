#ifndef QUEUE_H
#define QUEUE_H
\
#define MAX_QUEUE 5

typedef struct {
    char name;
    int id;
} Piece;

typedef struct {
    Piece items[MAX_QUEUE];
    int front;
    int rear;
    int count;
    int nextId;
} Queue;

void initQueue(Queue *q);
Piece generatePiece(Queue *q);
int enqueue(Queue *q);
int dequeue(Queue *q, Piece *removed);
void displayQueue(Queue *q);

#endif
