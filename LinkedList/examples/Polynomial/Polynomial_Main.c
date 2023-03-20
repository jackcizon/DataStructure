#include"Polynomial.h"

#define Polynomial void main(void)


#define BEGIN {

#define END }


static void SUM(void);
static void SUB(void);
static void MUL(void);
static void DIV(void);


    Polynomial

BEGIN

    SUM();
    SUB();
    MUL();
    DIV();

    puts("all executions success !");

END


static void SUM(void)
{
    polynomial* a = create();

    insert(a, 9, 3);
    insert(a, 4, 2);
    insert(a, 3, 0);
    insert(a, 7, 1);
    insert(a, 3, 4);
    
    puts("polynomial a : ");
    display(a);

    polynomial* b = create();
    insert(b, 7, 3);
    insert(b, 4, 0);
    insert(b, 6, 1);
    insert(b, 1, 2);
    puts("polynomial b : ");
    display(b);

    polynomial* Sum = create();
    add(a, b, Sum);
    puts("Sum : ");
    display(Sum);

    free(a);
    free(b);
    free(Sum);
}


static void SUB(void)
{
    polynomial* a = create();

    insert(a, 9, 3);
    insert(a, 4, 2);
    insert(a, 3, 0);
    insert(a, 7, 1);
    insert(a, 3, 4);
    
    puts("polynomial a : ");
    display(a);

    polynomial* b = create();
    insert(b, 7, 3);
    insert(b, 4, 0);
    insert(b, 6, 1);
    insert(b, 1, 2);
    puts("polynomial b : ");
    display(b);

    polynomial* differ = create();
    substract(a, b, differ);
    puts("difference : ");
    display(differ);

    free(a);
    free(b);
    free(differ);
}


static void MUL(void)
{
    polynomial* a = create();

    insert(a, 7, 3);
    insert(a, 4, 0);
    insert(a, 6, 1);
    insert(a, 1, 2);
    
    puts("polynomial a : ");
    display(a);

    polynomial* b = create();
    insert(b, 7, 3);
    insert(b, 4, 0);
    insert(b, 6, 1);
    insert(b, 1, 2);
    puts("polynomial b : ");
    display(b);

    polynomial* product = create();
    multiply(a, b, product);
    puts("quotient : ");
    display(product);

    free(a);
    free(b);
    free(product);
}


static void DIV(void)
{
    polynomial* a = create();

    insert(a, 7, 3);
    insert(a, 4, 0);
    insert(a, 6, 1);
    insert(a, 1, 2);
    
    puts("polynomial a : ");
    display(a);

    polynomial* b = create();
    insert(b, 7, 3);
    insert(b, 4, 0);
    insert(b, 6, 1);
    insert(b, 1, 2);
    puts("polynomial b : ");
    display(b);

    polynomial* quotient = create();
    divide(a, b, quotient);
    puts("quotient : ");
    display(quotient);

    free(a);
    free(b);
    free(quotient);
}

















