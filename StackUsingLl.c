// Author: Ajit J.
// Subject: Data Structures
// Description: Implementation of stack using Doubly Linked List

#include "mydef.h"
#include <sys/resource.h>

// Memory Limit 32MB
struct rlimit r1 = {33554432, 33554432};

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *Top=NULL, *Head=NULL;

// Returns node
struct Node * getNode()
{
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    if(!p)
    {
        printMemNotAvailable();
        exit(1);
    }
    return p;
}

// Creates new node and adds data to it
void push(int data)
{
    if (Head == NULL)               // if there is no node in stack create first
    {
        Top = Head = getNode();
        Top->prev = NULL;
    }
    else {                          // else join new to existing
        Top->next = getNode();
        Top->next->prev = Top;
        Top = Top->next;
    }
    Top->data = data;
    Top->next = NULL;
}

// Retrives data from node and removes that node
int pop()
{
    int data;
    if(!Top)                    // If no Nodes
    {
        fprintf(stderr, Bold_Red "[ERROR]: " Red "Stack Underflow.\n");
        exit(2);
    }
    data = Top->data;           // get data from top node
    if(Top->prev == NULL){      // If node is last node
        free(Top);
        Head = Top = NULL;
    } else {                    // If node is not last
        Top = Top->prev;
        free(Top->next);
    }
    return data;
}

int main(int argc, char const *argv[])
{   
    setrlimit(RLIMIT_AS, &r1);
    ps("Pushing 10 on stack");
    push(10);
    ps("Pushing 20 on stack");
    push(20);
    ps("Pushing 30 on stack");
    push(30);
    ps("Popping from stack: ");
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    while(1) push(10);          // To check mem full
    return 0;
}
