#include"avl_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdarg.h>


AVLTree NewAVLTree(void)
{
    AVLTree avl_tree = (AVLTree)malloc(sizeof *avl_tree);
    avl_tree = NULL;
    return avl_tree;
}

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* node) {
    return (node != NULL) ? node->height : 0;
}

int getBalanceFactor(Node* node) {
    return (node != NULL) ? (getHeight(node->left) - getHeight(node->right)) : 0;
}

Node* updateBalanceFactor(int balance, Node* root)
{
    // LL rotate
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // RR
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // LR
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // all balanced
    return root;
}

/**
 * @brief rightRotate
 * @brief avl tree satisfies lc <= parent <= rc
 * @param parent 
 * @return Node* 
 * 
 * @details
 * 
 *       A                            P ---> A
 *     /   \        ll insert              /   \
 *    B    AR   --------------->  LC ---> B    AR
 *  /  \      (insert after b's BL)     /  \  
 * BL  BR                              BL  BR  <--- T2
 *                                    /
 *                                   i
 * BL < B < BR < A < AR       i < BL < B < BR < A < AR
 * 
 * after inserting, tree is not balnaced,
 * because i < BL < B, so i and BL still in B's left
 * because A > B, so A is B's rc
 * because B < BR < A, so A's lc is BR
 * 
 * after rotating:
 *           B
 *         /   \
 *        BL   A
 *       /   /   \ 
 *      i   BR   AR
 * 
 * tree is balanced
 */
Node* rightRotate(Node* parent) {
    Node* LC = parent->left;
    Node* T2 = LC->right;

    LC->right = parent;
    parent->left = T2;

    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    LC->height = max(getHeight(LC->left), getHeight(LC->right)) + 1;

    return LC;
}

Node* leftRotate(Node* parent) {
    Node* RC = parent->right;
    Node* T2 = RC->left;

    RC->left = parent;
    parent->right = T2;

    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    RC->height = max(getHeight(RC->left), getHeight(RC->right)) + 1;

    return RC;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalanceFactor(root);
    
    return updateBalanceFactor(balance, root);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalanceFactor(root);

    return updateBalanceFactor(balance, root);
}

void printTree(Node* root) {
    if (root) {
        printf("%d ", root->key);
        printTree(root->left);
        printTree(root->right);
    }
    // before deleting:
    /**
     *            50 
     *     25             75
     *   15  35      60        120
     * 10          68  68    90     125
     *                   83   100   
     */                
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}
