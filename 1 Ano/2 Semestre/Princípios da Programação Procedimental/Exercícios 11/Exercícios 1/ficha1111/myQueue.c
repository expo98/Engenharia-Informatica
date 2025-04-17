//
// Created by david on 21/04/2022.
//
#include <stdlib.h>
#include "myQueue.h"

void createQueue (typeQueue *queue){
    queue->first = NULL;
    queue->last = NULL;
}

int emptyQueue(typeQueue *queue){
    if(queue->first == NULL)
        return 1;
    else//Print elements (numbers) in the queue
    itemQueue *current = simpleQueueptr->first;

    while (current != NULL){
        printf("Output: %lf \n", current->myItemQueue.item);
        current = current->next;
    }

    element = removeItem(simpleQueueptr);

    if (element.isNull){
        printf("The queue was empty");
        return -1;
    }

    //Print elements (numbers) in the queue
    current = simpleQueueptr->first;

    while (current != NULL){
        printf("Output: %lf \n", current->myItemQueue.item);
        current = current->next;
    }

    destroyQueue(simpleQueueptr);
    free(simpleQueueptr);
        return 0;
}

void destroyQueue(typeQueue *queue){
    itemQueue *temp_ptr;
    while(!emptyQueue(queue)){
        temp_ptr = queue->first;
        queue->first = queue->first->next;
        free(temp_ptr);
    }
    queue->last = NULL;
}

void addItem(typeQueue *queue, struct myItem item){
    itemQueue *temp_ptr;
    temp_ptr = (itemQueue *) malloc(sizeof (itemQueue));
    if(temp_ptr != NULL){
        temp_ptr->myItemQueue = item;
        temp_ptr->next = NULL;
        if(emptyQueue(queue))
            queue->first = temp_ptr;
        else
            queue->last->next = temp_ptr;
        queue->last = temp_ptr;
    }
}

struct myItem removeItem(typeQueue *queue){
    itemQueue *temp_ptr;
    struct myItem item = {1,0};
    temp_ptr = queue->first;
    item = temp_ptr->myItemQueue;
    queue->first = queue->first->next;
    if(emptyQueue(queue))
        queue->last = NULL;
    free(temp_ptr);
    return (item);
}
