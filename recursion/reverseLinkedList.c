// Author: Ajit Jadhav
// Subject: Data Structures
// Date: 07-06-2019 15:13
// Desc: Reversing Singly Linked List recursively

#include "../mydef.h"
#include <sys/resource.h>

MEM_LIMIT_32MB;

struct Node
{
    long int data;
    struct Node *next;
};

// Return address of allocated node if mem available
struct Node * getNode(int data, struct Node *next)
{
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    if(!p){
        printMemNotAvailable();
        exit(1);
    }
    p->data = data;
    p->next = next;
    return p;
}

// create linked list of length `length`
struct Node * createLinkedList(unsigned int length)
{
    unsigned int i;
    struct Node *head, *p;
    head = p = getNode(0, NULL);
    for(i = 1; i < length; i++)
    {
        p = p->next = getNode(i, NULL);
    }
    return length > 0 ? head : NULL;
}

// Reverse linked list recursively(Non-tail recursion)
void reverseLl(struct Node *p, struct Node *q, struct Node **newHead)
{
    if(!q->next)
    {
        q->next = p;
        *newHead = q;
        return;
    }
    reverseLl(q, q->next, newHead);
    q->next = p;

}

// Print LL
void printLl(struct Node *head)
{
    while(head){
        printf("%ld ", head->data);
        head = head->next;
    }
    ps("");
}

// Free all blocks allocated on heap
// to check leaks use valgrind (disable mem restrictions)
void freeLl(struct Node *head)
{
    struct Node *p = head;
    while(head) {
        /**
         * Just for FUN (comma operator) !
         * Original flow :
         * p = head;
         * free(p);
         * head = head->next();
         */
        head = ((p = head), free(p), head->next);
    }
}

int main(int argc, char const *argv[])
{
    unsigned int len = 0;
    struct Node *HEAD = NULL;

    // Set mem limit 
    setrlimit(RLIMIT_AS, &r1);

    ps("Enter length for linked list: ");
    si(len);
    HEAD = createLinkedList(len);
    ps("Created linked list: ");
    printLl(HEAD);
    reverseLl(NULL, HEAD, &HEAD);
    ps("Reversed linked list: ");
    printLl(HEAD);
    freeLl(HEAD);
    return 0;
}
