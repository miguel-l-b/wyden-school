#include <stdio.h>
#include <stdlib.h>
#include "mansion.h"

int main() {
    system("clear");
    Room *hall = createRoom("Hall de entrada");
    Room *living = createRoom("Sala de estar");
    Room *kitchen = createRoom("Cozinha");
    Room *library = createRoom("Biblioteca");
    Room *garden = createRoom("Jardim");
    Room *dining = createRoom("Sala de jantar");

    hall->left = living;
    hall->right = kitchen;

    living->left = library;
    living->right = garden;

    kitchen->right = dining;

    printf("🔎 Bem-vindo(a) ao Detective Quest!\n");
    printf("Explore a mansão e descubra os segredos escondidos...\n");

    exploreMansion(hall);

    return 0;
}
