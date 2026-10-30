#include <stdio.h>
#include <stdlib.h>

void sortAscending(int *values, int size){
    for (int i = 1; i<size; i++){
        int j=i-1;
        int key = values[i];
        while(j>=0 && values[j] > key){
            values[j+1] = values[j];
            j--;
        }
        values[j+1] = key;
    }
}