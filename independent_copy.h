#include <stdlib.h>

int* copyArray(const int *arr, int size){
    int *copy_arr = (int*) malloc(size * sizeof(int));
    if(copy_arr == NULL){
        return NULL;
    }

    if(size != 0){
        copy_arr[0] = arr[0];
    }

    for(int i = 1; i < size; i++){
        copy_arr[i] = arr[i]; 
    }

    return copy_arr;
}