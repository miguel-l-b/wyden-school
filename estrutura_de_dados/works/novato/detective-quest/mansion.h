#ifndef MANSION_H
#define MANSION_H

typedef struct Room {
    char name[50];
    struct Room *left;
    struct Room *right;
} Room;

Room* createRoom(const char *name);
void exploreMansion(Room *room);

#endif
