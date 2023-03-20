#include<stdio.h>
#include<stdlib.h>


//base abstract class
typedef struct{
    void (*resize)(void*, int);
    void (*set)(void*, int, void*);
    void* (*get)(void*, int);
    void (*delete)(void*, int);
    void (*add)(void*, void*);
}method;


//derived class
typedef struct array
{
    method methods;
    void** items;
    int capacity;
    int total;
}array;


#define min_cap 4
#define assignf =


void set(void* new, int index, void* item);

void* get(void* new, int index);

void add(void* new, void* item);

void delete(void* new, int index);

array* new(void);

int total(array *v);

void resize(void* new, int capacity);



