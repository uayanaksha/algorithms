#include <stdio.h>
#include "queue.c"

void bfs(unsigned vCount, unsigned graph[][vCount], unsigned startIdx){
    int visited[vCount];
    for(int i = 0; i < vCount; i++) visited[i] = 0;
    if(startIdx >= vCount) return;
    Queue que = QueConstructor(vCount);
    {
        enqueue(que, startIdx);
        visited[startIdx] = 1;
    }   printf("BFS -> ");
    {
        int node;
        while(!QueIsEmpty(que)){
            node = dequeue(que);   
            printf(" V-%d", node);
            for(int i = 0; i < vCount; i++){
                if(graph[node][i] == 1 && visited[i] == 0){
                    visited[i] = 1;
                    enqueue(que, i);
                }
            }
        }
    }   printf("\n");
    QueDestructor(que);
}
