#ifndef __MY_LIB
    #define __MY_LIB
    #include "mydef.h"
#endif

/**
 * @brief Node structure for binary tree
 * - int data : Data to be inserted 
 * - Node *left : left pointer of node
 * 
 */
typedef struct Node
{
    int data, balanceFactor;
    struct Node *left, *right, *parent;
}Node;

Node * getNode(int, Node *lp, Node *rp, Node *pp);
void insertBSTNode(int, Node *, Node **);
void inorderTraversal(Node *);
void preorderTraversal(Node *);
void postorderTraversal(Node *);
short hasOnlyLeftChild(Node *);
short hasOnlyRightChild(Node *);
short hasBothChilds(Node *);
short hasNoChild(Node *);
int countNodes(Node *);
int depthOfTree(Node *);
int getLeafNodeCount(Node *);
Node * searchNode(int, Node *);
Node * nthInorderSuccessor(Node *, const Node *, const unsigned int);
Node * getParentRec(Node *, Node *);
Node * getParent(Node *node);
Node * deleteNode(Node *, Node *);
void updateParentPointers(Node *, Node *, Node *);
void deleteTree(Node *);
void balanceTree(Node **root, Node *new_node);
int getMin(Node *root);
int getMax(Node *root);