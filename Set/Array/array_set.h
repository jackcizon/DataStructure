#ifndef ARRAY_SET_H
#define ARRAY_SET_H

#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


#define pass NULL

#define INIT_CAP 4


typedef char* string;


typedef struct Set
{
    void** items;
    size_t size;
    size_t capacity;
}
Set;

/**************************************************
*use va_list cause integeral promote.
*   solution:
*       1.type casting, but code is poor readability   
*
*       2.macro, and use void*
**************************************************/
Set* New(size_t size, ...);

void Destroy(Set* S);

size_t Size(Set* S);

bool Empty(Set* S);

bool Add(Set* S, void* data);

void Clear(Set* S);

bool Remove(Set* S, void* data);

bool Contain(Set* S, void* data);

#endif