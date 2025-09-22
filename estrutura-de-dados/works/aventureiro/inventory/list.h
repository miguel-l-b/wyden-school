#ifndef LIST_H
#define LIST_H

typedef struct {
    char name[30];
    char type[20];
    int quantity;
} Item;

typedef struct Node {
    Item data;
    struct Node* next;
} Node;

// Funções da lista encadeada
Node* insertItemList(Node *head);
Node* removeItemList(Node *head, const char *name);
void listItemsList(Node *head);
Node* sequentialSearchList(Node *head, const char *name, int *comparisons);
void freeList(Node *head);

#endif
