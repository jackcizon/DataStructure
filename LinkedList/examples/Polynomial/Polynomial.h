#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct node
{
    int data;
    int power;
    struct node* next;
}
node;

typedef struct polynomial
{
    struct node* head;
}
polynomial;


node* newNode(int data, int power);

polynomial* create(void);

void display(polynomial*);

void insert(polynomial*, int, int);

void add(polynomial*, polynomial*, polynomial*);

void multiply(polynomial*, polynomial*, polynomial*);
 
void substract(polynomial*, polynomial*, polynomial*);

void divide(polynomial*, polynomial*, polynomial*);

void inverse(polynomial*);

void negate(polynomial*);


#endif
