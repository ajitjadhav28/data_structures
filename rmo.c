// Author: Ajit J.
// Subject: Data Structures
// Description: Storing 2D array in 1D array by Row Major Order and accessing it

#include "mydef.h"
#define N 9
#define ROWS 3
#define COLUMNS 3

void printArr(int *a, int s)
{
    int i;
    for(i=0; i<s; i++)
    {
        printf("%d ", a[i]);
        if((i+1) % ROWS == 0) printf("\n");
    }    
}

int main()
{
    int arr[N], i, j = 0, loc = 0;
    ps("Enter 3x3 integer matrix in Row Major Order:");
    for(i = 0; i < 9; i++)
        scanf("%d", &arr[i]);
    printArr(arr, N);
    printf("Enter location of element to retrive example-1,3:");
    scanf("%d,%d", &i, &j);
    if((i<4 && j<4) && (i>0 && j>0))
    {
        loc = ((i-1)*ROWS) + (j-1);
        printf( Green "Element(%d,%d): %d\n", i, j, arr[loc]);
    } else {
        fprintf(stderr, Bold_Red "[ERROR]: " Red "i or j value out of range.\n");
        exit(1);
    }
    return 0;
}