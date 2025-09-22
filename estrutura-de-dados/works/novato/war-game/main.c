#include <stdio.h>
#include <stdlib.h>
#include "territory.h"

int main() {
    system("clear");
    Territory territories[5];
    for (int i = 0; i < 5; i++) {
        inputTerritory(&territories[i], i);
    }
    for (int i = 0; i < 5; i++) {
        printTerritory(territories[i], i);
    }    
}