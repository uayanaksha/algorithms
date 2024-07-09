#include "header.h"
#include "stack.c"

void dfs(unsigned vCount, unsigned graph[][vCount], unsigned startIdx){
    int visited[vCount];
    for(int i = 0; i < vCount; i++) visited[i] = 0;
    if(startIdx >= vCount) return;
    Stack st = StConstructor(vCount);
    {
        StPush(st, startIdx);
        visited[startIdx] = 1;
    }   printf("DFS -> ");
    {
        int node;
        while(!StIsEmpty(st)){
            node = StPop(st);   
            printf(" V-%d", node);
            for(int i = 0; i < vCount; i++){
                if(graph[node][i] == 1 && visited[i] == 0){
                    visited[i] = 1;
                    StPush(st, i);
                }
            }
        }
    }   printf("\n");
    StDestructor(st);
}
