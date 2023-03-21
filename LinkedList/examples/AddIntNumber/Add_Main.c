#include"single_linked_list.h"

//use single linked list we need to inverse to get correct result, 
// or we will use double linked list.
list(int);


#define Add void main(void)

#define BEGIN {

#define END }

    Add

BEGIN

    int addend1 = 567;

    int addend2 = 7891;

    int_list* AddEnd1 = int_new();
    int_list* AddEnd2 = int_new();
    int_list* Sum = int_new();

    while(addend1)
    {
        int_append(AddEnd1, addend1 % 10);
        addend1 /= 10;
    }

    while(addend2)
    {
        int_append(AddEnd2, addend2 % 10);
        addend2 /= 10;
    }

    int_traverse(AddEnd1);
    puts("");
    int_traverse(AddEnd2);
    puts("");

    int carry = 0;
    int sum = 0;

    int_node* a1 = AddEnd1->head;
    int_node* a2 = AddEnd2->head;

    while(a1 && a2)
    {
        sum = 0;
        sum += a1->data;
        sum += a2->data;
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
    
        //in .h, we have already implement push(), so we don't need reverse()
        int_append(Sum, sum);
        a1 = a1->next;
        a2 = a2->next;
    }

    //if len(A1) = len(A2)
    if(!a1 && !a2)
    {
        if(carry == 1)
        {
            int_append(Sum, 1);
        }
    }

    else if(a1 || a2)
    {
        while(a1)
        {
            sum = 0;
            sum += a1->data;
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;

            int_append(Sum, sum);
            a1 = a1->next;
        }

        while(a2)
        {
            sum = 0;
            sum += a2->data;
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;

            int_append(Sum, sum);
            a2 = a2->next;
        }
    }    

    int_traverse(Sum);
    puts("");

    int_reverse(Sum);

    int_traverse(Sum);
    puts("");

    puts("all executions success!");

END
