#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

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
#define list(T) \
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
    __pop__(T);


//List Constructor
#define __constructor__(T)\
    typedef struct T##_node{\
        T data;\
        struct T##_node* next;\
        struct T##_node* prev;\
    }T##_node;\
    typedef struct T##_list{\
        T##_node* head;\
        size_t size;\
    }T##_list;


//Methods
#define __new__(T)\
    T##_list* T##_new(void){\
        T##_list* L = malloc(sizeof *L);\
        assert(L);\
        L->head = NULL;\
        L->size = 0;\
        return L;\
    }


#define __size__(T)\
    size_t T##_size(T##_list* L){\
        return L->size;\
    }


#define __empty__(T)\
    bool T##_empty(T##_list* L){\
        return L->size == 0 ? true : false;\
    }


#define __index__(T)\
    size_t T##_index(T##_list* L, T data){\
        size_t count = 0;\
        T##_node* curr = L->head;\
        while(curr->data != data){\
            count += 1;\
            curr = curr->next;\
        }\
        return count;\
    }


#define __head__(T)\
    T##_node* T##_head(T##_list* L){\
        return L->head;\
    }


#define __traverse__(T)\
    void T##_traverse(T##_list* L){\
        assert(L && L->head);\
        T##_node* curr = L->head;\
        if(strcmp(typename(L->head->data), "double")== 0)/*sizeof str=double*/\
        {\
            while(curr != NULL)\
            {\
                printf("%lf ", curr->data);\
                curr = curr->next;\
            }\
        }\
        if(strcmp(typename(L->head->data), "int")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%d ", curr->data);\
                curr = curr->next;\
            }\
        }\
        if(strcmp(typename(L->head->data), "char")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%c", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(L->head->data), "float")== 0)\
        {\
            while(curr != NULL)\
            {\
                printf("%f ", curr->data);\
                curr = curr->next;\
            }\
        }\
        else if(strcmp(typename(L->head->data), "string")== 0){\
            while(curr != NULL)\
            {\
                printf("%s", curr->data);\
                curr = curr->next;\
            }\
        }\
    }


#define __get__(T)\
    T T##_get(T##_list* L, size_t index){\
        size_t count = 0;\
        T##_node* curr = L->head;\
        while(index != count){\
            count += 1;\
            curr = curr->next;\
        }\
        return curr->data;\
    }


#define __search__(T)\
    bool T##_search(T##_list* L, T data){\
        T##_node* curr = L->head;\
        while(curr->data != data && curr != NULL){\
            curr = curr->next;\
        }\
        if(curr != NULL){\
            return true;\
        }\
        else{\
            return false;\
        }\
    }


//insert at end
#define __append__(T)\
    void T##_append(T##_list* L, T data){\
        assert(L);\
        L->size += 1;\
        T##_node* node = malloc(sizeof *node);\
        node->data = data;\
        /*add to empty*/\
        if(L->head == NULL){\
            L->head = node;\
            node->prev = node->next = NULL;\
        }\
        /*loop node*/\
        else{\
            node->next = NULL;\
            T##_node* curr = L->head;\
            while(curr->next != NULL){\
                curr = curr->next;\
            }\
            curr->next = node;\
            node->prev = curr;\
        }\
    }


//insert at begin
#define __push__(T)\
    void T##_push(T##_list* L, T data){\
        assert(L);\
        L->size += 1;\
        T##_node* node = malloc(sizeof *node);\
        node->data = data;\
        /*add to empty*/\
        if(L->head == NULL){\
            L->head = node;\
            node->prev = node->next = NULL;\
        }\
        else{\
            node->next = L->head;\
            L->head->prev = node;\
            L->head = node;\
        }\
    }


#define __insert__(T)\
    void T##_insert(T##_list* L, size_t index, T data){\
        assert(L);\
        assert(index >= 0 && index <= L->size);\
        T##_node* curr1 = L->head;\
        T##_node* curr2 = NULL;\
        T##_node* node = malloc(sizeof *node);\
        node->next = node->prev = NULL;\
        node->data = data;\
        if(index == 0){\
            T##_push(L, data);\
        }\
        else if(index < L->size){\
            L->size += 1;\
            size_t count = 0;\
            while(count != index - 1){\
                count += 1;\
                curr1 = curr1->next;\
            }\
            /*consider if curr2 is null, cause null can't point anything, 
            we can't assign curr2->prev, it may cause memery leak*/\
            curr2 = curr1->next;\
            curr1->next = node;\
            curr2->prev = node;\
            node->next = curr2;\
            node->prev = curr1;\
        }\
        else{\
            T##_append(L, data);\
        }\
    }


//delete the last one
#define __pop__(T)\
    void T##_pop(T##_list* L){\
        assert(L && L->head);\
        /*size = 1*/\
        if(L->size == 1){\
            T##_delete(L, 0);\
        }\
        else{\
            L->size -= 1;\
            T##_node* curr = L->head;\
            T##_node* prev = NULL;\
            while(curr->next != NULL){\
                curr = curr->next;\
            }\
            prev = curr->prev;\
            prev->next = NULL;\
            free(curr);\
            curr = NULL;\
        }\
    }


#define __remove__(T)\
    void T##_remove(T##_list* L, T data){\
        assert(L && L->head);\
        T##_node* curr = L->head;\
        T##_node* prev = NULL;\
        if(L->head->data == data){\
            L->head = curr->next;\
            free(curr);\
        }\
        else{\
            /*loop until the -2 pos*/\
            while(curr->data != data && curr->next->next != NULL){\
                curr = curr->next;\
            }\
            if(curr->data == data){\
                prev = curr->prev;\
                prev->next = curr->next;\
                curr->next->prev = prev;\
                free(curr);\
            }\
            /*the last one*/\
            else{\
                if(curr->next->data == data){\
                    curr = curr->next;\
                    prev = curr->prev;\
                    prev->next = NULL;\
                    free(curr);\
                    curr = NULL;\
                }\
            }\
        }\
        L->size -= 1;\
    }


#define __delete__(T)\
    void T##_delete(T##_list* L, size_t index){\
        assert(L && L->head);\
        assert(index >= 0 && index < L->size);\
        T##_node* curr = L->head;\
        T##_node* prev = NULL;\
        if(index == 0){\
            L->head = curr->next;\
            free(curr);\
        }\
        else if(index < L->size - 1){\
            size_t count = 0;\
            while(count < index){\
                curr = curr->next;\
                count += 1;\
            }\
            prev = curr->prev;\
            prev->next = curr->next;\
            curr->next->prev = prev;\
            free(curr);\
        }\
        else{\
        T##_pop(L);\
        }\
        L->size -= 1;\
    }

#endif
