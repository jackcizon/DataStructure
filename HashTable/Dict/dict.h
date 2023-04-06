#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char* string;

#define pass 0

//#define echo(str) puts(#str)

#define echo(str) puts(str)

typedef struct Entry
{
    string key;
    string value;
}
Entry;


typedef struct Dict
{
    size_t size;
    size_t count;
    Entry* entries;
}
Dict;


Dict* NewDict(size_t size);

size_t Hash(const string key, size_t size);

void InsertEntry(Dict* D, const string key, const string value);

string GetValue(Dict* D, const string key);

void DestroyDict(Dict* D);

void Copy(Dict* dest, Dict* src);

void Remove(Dict* D, string key);

void Update(Dict* D, const string key, const string new_value);

void Traverse(Dict* D);