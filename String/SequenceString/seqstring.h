#ifndef SEQSTRING_H
#define SEQSTRING_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define pass NULL//or (void) 0, 0

#define MAXSIZE 255

typedef char* string;


typedef struct SeqStr
{
    char str[MAXSIZE];
    size_t len;
}
SeqStr;



void Assign(SeqStr* SS, const string str);

size_t Length(SeqStr* SS);

bool Empty(SeqStr* SS);

void SubStr(SeqStr* SS, SeqStr* sub, size_t begin, size_t length);

void Echo(SeqStr* SS);

void Clear(SeqStr* SS);

int Compare(SeqStr* SS1, SeqStr* SS2);

void Copy(SeqStr* dest, SeqStr* src);

void Delete(SeqStr* SS, size_t begin, size_t length);

void Insert(SeqStr* SS, size_t begin, const string str);

void Replace(SeqStr* SS, size_t begin, string str);

char Get(SeqStr* SS, size_t index);

void Concat(SeqStr* SS1, SeqStr* SS2);

void Set(SeqStr* SS, size_t index, char ch);

#endif