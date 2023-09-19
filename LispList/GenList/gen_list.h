#pragma once
#include"config.h"

typedef int AtomType;

typedef enum ElemTag
{
    HEAD,
    ATOM,
    CHILDLIST
}
ElemTag;


/**
 * @brief General Lsit
 * 
 */

typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;
        struct GLNode* hp;
    };
    struct GLNode* tp;
}
GLNode;



