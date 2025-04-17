#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"

int main() {
    int n;
    double value;
    //typeQueue simpleQueue;
    typeQueue *simpleQueueptr; //= &simpleQueue;
    struct myItem element;

    printf("Please introduce the number of elements to add to the queue: ");
    scanf("%d",&n);

    simpleQueueptr = (typeQueue *) malloc(sizeof(typeQueue));

    if (simpleQueueptr == NULL){
        printf("Memory not allocated.\n");
        exit(1);
    }

    createQueue(simpleQueueptr);

    for(int i = 0; i<n; i++){
        printf("Element: ");
        scanf("%lf",&value);
        element.isNull = 0;
        element.item = value;
        addItem(simpleQueueptr, element);
    }

    //Print elements (numbers) in the queue
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
