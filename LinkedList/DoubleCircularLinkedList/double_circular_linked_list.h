#ifndef DOUBLE_CIRCULAR_LINKED_LIST_H
#define DOUBLE_CIRCULAR_LINKED_LIST_H


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


//Class
#define circular(T) \
    __constructor__(T);\
    __new__(T);\
    __size__(T);\
    __empty__(T);\
    __head__(T);\
    __append__(T);\
    __push__(T);\
    __traverse__(T);\
    __delete__(T);\
    __insert__(T);\
    __get__(T);\
    __remove__(T);\
    __search__(T);\
    __index__(T);\
    __pop__(T);\
    __tail__(T);

    
//List Constructor
#define __constructor__(T)\
    typedef struct T##_node{\
        T data;\
        struct T##_node* next;\
        struct T##_node* prev;\
    }T##_node;\
    typedef struct T##_circular{\
        T##_node* head;\
        T##_node* tail;\
        size_t size;\
    }T##_circular;


/**********************************************
 *          /\===>====>====>===>===||
 *          ||                     \/
 *         head <=>....<=>....<=> tail
 *          /\                     ||
 *          ||=<====<====<====>===>\/
 *                           
 **********************************************/


//Methods
#define __new__(T)\
    T##_circular* T##_new(void){\
        T##_circular* C = malloc(sizeof *C);\
        assert(C);\
        C->head = NULL;\
        C->tail = NULL;\
        C->size = 0;\
        return C;\
    }


#define __size__(T)\
    size_t T##_size(T##_circular* C){\
        return C->size;\
    }


#define __empty__(T)\
    bool T##_empty(T##_circular* C){\
       return C->size == 0 ? true : false;\
    }


#define __index__(T)\
    T T##_index(T##_circular* C, size_t index){\
        assert(index >= 0 && index < C->size);\
        T##_node* curr = C->head;\
        for(size_t i = 0; i < index; i ++){\
            curr = curr->next;\
        }\
        return curr->data;\
    }


#define __head__(T)\
    T##_node* T##_head(T##_circular* C){\
        assert(C->head);\
        return C->head;\
    }


#define __tail__(T)\
    T##_node* T##_tail(T##_circular* C){\
        assert(C->tail);\
        return C->tail;\
    }


#define __get__(T)\
    T T##_get(T##_circular* C, size_t index){\
        assert(index >= 0 && index < C->size);\
        T##_node* curr = C->head;\
        for(size_t i = 0; i < index; i ++){\
            curr = curr->next;\
        }\
        return curr->data;\
    }


#define __search__(T)\
    bool T##_search(T##_circular* C, T data){\
        if(C->size == 1){\
            if(C->head->data == data){\
                return true;\
            }\
        }\
        else if(true){\
            T##_node* curr = C->head;\
            while(curr->next != C->head){\
                curr = curr->next;\
                if(curr->data == data){\
                    return true;\
                }\
            }\
        }\
        else{\
            return false;\
        }\
    }


#define __remove__(T)\
    void T##_remove(T##_circular* C, T data){\
        assert(C && C->head);\
        T##_node* curr = C->head;\
        for(size_t i = 0; i < C->size; i ++){\
            if(curr->data == data){\
                T##_delete(C, i);\
            }\
        }\
    }


#define __push__(T)\
    void T##_push(T##_circular* C, T data){\
        T##_node* new = malloc(sizeof *new);\
        new->data = data;\
        new->prev = NULL;\
        new->next = NULL;\
        /*if empty*/\
        if(C->size == 0){\
            C->head = new;\
            C->tail = new;\
            new->next = new;\
            new->prev = new;\
        }\
        else{\
            new->next = C->head;\
            new->prev = C->tail;\
            C->head->prev = new;\
            C->tail->next = new;\
            C->head = new;\
        }\
        C->size += 1;\
    }


