#ifndef VECTOR_H
#define VECTOR_H

#define MAX_ITEMS 50

typedef struct {
    char name[30];
    char type[20];
    int quantity;
} Item;

void insertItemVector(Item backpack[], int *size);
void removeItemVector(Item backpack[], int *size, const char *name);
void listItemsVector(Item backpack[], int size);
int sequentialSearchVector(Item backpack[], int size, const char *name, int *comparisons);
void sortVector(Item backpack[], int size);
int binarySearchVector(Item backpack[], int size, const char *name, int *comparisons);

#endif
