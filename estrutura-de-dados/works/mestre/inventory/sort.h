#ifndef SORT_H
#define SORT_H

#include "component.h"

void bubbleSortName(Component components[], int size, int *comparisons);
void insertionSortType(Component components[], int size, int *comparisons);
void selectionSortPriority(Component components[], int size, int *comparisons);

int binarySearchByName(Component components[], int size, char target[], int *comparisons);

void showComponents(Component components[], int size);

#endif
