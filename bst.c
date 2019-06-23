/**
 * @file bst.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Implementation of binary search tree
 * @date 2019-06-23 
 */
#include "bTree.h"
#include<sys/resource.h>

#ifndef __MY_LIB
    #define __MY_LIB
    #include "mydef.h"
#endif

MEM_LIMIT_32MB;

int main(int argc, char const *argv[])
{
    setrlimit(RLIMIT_AS, &r1);
    Node *root = getNode(9, NULL, NULL);
    insertBSTNode(3, root);
    insertBSTNode(1, root);
    insertBSTNode(4, root);
    insertBSTNode(7, root);
    insertBSTNode(5, root);
    insertBSTNode(6, root);
    insertBSTNode(11, root);
    insertBSTNode(12, root);
    ps("Inorder traversal: ");
    inorderTraversal(root);
    printf("\nTotal no of nodes: %d\n", countNodes(root));
    printf("Depth of a Tree: %d\n", depthOfTree(root));
    printf("Leaf nodes: %d\n", getLeafNodeCount(root));
    return 0;
}
