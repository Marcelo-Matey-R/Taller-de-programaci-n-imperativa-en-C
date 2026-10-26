#include <stdio.h>
#include "find_pair.h"
#include "independent_copy.h"
#include "stats.h"
#include "swap.h"

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
    int *copy = copyArray(arr, 5);
    int copy_size = (copy == NULL) ? 0 : 5;

    swap(&a, &b);
    printf("\nResultados de swap\na = %d\nb = %d\n", a, b);

    printf("\nResultado de Copy Array: ");
    print_list(copy, copy_size);

    arr_stats(arr, 5);

    printf("\nResultado de Find Pair: ");
    findPair(fp_arr1, 5, target1);
    findPair(fp_arr1, 5, target2);
    findPair(fp_arr2, 2, target3);
    findPair(fp_arr3, 1, target4);

    free(copy);

}