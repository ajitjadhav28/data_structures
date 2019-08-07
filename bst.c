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
#include <math.h>
#include <assert.h>
#include <signal.h>
#include "darray.h"

/**
 * @brief Calculates time in seconds
 */
#define TimeInSec(x, y) ((double)y-x)/CLOCKS_PER_SEC

/**
 * @brief RANDOM_RANGE for rand()
 */
#define RANDOM_RANGE 999999

/**
 * @brief Random() macro to get random numbers below RANDOM_RANGE
 */
#define Random() (rand()%RANDOM_RANGE)

#ifndef __MY_LIB
    #define __MY_LIB
    #include "mydef.h"
#endif

MEM_LIMIT_4GB;

volatile sig_atomic_t sigInt = 0;

void handle_interrupt(int sig) {
    sigInt = 1;
}

/**
 * @brief main function of binary search tree.  
 * 
 * @param argc Not used
 * @param argv Not used
 * @return int 0
 */
int main(int argc, char const *argv[])
{
    unsigned int n = 0, i = 0, t = 0;
    int *array, sz, *tmp;
    clock_t start, end;
    // FILE *f_ptr = NULL;
    setrlimit(RLIMIT_AS, &r1);
    
    Node *root = getNode(9, NULL, NULL, NULL);
    
    insertBSTNode(5, root, &root);
    insertBSTNode(7, root, &root);
    insertBSTNode(10, root, &root);
    debug_print("Deleting node: %d\n", 5);
    deleteNode(root, searchNode(5, root), &root);
    insertBSTNode(11, root, &root);
    insertBSTNode(3, root, &root);
    insertBSTNode(1, root, &root);
    insertBSTNode(2, root, &root);
    insertBSTNode(8, root, &root);
    insertBSTNode(15, root, &root);
    insertBSTNode(13, root, &root);
    ps("\nInorder traversal: ");
    inorderTraversal(root);
    ps("\nIterative Inorder traversal: ");
    inorderTraversalIt(root);
    ps("\npreorder traversal: ");
    preorderTraversal(root);
    ps("\nIterative Preorder traversal: ");
    preorderTraversalIt(root);
    ps("\npostorder traversal: ");
    postorderTraversal(root);
    n = countNodes(root);
    i = depthOfTree(root) - 1;
    assert(1.44*log2(n) >= i);
    printf("\nTotal no of nodes: %d\n", n);
    printf("Depth of a Tree: %d\n", i);
    printf("Width of a tree: %d\n", widthOfTree(root));
    printf("Leaf nodes: %d\n", getLeafNodeCount(root));
    printf("Minimum : %d\nMaximum : %d\n", getMin(root), getMax(root));
    deleteTree(root);
    printf( Bold_Cyan "\nSize of int : %ld\nSize of pointer : %ld\nSize of node : %ld\n" Reset, sizeof(int), sizeof(Node *), sizeof(Node));
    ps("\nEnter no of nodes to create tree with random data (enter 0 to exit): ");
    scanf("%u", &n);
    if(n <= 0 ) exit(0);
    // f_ptr = fopen("avl_insertion_performance.csv", "w+");
    // fprintf(f_ptr, "Sequence Number,Node,time\n");
    // if(!f_ptr){
    //     printError("Can't open file!");
    //     exit(1);
    // }
    // t = Random();
    i = 1;
    root = getNode(1, NULL, NULL, NULL);
    tmp = array = getIntArray(n);
    sz = n;
    *tmp++ = 1; 
    while(--n){
        //t = Random();            
        // start = clock();
        insertBSTNode(++i, root, &root);
        // end = clock();
        *tmp++ = i;
        // fprintf(f_ptr, "%d,%d,%f\n", i, n, TimeInSec(start, end));
        if(sigInt)
            deleteTree(root);
    }
    // fclose(f_ptr);
    n = countNodes(root);
    i = depthOfTree(root) - 1;
    if(n > 1)
        assert(1.44*log2(n) >= i-1);  // halt if height is more than worst case
    printf("\nTotal no of nodes: %d\n", n);
    printf("Depth of a Tree: %d\n", i);
    printf("Width of a tree: %d\n", widthOfTree(root));
    printf("Minimum : %d\nMaximum : %d\n", getMin(root), getMax(root));
    
    // start = clock();
    // inorderTraversal(root);
    // end = clock();
    // printf("Recursive traversal time: %f sec.\n", TimeInSec(start, end));
    
    // start = clock();
    // inorderTraversalIt(root);
    // end = clock();
    // printf("Iterative traversal time: %f sec.\n", TimeInSec(start, end));
    n = 1;
    while(1){
        printf(Red "\n[TRY-%d] " Reset "Enter number to search in tree: ", n++);
        scanf("%d", &i);
        start = clock();
        t = searchNode(i, root) && 1;
        end = clock();
        if(t)
            printf(Bold_Green "[TREE] " Green "Number found in %f sec.\n" Reset, (double)(end - start)/CLOCKS_PER_SEC);
        else
            printf(Red "[TREE] " Red "Number not found. Time to search tree: %f sec.\n" Reset, (double)(end - start)/CLOCKS_PER_SEC);
        start = clock();
        t = intArrayLinearSearch(array, sz, i);
        end = clock();
        if(t)
            printf(Bold_Green "[ARRAY_LINEAR] " Green "Number found in %f sec.\n" Reset, (double)(end - start)/CLOCKS_PER_SEC);
        else
            printf(Bold_Red "[ARRAY_LINEAR] " Red "Number not found. Time to search tree: %f sec.\n" Reset, (double)(end - start)/CLOCKS_PER_SEC);
        start = clock();
        t = intArrayBinarySearch(array, sz, i);
        end = clock();
        if(t)
            printf(Bold_Green "[ARRAY_BINARY] " Green "Number found in %f sec.\n" Reset, (double)(end - start)/CLOCKS_PER_SEC);
        else
            printf(Bold_Red "[ARRAY_BINARY] " Red "Number not found. Time to search tree: %f sec.\n" Reset, (double)(end - start)/CLOCKS_PER_SEC);
        if(sigInt) {
            deleteTree(root);
            free(array);
        }
    }
    return 0;
}
