#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_ITEMS 10

typedef struct {
    char name[30];
    char type[20];
    int quantity;
} Item;

void insertItem(Item backpack[], int *numItems);
void removeItem(Item backpack[], int *numItems);
void listItems(Item backpack[], int numItems);
void searchItem(Item backpack[], int numItems);

#endif