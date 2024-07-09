#include "header.h"
#ifndef QUEUE_H
#define QUEUE_H
typedef struct Queue {
    int *list;
    int head, tail;
    unsigned maxVol;
} *Queue;

Queue QueConstructor(unsigned maxVol){
    if(maxVol < 1) return NULL;
    Queue que = malloc(sizeof(Queue));
    if(que){
        que->list = (int*) calloc(maxVol, sizeof(int));
        que->head = -1;
        que->tail = -1;
        que->maxVol = maxVol;
    }   return que;
}

bool QueIsEmpty(Queue que){
    return que->head == -1 && que->head == que->tail;
}

bool QueIsFull(Queue que){
    return que->tail == que->maxVol -1;
}

void enqueue(Queue que, int data){
    if(QueIsFull(que)) return;
    if(QueIsEmpty(que)) que->head++;
    que->list[++que->tail] = data;
}

int dequeue(Queue que){
    int res =  QueIsEmpty(que) ? -1 : que->list[que->head++];
    if(que->head > que->tail) {
        que->head = -1;
        que->tail = -1;
    }   return res;
}

void QueDestructor(Queue que){   
    free(que->list);
    free(que);
}
#endif
