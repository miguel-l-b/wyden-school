#include <stdio.h>
#include "territory.h"

void inputTerritory(Territory *territory, int index)
{
    printf("\n=== Cadastro do Território %d ===\n", index + 1);

    printf("Digite o nome do território (max. 30 caracteres): ");
    scanf("%s", territory->name);

    printf("Digite a cor do território (max. 10 caracteres): ");
    scanf("%s", territory->cor);

    printf("Digite o número de tropas no território: ");
    scanf("%d", &territory->troops);
}

void printTerritory(Territory territory, int index)
{
    printf("\n=== Detalhes do Território %d ===\n", index + 1);
    printf("Nome: %s\n", territory.name);
    printf("Cor: %s\n", territory.cor);
    printf("Número de tropas: %d\n", territory.troops);
}