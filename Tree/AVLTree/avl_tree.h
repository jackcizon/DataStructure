#include<config.h>
#include<stddef.h>
#include<string.h>
#include<assert.h>


typedef struct Node 
{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
}
Node;

typedef Node* AVLTree;
AVLTree NewAVLTree(void);
Node* createNode(int key);
int max(int a, int b);
int getHeight(Node* node);
int getBalanceFactor(Node* node);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
Node* insert(Node* root, int key);
Node* minValueNode(Node* node);
Node* deleteNode(Node* root, int key);
void printTree(Node* root);
Node* search(Node* root, int key);