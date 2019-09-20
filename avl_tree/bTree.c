 /**
 * @file bTree.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Collection of binary tree (with height balancing) functions
 * @date 2019-06-23
 */

#include "bTree.h"
#include "../mydef.h"

/**
 * @brief Create new node
 *
 * @param data Data to insert
 * @param lp left pointer
 * @param rp right pointer
 * @param pp parent pointer
 * @return Node*
 */
Node * getNode(int data, Node *lp, Node *rp, Node *pp)
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
    p->parent = pp;
    return p;
}

/**
 * @brief Insert new node in binary search tree
 *
 * @param data _Data to be inserted in new node_
 * @param root _Root of tree_
 * @param r Pointer to root pointer.
 */
void insertBSTNode(int data, Node *root, Node **r)
{
    if(data <= root->data)
    {
        if(root->left) insertBSTNode(data, root->left, r);
        else {
            root->left = getNode(data, NULL, NULL, root);
            debug_print("%d Inserted\n", data);
            // pi(data);ps("Inserted");
            balanceTree(r, root->left);
        }
    } else {
        if(root->right) insertBSTNode(data, root->right, r);
        else {
            root->right = getNode(data, NULL, NULL, root);
            debug_print("%d Inserted\n", data);
            // pi(data);ps("Inserted");
            balanceTree(r, root->right);
        }
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
    printf("%d ", root->data);
    // pi(root->data);
    inorderTraversal(root->right);
}

/**
 * @brief Iterative inorder traversal using stack
 *
 * @param root Root Node of tree
 */
void inorderTraversalIt(Node *root)
{
    stackNode *tos = NULL, *n = NULL;
    if(root == NULL) return;
    do {
        while(root) {
            tos = push((void *) root, NODE_TYPE, tos);
            root = root->left;
        }
        if(!root && tos){
            n = pop(&tos);
            root = (Node *) n->data_ptr;
            free(n);
            printf("%d ", root->data);
            root = root->right;
        }
    } while(tos || root);
}

/**
 * @brief Iterative preorder traversal using stack
 *
 * @param root Root of tree
 */
void preorderTraversalIt(Node *root)
{
    stackNode *tos = NULL, *n = NULL;
    if(root == NULL) return;
    do {
        while(root) {
            printf("%d ", root->data);
            tos = push((void *) root, NODE_TYPE, tos);
            root = root->left;
        }
        if(!root && tos){
            n = pop(&tos);
            root = (Node *) n->data_ptr;
            free(n);
            root = root->right;
        }
    } while(tos || root);
}

/**
 * @brief Preorder traversal of tree from root
 *
 * @param root root of a tree
 */
void preorderTraversal(Node *root)
{
    if(!root) return;
    pi(root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

/**
 * @brief Postorder traversal of tree
 *
 * @param root root of a tree
 */
void postorderTraversal(Node *root)
{
    if(!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    pi(root->data);
}

/**
 * @brief Iterative version of postorder traversal using two stacks
 *
 * @param root Root node of a tree
 */
void postorderTraversalIt(Node *root){
    stackNode *tos1 = NULL, *tos2 = NULL, *tmp = NULL;
    if(root == NULL)
        return;
    tos1 = push((void *) root, NODE_TYPE, tos1);
    while (tos1)
    {
        tmp = pop(&tos1);
        root = (Node *) tmp->data_ptr;
        free(tmp);
        if(root->left)
            tos1 = push((void *)root->left, NODE_TYPE, tos1);
        if(root->right)
            tos1 =  push((void *)root->right, NODE_TYPE, tos1);
        tos2 = push((Node *)root, NODE_TYPE, tos2);
    }
    while (tos2)
    {
        tmp = pop(&tos2);
        printf("%d ", ((Node *)tmp->data_ptr)->data);
        free(tmp);
    }

}

/**
 * @brief levelOrderTraversal
 * 
 * @param root Root of tree
 */
void levelOrderTraversal(Node *root){
    stackNode *tos = NULL, *tmp = NULL;
    tos = push((void *) root, NODE_TYPE, tos);
    while(tos){
        while(tos){
            if(tmp == NULL)
                tmp = pop(&tos);
            else {
                tmp->down = pop(&tos);
                tmp->down->up = tmp;
                tmp = tmp->down;
            }
            root = (Node *)tmp->data_ptr;
            printf("%d ", root->data);
        }
        while (tmp)
        {
            root = (Node *)tmp->data_ptr;
            if(root->right)
                tos = push((void *) root->right, NODE_TYPE, tos);
            if(root->left)
                tos = push((void *) root->left, NODE_TYPE, tos);
            if(tmp->up == NULL){
                free(tmp);
                tmp = NULL;
            }
            else{
            tmp = tmp->up;
            free(tmp->down);
            }
        }

    }
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
 * @return int count
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

/**
 * @brief Get the Parent node of **node** without using parent pointer
 *
 * @param root root of tree
 * @param node
 * @return Node*
 */
Node * getParentRec(Node *root, Node *node)
{
    if(!root) return NULL;
    if((root->left == node) || (root->right == node))
        return root;
    if(node->data <= root->data)
        getParentRec(root->left, node);
    else getParentRec(root->right, node);
}

/**
 * @brief Get the Parent node if exists
 *
 * @param node
 * @return Node*
 */
Node * getParent(Node *node)
{
    return node ? node->parent : NULL;
}

/**
 * @brief Update left and right pointers of parent of node **node**
 *  with value **val**
 *
 * @param root root of tree
 * @param node
 * @param val
 */
void updateParentPointers(Node *root, Node *node, Node *val)
{
    Node *tmp = getParent(node);
    if(!tmp) {
        printError("Parent of given node not found!");
        exit(1);
    }
    if(tmp->left == node)
        tmp->left = val;
    else
        tmp->right = val;
}

/**
 * @brief Delete node from tree.
 *
 * @param root root of tree
 * @param node node to delete
 * @param r pointer to root pointer
 */
void deleteNode(Node *root, Node *node, Node **r)
{
    Node *tmp;
    if(!node || !root) return;
    if(hasNoChild(node)){
        updateParentPointers(root, node, NULL);
        tmp = node->parent;
        free(node);
        balanceTree(r, tmp);
    }
    if(hasOnlyLeftChild(node)){
        if(root != node) {
            updateParentPointers(root, node, node->left);
            tmp = node->parent;
            free(node);
            balanceTree(r, tmp);
        }
        tmp = root->left;
        free(root);
        balanceTree(r, tmp);
    }
    if(hasOnlyRightChild(node)){
        if(root != node){
            updateParentPointers(root, node, node->right);
            tmp = node->parent;
            free(node);
            balanceTree(r, tmp);

        }
        tmp = root->right;
        free(root);
        balanceTree(r, tmp);
    }
    if(hasBothChilds(node)){
        tmp = nthInorderSuccessor(root, node, 1);
        // instead of deleting node replacing data to minimize computation
        node->data = tmp->data;
        deleteNode(root, tmp, r);
        balanceTree(r, tmp->parent);
    }
}

/**
 * @brief Remove tree from memory
 *
 * @param root root of a tree
 */
void deleteTree(Node *root)
{
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    if(root) free(root);
}

/**
 * @brief Return 1 if **node** is left child of parent else 0
 *
 * @param node
 * @return short
 */
short isLeftChild(Node *node)
{
    return node->parent->left == node;
}

/**
 * @brief Apply LL rotation
 *
 * @param node imbalanced node
 * @return Node* new root
 */
Node * llRotation(Node *node)
{
    Node *p = node->left;
    //printf(" Data at pointer p : right child=%d\n", p->right->data);
    p->parent = node->parent;
    node->left = p->right;
    p->right = node;
    node->parent = p;
    if(node->left)
        node->left->parent = node;
    return p;
}

/**
 * @brief Apply RR Rotation
 *
 * @param node imbalanced node
 * @return Node* new root
 */
Node * rrRotation(Node *node)
{
    Node *p = node->right;
    p->parent = node->parent;
    node->right = p->left;
    p->left = node;
    node->parent = p;
    if(node->right)
        node->right->parent = node;
    return p;
}

/**
 * @brief Apply LR rotation
 *
 * @param node imbalanced node
 * @return Node* new root
 */
Node * lrRotation(Node *node)
{
    Node *nr = getNode(node->left->right->data, node->left, node, NULL);
    Node *p = node->left->right;
    node->left->parent = node->parent = nr;
    node->left = p->right;
    nr->left->right = p->left;
    free(p);
    if(nr->right->left)
        nr->right->left->parent = nr->right;
    if(nr->left->right)
        nr->left->right->parent = nr->left;
    return nr;
}

/**
 * @brief Apply RL Rotation
 *
 * @param node imbalanced node
 * @return Node* new root
 */
Node * rlRotation(Node *node)
{
    Node *nr = getNode(node->right->left->data, node, node->right, NULL);
    Node *p = node->right->left;
    node->right->parent = nr;
    node->parent = nr;
    node->right = p->left;
    nr->right->left = p->right;
    free(p);
    if(nr->right->left)
        nr->right->left->parent = nr->right;
    if(nr->left->right)
        nr->left->right->parent = nr->left;
    return  nr;
}

/**
 * @brief Update balance factors of entire tree
 *
 * @param root root of tree
 */
void updateBalanceFactors(Node *root)
{
    if(!root) return;
    root->balanceFactor = depthOfTree(root->left) - depthOfTree(root->right);
    updateBalanceFactors(root->left);
    updateBalanceFactors(root->right);
}

/**
 * @brief Get the Balance Factor of a node
 *
 * @param node node
 * @return int balance factor
 */
int getBalanceFactor(Node *node)
{
    if(!node) { printError("NULL pointer exception in getBalanceFactor()!"); exit(1); }
    if(!node->right && !node->left) return 0;
    return depthOfTree(node->left) - depthOfTree(node->right);
}

/**
 * @brief Detect which type of imbalance occured and apply rotation accordingly
 *
 * @param root root of the tree
 * @param node imbalanced node
 */
void applyRotation(Node **root, Node *node)
{
    Node *p = node->parent;
    if(node->balanceFactor == 2 && node->left->balanceFactor >= 0 ){
        debug_print(Yellow"Applying ll rotation at Node[%d]\n"Reset, node->data);
        if(!p){
            *root = llRotation(node);
            (*root)->parent = NULL;
        }
        else{
            if(isLeftChild(node)) {
                p->left = llRotation(node);
                p->left->parent = p;
            }
            else if(!isLeftChild(node)) {
                p->right = llRotation(node);
                p->right->parent = p;
            }
        }
    }
    else if(node->balanceFactor == -2 && node->right->balanceFactor <= 0 ){
        debug_print(Yellow"Applying rr rotation at Node[%d]\n"Reset, node->data);
        if(!p){
            *root = rrRotation(node);
            (*root)->parent = NULL;
        }
        else{
            if(isLeftChild(node)) {
                p->left = rrRotation(node);
                p->left->parent = p;
            }
            else if(!isLeftChild(node)) {
                p->right = rrRotation(node);
                p->right->parent = p;
            }
        }
    }
    else if(node->balanceFactor == -2 && node->right->balanceFactor == 1){
        debug_print(Yellow"Applying rl rotation at Node[%d]\n"Reset, node->data);
        if(!p){
            *root = rlRotation(node);
            (*root)->parent = NULL;
        }
        else{
            if(isLeftChild(node)) {
                p->left = rlRotation(node);
                p->left->parent = p;
            }
            else if(!isLeftChild(node)) {
                p->right = rlRotation(node);
                p->right->parent = p;
            }
        }
    }
    else if(node->balanceFactor == 2 && node->left->balanceFactor == -1){
        debug_print(Yellow"Applying lr rotation at Node[%d]\n"Reset, node->data);
        if(!p){
            *root = lrRotation(node);
            (*root)->parent = NULL;
        }
        else{
            if(isLeftChild(node)){
                p->left = lrRotation(node);
                p->left->parent = p;
            }
            else if(!isLeftChild(node)) {
                p->right = lrRotation(node);
                p->right->parent = p;
            }
        }
    }
    // ps("Inorder Traversal: ");
    // inorderTraversal(*root);
}

/**
 * @brief Detect imbalance and passes imbalanced node to applyRotation()
 *
 * @param root Root of the tree
 * @param new_node newly inserted node
 */
void balanceTree(Node **root, Node *new_node)
{
    if(!root || !new_node) return;
    while(new_node)
    {
        new_node->balanceFactor = getBalanceFactor(new_node);
        debug_print("{%d}Node[%d](%d){%d}_____Balance_Factor[%d]\n", new_node->left ? new_node->left->data : 0, new_node->data, new_node->parent ? new_node->parent->data: 0, new_node->right ? new_node->right->data : 0, new_node->balanceFactor);
        if(abs(new_node->balanceFactor) >= 2)
        {
            debug_print(Red "Imbalance detected\n"Reset, NULL);
            applyRotation(root, new_node);
            break;
        }
        new_node = new_node->parent;
    }
}

/**
 * @brief Get the Min data in tree
 *
 * @param root
 * @return int
 */
int getMin(Node *root)
{
    if(!root->left)
        return root->data;
    return getMin(root->left);
}

/**
 * @brief Get the Max data in tree
 *
 * @param root
 * @return int
 */
int getMax(Node *root)
{
    if(!root->right)
        return root->data;
    return getMax(root->right);
}

/**
 * @brief Calculates width of a tree.
 *
 * @param root Root of tree
 * @return int Width of tree
 */
int widthOfTree(Node *root)
{
    if(!root) return -1;
    return depthOfTree(root->left) + depthOfTree(root->right) + 1;
}
