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

ClueNode* createClue(ClueNode* root, const char* clue) {
    if (root == NULL) {
        ClueNode* node = (ClueNode*) malloc(sizeof(ClueNode));
        strcpy(node->clue, clue);
        node->left = node->right = NULL;
        return node;
    }
    if (strcmp(clue, root->clue) < 0) root->left = createClue(root->left, clue);
    else if (strcmp(clue, root->clue) > 0) root->right = createClue(root->right, clue);
    return root;
}

void exploreMansion(Room* current, ClueNode** collectedClues) {
    if (current == NULL) return;

    printf("\nVocê está em: %s\n", current->name);
    if (strlen(current->clue) > 0) {
        printf("💡 Pista encontrada: %s\n", current->clue);
        *collectedClues = createClue(*collectedClues, current->clue);
    }

    char choice;
    printf("Escolha o próximo caminho: esquerda (e), direita (d) ou sair (s): ");
    scanf(" %c", &choice);
    system("clear");

    if (choice == 'e') exploreMansion(current->left, collectedClues);
    else if (choice == 'd') exploreMansion(current->right, collectedClues);
    else printf("Você decidiu sair da exploração.\n");
}

void printClues(ClueNode* root) {
    if (root == NULL) return;
    printClues(root->left);
    printf("- %s\n", root->clue);
    printClues(root->right);
}
