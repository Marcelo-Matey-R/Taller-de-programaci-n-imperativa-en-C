#include <stdio.h>
#include <stdlib.h>

int maxInt(int a, int b){ 
    if(a >= b) return a;
    else return b;
 }
int minInt(int a, int b){ 
        if(a >= b) return b;
    else return a;
 }


void buildLeftMax(const int *height, int size, int *leftMax){ 
    leftMax[0] = height[0];
    for (int i = 1; i < size; i++){
        leftMax[i] = maxInt(leftMax[i-1], height[i]);
    }
 }
void buildRightMax(const int *height, int size, int *rightMax){ 
    rightMax[size-1] = height[size-1];
    for (int i = size-2; i >=0; i--){
        rightMax[i]=maxInt(height[i],rightMax[i+1]);
    }
 }

long long trappedWater(const int *height, int size){ 
    int* leftMax = (int*)malloc(size * sizeof(int));
    int* rightMax = (int*)malloc(size * sizeof(int));
    if(leftMax == NULL || rightMax == NULL) {
        free(rightMax);
        free(leftMax);
        return -1;
    }
    buildLeftMax(height,size,leftMax);
    buildRightMax(height,size,rightMax);
    long long total = 0;
    for(int i= 0; i<size; i++){
        total+=minInt(leftMax[i],rightMax[i])-height[i];
    }
    free(leftMax);
    free(rightMax);
    return total;
 }
void printWaterTable(const int *height, int size){ 
    printf("  i | height | leftMax | rightMax | agua\n");
        int* leftMax = (int*)malloc(size * sizeof(int));
    int* rightMax = (int*)malloc(size * sizeof(int));
    if(leftMax == NULL || rightMax == NULL) {
        free(rightMax);
        free(leftMax);
        return;
    }
    buildLeftMax(height,size,leftMax);
    buildRightMax(height,size,rightMax);
    for(int i= 0; i<size; i++){
        int agua = minInt(leftMax[i], rightMax[i]) - height[i];
        printf("%3d | %6d | %7d | %8d | %4d\n", i, height[i], leftMax[i], rightMax[i], agua);
    }
    free(leftMax);
    free(rightMax);
 }