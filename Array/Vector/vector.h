#ifndef VECTOR_H
#define VECTOR_H


#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>

#define pass NULL//or (void) 0, 0

#define vector_MIN_CAP 4

typedef char* string;//sizeof(char*) = 8

#define PUBLIC
#define PRIVATE static


#define typename(x)\
    _Generic((x), \
        double:  "double",\
        int:     "int", \
        float:   "float", \
        bool:    "bool",\
        char:    "char",\
        string:  "string",\
        default: "unkonwn")\


//class
#define vector(T)\
    __constructor__(T);\
    __new__(T);\
    __get__(T);\
    __addr__(T);\
    __set__(T);\
    __append__(T);\
    __traverse__(T);\
    __size__(T);\
    __capacity__(T);\
    __pop__(T);\
    __delete__(T);\
    __insert__(T); 



//constructor
#define __constructor__(T)\
    typedef struct T##_vector{\
        T *buf;\
        size_t capacity;\
        size_t size;\
    } T##_vector;

/*
#define __new__(T)\
    T##_vector* T##_new(void){\
        T##_vector* vec = malloc(sizeof *vec);\
        vec->capacity = vector_MIN_CAP;\
        vec->buf = malloc(sizeof(T) * vec->capacity);\
        vec->size = 0;\
        assert(vec);\
        assert(vec->buf);\
        return vec;\
    }
*/


#define __new__(T)\
  T##_vector* T##_new(size_t size,...){\
    T##_vector* vec = malloc(sizeof *vec);\
    vec->capacity = vector_MIN_CAP;\
    vec->buf = malloc(sizeof(T) * vec->capacity);\
    while(size >= vec->capacity)\
    {\
      vec->capacity *= 2;\
    }\
    vec->buf = realloc(vec->buf, sizeof(T) * vec->capacity);\
    if(strcmp(typename(vec->buf[0]), "char") == 0){\
            if(size != 0){\
                perror("prevent integral promote excutions.\n");\
                exit(EXIT_FAILURE);\
            }\
        }\
    else if(strcmp(typename(vec->buf[0]), "float") == 0){\
            if(size != 0){\
                perror("prevent integral promote excutions.\n");\
                exit(EXIT_FAILURE);\
            }\
        }\
    vec->size = size;\
    va_list ap;\
    va_start(ap, size);\
    for(size_t i = 0; i < size; i ++){\
      vec->buf[i] = va_arg(ap, T);\
    }\
    va_end(ap);\
    return vec;\
  }

//if(strcmp(typename(vec->buf[0]), "double") == 0)

#define __size__(T)\
    size_t T##_size(T##_vector* vec)\
    {\
        assert(vec->size >= 0);\
        return vec->size;\
    }                           


#define __capacity__(T)\
    size_t T##_capacity(T##_vector* vec)\
    {\
        assert(vec->capacity >= 0);\
        return vec->capacity;\
    }


//get addr, we need buf[i](dereference) to get value
#define __addr__(T)\
    void* T##_addr(T##_vector *vec, size_t idx){\
        return vec->buf + idx;\
    }


#define __get__(T)\
    T T##_get(T##_vector* vec, size_t index)\
    {\
        assert(index >=0 || index < vec->size);\
        return vec->buf[index];\
    }                                         


#define __set__(T)\
    void T##_set(T##_vector *vec, size_t idx, T data){\
        vec->buf[idx] = data;\
    }


#define __append__(T)\
    void T##_append(T##_vector *vec, T data){\
        if (vec->size == vec->capacity){\
            vec->capacity *= 2;\
            vec->buf = realloc(vec->buf, sizeof(T) * vec->capacity);\
        }\
        T##_set(vec, vec->size++, data);\
    }


#define __pop__(T)\
    void T##_pop(T##_vector* vec)\
    {\
        vec->buf[vec->size] = 0;\
        vec->size -= 1;\
    }


#define __insert__(T)\
  void T##_insert(T##_vector* vec, size_t index, T data)\
  {\
    assert(index >= 0 && index < vec->size);\
    if(vec->size == vec->capacity)\
    {\
        vec->capacity *= 2;\
        vec->buf = realloc(vec->buf, sizeof(T) * vec->capacity);\
    }\
    for(int i = vec->size - 1; i > index; i--)\
    {\
        vec->buf[i + 1] = vec->buf[i];\
    }\
    vec->size += 1;\
    vec->buf[index] = data;\
  }

  
#define __delete__(T)\
    void T##_delete(T##_vector* vec, size_t index)\
    {\
        assert(index >= 0 && index < vec->size);\
        vec->buf[index] = 0;\
        for (int i = index + 1; i < vec->size; i++)\
        {\
            vec->buf[i - 1] = vec->buf[i];\
        }\
        vec->size -= 1;\
        vec->buf[vec->size] = 0;\
    }


#define __traverse__(T)\
    void T##_traverse(T##_vector* vec){\
        if(strcmp(typename(vec->buf[0]), "double") == 0)\
        {\
            for (int i = 0; i < vec->size; i++)\
            {\
                printf("%lf ", vec->buf[i]);\
            }\
        }\
        else if(strcmp(typename(vec->buf[0]), "int") == 0)\
        {\
            for (int i = 0; i < vec->size; i++)\
            {\
                printf("%d ", vec->buf[i]);\
            }\
        }\
        else if(strcmp(typename(vec->buf[0]), "char") == 0)\
        {\
            for (int i = 0; i < vec->size; i++)\
            {\
                printf("%c", vec->buf[i]);\
            }\
        }\
        else if(strcmp(typename(vec->buf[0]), "float") == 0)\
        {\
            for (int i = 0; i < vec->size; i++)\
            {\
                printf("%f ", vec->buf[i]);\
            }\
        }\
        else if(strcmp(typename(vec->buf[0]), "string") == 0)\
        {\
            for (int i = 0; i < vec->size; i++)\
            {\
                printf("%s\n", vec->buf[i]);\
            }\
        }\
        else\
        {\
            exit(EXIT_FAILURE);\
        }\
    }


#endif
