#include <stdio.h>
#include <stdlib.h>

#include "array.h"


array* init(void)
{
    array* v = malloc(sizeof *v);
    v->capacity = array_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
    return v;
}

int total(array *v)
{
    return v->total;
}

static void resize(array *v, int capacity)
{
    void **items = realloc(v->items, sizeof(void *) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void add(array *v, void *item)
{
    if (v->capacity == v->total)
        resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void set(array *v, int index, void *item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

void *get(array *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;

}

void delete(array *v, int index)
{
    if (index < 0 || index >= v->total)
        return;

    v->items[index] = NULL;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        resize(v, v->capacity / 2);
}

void _free(array *v)
{
    free(v->items);
    free(v);
}




