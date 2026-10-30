#include <stdio.h>
#include "find_pair.h"
#include "independent_copy.h"
#include "stats.h"
#include "swap.h"
#include "sort.h"
#include "threesum.h"
#include "water.h"

void probarCopia(const int *values, int size){
    int *copia = copyArray(values, size);
    if(copia == NULL){
        printf("Error: fallo la reserva de memoria\n");
        return;
    }
    copia[0] = 99;             
    printf("\nOriginal: ");
    print_list(values, size);
    printf("Copia:    ");
    print_list(copia, size);
    free(copia);
}

void probarOrden(const int *values, int size){
    int *copia = copyArray(values, size);
    if(copia == NULL){
        printf("Error: fallo la reserva de memoria\n");
        return;
    }
    sortAscending(copia, size);
    printf("\nOriginal: ");
    print_list(values, size);
    printf("Ordenado: ");
    print_list(copia, size);
    free(copia);
}

void probarAgua(const int *height, int size){
    printf("\nAlturas: ");
    print_list(height, size);
    long long total = trappedWater(height, size);
    if(total == -1){
        printf("Error: fallo la reserva de memoria\n");
    } else {
        printf("Agua total = %lld\n", total);
    }
}

void probarThreeSum(const int *values, int size){
    printf("\nEntrada: ");
    print_list(values, size);
    int total = threeSum(values, size);
    if(total == -1){
        printf("Error: fallo la reserva de memoria\n");
    } else {
        printf("Total de ternas = %d\n", total);
    }
}

void probarMaximos(const int *height, int size){
    int *leftMax = (int*) malloc(size * sizeof(int));
    int *rightMax = (int*) malloc(size * sizeof(int));

    if(leftMax == NULL || rightMax == NULL){
        printf("Error: fallo la reserva de memoria\n");
        free(leftMax);
        free(rightMax);
        return;
    }

    buildLeftMax(height, size, leftMax);
    buildRightMax(height, size, rightMax);

    printf("\nheight:   ");
    print_list(height, size);
    printf("leftMax:  ");
    print_list(leftMax, size);
    printf("rightMax: ");
    print_list(rightMax, size);

    free(leftMax);
    free(rightMax);
}

int main(){
    int a = -3;
    int b = 9;

    int fp_arr1[] = {-4, -1, 0, 2, 5};
    int target1 = 1;
    int target2 = 8;
    int fp_arr2[] = {0, 0};
    int target3 = 0;
    int fp_arr3[] = {3};
    int target4 = 6;

    int arr[] = {4, -2, 0, 7, -5};
    printf("\nResultado de Copy Array:");
    probarCopia(arr, 5);

    printf("\nResultado de ordenar una copia:");
    probarOrden(arr, 5);

    swap2(a, b);
    printf("\nResultado para swap2\na = %d\nb = %d\n", a, b);
    swap(&a, &b);
    printf("\nResultados de swap\na = %d\nb = %d\n", a, b);

    arr_stats(arr, 5);

    printf("\nResultado de Find Pair: ");
    findPair(fp_arr1, 5, target1);
    findPair(fp_arr1, 5, target2);
    findPair(fp_arr2, 2, target3);
    findPair(fp_arr3, 1, target4);

    int arr_trio1[] = {-1, 0, 1, 2, -1, -4};
    int arr_trio2[] = {0, 1, 1};
    int arr_trio3[] = {0, 0, 0};
    int arr_trio4[] = {0, 0, 0, 0};
    int arr_trio5[] = {-2, 0, 0, 2, 2};
    int arr_trio6[] = {1, -1};

    printf("\nResultados de 3Sum:");
    probarThreeSum(arr_trio1, 6);
    probarThreeSum(arr_trio2, 3);
    probarThreeSum(arr_trio3, 3);
    probarThreeSum(arr_trio4, 4);
    probarThreeSum(arr_trio5, 5);
    probarThreeSum(arr_trio6, 2);

    int max_arr1[] = {3, 0, 2, 0, 4};
    int max_arr2[] = {5};
    int max_arr3[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    printf("\nResultados de maximos acumulados:");
    probarMaximos(max_arr1, 5);
    probarMaximos(max_arr2, 1);
    probarMaximos(max_arr3, 12);

        int agua1[] = {5};
    int agua2[] = {0, 1, 2, 3};
    int agua3[] = {3, 2, 1, 0};
    int agua4[] = {2, 2, 2};
    int agua5[] = {3, 0, 3};
    int agua6[] = {3, 0, 2, 0, 4};
    int agua7[] = {4, 2, 0, 3, 2, 5};
    int agua8[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int agua9[] = {5, 5, 0, 2, 0, 3};   // caso propio

    printf("\nResultados de agua atrapada:");
    probarAgua(agua1, 1);
    probarAgua(agua2, 4);
    probarAgua(agua3, 4);
    probarAgua(agua4, 3);
    probarAgua(agua5, 3);
    probarAgua(agua6, 5);
    probarAgua(agua7, 6);
    probarAgua(agua8, 12);
    probarAgua(agua9, 6);

    printf("\nTabla del caso propio:\n");
    printWaterTable(agua9, 6);

}