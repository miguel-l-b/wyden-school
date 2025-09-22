#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#include "component.h"

int main() {
    Component components[MAX_COMPONENTS];
    int size = 0;

    printf("🛠️ Cadastro de componentes da torre de fuga (máx. 20)\n");
    while (size < MAX_COMPONENTS) {
        printf("\nNome do componente (ou 'fim' para encerrar): ");
        fgets(components[size].name, 30, stdin);
        components[size].name[strcspn(components[size].name, "\n")] = '\0';
        if (strcmp(components[size].name, "fim") == 0) break;

        printf("Tipo: ");
        fgets(components[size].type, 20, stdin);
        components[size].type[strcspn(components[size].type, "\n")] = '\0';

        printf("Prioridade (1-10): ");
        scanf("%d", &components[size].priority);
        getchar();

        size++;
    }

    int option, comparisons;
    char searchName[30];
    clock_t start, end;
    double duration;

    do {
        printf("\n=== Menu de Estratégia ===\n");
        printf("1 - Ordenar por nome (Bubble Sort)\n");
        printf("2 - Ordenar por tipo (Insertion Sort)\n");
        printf("3 - Ordenar por prioridade (Selection Sort)\n");
        printf("4 - Buscar componente-chave por nome (após ordenar por nome)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);
        getchar();

        if (option == 1) {
            start = clock();
            bubbleSortName(components, size, &comparisons);
            end = clock();
            duration = ((double)(end - start)) / CLOCKS_PER_SEC;
            showComponents(components, size);
            printf("🔹 Comparações: %d | Tempo: %.6f s\n", comparisons, duration);
        }
        else if (option == 2) {
            start = clock();
            insertionSortType(components, size, &comparisons);
            end = clock();
            duration = ((double)(end - start)) / CLOCKS_PER_SEC;
            showComponents(components, size);
            printf("🔹 Comparações: %d | Tempo: %.6f s\n", comparisons, duration);
        }
        else if (option == 3) {
            start = clock();
            selectionSortPriority(components, size, &comparisons);
            end = clock();
            duration = ((double)(end - start)) / CLOCKS_PER_SEC;
            showComponents(components, size);
            printf("🔹 Comparações: %d | Tempo: %.6f s\n", comparisons, duration);
        }
        else if (option == 4) {
            printf("Nome do componente-chave: ");
            fgets(searchName, 30, stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            int index = binarySearchByName(components, size, searchName, &comparisons);
            if (index != -1) printf("✅ Componente '%s' encontrado na posição %d (%d comparações)\n",
                                    components[index].name, index + 1, comparisons);
            else printf("❌ Componente não encontrado (%d comparações)\n", comparisons);
        }

    } while (option != 0);

    printf("\n🏁 Montagem final encerrada.\n");
    return 0;
}
