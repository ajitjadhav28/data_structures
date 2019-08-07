#ifndef __MY_LIB
    #define __MY_LIB
    #include "mydef.h"
#endif

int * getIntArray(unsigned int size);
short intArrayLinearSearch(int *array, int sizeOfArray, int number);
short intArrayBinarySearch(int *array, int sizeOfArray, int number);