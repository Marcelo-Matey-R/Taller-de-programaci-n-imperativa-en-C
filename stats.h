#include <stdio.h>
#include <stdlib.h>

int calc_sum(const int *arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    
    return sum;
}

int calc_min(const int *arr, int size){
    int min = arr[0];
    for(int i = 1; i < size; i++){
        int val = arr[i];
        if(val < min){
            min = val;
        }
    }

    return min;
}

int calc_max(const int *arr, int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        int val = arr[i];
        if(val > max){
            max = val;
        }
    }

    return max;
}

int calc_can_neg(const int *arr, int size){
    int cnt = 0;
    for(int i = 1; i < size; i++){
        int val = arr[i];
        if(val < 0){
            cnt += 1;
        }
    }

    return cnt;
}

int* reverse(const int *arr, int size){
    int *reverse_arr = (int*) malloc(size * sizeof(int));
    if(reverse_arr == NULL){
        return NULL;
    }
    int real_size = size - 1;
    for(int i = real_size; i >= 0; i--){
        reverse_arr[real_size - i] = arr[i]; 
    }

    return reverse_arr;
}

void print_list(const int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]); // Puedes usar también *(arreglo + i)
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void arr_stats(const int *arr, int size){
    int *my_lst = reverse(arr, size);
    int my_lst_size = (my_lst == NULL) ? 0 : size;
    int suma = calc_sum(arr, size);
    int min = calc_min(arr, size);
    int max = calc_max(arr, size);
    int neg = calc_can_neg(arr, size);
    printf("\nResultados de stats:\nEntrada: ");
    print_list(arr, size);

    printf("Suma: %d\nMinimo: %d\nMaximo: %d\nNegativos: %d\nInversion: ", suma, min, max, neg);
    print_list(my_lst, my_lst_size);

    free(my_lst);
}