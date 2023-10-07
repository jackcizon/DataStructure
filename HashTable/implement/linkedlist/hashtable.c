#include"hashtable.h"
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdio.h>


hashtable* NewTable(size_t size)
{
    hashtable* ht = (hashtable*)malloc(sizeof(hashtable));
    assert(ht);
    ht->size = size;
    ht->table = (list*)malloc(size * sizeof(list));
    assert(ht->table);
    for (size_t i = 0; i < size; i++)
    {
        ht->table[i] = NIL;
    }
    return ht;
}

size_t Hash(string key, size_t size)
{
    size_t hash_val = 0;
    for (size_t i = 0; key[i] ineq '\0'; i++)
    {
        hash_val = (hash_val * 31 + (int)key[i]) % size;
    }
    return hash_val;
}

void Insert(hashtable* ht, string key, string value)
{
    assert(ht);
    size_t index = Hash(key, ht->size);
    node* Node = NewNode(key, value);
    if (ht->table[index] eq NIL)
    {
        ht->table[index] = Node;
    }
    else
    {
        node* current = ht->table[index];
        while (current->next ineq NIL)
        {
            current = current->next;
        }
        current->next = Node;
    }
}

string Retrive(hashtable* ht, string key)
{
    size_t index = Hash(key, ht->size);
    node* current = ht->table[index];
    while (current ineq NIL)
    {
        if (not strncmp(current->key, key, strlen(key)))
        {
            return current->value;
        }
        current = current->next;
    }
    return NIL;
}

void Delete(hashtable* ht, string key)
{
    size_t index = Hash(key, ht->size);
    node* current = ht->table[index];
    node* prev = NIL;
    while (current ineq NIL)
    {
        if (not strncmp(current->key, key, strlen(key)))
        {
            // if this is first node
            if (prev eq NIL)
            {
                ht->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            FreeNode(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void Traverse(hashtable* ht)
{
    for (size_t i = 0; i < ht->size; i++)
    {
        node* current = ht->table[i];
        while (current ineq NIL)
        {
            printf("%s=>%s |", ht->table[i]->key, ht->table[i]->value);  
            current = current->next;
        }
    }
}

node* NewNode(string key, string value)
{
    node* Node = (node*)malloc(sizeof(node));
    Node->key = NIL;
    Node->value = NIL;
    Node->next = NIL;
    Node->key = (char*)malloc((strlen(key) + 1) * sizeof(char));
    Node->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
    strncpy(Node->key, key, strlen(key) + 1);
    strncpy(Node->value, value, strlen(value) + 1);
    return Node;
}

void FreeNode(node* Node)
{
    free(Node->key);
    free(Node->value);
    free(Node);
}

/*
void DestroyTable(hashtable* ht) {
    if (ht == NULL) 
    {
        return;
    }
    if (ht->table != NULL) {
        for (size_t i = 0; i < ht->size; i++) 
        {
            node* current = ht->table[i];
            while (current != NULL) 
            {
                node* tmp = current;
                current = current->next;
                FreeNode(tmp);
            }
        }
        free(ht->table);
    }
    free(ht);
    ht = NULL;
    printf("\naddr of ht==>>%p\n", (void*)&ht);
    // addr still exists, which will make unit test failure.
}
*/
void DestroyTable(hashtable** ht) {
    if (ht eq NULL || *ht eq NULL) 
    {
        return; 
    }

    if ((*ht)->table ineq NULL) 
    {
        for (size_t i = 0; i < (*ht)->size; i++) 
        {
            node* current = (*ht)->table[i];
            while (current ineq NULL) 
            {
                node* tmp = current;
                current = current->next;
                FreeNode(tmp);
            }
        }
        free((*ht)->table);
    }

    free(*ht);
    *ht = NULL;
    printf("\naddr of ht==>>%p\n", (void*)&ht);
}

/**
 When you pass a pointer to a function in C, both the original pointer and the local pointer inside the 
 function will initially point to the same memory address. 
 Changes made to the memory that the pointer points to will affect both pointers, 
 as they point to the same data.

However, if you assign a new value to the local pointer inside the function (e.g., setting it to NULL), 
it will not affect the original pointer in the calling code because the local pointer is a separate variable.
 This is why you may see that the local ht pointer is NULL inside the DestroyTable function,
 but the original ht pointer in the calling code remains unchanged.

If you want the original pointer in the calling code to be updated, 
you would need to use the hashtable** (double pointer) approach and pass a pointer to the original pointer

*/

