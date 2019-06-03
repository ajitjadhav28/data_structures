#include "mydef.h"

void printOutOfRangeError()
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "row or column index out of range.\n");
}