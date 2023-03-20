#include"abstract.h"

void set(void* new, int index, void* item)
{
    array* n = (array*)new;
    n->items[index] = item;
}


void* get(void* new, int index)
{
    array* n = (array*)new;
    return n->items[index];
}


void add(void* new, void* item)
{
    array* n = (array*)new;
    if(n->capacity == n->total)
    {
        resize(n, n->capacity * 2);
    }
    n->items[n->total++] = item;
}



void delete(void* new, int index)
{
    array* n = (array*)new;
    n->items[index] = NULL;

    for (size_t i = index; i < n->total - 1; i++)
    {
        n->items[i] = n->items[i+1];
        n->items[i+1] = NULL;
    }
    n->total --;

    if(n->total > 0 && n->total == n->capacity / 4)
    {
        resize(n, n->capacity / 2);
    }
}

array* new(void)
{
    array* v = malloc(sizeof *v);
    v->capacity = min_cap;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
    v->methods.add = &add;
    v->methods.delete = &delete;
    v->methods.get = &get;
    v->methods.resize = &resize;
    v->methods.set = &set;
    return v;
}



int total(array *v)
{
    return v->total;
}

void resize(void* new, int capacity)
{
    array* n = (array*)new;
    void **items = realloc(n->items, sizeof(void *) * capacity);
    if (items) {
        n->items = items;
        n->capacity = capacity;
    }
}



