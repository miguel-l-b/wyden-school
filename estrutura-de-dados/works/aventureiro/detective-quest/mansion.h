#ifndef MANSION_H
#define MANSION_H

typedef struct Sala {
    char name[50];
    char clue[100];
    struct Sala *left;
    struct Sala *right;
} Room;

typedef struct PistaNode {
    char clue[100];
    struct PistaNode *left;
    struct PistaNode *right;
} ClueNode;

Room* createRoom(const char* name, const char* clue);
void exploreMansion(Room* current, ClueNode** collectedClues);

ClueNode* createClue(ClueNode* root, const char* clue);
void printClues(ClueNode* root);

#endif
