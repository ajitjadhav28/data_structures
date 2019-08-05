/**
 * @file stack.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief General stack
 * @date 05-08-2019
 * @subject Data Structures
 * 
 */

#include <stdio.h>
#include "stack.h" 

/**
 * @brief Get the Node object
 * 
 * @param data_ptr Data pointer
 * @param type Type if data
 * @param up poniter to node above
 * @param down pointer to node below
 * @return stackNode* address of created pointer
 */
stackNode * getStackNode(void *data_ptr, char *type, stackNode *up, stackNode *down){
    stackNode *p = NULL;
    p = (stackNode *) malloc(sizeof(stackNode));
    if(!p){
        printMemNotAvailable();
        exit(1);
    }
    p->data_ptr = data_ptr;
    p->type = type;
    p->up = up;
    p->down = down;
    return p;
}

/**
 * @brief Push data on stack
 * 
 * @param data_ptr data pointer
 * @param type type of data
 * @param TOP TOS pointer
 */
stackNode * push(void *data_ptr, char *type, stackNode *TOP)
{
    if (TOP == NULL)               // if there is no node in stack create first
    {
        TOP = getStackNode(data_ptr, type, NULL, NULL);
        return TOP;
    }
    TOP->up = getStackNode(data_ptr, type, NULL, NULL); // else join new to existing
    TOP->up->down = TOP;
    TOP = TOP->up;
    return TOP;
}

/**
 * @brief Pop item from stack
 * 
 * @param TOP TOS pointer
 * @return stackNode* return stack element
 */
stackNode * pop(stackNode **TOP)
{
    stackNode *n = NULL;
    if(!(*TOP))                    // If no Nodes
    {
        printUnderflowError("Stack");
        exit(2);
    }
    if((*TOP)->down == NULL){      // If node is last node
        n = getStackNode((*TOP)->data_ptr, (*TOP)->type, NULL, NULL);
        free(*TOP);
        *TOP = NULL;
    } else {                    // If node is not last
        n = getStackNode((*TOP)->data_ptr, (*TOP)->type, NULL, NULL);
        *TOP = (*TOP)->down;
        free((*TOP)->up);
        (*TOP)->up = NULL;
    }
    return n;
}

/**
 * @brief Returns number of elements currently present in stack
 * 
 * @param TOP TOS pointer
 * @return unsigned int no of elements
 */
unsigned int totalElementsInStack(stackNode *TOP)
{
    if(!TOP) return 0;
    if(TOP->down == NULL) return 1;
    return 1 + totalElementsInStack(TOP->down);
}
