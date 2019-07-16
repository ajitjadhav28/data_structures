/**
 * @file bst.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Implementation of binary search tree
 * @date 2019-06-23
 * @subject Data Structures
 */
#include "bTree.h"
#include<sys/resource.h>
#include <time.h>

/**
 * @brief Calculates time in seconds
 */
#define TimeInSec(x) ((double)clock()-x)/CLOCKS_PER_SEC

/**
 * @brief RANDOM_RANGE for rand()
 */
#define RANDOM_RANGE 99999

/**
 * @brief Random() macro to get random numbers below RANDOM_RANGE
 */
#define Random() (rand()%RANDOM_RANGE)

#ifndef __MY_LIB
    #define __MY_LIB
    #include "mydef.h"
#endif

MEM_LIMIT_128MB;

/**
 * @brief main function of binary search tree.  
 * 
 * @param argc Not used
 * @param argv Not used
 * @return int 0
 */
int main(int argc, char const *argv[])
{
    unsigned int n = 0, i = 0;
    clock_t start, end;
    setrlimit(RLIMIT_AS, &r1);
    Node *root = getNode(9, NULL, NULL, NULL);
    insertBSTNode(5, root, &root);
    insertBSTNode(7, root, &root);
    insertBSTNode(10, root, &root);
    insertBSTNode(11, root, &root);
    insertBSTNode(3, root, &root);
    insertBSTNode(1, root, &root);
    insertBSTNode(2, root, &root);
    insertBSTNode(8, root, &root);
    insertBSTNode(15, root, &root);
    insertBSTNode(13, root, &root);
    ps("\nInorder traversal: ");
    inorderTraversal(root);
    ps("\npreorder traversal: ");
    preorderTraversal(root);
    ps("\npostorder traversal: ");
    postorderTraversal(root);
    printf("\nTotal no of nodes: %d\n", countNodes(root));
    printf("Depth of a Tree: %d\n", depthOfTree(root));
    printf("Leaf nodes: %d\n", getLeafNodeCount(root));
    printf("Minimum : %d\nMaximum : %d\n", getMin(root), getMax(root));
    // ps("Deleting node 6:");
    // deleteNode(root, searchNode(6, root));
    // ps("Inorder traversal: ");
    // inorderTraversal(root);
    deleteTree(root);
    printf( Bold_Cyan "\nSize of int : %ld\nSize of pointer : %ld\nSize of node : %ld\n" Reset, sizeof(int), sizeof(Node *), sizeof(Node));
    ps("\nEnter no of nodes to create tree with random data (enter 0 to exit): ");
    scanf("%u", &n);
    if(n <= 0 ) exit(0);
    start = clock();
    root = getNode(Random(), NULL, NULL, NULL);
    printf("Time required to create 1 node : %f sec.\n", TimeInSec(start));
    start = clock();
    while(--n){
        // scanf("%d", &i);
        insertBSTNode(Random(), root, &root);
    }
    printf("\nTime Required : %f sec.", TimeInSec(start));
    printf("\nTotal no of nodes: %d\n", countNodes(root));
    printf("Depth of a Tree: %d\n", depthOfTree(root));
    // ps("Inorder traversal: ");
    // inorderTraversal(root);
    for(n = 0; n < 3; n++){
        printf(Red "\n[TRY-%d] " Reset "Enter number to search in tree (0-%d): ", n, RANDOM_RANGE);
        scanf("%d", &i);
        start = clock();
        i = searchNode(i, root) && 1;
        end = clock();
        if(i)
            printf(Green "Number found in %f sec.\n" Reset, (double)(end - start)/CLOCKS_PER_SEC);
        else
            printf(Red "Number not found. Time to search tree: %f sec.\n" Reset, (double)(end - start)/CLOCKS_PER_SEC);
    }
    printf("Minimum : %d\nMaximum : %d\n", getMin(root), getMax(root));
    deleteTree(root);
    return 0;
}
