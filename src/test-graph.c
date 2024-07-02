#include "breadth-first-search.c"
#include "depth-first-search.c"
#define NODES 6

void displayGraph(unsigned vCount, unsigned graph[][vCount]){
    printf("Graph[%u][%u]: {\n", vCount, vCount);
    for(int i = 0; i < vCount; i++){
        printf("%8s{", "");
        for(int j = 0; j < vCount; j++){
            printf("%3d,", graph[i][j]);
        }   printf(" },\n");
    }   printf("}\n");
}

int main(void){
    unsigned graph[NODES][NODES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 1, 0}
    };
    displayGraph(NODES, graph);
    bfs(NODES, graph, 1);
    dfs(NODES, graph, 1);
    return 0;
}
