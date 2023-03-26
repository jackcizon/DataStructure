#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>


typedef char* string;


#define PUBLIC
#define PRIVATE static


#define typename(x)\
    _Generic((x), \
        double: "double",\
        int:     "int", \
        float:   "float", \
        bool:    "bool",\
        char:    "char",\
        string:  "string",\
        default: "unkonwn")\


//class
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
    __pop__(T);\
    __reverse__(T);


//List Constructor
#define __constructor__(T)\
    typedef struct T##_node{\
        T data;\
        struct T##_node* next;\
    }T##_node;\
    typedef struct T##_list{\
        T##_node* head;\
        size_t size;\
    }T##_list;


/*methods*/
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
        T##_node* temp = L->head;\
        while(temp->data != data){\
            count += 1;\
            temp = temp->next;\
        }\
        return count;\
    }


#define __head__(T)\
    T##_node* T##_head(T##_list* L){\
        return L->head;\
    }


#define __get__(T)\
    T T##_get(T##_list* L, size_t index){\
        size_t count = 0;\
        T##_node* temp = L->head;\
        while(index != count){\
            count += 1;\
            temp = temp->next;\
        }\
        return temp->data;\
    }


#define __search__(T)\
    bool T##_search(T##_list* L, T data){\
        T##_node* temp = L->head;\
        while(temp->data != data && temp != NULL){\
            temp = temp->next;\
        }\
        if(temp != NULL){\
            return true;\
        }\
        else{\
            return false;\
        }\
    }


#define __reverse__(T)\
    void T##_reverse(T##_list* L){\
        /*we will use two pointer, current and next, and change L->head each time while moving*/\
        assert(L->head);\
        if(L->size == 1){\
            return;\
        }\
        else{\
            T##_node* current = NULL;\
            T##_node* next = NULL;\
            /*draw a graph to understand*/\
            while(L->head != NULL){\
                next = L->head->next;\
                L->head->next = current;\
                current = L->head;\
                /*special case when next is null*/\
                if(next != NULL){\
                    L->head = next;\
                }\
                else{\
                    return;\
                }\
            }\
        }\
    }


//remove the first if found
#define __remove__(T)\
    void T##_remove(T##_list* L, T data){\
        assert(L && L->head);\
        T##_node* curr = L->head;\
        T##_node* prev = L->head;\
        if(L->head->data == data){\
            L->head = curr->next;\
            free(curr);\
        }\
        else{\
            while(curr->data != data && curr != NULL){\
                prev = curr;\
                curr = curr->next;\
            }\
            if(curr->data == data){\
                prev->next = curr->next;\
                free(curr);\
                curr = NULL;\
            }\
        }\
    }


//insert at end
#define __append__(T)\
    void T##_append(T##_list* L, T data){\
        assert(L);\
        T##_node* node = malloc(sizeof *node);\
        node->data = data;\
        if(L->size == 0){\
            /*push(L, data)*/\
            L->size += 1;\
            node->next = L->head;\
            L->head = node;\
        }\
        /*loop node*/\
        else{\
            node->next = NULL;\
            T##_node* temp = L->head;\
            while(temp->next != NULL){\
                temp = temp->next;\
            }\
            temp->next = node;\
            L->size += 1;\
        }\
    }


//insert at begin
#define __push__(T)\
    void T##_push(T##_list* L,T data){\
        assert(L);\
        L->size += 1;\
        T##_node* node = malloc(sizeof *node);\
        node->data = data;\
        node->next = L->head;\
        L->head = node;\
    }


//delete the last one
#define __pop__(T)\
    void T##_pop(T##_list* L){\
        assert(L && L->head);\
        L->size -= 1;\
        /*size = 1*/\
        if(L->head->next == NULL){\
            free(L->head);\
            L->head = NULL;\
        }\
        else{\
            T##_node* temp1 = L->head;\
            T##_node* temp2 = NULL;\
            while(temp1->next != NULL){\
            temp2 = temp1;\
            temp1 = temp1->next;\
            }\
            temp2->next = NULL;\
            free(temp1);\
            temp1 =NULL;\
        }\
    }


#define __delete__(T)\
    void T##_delete(T##_list* L, size_t index){\
        assert(L && L->head);\
        assert(index >= 0 && index < L->size);\
        T##_node* curr = L->head;\
        T##_node* prev = L->head;\
        L->size -= 1;\
        if(index == 0){\
            L->head = curr->next;\
            free(curr);\
        }\
        else{\
            size_t count = 0;\
            while(count < index){\
                prev = curr;\
                curr = curr->next;\
                count += 1;\
            }\
            prev->next = curr->next;\
            free(curr);\
            curr = NULL;\
        }\
    }


#define __insert__(T)\
    void T##_insert(T##_list* L, size_t index, T data){\
        assert(L);\
        T##_node* temp = L->head;\
        T##_node* node = malloc(sizeof *node);\
        node->data = data;\
        assert(index >= 0 && index <= L->size);\
        size_t count = 0;\
        if(count == index){\
            T##_push(L, data);\
        }\
        else{\
            while(count != index - 1){\
                count += 1;\
                temp = temp->next;\
        }\
            node->next = temp->next;\
            temp->next = node;\
            L->size += 1;\
        }\
    }


#define __traverse__(T)\
    void T##_traverse(T##_list* L){\
        assert(L && L->head);\
        T##_node* temp = L->head;\
        if(strcmp(typename(L->head->data), "double")== 0)/*sizeof str=double*/\
        {\
            while(temp != NULL)\
            {\
                printf("%lf\n", temp->data);\
                temp = temp->next;\
            }\
        }\
        if(strcmp(typename(L->head->data), "int")== 0)\
        {\
            while(temp != NULL)\
            {\
                printf("%d\n", temp->data);\
                temp = temp->next;\
            }\
        }\
        if(strcmp(typename(L->head->data), "char")== 0)\
        {\
            while(temp != NULL)\
            {\
                printf("%c\n", temp->data);\
                temp = temp->next;\
            }\
        }\
        else if(strcmp(typename(L->head->data), "float")== 0)\
        {\
            while(temp != NULL)\
            {\
                printf("%f\n", temp->data);\
                temp = temp->next;\
            }\
        }\
        else if(strcmp(typename(L->head->data), "string")== 0){\
            while(temp != NULL)\
            {\
                printf("%s\n", temp->data);\
                temp = temp->next;\
            }\
        }\
    }

#endif
