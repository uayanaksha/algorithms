#include "header.h"
static bool isascending(int array[], unsigned size){
    if(size < 2) return true;
    int tmp;
    bool state = true;
    for (int i = 1; i < size; i++) {
        tmp = array[i] - array[i-1];
        if(tmp < 0){
            state = false;
            break;
        }
    }   return state;
}

static bool isdescending(int array[], unsigned size){
    if(size < 2) return true;
    int tmp;
    bool state = true;
    for (int i = 1; i < size; i++) {
        tmp = array[i-1] - array[i];
        if(tmp < 0){
            state = false;
            break;
        }
    }   return state;
}

int linearsearch(int array[], int target, unsigned size){
    int idx = -1;
    for(int i = 0; i < size; i++){
        if(target == array[i]){
            idx = i;
            break;
        }
    }   return idx;
}

int binarysearch(int array[], int target, unsigned size){
    if(!isascending(array, size) && !isdescending(array, size)) return -1;
    int idx = -1;
    int start = 0, end = size - 1;
    int mid;
    while(start<end){
        mid = start + (end - start)/2;
        if(target == array[mid]){
            idx = mid;
            break;
        } else if(target < array[mid]){
            end = mid - 1;
        } else if(target > array[mid]){
            start = mid + 1;
        }
    }   return idx;
}
