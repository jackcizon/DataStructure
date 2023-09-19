#pragma once

#include"config.h"
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>

/**
 * @brief unit of ThrBTree
 * 
 * @param ltag: bool
 *      if lchild is null, then ltag is true, otherwise fasle
 * @param rtag: bool
 *      
 *     if rchild is null, then rtag is true, otherwise fasle
 */

typedef struct node
{
    void* data;
    struct node* lchild;
    struct node* rchild;
    bool ltag;
    bool rtag;
}
node;

typedef struct ThrBTree
{
    node* root;
}
ThrBTree;

node* NewNode(void* data);

ThrBTree* NewTree(string data[], size_t size);

void Insert(node** parent, void* data);

void Delete(node** parent, void* data);

node* MinValueNode(node* _node);

void InOrderTraverse(node* root);

void PostOrderTraverse(node* root);

void PreOrderTraverse(node* root);

bool Search(node** parent, void* data);

void Clear(node* parent);

void Destroy(ThrBTree* BT);

node* Root(ThrBTree* BT);

bool SameTree(node* root1, node* root2);

node* LCA(node* parent, void* data1, void* data2);

void* LowestCommonAncestor(ThrBTree* BT, void* data, void* data1, void* data2);

size_t Depth(node* parent);

size_t Length(node* parent);

void* LeftChild(node** parent);

void* RightChild(node** parent);