#define __append__(T)\
    void T##_append(T##_circular* C, T data){\
        T##_node* new = malloc(sizeof *new);\
        new->data = data;\
        new->prev = NULL;\
        new->next = NULL;\
        /*if empty*/\
        if(C->size == 0){\
            C->head = new;\
            C->tail = new;\
            new->next = new;\
            new->prev = new;\
        }\
        else{\
            new->next = C->head;\
            new->prev = C->tail;\
            C->tail->next = new;\
            C->head->prev = new;\
            C->tail = new;\
        }\
        C->size += 1;\
    }


#define __pop__(T)\
    void T##_pop(T##_circular* C){\
        assert(C && C->head);\
        T##_node* delete = C->tail;\
        C->tail = delete->prev;\
        C->tail->next = C->head;\
        C->head->prev = C->tail;\
        free(delete);\
        C->size -= 1;\
    }


#define __delete__(T)\
    void T##_delete(T##_circular* C, size_t index){\
        assert(C && C->head);\
        assert(index >= 0 && index < C->size);\
        if(C->size == 1){\
            free(C->head);\
            C->head = NULL;\
            C->tail = NULL;\
            C->size -= 1;\
        }\
        else if(index == 0){\
        T##_node* delete = C->head;\
            C->head = delete->next;\
            C->head->prev = C->tail;\
            C->tail->next = C->head;\
            free(delete);\
            C->size -= 1;\
        }\
        else if(index == C->size - 1){\
            T##_pop(C);\
        }\
        else{\
            T##_node* delete = C->head;\
            for(size_t i = 0; i < index; i ++){\
                delete = delete->next;\
            }\
            delete->prev->next = delete->next;\
            delete->next->prev = delete->prev;\
            free(delete);\
            C->size -= 1;\
        }\
    }


#define __insert__(T)\
    void T##_insert(T##_circular* C, size_t index, T data){\
        assert(C);\
        assert(index >= 0 && index <= C->size);\
        if(index == 0){\
            T##_push(C, data);\
        }\
        else if(index < C->size){\
            C->size += 1;\
            T##_node* curr1 = C->head;\
            T##_node* curr2 = NULL;\
            T##_node* new = malloc(sizeof *new);\
            new->next = NULL;\
            new->prev = NULL;\
            new->data = data;\
            for(size_t i = 0; i < index - 1; i ++){\
                curr1 = curr1->next;\
            }\
            curr2 = curr1->next;\
            curr1->next = new;\
            curr2->prev = new;\
            new->next = curr2;\
            new->prev = curr1;\
        }\
        else{\
            T##_append(C, data);\
        }\
    }


#define __traverse__(T)\
    void T##_traverse(T##_circular* C){\
        assert(C && C->head);\
        T##_node* curr = C->head;\
        if(strcmp(typename(C->head->data), "double")== 0)/*sizeof str=double*/\
        {\
            while(curr != C->tail)\
            {\
                printf("%lf ", curr->data);\
                curr = curr->next;\
            }\
            printf("%lf ", C->tail->data);\
        }\
        if(strcmp(typename(C->head->data), "int")== 0)\
        {\
            while(curr != C->tail)\
            {\
                printf("%d ", curr->data);\
                curr = curr->next;\
            }\
            printf("%d ", C->tail->data);\
        }\
        if(strcmp(typename(C->head->data), "char")== 0)\
        {\
            while(curr != C->tail)\
            {\
                printf("%c", curr->data);\
                curr = curr->next;\
            }\
            printf("%c ", C->tail->data);\
        }\
        else if(strcmp(typename(C->head->data), "float")== 0)\
        {\
            while(curr != C->tail)\
            {\
                printf("%f ", curr->data);\
                curr = curr->next;\
            }\
            printf("%f ", C->tail->data);\
        }\
        else if(strcmp(typename(C->head->data), "string")== 0){\
            while(curr != C->tail)\
            {\
                printf("%s", curr->data);\
                curr = curr->next;\
            }\
            printf("%s ", C->tail->data);\
        }\
    }


#endif