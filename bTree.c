 /**
 * @file bTree.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Collection of binary tree functions
 * @date 2019-06-23
 */

#include "bTree.h"

/**
 * @brief Create new node
 *
 * @param data Data to insert
 * @param lp left pointer
 * @param rp right pointer
 * @return Node*
 */
Node * getNode(int data, Node *lp, Node *rp)
{
    Node *p = NULL;
    p = (Node *) malloc(sizeof(Node));
    if(!p)
    {
        printMemNotAvailable();
        exit(1);
    }
    p->data = data;
    p->left = lp;
    p->right = rp;
    return p;
}

/**
 * @brief Insert new node in binary search tree
 *
 * @param data _Data to be inserted in new node_
 * @param root _Root of tree_
 */
void insertBSTNode(int data, Node *root)
{
    if(data <= root->data)
    {
        if(root->left) insertBSTNode(data, root->left);
        else root->left = getNode(data, NULL, NULL);
    } else {
        if(root->right) insertBSTNode(data, root->right);
        else root->right = getNode(data, NULL, NULL);
    }
}

/**
 * @brief Inorder traversal of a binary tree
 *
 * @param root _Root Node of sub tree_
 */
void inorderTraversal(Node *root)
{
    if(!root) return;
    inorderTraversal(root->left);
    pi(root->data);
    inorderTraversal(root->right);
}

/**
 * @brief returns **n**th successor of node **node** in tree.
 *
 * @param root
 *  root of a tree
 * @param node
 * @param n
 * @return Node* nth successor node
 */
Node * nthInorderSuccessor(Node *root, const Node *node, const unsigned int n)
{
    static Node *p = NULL;
    static unsigned int i;
    if (!root || p) return p;

    nthInorderSuccessor(root->left, node, n);

    if(!p && (root->data >= node->data))
        if((root != node) && (++i == n))
            p = root;

    nthInorderSuccessor(root->right, node, n);
}


/**
 * @brief returns true if node has only left child
 *
 * @param root
 * @return short
 */
short hasOnlyLeftChild(Node *root)
{
    return root->left && !root->right;
}

/**
 * @brief returns true if node has only right child
 *
 * @param root
 * @return short
 */
short hasOnlyRightChild(Node *root)
{
    return root->right && !root->left;
}

/**
 * @brief Returns true if node has both child
 *
 * @param root
 * @return short
 */
short hasBothChilds(Node *root)
{
    return root->left && root->right;
}

/**
 * @brief Returns true if node is leaf node
 *
 * @param root
 * @return short
 */
short hasNoChild(Node *root)
{
    return !root->left && !root->right;
}

/**
 * @brief Count the number of nodes in given binary tree recursively
 * @param Node *root Root of tree
 */
int countNodes(Node *root)
{
    if(!root) return 0;
    if(hasNoChild(root))
        return 1;
    if(hasBothChilds(root))
        return 1 + countNodes(root->left) + countNodes(root->right);
    if(hasOnlyLeftChild(root))
        return 1 + countNodes(root->left);
    if(hasOnlyRightChild(root))
        return 1 + countNodes(root->right);
    return 0;
}

/**
 * @brief Returns depth _(root node at level 1)_ of tree recursively
 *
 * @param root
 * @return int
 */
int depthOfTree(Node *root)
{
    int a = 0, b = 0;
    if(!root) return 0;
    return (a = 1 + depthOfTree(root->left)) > (b= 1 + depthOfTree(root->right)) ? a : b;
}

/**
 * @brief Get the Leaf Node Count
 *
 * @param root
 * @return int
 */
int getLeafNodeCount(Node *root)
{
    if(!root) return 0;
    if(hasNoChild(root)) return 1;
    return getLeafNodeCount(root->left) + getLeafNodeCount(root->right);
}

/**
 * @brief Search node in tree of given data
 *      and return pointer to node.
 * @param data
 * @param root
 * @return Node* return address of node if found else NULL
 */
Node * searchNode(int data, Node *root)
{
    while(root && (root->data != data))
    {
        root = data > root->data ? root->right : root->left;
    }
    return root;
}
