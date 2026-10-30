#include <stdlib.h>
#include <stdio.h>

int findTrio(const int *values, int size, int start){
    int can = 0;
    int left = start + 1;
    int right = size - 1;
    int real_target = -values[start];

    while(left < right){
        int sum = values[left] + values[right];

        if(sum == real_target){
            printf("Trio valido: (%d, %d, %d)\n", values[start], values[left], values[right]);
            can++;
            left++;
            right--;

            while(left < right && values[left] == values[left - 1]){
                left++;
            }
            while(left < right && values[right] == values[right + 1]){
                right--;
            }
        }
        else if(sum < real_target){
            left++;
        }
        else{
            right--;
        }
    }
    return can;
}

int threeSum(const int *values, int size){
    if(size < 3){
        return 0;
    }

    int *copia = copyArray(values, size);
    if(copia == NULL){
        return -1;
    }

    sortAscending(copia, size); // se ordena la copia, el original queda intacto

    int total = 0;
    for(int i = 0; i < size - 2; i++){
        // Saltar repetidos del elemento fijo
        if(i > 0 && copia[i] == copia[i - 1]){
            continue;
        }
        total += findTrio(copia, size, i);
    }

    free(copia);
    return total;
}