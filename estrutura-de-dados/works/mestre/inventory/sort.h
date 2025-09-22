#ifndef SORT_H
#define SORT_H

#include "component.h"

// Funções de ordenação
void bubbleSortName(Component components[], int size, int *comparisons);
void insertionSortType(Component components[], int size, int *comparisons);
void selectionSortPriority(Component components[], int size, int *comparisons);

// Busca binária por nome
int binarySearchByName(Component components[], int size, char target[], int *comparisons);

// Função para mostrar componentes
void showComponents(Component components[], int size);

#endif
