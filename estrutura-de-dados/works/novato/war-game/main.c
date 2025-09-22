#include <stdio.h>
#include "territory.h"

int main() {
    Territory territories[5];
    for (int i = 0; i < 5; i++) {
        inputTerritory(&territories[i], i);
    }
    for (int i = 0; i < 5; i++) {
        printTerritory(territories[i], i);
    }    
}