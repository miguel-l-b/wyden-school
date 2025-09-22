#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "list.h"

int main() {
    int structureOption;
    Item backpackVector[MAX_ITEMS];
    int vectorSize = 0;
    Node *backpackList = NULL;

    do {
        printf("\n=== Menu Principal ===\n");
        printf("1 - Usar mochila com Vetor\n");
        printf("2 - Usar mochila com Lista Encadeada\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &structureOption);

        if (structureOption == 1) {
            int option;
            do {
                printf("\n--- Mochila (Vetor) ---\n");
                printf("1 - Inserir item\n");
                printf("2 - Remover item\n");
                printf("3 - Listar itens\n");
                printf("4 - Buscar sequencial\n");
                printf("5 - Ordenar itens\n");
                printf("6 - Buscar binária\n");
                printf("0 - Voltar\n");
                printf("Escolha: ");
                scanf("%d", &option);

                if (option == 1) insertItemVector(backpackVector, &vectorSize);
                else if (option == 2) {
                    char name[30];
                    printf("Nome do item: ");
                    scanf(" %[^\n]", name);
                    removeItemVector(backpackVector, &vectorSize, name);
                }
                else if (option == 3) listItemsVector(backpackVector, vectorSize);
                else if (option == 4) {
                    char name[30]; int comp;
                    printf("Nome do item: ");
                    scanf(" %[^\n]", name);
                    int pos = sequentialSearchVector(backpackVector, vectorSize, name, &comp);
                    if (pos != -1) printf("✅ Item encontrado no índice %d (%d comparações)\n", pos, comp);
                    else printf("❌ Item não encontrado (%d comparações)\n", comp);
                }
                else if (option == 5) sortVector(backpackVector, vectorSize);
                else if (option == 6) {
                    char name[30]; int comp;
                    printf("Nome do item: ");
                    scanf(" %[^\n]", name);
                    int pos = binarySearchVector(backpackVector, vectorSize, name, &comp);
                    if (pos != -1) printf("✅ Item encontrado no índice %d (%d comparações)\n", pos, comp);
                    else printf("❌ Item não encontrado (%d comparações)\n", comp);
                }
            } while (option != 0);
        }

        else if (structureOption == 2) {
            int option;
            do {
                printf("\n--- Mochila (Lista Encadeada) ---\n");
                printf("1 - Inserir item\n");
                printf("2 - Remover item\n");
                printf("3 - Listar itens\n");
                printf("4 - Buscar sequencial\n");
                printf("0 - Voltar\n");
                printf("Escolha: ");
                scanf("%d", &option);

                if (option == 1) backpackList = insertItemList(backpackList);
                else if (option == 2) {
                    char name[30];
                    printf("Nome do item: ");
                    scanf(" %[^\n]", name);
                    backpackList = removeItemList(backpackList, name);
                }
                else if (option == 3) listItemsList(backpackList);
                else if (option == 4) {
                    char name[30]; int comp;
                    printf("Nome do item: ");
                    scanf(" %[^\n]", name);
                    Node *res = sequentialSearchList(backpackList, name, &comp);
                    if (res != NULL) printf("✅ Item encontrado (%d comparações)\n", comp);
                    else printf("❌ Item não encontrado (%d comparações)\n", comp);
                }
            } while (option != 0);
            freeList(backpackList);
            backpackList = NULL;
        }

    } while (structureOption != 0);

    printf("\n👋 Jogo encerrado.\n");
    return 0;
}
