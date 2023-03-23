#include"convert.h"
#include"stack.h"
#include<ctype.h>
#include<math.h>


stack(int);
stack(char);

void decimal_to_n_base(int decimal, int base)
{
    if((int)base < 10)
    {
        int_stack* S = int_new();
        while(decimal != 0)
        {
            int_push(S, decimal % base);
            decimal /= base; 
        }
        int_traverse(S);
        free(S);
    }
    else if(base == 10)
    {
        printf("%d", decimal);
    }
    else if((int)base <= 16)
    {
        if(decimal < 10)
        {
            printf("%d", decimal);
            return;
        }
        char_stack* S = char_new();
        int reminder = 0;

        while(decimal != 0)
        {
            reminder = decimal % base;
            switch (reminder)
            {
            case 10:
                char_push(S, 'A');
                break;
            case 11:
                char_push(S, 'B');
                break;
            case 12:
                char_push(S, 'C');
                break;
            case 13:
                char_push(S, 'D');
                break;
            case 14:
                char_push(S, 'E');
                break;
            case 15:
                char_push(S, 'F');
                break;
            default:
                break;
            }
            decimal /= base;
        }
        char_traverse(S);
        free(S);
    }
}


void n_base_to_decimal(const char* n_base_number, int base)
{
    int decimal = 0;
    int digit = 0;

    for(int i = strlen(n_base_number) - 1; i >= 0; i --)
    {
        if(isdigit(n_base_number[i]))
        {
            digit = n_base_number[i] - '0';
        }
        else if(isalnum(toupper(n_base_number[i])))
        {
            digit = n_base_number[i] - 'A' + 10;
        }
        else
        {
            perror("invalid number.\n");
            exit(EXIT_FAILURE);
        }
        decimal += digit * pow(base, strlen(n_base_number) - 1 -i); 
    }

    int_stack* S = int_new();
    
    int_push(S, decimal);

    int_traverse(S);
}