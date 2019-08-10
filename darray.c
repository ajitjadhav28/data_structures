/**
 * @file darray.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Daynamic arrays implementation
 * @date 07-08-2019
 * @subject Data Structures
 * 
 */
#include "darray.h"
#include "mydef.h"

/**
 * @brief Get the Int Array object
 * 
 * @param size Size of array
 * @return int* pointer to created array
 */
int * getIntArray(unsigned int size)
{
    int *p = (int *) calloc(size, sizeof(int));
    if(!p){
        printError("Can't allocate memory for array.");
        exit(1);
    }
    return p;
}

/**
 * @brief Perform linear search on integer array
 * 
 * @param array pointer to array
 * @param sizeOfArray Size of array
 * @param number Number to search on array
 * @return short 1 if found, else 0
 */
short intArrayLinearSearch(int *array, int sizeOfArray, int number)
{
    int *base = array;
    while(array < (base+sizeOfArray))
        if(*array++ == number) return 1;
    return 0;
}

/**
 * @brief Perform binary search on integer array
 * 
 * @param array Pointer to array
 * @param sizeOfArray array size
 * @param number number to search
 * @return short 1 if found, else 0
 */
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