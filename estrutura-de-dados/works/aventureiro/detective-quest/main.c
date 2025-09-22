#include <stdio.h>
#include <stdlib.h>
#include "mansion.h"

int main() {
    system("clear");
    Room* hall = createRoom("Hall de Entrada", "Chave encontrada");
    Room* kitchen = createRoom("Cozinha", "Pegada suspeita");
    Room* library = createRoom("Biblioteca", "Livro aberto em código");
    Room* garden = createRoom("Jardim", NULL);
    Room* cellar = createRoom("Adega", "Garrafa quebrada");

    hall->left = kitchen;
    hall->right = library;
    kitchen->left = garden;
    kitchen->right = cellar;

    ClueNode* collectedClues = NULL;

    printf("🔍 Bem-vindo ao Detective Quest - Coleta de Pistas\n");

    exploreMansion(hall, &collectedClues);

    printf("\n🏆 Todas as pistas coletadas (em ordem alfabética):\n");
    printClues(collectedClues);

    return 0;
}
