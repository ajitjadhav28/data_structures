// Author: Ajit Jadhav
// Subject: Data Structures
// Date: 10-06-2019 17:32
// Desc: Exercise from book `Data Structures using C & CPP` by Tenenbaum
//         Q: Find minimum element, maximum element, average of array recursively

#include "../mydef.h"
#define N 10    // Length of array

int arr[] = {10,20,300,40,50,600,70,80,90,100};

// Recursive defination for max array element
int maxArrayElement(int *arr, int l, int max)
{
    if (l == 0) return max;
    return maxArrayElement(arr+1, --l, *arr > max ? *arr : max);
}

// Recursive defination for min array element
int minArrayElement(int *arr, int l, int min)
{
    if (l == 0) return min;
    return minArrayElement(arr+1, --l, *arr < min ? *arr : min);
}

// Recursive avg
int avg(int *arr, int i, const int l, int sum)
{
    if(i == 1) return sum/l;
    sum += arr[--i];
    return avg(arr, i, l, sum);
}

int main(int argc, char const *argv[])
{
    printf("Max element of array: %d\n", maxArrayElement(arr, N, arr[0]));
    printf("Min element of array: %d\n", minArrayElement(arr, N, arr[0]));
    printf("Avg of array elements: %d\n",avg(arr, N, N, *arr));
    return 0;
}
