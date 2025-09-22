#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    system("clear");
    printf("\n🎮 SELETOR DE PROJETOS - ESTRUTURA DE DADOS - Nível Aventureiro\n");
    printf("==========================================\n");
    printf("1 - Detective Quest\n");
    printf("2 - Sistema de Inventário\n");
    printf("3 - War game\n");
    printf("4 - Tetris Stack\n");
    printf("0 - Sair\n");
    printf("==========================================\n");
    printf("Escolha um projeto: ");
}

void runProject(int choice) {
    switch(choice) {
        case 1:
            system("clear");
            printf("\n🏚️ Executando Detective Quest...\n");
            system("cd detective-quest && make && ./detective-quest");
            break;
        case 2:
            system("clear");
            printf("\n🎒 Executando Sistema de Inventário...\n");
            system("cd inventory && make && ./inventory");
            break;
        case 3:
            system("clear");
            printf("\n🗺️ Executando Gerenciador de Territórios...\n");
            system("cd war-game && make && ./war-game");
            break;
        case 4:
            system("clear");
            printf("\n🟩 Executando Tetris Stack...\n");
            system("cd tetris-stack && make && ./tetris-stack");
            break;
        case 0:
            printf("\n👋 Saindo do seletor...\n");
            break;
        default:
            printf("\n❌ Opção inválida! Tente novamente.\n");
    }
}

int main() {
    int choice;
    
    do {
        showMenu();
        scanf("%d", &choice);
        runProject(choice);
        
        if (choice != 0) {
            printf("\nPressione Enter para voltar ao menu...");
            getchar();
            getchar();
        }
        
    } while (choice != 0);
    
    return 0;
}