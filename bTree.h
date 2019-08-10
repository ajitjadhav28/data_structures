#ifndef GUARD_bTree_h
#define GUARD_bTree_h

#include "stack.h"

#define NODE_TYPE "B_TREE"

/**
 * @brief Node structure for binary tree
 * - int data : Data to be inserted 
 * - Node *left : left pointer of node
 * - Node *right : right pointer of node
 * - Node *parent : parent pointer of node
 */
typedef struct Node
{
    int data, balanceFactor;
    struct Node *left, *right, *parent;
}Node;

Node * getNode(int, Node *lp, Node *rp, Node *pp);
void insertBSTNode(int, Node *, Node **);
void inorderTraversal(Node *);
void inorderTraversalIt(Node *root);
void preorderTraversalIt(Node *root);
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
void deleteNode(Node *root, Node *node, Node **r);
void updateParentPointers(Node *, Node *, Node *);
void deleteTree(Node *);
void balanceTree(Node **root, Node *new_node);
int getMin(Node *root);
int getMax(Node *root);
int widthOfTree(Node *root);

#endif