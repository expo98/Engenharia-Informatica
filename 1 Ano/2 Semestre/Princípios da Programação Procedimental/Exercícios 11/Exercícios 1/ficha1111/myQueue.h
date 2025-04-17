//
// Created by david on 21/04/2022.
//

#ifndef FICHA1111_MYQUEUE_H
#define FICHA1111_MYQUEUE_H

struct myItem{
    int isNull;
    double item;
};

typedef struct itemQueue{
    struct myItem myItemQueue;
    struct itemQueue *next;
} itemQueue;

typedef struct typeQueue{
    itemQueue *first;
    itemQueue *last;
} typeQueue;

void createQueue (typeQueue *queue);
int emptyQueue(typeQueue *queue);
void destroyQueue(typeQueue *queue);
void addItem(typeQueue *queue, struct myItem item);
struct myItem removeItem(typeQueue *queue);

#endif //FICHA1111_MYQUEUE_H