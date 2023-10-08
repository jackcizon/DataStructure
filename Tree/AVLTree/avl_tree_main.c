#include"avl_tree.h"
#include <stdio.h>
#include <stdlib.h>



int main() {
    Node* root = NewAVLTree();
    int keys[] = {50, 25, 75, 15, 35, 60, 120, 10, 68, 90, 125, 83, 100};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    printf("Preorder traversal of AVL tree:\n");
    printTree(root);
    printf("\n");

    int searchKey = 125;
    Node* result = NULL;
    result = search(root, searchKey);
    printf("Search for %d: %s\n", searchKey, (result != NULL) ? "Found" : "Not found");

    searchKey = 1;
    result = search(root, searchKey);
    printf("Search for %d: %s\n", searchKey, (result != NULL) ? "Found" : "Not found");

    int deleteKey = 120;
    root = deleteNode(root, deleteKey);
    printf("\nAfter deleting %d:\n", deleteKey);
    printTree(root);
    printf("\n");

    deleteKey = 10;
    root = deleteNode(root, deleteKey);
    printf("After deleting %d:\n", deleteKey);
    printTree(root);
    printf("\n");

    return 0;
}
