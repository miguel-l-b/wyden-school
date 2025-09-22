#include <stdio.h>
#include <string.h>
#include "sort.h"

void bubbleSortName(Component components[], int size, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            (*comparisons)++;
            if (strcmp(components[j].name, components[j + 1].name) > 0) {
                Component temp = components[j];
                components[j] = components[j + 1];
                components[j + 1] = temp;
            }
        }
    }
    printf("\n✅ Componentes ordenados por nome (Bubble Sort)\n");
}

void insertionSortType(Component components[], int size, int *comparisons) {
    *comparisons = 0;
    for (int i = 1; i < size; i++) {
        Component key = components[i];
        int j = i - 1;
        while (j >= 0) {
            (*comparisons)++;
            if (strcmp(components[j].type, key.type) > 0) {
                components[j + 1] = components[j];
                j--;
            } else break;
        }
        components[j + 1] = key;
    }
    printf("\n✅ Componentes ordenados por tipo (Insertion Sort)\n");
}

void selectionSortPriority(Component components[], int size, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            (*comparisons)++;
            if (components[j].priority < components[minIndex].priority) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Component temp = components[i];
            components[i] = components[minIndex];
            components[minIndex] = temp;
        }
    }
    printf("\n✅ Componentes ordenados por prioridade (Selection Sort)\n");
}

int binarySearchByName(Component components[], int size, char target[], int *comparisons) {
    int left = 0, right = size - 1;
    *comparisons = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        (*comparisons)++;
        int cmp = strcmp(components[mid].name, target);
        if (cmp == 0) return mid;
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void showComponents(Component components[], int size) {
    printf("\n📦 Componentes:\n");
    for (int i = 0; i < size; i++) {
        printf("%d) %s | Tipo: %s | Prioridade: %d\n",
               i + 1, components[i].name, components[i].type, components[i].priority);
    }
}
