#include"heapstring.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>


HeapStr* NewHS(const string str)
{
    HeapStr* HS = malloc(sizeof *HS);
    HS->len = strlen(str);
    HS->str = malloc(HS->len + 1);
    strncpy(HS->str, str, strlen(str) + 1);
    return HS;
}


void Echo(HeapStr* HS)
{
    puts(HS->str);
}


size_t Length(HeapStr* HS)
{
    return HS->len;
}


bool Empty(HeapStr* HS)
{
    return HS->len == 0 ? true : false;
}


char Get(HeapStr* HS, size_t index)
{
    assert(index <= Length(HS));
    return HS->str[index];   
}


void Insert(HeapStr* HS, size_t begin, string str)
{
    size_t str_len = strlen(str);
    size_t new_len = Length(HS) + str_len;
    string new_str = realloc(HS->str, new_len + 1);
    HS->str = new_str;
    memmove(HS->str + begin + str_len, HS->str + begin, Length(HS) - begin + 1);
    memcpy(HS->str + begin, str, str_len);
    HS->len = new_len;
}


int Compare(HeapStr* HS1, HeapStr* HS2)
{
    return strcmp(HS1->str, HS2->str);
}


bool Equal(HeapStr* HS1, HeapStr* HS2)
{
    assert(HS1 && HS2);
    return strcmp(HS1->str, HS2->str) == 0 ? true : false;
}


void Copy(HeapStr* src, HeapStr* copy)
{
    assert(src && copy);
    string new_str = NULL;
    if(copy->str == NULL)
    /*this will never happens, just because copy->str cannot access,cauese SIGSEGV*/
    {
        fprintf(stderr, "Error: unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    /*do not use realloc() if not init, will cause segment fault.*/
    else 
    {
        new_str = copy->str;
        string new_str = realloc(copy->str, sizeof(char) * (Length(src) + 1));
    }
    memcpy(new_str, src->str, sizeof(char) * (Length(src) + 1));
    copy->str = new_str;
    copy->len = Length(src);
}


void Set(HeapStr* HS, size_t index, char ch)
{
    assert(index <= Length(HS));
    HS->str[index] = ch;
}


void Repalce(HeapStr* HS, size_t begin, string str)
{
    size_t str_len = strlen(str);
    size_t new_len = str_len + begin;
    if(new_len > Length(HS))
    {
        string new_str = realloc(HS->str, new_len + 1);
        HS->str = new_str;
        HS->len = new_len;
    }
    //move mem block,from &str[begin] to &str[begin] + strlen, 
    //shift length(HS) - begin + 1, so that can insert str to HS->str.
    memmove(HS->str + begin + str_len, HS->str + begin, Length(HS) - begin + 1);
    memcpy(HS->str + begin, str, str_len);  
}


void Concat(HeapStr* HS1, HeapStr* HS2)
{
    size_t new_len = HS1->len + HS2->len;
    string new_str = realloc(HS1->str, new_len + 1);
    HS1->str = new_str;
    strcat(HS1->str, HS2->str);
    HS1->len = new_len;
}


HeapStr* SubStr(HeapStr* HS, size_t begin, size_t length)
{
    assert(begin <= HS->len);
    if(begin + length > Length(HS))
    {
        length = Length(HS) - begin;
    }
    HeapStr* Sub = malloc(sizeof *Sub);
    Sub->str = malloc(length + 1);
    strncpy(Sub->str, HS->str + begin, length);
    Sub->str[length] = '\0';
    Sub->len = length;
    return Sub;
}


void Delete(HeapStr* HS, size_t begin, size_t length)
{
    assert(begin <= Length(HS));
    if(begin + length > Length(HS))
    {
        length = Length(HS) - begin;
    }
    memmove(HS->str + begin, HS->str + begin + length, Length(HS) - begin - length + 1);
    HS->len -= length;
}








