#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "array.h"


void merge(array* a1, array* a2, array* a3);

void sort(array* a1);

void _union(array* a1, array* a2, array* a3);

void difference(array* a1, array* a2, array* a3);


int main(int argc, char** argv)
{
    array* a1 = init();

    add(a1, "hey");
    add(a1, "tank");
    add(a1, "kmap");
    add(a1, "mod");

    array* a2 = init();

    add(a2, "log");
    add(a2, "sys");
    add(a2, "kmap");
    add(a2, "own");

    array* a3 = init();

    //test functions
    //=============================
    //merge(a1, a2, a3);
    //_union(a1, a2, a3);
    difference(a1, a2, a3);
    //=============================

    for (int i = 0; i < total(a3); i++)
        printf("%s ", get(a3, i));
    printf("\n");


    free(a1);
    free(a2);
    free(a3);

    return 0;
}


void merge(array* a1, array* a2, array* a3)
{
    int i = 0;
    int j = 0;

    while (i < a1->total && j < a2->total)
    {
        a1->items[i] > a2->items[i] ?
            add(a3, a1->items[i]), i ++ :
                add(a3, a2->items[j]), j ++;
    }
    while (i < a1->total)
    {
        add(a3, a1->items[i]);
        i ++;
    }
    while (j < a2->total)
    {
        add(a3, a2->items[j]);
        j ++;
    }   
}


//better algo can be used, for simple, we use bubble sort
void sort(array* a)
{
    for(int i = 0; i < a->total - 1; i ++)
    {
        for (size_t j = i + 1; j < a->total - 1 - i; j++)
        {
            if (strcmp(a->items[j], a->items[j + 1]) > 0)
            {
                char* tmp = a->items[j];
                a->items[j] = a->items[j + 1];
                a->items[j + 1] = tmp; 
            }
        }
    }
}


void _union(array* a1, array* a2, array* a3)
{
    int i = 0;
    int j = 0;

    sort(a1);
    sort(a2);

    while (i < a1->total && j < a2->total)
    {
        if (strcmp(a1->items[i], a2->items[j]) < 0)
        {
            add(a3, a1->items[i]);
            i ++;
        }
        else if(strcmp(a1->items[i], a2->items[j]) > 0)
        {
            add(a3, a2->items[j]);
            j ++;
        }
        else
        {
            add(a3, a1->items[i]);
            i ++;
            j ++;
        }
    }
    while (i < a1->total)
    {
        add(a3, a1->items[i]);
        i ++;
    }
    while (j < a2->total)
    {
        add(a3, a2->items[j]);
        j ++;
    }
}

void difference(array* a1, array* a2, array* a3)
{
    sort(a1);//h k m t
    sort(a2);//l k o s

    int i = 0;
    int j = 0;

    while (i < a1->total && j < a2->total)
    {
        if(strcmp(a1->items[i], a2->items[j]) != 0)
        {
            add(a3, a1->items[i]);
            add(a3, a2->items[j]);
            i ++;
            j ++;
        }
        else
        {
            i ++;
            j ++;
        }
    }
    while (i < a1->total)
    {
        add(a3, a1->items[i]);
        i ++;
    }
    while (j < a2->total)
    {
        add(a3, a2->items[j]);
        j ++;
    }
}