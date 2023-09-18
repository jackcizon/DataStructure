#include"sparse_matrix.h"
#include<sys/dir.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdio.h>

function int main(int argc, char const *argv[])
{
    SMatrix sm, sm1, sm2, sm3, sm4, sm5, sm6;
    CreateMatrix(&sm);
    CreateMatrix(&sm1);
    CreateMatrix(&sm2);
    CreateMatrix(&sm3);
    CreateMatrix(&sm4);
    CreateMatrix(&sm5);
    CreateMatrix(&sm6);

    PrintMatrix(&sm); 

    puts("copy matrix:");
    Copy(&sm, &sm1);
    PrintMatrix(&sm1);

    puts("after adding:");
    Add(&sm, &sm1, &sm2);
    PrintMatrix(&sm2);

    puts("after subing:");
    Sub(&sm, &sm1, &sm3);
    PrintMatrix(&sm3);

    
    puts("after transposing:");
    Transpose(&sm, &sm4);
    PrintMatrix(&sm4);

    puts("after muling:");
    Mul(&sm, &sm4, &sm5);
    PrintMatrix(&sm5);

    puts("after fast transposing:");
    FastTranspose(&sm, &sm6);
    PrintMatrix(&sm6);

    puts("\npress enter to exit...\n");
    getchar();
    puts("press 'continue' or 'step over' to end.");
    return 0;
}