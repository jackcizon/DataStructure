#ifndef SHARE_STACK_H
#define SHARE_STACK_H


#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>


typedef char* string;

#define assignf =
#define equal ==


#define typename(x)\
    _Generic((x), \
        double: "double",\
        int:     "int", \
        float:   "float", \
        bool:    "bool",\
        char:    "char",\
        string:  "string",\
        default: "unkonwn")\


//Stack Class
#define sstack(T)\
    __constructor__(T);\
    __new__(T);\
    __empty__(T);\
    __push__(T);\
    __pop__(T);\
    __peek__(T);\
    __traverse__(T);


//Constructor
#define __constructor__(T)\
    typedef struct T##_node{\
        T data;\
        struct T##_node* next;\
    }T##_node;\
    typedef struct T##_sstack{\
        T##_node* top1;\
        T##_node* top2;\
    }T##_sstack;


#define __new__(T)\
    T##_sstack* T##_new(void){\
        T##_sstack* S = malloc(sizeof *S);\
        assert(S);\
        S->top1 = S->top2 = NULL;\
        return S;\
    }


#define __empty__(T)\
    bool T##_empty(T##_sstack* S){\
        return S->top1 equal NULL || S->top2 equal NULL ? true : false;\
    }


#define __push__(T)\
    /*flag = 1, push in s1, flag = 2, push in s2*/\
    void T##_push(T##_sstack* S, int flag, T data){\
        T##_node* new = malloc(sizeof *new);\
        new->data assignf data;\
        new->next assignf NULL;\
        if(flag equal 1){\
            new->next assignf S->top1;\
            S->top1 assignf new;\
        }\
        else if(flag equal 2){\
            new->next assignf S->top2;\
            S->top2 assignf new;\
        }\
        else{\
            perror("flag error");\
            exit(EXIT_FAILURE);\
        }\
    }


#define __pop__(T)\
    /*flag = 1, pop in s1, flag = 2, pop in s2*/\
    void T##_pop(T##_sstack* S, int flag){\
        if(flag equal 1){\
            assert(S->top1);\
            T##_node* temp = S->top1;\
            S->top1 = S->top1->next;\
            free(temp);\
        }\
        else if(flag equal 2){\
            assert(S->top2);\
            T##_node* temp = S->top2;\
            S->top2 = S->top2->next;\
            free(temp);\
        }\
        else{\
            perror("flag error");\
            exit(EXIT_FAILURE);\
        }\
    }


#define __peek__(T)\
    T##_node* T##_peek(T##_sstack* S, int flag){\
        if(flag equal 1){\
            assert(S->top1);\
            return S->top1;\
        }\
        else if(flag equal 2){\
            assert(S->top2);\
            return S->top2;\
        }\
        else{\
            perror("flag error");\
            exit(EXIT_FAILURE);\
        }\
    }


#define __traverse__(T)\
    void T##_traverse(T##_sstack* S, int flag){\
        if(flag equal 1){\
            assert(S && S->top1);\
            T##_node* curr = S->top1;\
            if(strcmp(typename(S->top1->data), "double")== 0)/*sizeof str=double*/\
            {\
                while(curr != NULL)\
                {\
                    printf("%lf ", curr->data);\
                    curr = curr->next;\
                }\
            }\
            if(strcmp(typename(S->top1->data), "int")== 0)\
            {\
                while(curr != NULL)\
                {\
                    printf("%d ", curr->data);\
                    curr = curr->next;\
                }\
            }\
            if(strcmp(typename(S->top1->data), "char")== 0)\
            {\
                while(curr != NULL)\
                {\
                    printf("%c", curr->data);\
                    curr = curr->next;\
                }\
            }\
            else if(strcmp(typename(S->top1->data), "float")== 0)\
            {\
                while(curr != NULL)\
                {\
                    printf("%f ", curr->data);\
                    curr = curr->next;\
                }\
            }\
            else if(strcmp(typename(S->top1->data), "string")== 0){\
                while(curr != NULL)\
                {\
                    printf("%s", curr->data);\
                    curr = curr->next;\
                }\
            }\
        }\
        else if(flag equal 2){\
            assert(S && S->top2);\
            T##_node* curr = S->top2;\
            if(strcmp(typename(S->top2->data), "double")== 0)/*sizeof str=double*/\
            {\
                while(curr != NULL)\
                {\
                    printf("%lf ", curr->data);\
                    curr = curr->next;\
                }\
            }\
            if(strcmp(typename(S->top2->data), "int")== 0)\
            {\
                while(curr != NULL)\
                {\
                    printf("%d ", curr->data);\
                    curr = curr->next;\
                }\
            }\
            if(strcmp(typename(S->top2->data), "char")== 0)\
            {\
                while(curr != NULL)\
                {\
                    printf("%c", curr->data);\
                    curr = curr->next;\
                }\
            }\
            else if(strcmp(typename(S->top2->data), "float")== 0)\
            {\
                while(curr != NULL)\
                {\
                    printf("%f ", curr->data);\
                    curr = curr->next;\
                }\
            }\
            else if(strcmp(typename(S->top2->data), "string")== 0){\
                while(curr != NULL)\
                {\
                    printf("%s", curr->data);\
                    curr = curr->next;\
                }\
            }\
        }\
        else{\
            perror("flag error");\
            exit(EXIT_FAILURE);\
        }\
    }


#endif