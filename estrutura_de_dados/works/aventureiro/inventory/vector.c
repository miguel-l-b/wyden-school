#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void insertItemVector(Item backpack[], int *size) {
    if (*size >= MAX_ITEMS) {
        printf("\n⚠️ Mochila cheia!\n");
        return;
    }

    Item newItem;
    printf("\nNome do item: ");
    scanf(" %[^\n]", newItem.name);
    printf("Tipo: ");
    scanf(" %[^\n]", newItem.type);
    printf("Quantidade: ");
    scanf("%d", &newItem.quantity);

    backpack[*size] = newItem;
    (*size)++;

    printf("\n✅ Item adicionado ao vetor!\n");
}

void removeItemVector(Item backpack[], int *size, const char *name) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(backpack[i].name, name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                backpack[j] = backpack[j + 1];
            }
            (*size)--;
            printf("\n🗑️ Item removido do vetor!\n");
            return;
        }
    }
    printf("\n⚠️ Item não encontrado no vetor!\n");
}

void listItemsVector(Item backpack[], int size) {
    printf("\n📦 Itens na mochila (vetor):\n");
    for (int i = 0; i < size; i++) {
        printf("%d) %s | Tipo: %s | Qtd: %d\n",
               i + 1, backpack[i].name, backpack[i].type, backpack[i].quantity);
    }
}

int sequentialSearchVector(Item backpack[], int size, const char *name, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (strcmp(backpack[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void sortVector(Item backpack[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(backpack[j].name, backpack[j + 1].name) > 0) {
                Item temp = backpack[j];
                backpack[j] = backpack[j + 1];
                backpack[j + 1] = temp;
            }
        }
    }
    printf("\n✅ Vetor ordenado por nome!\n");
}

int binarySearchVector(Item backpack[], int size, const char *name, int *comparisons) {
    int left = 0, right = size - 1;
    *comparisons = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        (*comparisons)++;
        int cmp = strcmp(backpack[mid].name, name);
        if (cmp == 0) return mid;
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
