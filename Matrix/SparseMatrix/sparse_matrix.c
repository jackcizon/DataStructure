#include"sparse_matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#include<memory.h>

function void CreateMatrix(SMatrix* M)
{
    memset(M, 0, sizeof *M);
    FILE* $fp = fopen("matrix.txt", "rb");
    if (not $fp)
    {
        exit(EXIT_FAILURE);
    }
    
    fscanf($fp, "%d %d", &M->mu, &M->nu);

    int value;
    int k = 0;
    for (int i = 0; i < M->mu; i++)
    {
        for (int j = 0; j < M->nu; j++)
        {
            fscanf($fp, "%d", &value);
            if (value != 0)
            {
                M->data[k].e = value;
                M->data[k].i = i;
                M->data[k].j = j;
                k ++;
            }
        }
    }
    M->tu = k;
    fclose($fp);
}

function void PrintMatrix(SMatrix* M)
{
    printf("row = %d, col = %d, total = %d\n", M->mu, M->nu, M->tu);
    for (int i = 0; i < M->tu; i++)
    {
        printf("(%d, %d, %d)\n", M->data[i].i, M->data[i].j, M->data[i].e);
    }   
}

function void Copy(SMatrix* M, SMatrix* T)
{
    T->mu = M->mu;
    T->nu = M->nu;
    T->tu = M->tu;

    for (int i = 0; i < M->tu; i++)
    {
        T->data[i].i = M->data[i].i;
        T->data[i].j = M->data[i].j;
        T->data[i].e = M->data[i].e;
    }
    
}

function void Add(SMatrix* M, SMatrix* N, SMatrix* T)
{
    assert(M->mu eq N->mu or M->nu eq N->nu or M->tu eq N->tu);
    T->mu = M->mu;
    T->nu = M->nu;
    T->tu = M->tu + N->tu;
    for (int k = 0; k < M->tu; k++)
    {
        T->data[k].i = M->data[k].i;
        T->data[k].j = M->data[k].j;
        T->data[k].e = M->data[k].e;
    }
    for (int k = 0; k < N->tu; k++)
    {
        T->data[k].i = N->data[k].i;
        T->data[k].j = N->data[k].j;
        T->data[k].e += N->data[k].e;
    }
    //unique
    int k = 0;
    for (int i = 0; i < M->mu; i++)
    {
        for (int j = 0; j < M->nu; j++)
        {
            if (M->data[k].i eq N->data[k].i and M->data[k].j eq N->data[k].j and k < (int)fmin(M->tu, N->tu))//check scope of 'k', check i, j if has duplicate
            {
                //if m(i, j) and n(i, j), count -1
                k += 1;
                T->tu -= 1;
            }
        }
    }
    //del (i, j, 0) -> '0'
    for (int size = T->tu; size > 0; size --)
    {
        if (T->data[size].e eq 0)
        {
            T->tu -= 1;
        }
    }
}

function void Sub(SMatrix* M, SMatrix* N, SMatrix* T)
{
    assert(M->mu eq N->mu or M->nu eq N->nu or M->tu eq N->tu);
    T->mu = M->mu;
    T->nu = M->nu;
    T->tu = M->tu + N->tu;
    for (int k = 0; k < M->tu; k++)
    {
        T->data[k].i = M->data[k].i;
        T->data[k].j = M->data[k].j;
        T->data[k].e = M->data[k].e;
    }
    for (int k = 0; k < N->tu; k++)
    {
        T->data[k].i = N->data[k].i;
        T->data[k].j = N->data[k].j;
        T->data[k].e -= N->data[k].e;
    }
    //unique
    int k = 0;
    for (int i = 0; i < M->mu; i++)
    {
        for (int j = 0; j < M->nu; j++)
        {
            if (M->data[k].i eq N->data[k].i and M->data[k].j eq N->data[k].j and k < (int)fmin(M->tu, N->tu))//check scope of 'k', check i, j if has duplicate
            {
                k += 1;
                T->tu -= 1;
            }
        }
    }
    //del (i, j, 0)->'0'
    for (int size = T->tu; size > 0; size --)
    {
        if (T->data[size].e eq 0)
        {
            T->tu -= 1;
        }
    }
    
}
//mxn nxq
//mxq
function void Mul(SMatrix* M, SMatrix* N, SMatrix* T)
{
    int k = 0;
    T->tu = 0;
    T->mu = M->mu;
    T->nu = N->nu;

    assert(M->nu eq N->mu);
    for (int i = 0; i < M->mu; i++)
    {
        for (int j = 0; j < N->nu; j++)
        {
            int sum = 0;
            for (int k = 0; k < N->mu; k++)
            {
                //e.g.: 24 -> (3, 2) , loc = 3 * 7 + 2 , i = 3, 7 = M->nu, 2 = k
                //mxp, pxn
                //(AB)_ij = sum(a_ij * b_kj, k, 1, p);
                //C[i][j] = C[i][j] + A[i][k] * B[k][j], we need convert 2-d to 1-d, locate element
                sum += M->data[i * M->nu + k].e + N->data[k * N->nu + j].e;
            }
            if (sum uneq 0)
            {
                T->data[k].e = sum;
                T->data[k].i = i;
                T->data[k].j = j;
                T->tu += 1;
                k += 1;
            }
        }
    }
}

function void Transpose(SMatrix* M, SMatrix* T)
{
    T->mu = M->nu;
    T->nu = M->mu;
    T->tu = M->tu;
    
    for (int k = 0; k < M->tu; k++)
    {
        T->data[k].i = M->data[k].j;
        T->data[k].j = M->data[k].i;
        T->data[k].e = M->data[k].e;
    }
}


function void FastTranspose(SMatrix* M, SMatrix* T)
{

}


