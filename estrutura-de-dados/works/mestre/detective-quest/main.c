#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mansion.h"

int main() {
    // Montar mansão
    Room* hall = createRoom("Hall de Entrada", "Pegada suja");
    Room* kitchen = createRoom("Cozinha", "Garrafa quebrada");
    Room* library = createRoom("Biblioteca", "Livro rasgado");
    Room* garden = createRoom("Jardim", "Flor murcha");
    Room* cellar = createRoom("Adega", "Chave perdida");

    hall->left = kitchen;
    hall->right = library;
    kitchen->left = garden;
    kitchen->right = cellar;

    // BST de pistas
    ClueNode* collectedClues = NULL;

    // Hash de pistas -> suspeitos
    HashNode* hashTable[HASH_SIZE] = {NULL};
    inserirNaHash(hashTable, "Pegada suja", "Suspeito A");
    inserirNaHash(hashTable, "Garrafa quebrada", "Suspeito B");
    inserirNaHash(hashTable, "Livro rasgado", "Suspeito A");
    inserirNaHash(hashTable, "Flor murcha", "Suspeito C");
    inserirNaHash(hashTable, "Chave perdida", "Suspeito B");

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
