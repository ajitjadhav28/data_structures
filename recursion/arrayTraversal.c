// Author: Ajit J.
// Subject: Data Structures
// Date: 06/06/2019
// Desc: Array traversal using recursion

#include "../mydef.h"
#define N 5

int arr[N] = {1,2,3,4,5};

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
