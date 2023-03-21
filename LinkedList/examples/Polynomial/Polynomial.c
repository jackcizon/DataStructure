#include"Polynomial.h"


node* newNode(int data, int power)
{
    node* new = malloc(sizeof *new);
    assert(new);
    new->data = data;
    new->power = power;
    new->next = NULL;
    return new;
}


polynomial* create(void)
{
    polynomial* new = malloc(sizeof *new);
    assert(new);
    new->head = NULL;
    return new;
}


void insert(polynomial* P, int data, int power)
{
    //if empty
    if(P->head == NULL)
    {
        P->head = newNode(data, power);
    }
    //if not empty, we need sort by power
    else
    {
        node* current = P->head;
        node* new = NULL;
        node* location = NULL;
        //example of expression, 3x^2 + 4x + 1
        while(current != NULL/*if not insert at begin, loccation won't be null*/ && current->power > power)
        //we must let the large power at begin. and small in end
        {
            //find the next if samll
            location = current;
            current = current->next;
        }

        //end loop, may some cases
        //case 1; we find the location
        if(location != NULL && location->power == power)
        {
            location->data = location->data + data;
        }
        //case 2, no match with data's power
        else
        {
            new = newNode(data, power);
            //in this case, the data's power is largest,
            //because the while loop will break and never
            //execute even one time, and location still be NULL
            if(location == NULL)
            {
                new->next = P->head;
                P->head = new;
            }
            //this case may can find matcher in mid or end,
            //so we just use location to locate position
            else
            {
                //e,g. insert 3x^2 into 4x^3 + 2x
                //then insert 2x into above expression
                new->next = location->next;//location won't be null, details in while() statement.
                location->next = new;
            }
        }
    }
}


void add(polynomial* Addend1, polynomial* Addend2, polynomial* Sum)
{
    //In order not to affect the original polynomial, 
    //we will construct a new polynomial to store the result
    node* a1 = Addend1->head;
    node* a2 = Addend2->head;
    while(a1->next && a2->next)
    {
        if(a1->power > a2->power)
        {
            insert(Sum, a1->data, a1->power);
            a1 = a1->next;
        }
        else if(a1->power < a2->power)
        {
            insert(Sum, a2->data, a2->power);
            a2 = a2->next;
        } 
        else//if match power
        {
            insert(Sum, a1->data + a2->data, a1->power);
            a1 = a1->next;
            a2 = a2->next;
        }
    }

    while(a1 || a2)
    {
        if(a1)
        {
            insert(Sum, a1->data, a1->power);
            a1 = a1->next;
        }
        if(a2)
        {
            insert(Sum, a2->data, a2->power);
            a2 = a2->next;
        }
    }
}


void multiply(polynomial* Multiplier1, polynomial* Multiplier2, polynomial* product)
{
    //multiplay is simple, just visit every node then multiply
    node* m1 = Multiplier1->head;
    while(m1)
    {
        node* m2 = Multiplier2->head;
        while(m2)
        {
            insert(product, m1->data * m2->data, m1->power + m2->power);
            m2 = m2->next;
        }
        m1 = m1->next;
    }
}


void substract(polynomial* minuend, polynomial* subtrahend, polynomial* difference)
{
    negate(subtrahend);
    add(minuend, subtrahend, difference);
}


//Quotient Divisor Division operation, this methods seems wrong, beacuse linked list cannot implement this operation correctly
void divide(polynomial* dividend, polynomial* divisor, polynomial* quotient)
{
    inverse(divisor);
    multiply(dividend, divisor, quotient);
}


//let P*inv(P) = 1, so data' = 1/data, power' = -power
void inverse(polynomial* P)
{
    node* current = P->head;
    assert(current);
    while(current)
    {
        current->data = 1 / current->data;
        current->power = -1 * current->power;
        current = current->next;
    }
}


//just let data negate
void negate(polynomial* P)
{
    node* current = P->head;
    assert(current);
    while(current)
    {
        current->data *= -1;
        current = current->next;
    }
}


//not good need optimize, not now
void display(polynomial* P)
{
    node* current = P->head;
    bool printed_term = false;

    while(current != NULL)
    {
        if(current->data != 0)
        {
            if(printed_term && current->data > 0)
            {
                printf(" + ");
            }

            if(current->data == -1 && current->power != 0)
            {
                printf("-");
            }
            else if(current->data != 1 || current->power == 0)
            {
                printf("%d", current->data);
            }

            if(current->power == 1)
            {
                printf("x");
            }
            else if(current->power > 1)
            {
                printf("x^%d", current->power);
            }

            printed_term = true;
        }

        current = current->next;
    }

    if(!printed_term)
    {
        printf("0");
    }

    printf("\n");
}

