/**
 * @file arrayOperations.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Exercise from book `Data Structures using C & CPP` by Tenenbaum.
 *  **Question => Find minimum element, maximum element, average of array recursively**
 * @date 10-06-2019
 */

#include "../mydef.h"
#define N 10    /*!< length of array */

/**
 * @brief global int array of length 10
 *  {10,20,300,40,50,600,70,80,90,100}
 */
int arr[] = {10,20,300,40,50,600,70,80,90,100};

/**
 * @brief Returns max element of array recursively 
 *  
 * @param arr pointer to array
 * @param l length of array
 * @param max max element
 * at first call max = array[0] 
 * @return int 
 */
int maxArrayElement(int *arr, int l, int max)
{
    if (l == 0) return max;
    return maxArrayElement(arr+1, --l, *arr > max ? *arr : max);
}

/**
 * @brief Returns min element of array recursively 
 *  
 * @param arr pointer to array
 * @param l length of array
 * @param min min element
 * at first call min = array[0] 
 * @return int 
 */
int minArrayElement(int *arr, int l, int min)
{
    if (l == 0) return min;
    return minArrayElement(arr+1, --l, *arr < min ? *arr : min);
}

/**
 * @brief finds average recursively
 * 
 * @param arr pointer to array
 * @param i at first call it is length of array
 * @param l at first call it is length of array
 * @param sum at first call it is array[0]
 * @return int average
 */
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
