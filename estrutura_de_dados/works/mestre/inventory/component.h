#ifndef COMPONENT_H
#define COMPONENT_H

#define MAX_COMPONENTS 20

typedef struct {
    char name[30];
    char type[20];
    int priority;
} Component;

#endif
