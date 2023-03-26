#include"array_set.h"


Set* New(size_t size, ...)
{
    Set* S = malloc(sizeof *S);
    S->capacity = INIT_CAP;
    S->size = 0;
    S->items = malloc(sizeof(void*) * S->capacity);
    
    while(size >= S->capacity)
    {
        S->capacity *= 2;
    }
    S->items = realloc(S->items, S->capacity * sizeof(void*));
    S->size = size;

    va_list L;
    va_start(L, size);
    for (size_t i = 0; i < size; i++)
    {
        void* item = va_arg(L, void*);
        S->items[i] = item;
    }
    va_end(L);

    return S;
}


size_t Size(Set* S)
{
    return S->size;
}


bool Add(Set* S, void* data)
{
    for (size_t i = 0; i < Size(S); i++)
    {
        if(S->items[i] == data)
        {
            return false;
        }
    }
    S->items[S->size ++] = data;
    return true;
}


void Clear(Set* S)
{
    S->size = 0;
}


bool Remove(Set* S, void* data)
{
    for(size_t i = 0; i < Size(S); i ++)
    {
        if(S->items[i] == data)
        {
            S->items[i] = NULL;
        }
        return true;
    }
    return false;
}


bool Contain(Set* S, void* data)
{
    for (size_t i = 0; i < Size(S); i++)
    {
        if(S->items[i] == data)
        {
            return true;
        }    
    }
    return false;
}


bool Empty(Set* S)
{
    return S->size == 0 ? true : false;
}


void Destroy(Set* S)
{
    free(S->items);
    free(S);
}


