#include "mydef.h"

void printOutOfRangeError()
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "row or column index out of range.\n");
}

void printMemNotAvailable()
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "Memory not available.\n");
}

/**
 * @brief print overflow error with type on stderr
 * 
 * @param type example: "queue", "stack"
 */
void printOverflowError(char *type)
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "%s Overflow.\n" Reset, type);
}

/**
 * @brief print underflow error with type on stderr
 * 
 * @param type example: "queue", "stack"
 */
void printUnderflowError(char *type)
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "%s Underflow.\n" Reset, type);
}

/**
 * @brief Prints error with msg on stderr
 * 
 * @param msg 
 */
void printError(char *msg)
{
    fprintf(stderr, Bold_Red "[ERROR]: " Red "%s\n" Reset, msg);
}