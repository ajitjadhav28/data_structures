#include "darray.h"

int * getIntArray(unsigned int size)
{
    int *p = (int *) calloc(size, sizeof(int));
    if(!p){
        printError("Can't allocate memory for array.");
        exit(1);
    }
    return p;
}

short intArrayLinearSearch(int *array, int sizeOfArray, int number)
{
    int *base = array;
    while(array < (base+sizeOfArray))
        if(*array++ == number) return 1;
    return 0;
}

short intArrayBinarySearch(int *array, int sizeOfArray, int number)
{
    int l = sizeOfArray-1, s = 0, t;
    if(*array == number) return 1;
    if(*(array+l) == number) return 1;
    while (s <= l)
    {
        t = s + (l-s) / 2;
        if(*(array+t) == number)
            return 1;
        if(*(array+t) < number){
            s = t + 1;
        } else
            l = t - 1;
    }
    return 0;
}