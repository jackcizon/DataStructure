#pragma once
#include<config.h>
#include<stddef.h>


#define SIZE 100

typedef struct node
{
    string key;
    string value;
    struct node* next;
}
node;

typedef node* list;


typedef struct hashtable
{
    size_t size;
    list* table;
}
hashtable;

hashtable* NewTable(size_t size);

size_t Hash(string key, size_t size);

void Insert(hashtable* ht, string key, string value);

string Retrive(hashtable* ht, string key);

void Delete(hashtable* ht, string key);

void Traverse(hashtable* ht);

node* NewNode(string key, string value);

void FreeNode(node* Node);

void DestroyTable(hashtable** ht);






