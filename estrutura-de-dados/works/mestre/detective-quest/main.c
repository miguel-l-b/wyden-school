#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mansion.h"

int main() {
    Room* hall = createRoom("Hall de Entrada", "Pegada suja");
    Room* kitchen = createRoom("Cozinha", "Garrafa quebrada");
    Room* library = createRoom("Biblioteca", "Livro rasgado");
    Room* garden = createRoom("Jardim", "Flor murcha");
    Room* cellar = createRoom("Adega", "Chave perdida");

    hall->left = kitchen;
    hall->right = library;
    kitchen->left = garden;
    kitchen->right = cellar;

    ClueNode* collectedClues = NULL;

    HashNode* hashTable[HASH_SIZE] = {NULL};
    inserirNaHash(hashTable, "Pegada suja", "Lara");
    inserirNaHash(hashTable, "Garrafa quebrada", "João");
    inserirNaHash(hashTable, "Livro rasgado", "Lara");
    inserirNaHash(hashTable, "Flor murcha", "Pedro");
    inserirNaHash(hashTable, "Chave perdida", "João");

    printf("🔎 Detective Quest - Capítulo Mestre\n");

    explorarSalas(hall, &collectedClues);

    printf("\n📄 Todas as pistas coletadas:\n");
    exibirPistas(collectedClues);

    char accusation[50];
    printf("\nIndique o suspeito que você acusa: ");
    scanf("%s", accusation);

    if (verificarSuspeitoFinal(hashTable, collectedClues, accusation))
        printf("✅ Acusação correta! Pistas suficientes apontam para %s.\n", accusation);
    else
        printf("❌ Acusação incorreta! Pistas não são suficientes para %s.\n", accusation);

    return 0;
}
