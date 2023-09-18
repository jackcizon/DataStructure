#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include"config.h"

typedef int ElemType;
#define MAX_SIZE 100

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
    ElemType e;
}
Triple;

/**
 * @brief Sparse Matrix
 * @param mu row-num
 * @param nu col-num
 * @param tu total count
 */
typedef struct SMatrix
{
    Triple data[MAX_SIZE];
    int mu;
    int nu;
    int tu;
}
SMatrix;

function void CreateMatrix(SMatrix* M);
function void PrintMatrix(SMatrix* M);
function void Copy(SMatrix* M, SMatrix* T);
function void Add(SMatrix* M, SMatrix* N, SMatrix* T);
function void Sub(SMatrix* M, SMatrix* N, SMatrix* T);
function void Mul(SMatrix* M, SMatrix* N, SMatrix* T);
function void Transpose(SMatrix* M, SMatrix* T);
function void FastTranspose(SMatrix* M, SMatrix* T);


#endif