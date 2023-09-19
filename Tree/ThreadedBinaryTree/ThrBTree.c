#include"ThrBTree.h"

node* NewNode(void* data)
{
    node* new_node = (node*)malloc(sizeof *new_node);
    new_node->data = data;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    new_node->ltag = true;
    new_node->rtag = true;
    return new_node;
}

ThrBTree* NewTree(string data[], size_t size)
{
    ThrBTree* new_tree = (ThrBTree*)malloc(sizeof(ThrBTree));
    new_tree->root = NULL;
    for (size_t i = 0; i < size; i++)
    {
        Insert(&(new_tree->root), data[i]);
    }
    return new_tree;
}


node* Root(ThrBTree* TBT)
{
    assert(TBT->root);
    return TBT->root;
}

void InOrderTraverse(node* root)
{
    if(root == NULL)
    {
        return;
    }
    InOrderTraverse(root->lchild);
    printf("%s ", (string)root->data);
    InOrderTraverse(root->rchild);
}

 
void PostOrderTraverse(node* root)
{
    if(root == NULL)
    {
        return;
    }  
    PostOrderTraverse(root->lchild);
    PostOrderTraverse(root->rchild);
    printf("%s", (string)root->data);
}


void PreOrderTraverse(node* root)
{   
    if(!root)
    {
        return;
    }
    printf("%s ", (string)root->data);
    PreOrderTraverse(root->lchild);
    PreOrderTraverse(root->rchild);
}


bool SameTree(node* root1, node* root2)
{   
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if(strcmp(root1->data, root2->data) == 0
        && SameTree(root1->lchild, root2->lchild)
            && SameTree(root1->rchild, root2->rchild))
    {
        return true;
    }
    return false;
}


node* MinValueNode(node* _node)
{
    node* current = _node;

    // find the lchildmost leaf node
    while (current && current->lchild != NULL)
    {
        current = current->lchild;
    }

    return current;
}


bool Search(node** parent, void* data)
{
    if(*parent == NULL)
    {
        return false;
    }
    else if(strcmp(data, (*parent)->data) < 0)
    {
        Search(&(*parent)->lchild, data);
    }
    else if(strcmp(data, (*parent)->data) > 0)
    {
        Search(&(*parent)->rchild, data);
    }
    else
    {
        return true;
    }
    return false;
}


void Clear(node* parent)
{
    if(parent == NULL)
    {
        return;
    }
    Clear(parent->lchild);
    Clear(parent->rchild);
    free(parent);
}


void Destroy(ThrBTree* BT)
{
    Clear(Root(BT));
    free(BT);
    BT = NULL;
}


node* LCA(node* parent, void* data1, void* data2)
{
    if(parent == NULL)
    {
        return NULL;
    }
    if(strcmp(parent->data, data1) == 0 || strcmp(parent->data, data2) == 0)
    {
        return parent;
    }

    node* left_lca = LCA(parent->lchild, data1, data2);
    node* right_lca = LCA(parent->rchild, data1, data2);

    if(left_lca != NULL && right_lca != NULL)
    {
        return parent;
    }
    if(left_lca != NULL)
    {
        return left_lca;
    }
    if(right_lca != NULL)
    {
        return right_lca;
    }
    return NULL;
}

void* LowestCommonAncestor(ThrBTree* BT, void* data, void* data1, void* data2)
{
    node* lca = LCA(Root(BT), data1, data2);
    if (lca == NULL)
    {
        return NULL;
    }
    else
    {
        return lca->data;
    }
}


size_t Length(node* parent)
{
    if (parent == NULL)
    {
        return 0;
    }
    else
    {
        return Length(parent->lchild) + Length(parent->rchild) + 1;
    }
}


size_t Depth(node* parent)
{
    if (parent == NULL)
    {
        return 0;
    }else
    {
        size_t left_Depth = Depth(parent->lchild);
        size_t right_Depth = Depth(parent->rchild);
        return (left_Depth > right_Depth ? left_Depth : right_Depth) + 1;
    }
}

void* LeftChild(node** parent)
{
    if (*parent == NULL)
    {
        return NULL;
    }
    else
    {
        return (*parent)->lchild->data;
    }
}


void* RightChild(node** parent)
{
    if (parent == NULL)
    {
        return NULL;
    }
    else
    {
        return (*parent)->rchild->data;
    }
}

//thread has error
void Insert(node** parent, void* data)
{
    if(*parent == NULL)
    {
        *parent = NewNode(data);
        return;
    }

    //check if data > BT.root.data or not
    strcmp(data, (*parent)->data) <= 0 ?
        Insert(&(*parent)->lchild, data) :
            Insert(&(*parent)->rchild, data);
}


void Delete(node** parent, void* data) {
    if(*parent == NULL)
    {
        return;
    }
    else if(strcmp(data , (*parent)->data) < 0)
    {
        Delete(&(*parent)->lchild, data);
    }
    else if(strcmp(data, (*parent)->data) > 0)
    {
        Delete(&(*parent)->rchild, data);
    }
    else
    {   // Case 1
        if((*parent)->lchild == NULL && (*parent)->rchild == NULL)
        { 
            free(*parent);
            *parent = NULL;
        }
        // Case 2
        else if((*parent)->lchild == NULL)
        { 
            node* temp = *parent;
            *parent = (*parent)->rchild;
            free(temp);
        }
        // Case 2
        else if((*parent)->rchild == NULL)
        { 
            node* temp = *parent;
            *parent = (*parent)->lchild;
            free(temp);
        }
        // Case 3
        else
        { 
            node* temp = (*parent)->rchild;
            while(temp->lchild != NULL)
            {
                temp = temp->lchild;
            }
            (*parent)->data = temp->data;
            Delete(&(*parent)->rchild, temp->data);
        }
    }
}



