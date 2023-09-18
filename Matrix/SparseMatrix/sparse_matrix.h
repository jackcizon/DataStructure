#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include"config.h"

typedef ELemType int;

/**
 * @brief define Triple
 * @param i row
 * @param j column
 * @param e element
 */
typedef struct Triple
{
    int i;
    int j;
    ELeType e;
}
Triple;




#endif