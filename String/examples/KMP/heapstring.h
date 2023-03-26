#ifndef HEAPSTRING_H
#define HEAPSTRING_H

#include<stdio.h>
#include<stdbool.h>


typedef char* string;

typedef struct HeapStr
{
    size_t len;
    string str;
}
HeapStr;


HeapStr* NewHS(const string str);

size_t Length(HeapStr* HS);

bool Empty(HeapStr* HS);

HeapStr* SubStr(HeapStr* HS, size_t begin, size_t length);

char Get(HeapStr* HS, size_t index);

void Insert(HeapStr* HS, size_t begin, string str);

void Delete(HeapStr* HS, size_t begin, size_t length);

int Compare(HeapStr* HS1, HeapStr* HS2);

bool Equal(HeapStr* HS1, HeapStr* HS2);

void Copy(HeapStr* src, HeapStr* copy);

void Concat(HeapStr* HS1, HeapStr* HS2);

void Set(HeapStr* HS, size_t index, char ch);

void Repalce(HeapStr* HS, size_t begin, string str);

void Echo(HeapStr* HS);

#endif
