#ifndef GUARD_stack_h
#define GUARD_stack_h

/**
 * @brief Stack node structure
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

#endif