#ifndef SCIRCULAR_H
#define SCIRCULAR_H


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


//Constructor
#define __constructor__(T)\
    typedef struct T##_node{\
        T data;\
        struct T##_node* next;\
    }T##_node;\
    typedef struct T##_circular{\
        T##_node* head;\
        T##_node* tail;\
        size_t size;\
    }T##_circular;


/**********************************************
 * 
 *         head->...->....-> tail
 *          /\                ||
 *          ||-<----<----<----\/
 *                           
 **********************************************/


//Methods
#define __new__(T)\
    T##_circular* T##_new(void){\
        T##_circular* C = malloc(sizeof * C);\
        assert(C);\
        C->head = C->tail = NULL;\
        C->size = 0;\
        return C;\
    }

#define __size__(T)\
    size_t T##_size(T##_circular* C){\
        return C->size;\
    }


#define __empty__(T)\
    bool T##_empty(T##_circular* C){\
        C->size == 0 ? true : false;\
    }


#define __index__(T)\
    size_t T##_index(T##_circular* C, size_t index){\
        assert(index >= 0 && index < C->size);\
        T##_node* curr = C->head;\
        for(size_t i = 0; i < index; i ++){\
            curr = curr->next;\
        }\
        return curr->data;\
    }


#define __head__(T)\
    T##_node* T##_head(T##_circular* C){\
        return C->head;\
    }


#define __tail__(T)\
    T##_node* T##_tail(T##_circular* C){\
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


#define __append__(T)\
    void T##_append(T##_circular* C, T data){\
        T##_node* new = malloc(sizeof *new);\
        new->data = data;\
        new->next = NULL;\
        /*if empty*/\
        if(C->size == 0){\
            C->head = C->tail = new;\
            new->next = new;\
        }\
        else{\
            new->next = C->head;\
            C->tail->next = new;\
            C->tail = new;\
        }\
        C->size += 1;\
    }

//insert at begin
#define __push__(T)\
    void T##_push(T##_circular* C, T data){\
    T##_node* new = malloc(sizeof *new);\
    new->data = data;\
    /*if empty*/\
        if(C->size == 0){\
            C->head = C->tail = new;\
            new->next = new;\
        }\
        else{\
            new->next = C->head;\
            C->head = new;\
            C->tail->next = new;\
        }\
        C->size += 1;\
    }


#define __remove__(T)\
    bool T##_remove(T##_circular* C, T data){\
        assert(C->head);\
        if(C->size == 1 && C->head->data == data){\
            free(C->head);\
            C->head = NULL;\
            C->tail = NULL;\
            C->size -= 1;\
            return true;\
        }\
        if(true){\
            T##_node* temp1 = C->head;\
            T##_node* temp2 = NULL;\
            while(temp1->next != C->head){\
                temp2 = temp1;\
                temp1 = temp1->next;\
                if(temp1->data == data){\
                temp2->next = temp1->next;\
                    free(temp1);\
                    C->size -= 1;\
                    return true;\
                }\
            }\
        }\
        return false;\
    }


#define __pop__(T)\
    void T##_pop(T##_circular* C){\
        assert(C && C->head);\
        if(C->size == 1){\
            free(C->head);\
            C->head = NULL;\
            C->tail = NULL;\
        }\
        else{\
            T##_node* curr = C->head;\
            while(curr->next != C->tail){\
                curr = curr->next;\
            }\
            T##_node* temp = C->tail;\
            C->tail = curr;\
            C->tail->next = C->head;\
            free(temp);\
        }\
        C->size -= 1;\
    }


#define __delete__(T)\
    void T##_delete(T##_circular* C, size_t index){\
        assert(C && C->head);\
        assert(index >= 0 && index < C->size);\
        /*delete first*/\
        if(C->size == 1){\
            free(C->head);\
            C->head = NULL;\
            C->tail = NULL;\
        }\
        else if(index == 0){\
            T##_node* temp = C->head;\
            C->head = C->head->next;\
            C->tail->next = C->head;\
            free(temp);\
        }\
        else if(index > 0 && index < C->size){\
            T##_node* temp1 = C->head;\
            T##_node* temp2 = NULL;\
            for(size_t i = 0; i < index; i ++){\
                temp2 = temp1;\
                temp1 = temp1->next;\
            }\
            temp2->next = temp1->next;\
            free(temp1);\
        }\
        /*delete last*/\
        else{\
            T##_node* curr = C->head;\
            while(curr->next != C->tail){\
                curr = curr->next;\
            }\
            T##_node* temp = C->tail;\
            C->tail = curr;\
            C->tail->next = C->head;\
            free(temp);\
        }\
        C->size -= 1;\
    }


#define __insert__(T)\
    void T##_insert(T##_circular* C, size_t index, T data){\
        assert(index >= 0 && index <= C->size);\
        /*if empty*/\
        if(C->size == 0){\
            T##_push(C, data);\
        }\
        else if(index < C->size){\
            T##_node* curr = C->head;\
            T##_node* new = malloc(sizeof *new);\
            new->data = data;\
            size_t count = 0;\
            while(count != index - 1){\
                count += 1;\
                curr = curr->next;\
            }\
            T##_node* next = curr->next;\
            curr->next = new;\
            new->next = next;\
            C->size += 1;\
        }\
        /*at end*/\
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