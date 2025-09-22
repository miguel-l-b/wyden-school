#ifndef LIST_H
#define LIST_H

#include "vector.h"

typedef struct Node {
	Item data;
	struct Node* next;
} Node;

Node* insertItemList(Node *head);
Node* removeItemList(Node *head, const char *name);
void listItemsList(Node *head);
Node* sequentialSearchList(Node *head, const char *name, int *comparisons);
void freeList(Node *head);

#endif
