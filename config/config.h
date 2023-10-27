#pragma once
#include<stdio.h>

#define eq ==
#define ineq !=
#define gt >
#define lt <
#define gte >=
#define lte <=
#define and &&
#define or ||
#define not !
#define pass 0
#define NIL (void*) 0
#define begin {
#define end }
#define function
#define PUBLIC
#define PRIVATE static
#define out
#define true 1
#define false 0
typedef char* string;


#define foreach(type, iter, array) for(type* iter = array; iter < (array) + sizeof(array) / sizeof(array[0]); iter++)