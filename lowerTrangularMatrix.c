// Author: Ajit J.
// Subject: Data Structures
// Description: Storing lower trangular matrix in 1D array in Row Major Order and accessing it

#include "mydef.h"
#define N 3

void printArr(int *a, int s)
{
    int i, j=0, k=0;
    for(i=0; i<N; i++)
    {
        for(j = 0; j <=i; j++)
        {
            if(k<s) printf("%d ", a[k++]);
        }
        printf("\n"); 
    }    
}

int getValue(int *arr, int row, int col)
{
    if((row <= N) && (col <= N) && (row>0) && (col>0))    // 0 < row/col <= N
    {
        if(col<=row)                                // LTM property
            return arr[((row*(row-1))/2 + (col-1))]; // 2D cross + 1D cross
        else
            return 0;
    }else {
        printOutOfRangeError();
        exit(1);
    } 
}

int main(int argc, char const *argv[])
{
    int size = (N*(N+1))/2;
    int arr[size], i = 0,j = 0, k = 0, temp = 0;
    
    printf("Enter %dx%d integer Lower trangular matrix in Row Major Order:\n", N, N);
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(j<=i) scanf("%d", &arr[k++]);
            else{
                scanf("%d", &temp);
                if(temp != 0)
                {
                    printf( Yellow "[warning]: Ignoring values on locations (col > row) for Lower Trangular Matrix.\n");
                }
            }
        }
    }
    ps("Entered LTM is:");
    printArr(arr, size);
    ps("Enter location to retrive number(Example-2,3): ");
    scanf("%d,%d", &i, &j);
    printf(Green "Element at (%d,%d) is: %d\n",i, j, getValue(arr, i, j));    
    return 0;
}
