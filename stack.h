#ifndef __MY_LIB
    #define __MY_LIB
    #include "mydef.h"
#endif
/**
 * @brief Stack of a stack
 * 
 */
typedef struct stackNode
{
    void *data_ptr;
    char *type;
    struct stackNode *up, *down;
}stackNode;

stackNode * getStackNode(void *data_ptr, char *type, stackNode *up, stackNode *down);
stackNode * push(void *data_ptr, char *type, stackNode *TOP);
stackNode * pop(stackNode **TOP);
unsigned int totalElementsInStack(stackNode *TOP);