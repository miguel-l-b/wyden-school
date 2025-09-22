#ifndef MANSION_H
#define MANSION_H

#define HASH_SIZE 10

typedef struct Sala {
    char name[50];
    char clue[100];
    struct Sala *left;
    struct Sala *right;
} Room;

typedef struct ClueNode {
    char clue[100];
    struct ClueNode *left;
    struct ClueNode *right;
} ClueNode;

typedef struct HashNode {
    char clue[100];
    char suspect[50];
    struct HashNode* next;
} HashNode;

Room* createRoom(const char* name, const char* clue);
void explorarSalas(Room* current, ClueNode** collectedClues);

ClueNode* inserirPista(ClueNode* root, const char* clue);
void exibirPistas(ClueNode* root);

int hashFunction(const char* clue);
void inserirNaHash(HashNode* hashTable[], const char* clue, const char* suspect);
char* encontrarSuspeito(HashNode* hashTable[], const char* clue);
int verificarSuspeitoFinal(HashNode* hashTable[], ClueNode* collectedClues, const char* suspect);

#endif
