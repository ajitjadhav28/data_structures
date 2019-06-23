#ifndef __MY_LIB
    #define __MY_LIB
    #include "mydef.h"
#endif

/**
 * @brief Node structure
 * - int data : Data to be inserted 
 * - Node *left : left pointer of node
 * 
 */
typedef struct Node
{
    int data;
    struct Node *left, *right;
}Node;

Node * getNode(int, Node *, Node *);
void insertBSTNode(int, Node *);
void inorderTraversal(Node *);
short hasOnlyLeftChild(Node *);
short hasOnlyRightChild(Node *);
short hasBothChilds(Node *);
short hasNoChild(Node *);
int countNodes(Node *);
int depthOfTree(Node *);
int getLeafNodeCount(Node *);