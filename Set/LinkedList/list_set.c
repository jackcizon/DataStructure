#include"list_set.h"



Set* New(size_t size, ...)
{
    Set* S = malloc(sizeof *S);
    S->size = 0;
    S->head = NULL;

    va_list ap;
    va_start(ap, size);

    for (size_t i = 0; i < size; i++)
    {
        void* data = va_arg(ap, void*);
        Contain(S, data) ?
            pass : Add(S, data);
    }
    va_end(ap);

    return S;   
}


node* Head(Set* S)
{
    return S->head;
}


void Destroy(Set* S)
{
    Clear(S);
    free(S);
}


size_t Size(Set* S)
{
    return S->size;
}


bool Empty(Set* S)
{
    return S->size == 0 ? true : false;
}


bool Add(Set* S, void* data)
{
    if(Contain(S, data))
    {
        return false;
    }

    node* _new = malloc(sizeof *_new);
    _new->data = data;
    _new->next = S->head;
    S->head = _new;
    S->size += 1;
    return true;
}


void Clear(Set* S)
{
    while(S->head)
    {
        node* temp = S->head;
        S->head = S->head->next;
        free(temp);
    }    
    S->size = 0;
}


bool Remove(Set* S, void* data)
{
    node* perv = NULL;
    node* curr = Head(S);
    while(curr)
    {
        if(curr->data == data)
        {
            if(perv)//size >= 1
            {
                perv->next = curr->next;
            }
            else//size == 1
            {
                S->head = curr->next;//NULL
            }
            free(curr);
            S->size -= 1;
            return true;
        }
        else
        {
            perv = curr;
            curr = curr->next;
        }
    }
    return false;
}


bool Contain(Set* S, void* data)
{
    node* curr = Head(S);

    while(curr)
    {
        if(curr->data == data)
        {
            return true;
        }
        else
        {
            curr = curr->next;
        }
    }
    return false;
}


void Traverse(Set* S) {
    node* curr = Head(S);
    printf("{ ");
    while (curr) {
        printf("%s ", (char*)curr->data);
        curr = curr->next;
    }
    printf("}\n");
}

