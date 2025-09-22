#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

int main() {
    system("clear");
    Item backpack[MAX_ITEMS];
    int numItems = 0;
    int option;

    do {
        printf("\n====== SISTEMA DE INVENTÁRIO ======\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1: insertItem(backpack, &numItems); break;
            case 2: removeItem(backpack, &numItems); break;
            case 3: listItems(backpack, numItems); break;
            case 4: searchItem(backpack, numItems); break;
            case 0: printf("\n👋 Saindo do inventário...\n"); break;
            default: printf("\n❌ Opção inválida, tente novamente.\n");
        }
    } while (option != 0);

    return 0;
}