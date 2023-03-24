#ifndef STACK_H
#define STACK_H


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
        long:     "long",\
        float:   "float", \
        bool:    "bool",\
        char:    "char",\
        string:  "string",\
        default: "unkonwn")\


//Stack Class
#define stack(T)\
    __constructor__(T);\
    __new__(T);\
    __empty__(T);\
    __push__(T);\
    __pop__(T);\
    __peek__(T);\
    __traverse__(T);\
    //__clear__(T);


//Constructor
#define __constructor__(T)\
    typedef struct T##_node{\
        T data;\
        struct T##_node* next;\
    }T##_node;\
    typedef struct T##_stack{\
        T##_node* top;\
    }T##_stack;


//Methods
#define __new__(T)\
    T##_stack* T##_new(void){\
        T##_stack* S = malloc(sizeof *S);\
        assert(S);\
        S->top = NULL;\
        return S;\
    }

#define __empty__(T)\
    bool T##_empty(T##_stack* S){\
        return S->top == NULL ? true : false;\
    }


#define __push__(T)\
    void T##_push(T##_stack* S, T data){\
        assert(S);\
        T##_node* node = malloc((sizeof *node));\
        node->data = data;\
        /*if empty*/\
        if(S->top == NULL)\
        {\
            S->top = node;\
            S->top->next = NULL;\
        }\
        else\
        {\
            node->next = S->top;\
            S->top = node;\
        }\
    }
    /*1->null*/
    /*2->null*/  /*1->null*/  /*2->1->null, 2 is top*/ 
    /*.... 4->3->2->1->null,4 is top*/                                  


#define __pop__(T)\
    void T##_pop(T##_stack* S, T* data){\
        assert(S && S->top);\
        *data = S->top->data;\
        T##_node* temp = S->top;\
        S->top = S->top->next;\
        free(temp);\
    }


#define __peek__(T)\
    T##_node* T##_peek(T##_stack* S){\
        assert(S && S->top);\
        return S->top;\
    }


//#define __clear__(T)\
    void T##_clear(T##_stack* S, T* data){\
        assert(S->top);\
        while(!T##_empty(S)){\
            T##_pop(S, data);\
        }\
    }


#define __traverse__(T)\
    void T##_traverse(T##_stack* S){\
        assert(S && S->top);\
        T##_node* curr = S->top;\
        if(strcmp(typename(S->top->data), "double")== 0)/*sizeof str=double*/\
        {\
            while(curr != NULL)\
            {\
                printf("%lf ", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(S->top->data), "long")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%ld ", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(S->top->data), "int")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%d ", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(S->top->data), "char")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%c", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(S->top->data), "float")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%f ", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(S->top->data), "string")== 0){\
            while(curr != NULL)\
            {\
                printf("%s", curr->data);\
                curr = curr->next;\
            }\
        }\
    }

#endif