#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mansion.h"

// ---------------- Sala ----------------
Room* createRoom(const char* name, const char* clue) {
    Room* room = (Room*) malloc(sizeof(Room));
    strcpy(room->name, name);
    if (clue != NULL) strcpy(room->clue, clue);
    else room->clue[0] = '\0';
    room->left = room->right = NULL;
    return room;
}

// ---------------- BST Pistas ----------------
ClueNode* inserirPista(ClueNode* root, const char* clue) {
    if (root == NULL) {
        ClueNode* node = (ClueNode*) malloc(sizeof(ClueNode));
        strcpy(node->clue, clue);
        node->left = node->right = NULL;
        return node;
    }
    if (strcmp(clue, root->clue) < 0) root->left = inserirPista(root->left, clue);
    else if (strcmp(clue, root->clue) > 0) root->right = inserirPista(root->right, clue);
    return root;
}

void exibirPistas(ClueNode* root) {
    if (root == NULL) return;
    exibirPistas(root->left);
    printf("- %s\n", root->clue);
    exibirPistas(root->right);
}

// ---------------- Hash ----------------
int hashFunction(const char* clue) {
    int sum = 0;
    for (int i=0; clue[i]; i++) sum += clue[i];
    return sum % HASH_SIZE;
}

void inserirNaHash(HashNode* hashTable[], const char* clue, const char* suspect) {
    int idx = hashFunction(clue);
    HashNode* node = (HashNode*) malloc(sizeof(HashNode));
    strcpy(node->clue, clue);
    strcpy(node->suspect, suspect);
    node->next = hashTable[idx];
    hashTable[idx] = node;
}

char* encontrarSuspeito(HashNode* hashTable[], const char* clue) {
    int idx = hashFunction(clue);
    HashNode* current = hashTable[idx];
    while (current) {
        if (strcmp(current->clue, clue) == 0) return current->suspect;
        current = current->next;
    }
    return NULL;
}

// ---------------- Exploração ----------------
void explorarSalas(Room* current, ClueNode** collectedClues) {
    if (current == NULL) return;

    printf("\nVocê entrou em: %s\n", current->name);
    if (strlen(current->clue) > 0) {
        printf("💡 Pista encontrada: %s\n", current->clue);
        *collectedClues = inserirPista(*collectedClues, current->clue);
    }

    char choice;
    printf("Escolha caminho: esquerda (e), direita (d), sair (s): ");
    scanf(" %c", &choice);

    if (choice == 'e') explorarSalas(current->left, collectedClues);
    else if (choice == 'd') explorarSalas(current->right, collectedClues);
    else printf("Você decidiu encerrar a exploração.\n");
}

// ---------------- Verificação de Suspeito ----------------
int verificarSuspeitoFinal(HashNode* hashTable[], ClueNode* collectedClues, const char* suspect) {
    int count = 0;

    // Função auxiliar para percorrer BST
    void countClues(ClueNode* node) {
        if (!node) return;
        countClues(node->left);
        char* s = encontrarSuspeito(hashTable, node->clue);
        if (s && strcmp(s, suspect) == 0) count++;
        countClues(node->right);
    }

    countClues(collectedClues);
    return count >= 2; // Pelo menos 2 pistas
}
