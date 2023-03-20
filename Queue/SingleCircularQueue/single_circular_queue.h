#ifndef SINGLE_CIRCULAR_QUEUE_H
#define SINGLE_CIRCULAR_QUEUE_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>


typedef char* string;


#define typename(x)\
    _Generic((x), \
        double: "double",\
        int:     "int", \
        float:   "float", \
        bool:    "bool",\
        char:    "char",\
        string:  "string",\
        default: "unkonwn")\


//Queue Class
#define queue(T)\
    __constructor__(T);\
    __new__(T);\
    __empty__(T);\
    __enqueue__(T);\
    __dequeue__(T);\
    __traverse__(T);


//Constructor
#define __constructor__(T)\
    typedef struct T##_node{\
        T data;\
        struct T##_node* next;\
    }T##_node;\
    typedef struct T##_queue{\
        T##_node* front;/*head in linked list*/\
        T##_node* rear;/*tail in linked list*/\
        size_t size;\
    }T##_queue;
    
/*****************************
 *      /\==<===<===<===/\
 *      ||              ||
 *    front->...->...->rear
*****************************/


#define __new__(T)\
    T##_queue* T##_new(void){\
        T##_queue* Q = malloc(sizeof *Q);\
        assert(Q);\
        Q->front = NULL;\
        Q->rear = NULL;\
        Q->size = 0;\
        return Q;\
    }


#define __empty__(T)\
    bool T##_empty(T##_queue* Q){\
        return Q->size == 0 ? true : false;\
    }


#define __enqueue__(T)\
    void T##_enqueue(T##_queue* Q, T data){\
        T##_node* new = malloc(sizeof *new);\
        new->data = data;\
        new->next = NULL;\
        if(T##_empty(Q)){\
            Q->front = Q->rear = new;\
            new->next = new;\
        }\
        else{\
            new->next = Q->front;\
            Q->rear->next = new;\
            Q->rear = new;\
        }\
        Q->size += 1;\
    }


#define __dequeue__(T)\
    void T##_dequeue(T##_queue* Q){\
        if(Q->size == 1){\
            free(Q->front);\
            Q->front = NULL;\
            Q->rear = NULL;\
        }\
        else{\
            T##_node* delete = Q->front;\
            Q->front = Q->front->next;\
            Q->rear->next = Q->front;\
            free(delete);\
        }\
        Q->size -= 1;\
    }


#define __traverse__(T)\
    void T##_traverse(T##_queue* Q){\
        assert(Q && Q->front);\
        T##_node* curr = Q->front;\
        if(strcmp(typename(Q->front->data), "double")== 0)/*sizeof str=double*/\
        {\
            while(curr != Q->rear)\
            {\
                printf("%lf ", curr->data);\
                curr = curr->next;\
            }\
            printf("%lf ", Q->rear->data);\
        }\
        if(strcmp(typename(Q->front->data), "int")== 0)\
        {\
            while(curr != Q->rear)\
            {\
                printf("%d ", curr->data);\
                curr = curr->next;\
            }\
            printf("%d ", Q->rear->data);\
        }\
        if(strcmp(typename(Q->front->data), "char")== 0)\
        {\
            while(curr != Q->rear)\
            {\
                printf("%c", curr->data);\
                curr = curr->next;\
            }\
            printf("%c ", Q->rear->data);\
        }\
        else if(strcmp(typename(Q->front->data), "float")== 0)\
        {\
            while(curr != Q->rear)\
            {\
                printf("%f ", curr->data);\
                curr = curr->next;\
            }\
            printf("%f ", Q->rear->data);\
        }\
        else if(strcmp(typename(Q->front->data), "string")== 0){\
            while(curr != Q->rear)\
            {\
                printf("%s", curr->data);\
                curr = curr->next;\
            }\
            printf("%s ", Q->rear->data);\
        }\
    }

#endif