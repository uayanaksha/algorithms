#include "./header.h"
#ifndef STACK_H
#define STACK_H
typedef struct Stack{
    int *list;
    int head;
    unsigned maxVol;
} *Stack;

Stack StConstructor(unsigned maxVol){
    if(maxVol < 1) return NULL;
    Stack st = malloc(sizeof(Stack));
    if(st){
        st->list = (int*) calloc(maxVol, sizeof(int));
        st->head = -1;
        st->maxVol = maxVol;
    }   return st;
}

bool StIsEmpty(Stack st){
    return st->head == -1;
}

bool StIsFull(Stack st){
    return st->head == st->maxVol -1;
}

void StPush(Stack st, int data){
    if(StIsFull(st)) return;
    st->list[++st->head] = data;
}

int StPop(Stack st){
    int res =  StIsEmpty(st) ? -1 : st->list[st->head--];
    if(st->head < 0) {
        st->head = -1;
    }   return res;
}

void StDestructor(Stack st){   
    free(st->list);
    free(st);
}
#endif
