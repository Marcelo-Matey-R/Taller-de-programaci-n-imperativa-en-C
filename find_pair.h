#include <stdio.h>

int findPair(const int *values, int size, int target){
    int left = 0;
    int right = size - 1;
    while(left < right){
        int sum = values[right] + values[left];

        if(sum == target){
            printf("Par valido: (%d, %d)\n", values[left], values[right]);
            return 1;
        }

        if(sum < target){
            left += 1;
        }
        
        else{
            right -= 1;
        }
    }

    printf("No hay pares validos\n");
    return 0;
}