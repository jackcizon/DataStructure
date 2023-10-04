#include"dict.h"


Dict* NewDict(size_t size)
{
    Dict* D = malloc(sizeof *D);
    D->count = 0;
    D->size = size;
    D->entries = calloc(size, sizeof(Entry));
    return D;
}


size_t Hash(const string key, size_t size)
{
    size_t HashValue = 0;
    for (size_t i = 0; key[i] != '\0'; i++)
    {
        HashValue += key[i] + HashValue * 31;
    }
    return HashValue % size;
}


void InsertEntry(Dict* D, const string key, const string value)
{
    if(D->count == D->size)
    {
        fprintf(stderr, "dict is full.\n");
        exit(EXIT_FAILURE);
    }

    Entry* E = &(D->entries[Hash(key, D->size)]);
    if (E->key == NULL)
    {
        E->key = malloc(strlen(key) + 1);
        strncpy(E->key, key, strlen(key) + 1);
        E->value = malloc(strlen(value) + 1);
        strncpy(E->value, value, strlen(value) + 1);
        D->count += 1;
    }
    else if (strcmp(E->key, key) == 0)
    {
        free(E->value);
        E->value = malloc(strlen(value) + 1);
        strncpy(E->value, value, strlen(value) + 1);
    }
    else
    {
        fprintf(stderr, "key:'%s' already exist.\n", key);
    }
}


string GetValue(Dict* D, const string key)
{
    Entry* E = &(D->entries[Hash(key, D->size)]);
    return E->key != NULL && strcmp(key, E->key) == 0 ?
        E->value : NULL;
}

void DestroyDict(Dict* D)
{
    for (size_t i = 0; i < D->size; i++)
    {
        if (D->entries[i].key != NULL)
        {
            free(D->entries[i].key);
            free(D->entries[i].value);
        }
    }
    free(D->entries);
    free(D);
}


void Copy(Dict* dest, Dict* src)
{
    for (size_t i = 0; i < dest->size; i++)
    {
        if (dest->entries[i].key != NULL)
        {
            free(dest->entries[i].key);
            dest->entries[i].key = NULL;
        }
        if (dest->entries[i].value != NULL)
        {
            free(dest->entries[i].value);
            dest->entries[i].value = NULL;
        }
    }
    dest->count = 0;
    dest->size = src->size;
    dest->entries = malloc(dest->size * sizeof(Entry));
    if (dest->entries == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < dest->size; i++)
    {
        dest->entries[i].key = NULL;
        dest->entries[i].value = NULL;
    }
    for (int i = 0; i < src->size; i++)
    {
        if (src->entries[i].key != NULL)
        {
            InsertEntry(dest, src->entries[i].key, src->entries[i].value);
        }
    }
}


void Remove(Dict* D, const string key)
{
    Entry* E = &(D->entries[Hash(key, D->size)]);
    if(E->key != NULL && strcmp(E->key, key) == 0)
    {
        free(E->key);
        free(E->value);
        E->key = NULL;
        E->value = NULL;
        D->count -= 1;
    }
}


void Update(Dict* D, const string key, const string new_value)
{
    Entry* E = &(D->entries[Hash(key, D->size)]);
    if (E->key == NULL)
    {
        fprintf(stderr, "key: '%s' does not exist.\n", key);
    }
    else if (strcmp(E->key, key) == 0)
    {
        free(E->value);
        E->value = malloc(strlen(new_value) + 1);
        strncpy(E->value, new_value, strlen(new_value) + 1);
    }
    else
    {
        fprintf(stderr, "key: '%s' does not exist.\n", key);
    }
}


void Traverse(Dict* D)
{
    for (size_t i = 0; i < D->size; i++)
    {
        if(D->entries[i].key != NULL && D->entries[i].value != NULL)
        {
            printf("%s => %s\n", D->entries[i].key, D->entries[i].value);
        }
    }
}