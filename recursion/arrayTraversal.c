/**
 * @file arrayTraversal.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Array traversal using recursion 
 * @date 06/06/2019
 * @subject Data Structures
 * 
 */
#include "../mydef.h"
#define N 5

int arr[N] = {1,2,3,4,5};

/**
 * @brief Traverse array in forward direction
 * 
 * @param arr array pointer
 * @param size size of array
 */
void traverseForward(int *arr, int size)
{
    if(size == 1){
        pi(*arr);
        return;
    } else {
        pi(*arr);
    }
    return traverseForward(++arr, --size);
}

/**
 * @brief Traverse array in reverse direction
 * 
 * @param arr array pointer
 * @param size size of array 
 */
void traverseReverse(int *arr, int size)
{
    if(size == 1){
        pi(arr[size-1]);
        return;
    } else {
        pi(arr[size-1]);
        return traverseReverse(arr, --size);
    }
}

/**
 * @brief Traverse array in reverse direction (another method)
 * 
 * @param arr array pointer
 * @param size size of array 
 */
void traverseRevAlt(int *arr, int size)
{
    if(size == 1){
        pi(*arr);
        return;
    } 
                                        // Try following
    traverseRevAlt(arr + 1, --size);    // ++arr, arr++ and arr+1 makes diff
    pi(*arr);                           // similarly --size and size--
    
}

int main(int argc, char const *argv[])
{
    traverseForward(arr, N);
    ps("");
    traverseReverse(arr, N);
    ps("");
    traverseRevAlt(arr, N);
    ps("");
    return 0;
}
