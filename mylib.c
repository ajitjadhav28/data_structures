#include "mydef.h"

void printOutOfRangeError()
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "row or column index out of range.\n");
}

void printMemNotAvailable()
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "Memory not available.\n");
}

void printOverflowError(char *type)
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "%s Overflow.\n" Reset, type);
}

void printUnderflowError(char *type)
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "%s Underflow.\n" Reset, type);
}

void printError(char *msg)
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "%s\n" Reset, msg);
}