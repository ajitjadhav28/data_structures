/**
 * @file reverseLinkedList.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief  Reversing singly linked list recursively
 * @date  07-06-2019
 */

#include "../mydef.h"
#include <sys/resource.h>

MEM_LIMIT_128MB;

/**
 * @brief Node for singly linked list
 * 
 */
struct LLNode
{
    long int data;
    struct LLNode *next;
};

/**
 * @brief Get the Node object
 * 
 * @param data
 *  data tp insert in node
 * @param next
 *  Next node pointer 
 * @return struct Node* 
 */
struct LLNode * getNode(int data, struct LLNode *next)
{
    struct LLNode *p = (struct LLNode *) malloc(sizeof(struct LLNode));
    if(!p){
        printMemNotAvailable();
        exit(1);
    }
    p->data = data;
    p->next = next;
    return p;
}

/**
 * @brief Create a Linked List of length **length**
 * 
 * @param length 
 * @return struct Node*
 *      root node of created linked list 
 */
struct LLNode * createLinkedList(unsigned int length)
{
    unsigned int i;
    struct LLNode *head, *p;
    head = p = getNode(0, NULL);
    for(i = 1; i < length; i++)
    {
        p = p->next = getNode(i, NULL);
    }
    return length > 0 ? head : NULL;
}

/**
 * @brief Reverse linked list using non-tail recursion
 * 
 * @param p 
 * @param q 
 * @param newHead 
 */
void reverseLl(struct LLNode *p, struct LLNode *q, struct LLNode **newHead)
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

/**
 * @brief prints linked list
 * 
 * @param head
 *  head pointer of linked list
 */
void printLl(struct LLNode *head)
{
    while(head){
        printf("%ld ", head->data);
        head = head->next;
    }
    ps("");
}

/**
 * @brief Free all the blocks of linked list from memory
 * 
 * @param head
 *  head pointer to linked list 
 */
void freeLl(struct LLNode *head)
{
    struct LLNode *p = head;
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
    struct LLNode *HEAD = NULL;

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
