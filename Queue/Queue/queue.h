#ifndef QUEUE_H
#define QUEUE_H


#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>


typedef char* string;

#define echo(str) puts(#str);

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
    }T##_queue;
    /*front->...->...->rear->null*/


//Methods
#define __new__(T)\
    T##_queue* T##_new(void){\
        T##_queue* Q = malloc(sizeof *Q);\
        assert(Q);\
        Q->front = Q->rear = NULL;\
        return Q;\
    }


#define __empty__(T)\
    bool T##_empty(T##_queue* Q){\
        return Q->front == NULL && Q->rear == NULL ? true : false;\
    }


/*append*/
#define __enqueue__(T)\
    void T##_enqueue(T##_queue* Q, T data){\
        assert(Q);\
        T##_node* node = malloc(sizeof *node);\
        node->data = data;\
        node->next = NULL;\
        if(Q->front == NULL && Q->rear == NULL){\
            Q->front = Q->rear = node;\
        }\
        else{\
            Q->rear->next = node;\
            Q->rear = node;\
        }\
    }


/*delete first*/
#define __dequeue__(T)\
    void T##_dequeue(T##_queue* Q){\
        assert(Q && Q->front);\
        if(Q->front == Q->rear){\
            free(Q->front);\
            Q->front = Q->rear = NULL;\
        }\
        else{\
            T##_node* temp = Q->front;\
            Q->front = Q->front->next;\
            free(temp);\
        }\
    }


#define __traverse__(T)\
    void T##_traverse(T##_queue* Q){\
        assert(Q && Q->front);\
        T##_node* curr = Q->front;\
        if(strcmp(typename(Q->front->data), "double")== 0)/*sizeof str=double*/\
        {\
            while(curr != NULL)\
            {\
                printf("%lf ", curr->data);\
                curr = curr->next;\
            }\
        }\
        if(strcmp(typename(Q->front->data), "int")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%d ", curr->data);\
                curr = curr->next;\
            }\
        }\
        if(strcmp(typename(Q->front->data), "char")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%c", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(Q->front->data), "float")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%f ", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(Q->front->data), "string")== 0){\
            while(curr != NULL)\
            {\
                printf("%s", curr->data);\
                curr = curr->next;\
            }\
        }\
    }



#endif
