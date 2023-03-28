#ifndef LIST_SET_H
#define LIST_SET_H


#include<stdlib.h>
#include<stdarg.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>


#define pass NULL

typedef char* string;

typedef struct node
{
    void* data;
    struct node* next;
}
node;

typedef struct Set
{
    node* head;
    size_t size;
}
Set;


Set* New(size_t size, ...);

void Destroy(Set* S);

size_t Size(Set* S);

bool Empty(Set* S);

bool Add(Set* S, void* data);

void Clear(Set* S);

bool Remove(Set* S, void* data);

bool Contain(Set* S, void* data);

node* Head(Set* S);

void Traverse(Set* S);

#endif