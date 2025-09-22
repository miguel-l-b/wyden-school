#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mansion.h"

Room* createRoom(const char* name, const char* clue) {
    Room* newRoom = (Room*) malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    if (clue != NULL) strcpy(newRoom->clue, clue);
    else newRoom->clue[0] = '\0';
    newRoom->left = NULL;
    newRoom->right = NULL;
    return newRoom;
}

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

void explorarSalasComPistas(Room* current, ClueNode** collectedClues) {
    if (current == NULL) return;

    printf("\nVocê está em: %s\n", current->name);
    if (strlen(current->clue) > 0) {
        printf("💡 Pista encontrada: %s\n", current->clue);
        *collectedClues = inserirPista(*collectedClues, current->clue);
    }

    char choice;
    printf("Escolha o próximo caminho: esquerda (e), direita (d) ou sair (s): ");
    scanf(" %c", &choice);

    if (choice == 'e') explorarSalasComPistas(current->left, collectedClues);
    else if (choice == 'd') explorarSalasComPistas(current->right, collectedClues);
    else printf("Você decidiu sair da exploração.\n");
}

void exibirPistas(ClueNode* root) {
    if (root == NULL) return;
    exibirPistas(root->left);
    printf("- %s\n", root->clue);
    exibirPistas(root->right);
}
