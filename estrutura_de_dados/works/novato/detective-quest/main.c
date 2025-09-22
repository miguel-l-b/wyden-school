#include <stdio.h>
#include <stdlib.h>
#include "mansion.h"

int main() {
    // Montagem manual da árvore (mapa da mansão)
    Room *hall = createRoom("Hall de entrada");
    Room *living = createRoom("Sala de estar");
    Room *kitchen = createRoom("Cozinha");
    Room *library = createRoom("Biblioteca");
    Room *garden = createRoom("Jardim");
    Room *dining = createRoom("Sala de jantar");

    // Conexões da árvore
    hall->left = living;
    hall->right = kitchen;

    living->left = library;
    living->right = garden;

    kitchen->right = dining;

    // Início da exploração
    printf("🔎 Bem-vindo(a) ao Detective Quest!\n");
    printf("Explore a mansão e descubra os segredos escondidos...\n");

    exploreMansion(hall);

    return 0;
}
