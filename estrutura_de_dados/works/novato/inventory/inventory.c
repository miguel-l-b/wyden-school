#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inventory.h"

void insertItem(Item backpack[], int *numItems) {
    if (*numItems >= MAX_ITEMS) {
        printf("\n⚠️ A mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item newItem;
    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", newItem.name);

    printf("Digite o tipo do item (arma, munição, cura, etc): ");
    scanf(" %[^\n]", newItem.type);

    printf("Digite a quantidade: ");
    scanf("%d", &newItem.quantity);

    backpack[*numItems] = newItem;
    (*numItems)++;

    printf("\n✅ Item adicionado com sucesso!\n");
    listItems(backpack, *numItems);
}

void removeItem(Item backpack[], int *numItems) {
    if (*numItems == 0) {
        printf("\n⚠️ A mochila está vazia!\n");
        return;
    }

    char name[30];
    printf("\nDigite o nome do item a ser removido: ");
    scanf(" %[^\n]", name);

    int found = -1;
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(backpack[i].name, name) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\n❌ Item não encontrado na mochila.\n");
    } else {
        for (int i = found; i < *numItems - 1; i++) {
            backpack[i] = backpack[i + 1];
        }
        (*numItems)--;
        printf("\n🗑️ Item removido com sucesso!\n");
    }

    listItems(backpack, *numItems);
}

void listItems(Item backpack[], int numItems) {
    printf("\n📦 Itens na mochila (%d/%d):\n", numItems, MAX_ITEMS);
    if (numItems == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < numItems; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, backpack[i].name, backpack[i].type, backpack[i].quantity);
    }
}

void searchItem(Item backpack[], int numItems) {
    if (numItems == 0) {
        printf("\n⚠️ A mochila está vazia!\n");
        return;
    }

    char name[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(backpack[i].name, name) == 0) {
            printf("\n🔎 Item encontrado:\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   backpack[i].name, backpack[i].type, backpack[i].quantity);
            return;
        }
    }

    printf("\n❌ Item não encontrado.\n");
}