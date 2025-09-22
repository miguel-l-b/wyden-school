#include <stdio.h>
#include <stdlib.h>

static void showLevelMenu() {
	system("clear");
	printf("\n🎓 SELETOR DE NÍVEL - ESTRUTURA DE DADOS\n");
	printf("==========================================\n");
	printf("1 - Novato\n");
	printf("2 - Aventureiro\n");
	printf("3 - Mestre\n");
	printf("0 - Sair\n");
	printf("==========================================\n");
	printf("Escolha um nível: ");
}

static void runLevel(int choice) {
	switch (choice) {
		case 1:
			printf("\n🟢 Entrando no nível Novato...\n");
			system("cd novato && make run");
			break;
		case 2:
			printf("\n🟡 Entrando no nível Aventureiro...\n");
			system("cd aventureiro && make run");
			break;
		case 3:
			printf("\n🔴 Entrando no nível Mestre...\n");
			system("cd mestre && make run");
			break;
		case 0:
			printf("\n👋 Saindo...\n");
			break;
		default:
			printf("\n❌ Opção inválida! Tente novamente.\n");
	}
}

int main() {
	int choice;
	do {
		showLevelMenu();
		if (scanf("%d", &choice) != 1) {
			return 0;
		}
		runLevel(choice);
		if (choice != 0) {
			printf("\nPressione Enter para voltar ao menu...");
			getchar();
			getchar();
		}
	} while (choice != 0);
	return 0;
}
