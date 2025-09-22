#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Node* insertItemList(Node *head) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("\nErro de memória!\n");
        return head;
    }

    printf("\nNome do item: ");
    scanf(" %[^\n]", newNode->data.name);
    printf("Tipo: ");
    scanf(" %[^\n]", newNode->data.type);
    printf("Quantidade: ");
    scanf("%d", &newNode->data.quantity);

    newNode->next = head;
    printf("\n✅ Item adicionado à lista!\n");
    return newNode;
}

Node* removeItemList(Node *head, const char *name) {
    Node *current = head, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (previous == NULL) head = current->next;
            else previous->next = current->next;
            free(current);
            printf("\n🗑️ Item removido da lista!\n");
            return head;
        }
        previous = current;
        current = current->next;
    }

    printf("\n⚠️ Item não encontrado na lista!\n");
    return head;
}

void listItemsList(Node *head) {
    printf("\n📦 Itens na mochila (lista encadeada):\n");
    Node *current = head;
    int i = 1;
    while (current != NULL) {
        printf("%d) %s | Tipo: %s | Qtd: %d\n",
               i++, current->data.name, current->data.type, current->data.quantity);
        current = current->next;
    }
}

Node* sequentialSearchList(Node *head, const char *name, int *comparisons) {
    *comparisons = 0;
    Node *current = head;
    while (current != NULL) {
        (*comparisons)++;
        if (strcmp(current->data.name, name) == 0) return current;
        current = current->next;
    }
    return NULL;
}

void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}
