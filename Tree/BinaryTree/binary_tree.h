#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>


#define pass 0

typedef char* string;//cannot cast again


typedef struct node
{
    void* data;
    struct node* lchild;
    struct node* rchild;
}
node;

//Tree is based on recursion, we cannot pass Root(BT) ro modify node.data
//only can use node** to get or modify data 
typedef struct BinaryTree
{
    node* root;
}
BinaryTree;


node* NewNode(void* data);

BinaryTree* NewTree(string data[], size_t size);

void Insert(node** parent, void* data);

void DeleteV1(node** parent, void* data);

node* MinValueNode(node* _node);

void DeleteV2(node** parent, void* data);

void InOrderTraverse(node* root);

void PostOrderTraverse(node* root);

void PreOrderTraverse(node* root);

bool Search(node** parent, void* data);

void Clear(node* parent);

void Destroy(BinaryTree* BT);

node* Root(BinaryTree* BT);

bool SameTree(node* root1, node* root2);

node* LCA(node* parent, void* data1, void* data2);

void* LowestCommonAncestor(BinaryTree* BT, void* data, void* data1, void* data2);

size_t Depth(node* parent);

size_t Length(node* parent);
