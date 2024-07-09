#include "header.h"
#include "search.c"

static void display(int array[], unsigned size){
    printf("List[%u]: ", size);
    for (int i = 0; i < size; i++) {
        if(i > 0) printf(" %s", (array[i-1] > array[i] ? ">" : "<="));
        printf(" %d", array[i]);    
    }   printf("\n");
}

int main(void){
    srand(time(0));
    const int max = 500;
    const int size = 64;
    int array[size];
    int sortedarray[size];
    int target;
    sortedarray[size - 1] = max;
    for (int i = size - 1; i > 0; i--) {
        array[i] = rand() % max;
        sortedarray[i-1] = sortedarray[i] - (rand() % 20);
    }
    display(array, size);
    display(sortedarray, size);
    target = rand() % max;
    printf("Target [%d] in array -> %d\n", target, linearsearch(array, target, size));
    target = rand() % max;
    printf("Target [%d] in sorted array -> %d\n", target, linearsearch(sortedarray, target, size));
    return 0;
}
