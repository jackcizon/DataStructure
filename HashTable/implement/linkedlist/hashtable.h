#pragma once
#include"config.h"

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

hashtable* newTable(size_t size);

void Hash(list* node, string key);

void Insert(hashtable* table, string key, string value);

void Delete(hashtable* table, string key);

void Traverse(hashtable* table);

list* newNode(string key, string value);







