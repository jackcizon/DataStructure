#include"expression.h"
#include"stack.h"
#include <ctype.h>
#include<string.h>
#include<math.h>


stack(char);
stack(int);


void InToPost(const char* infix, char* postfix)
{
    char symbol, next;

    char_stack* S = char_new();

    int j = 0;

    for(int i = 0; i < strlen(infix); i ++)
    {
        symbol = infix[i];
        if(!isspace(symbol))
        {
            switch (symbol)
            {
                /*notes: i' not add '{} and []', if wanna add these, use switch to map to '()'*/
                case '(':
                    char_push(S, symbol);
                    break;
            
                case ')':
                    while(char_peek(S)->data != '(')
                    {
                        char_pop(S, &next);
                        if(next != '(')
                        {
                            postfix[j ++] = next;
                        }
                    }
                    char_pop(S, &next);
                    break;

                case '+': case '-': case '*': case '/':
                    while(!char_empty(S) && precedence(S->top->data) >= precedence(symbol))
                    {
                        char_pop(S, &postfix[j ++]);
                    }
                    char_push(S, symbol);
                    break;
                
                default:
                    postfix[j ++] = symbol;
            }
        }
    }

    while(!char_empty(S))
    {
        char_pop(S, &postfix[j ++]);
    }
    postfix[j] = '\0';
}


int precedence(char symbol)
{
    //other operators not add, if want to add others, just add and check precedence.
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '%':
        return 1;
    case '+':
    case '-':
        return 0;
    
    default:
        return -1;
    }
}


void PostEval(const char* postfix)
{
    int a, b;

    int_stack* S = int_new();

    for(int i = 0; i < strlen(postfix); i ++)
    {
        if(isdigit(postfix[i]))
        {
            int_push(S, postfix[i] - '0');
        }
        else
        {
            int_pop(S, &a);
            int_pop(S, &b);
            switch (postfix[i])
            {
            case '+':
                int_push(S, b + a);
                break;
            case '-':
                int_push(S, b - a);
                break;
            case '*':
                int_push(S, b * a);
                break;
            case '/':
                int_push(S, b / a);
                break;
            case '%':
                int_push(S, b % a);
                break;
            case '^':
                int_push(S, (int)pow(b, a));
                break;
            default:
                break;
            }
        }
    }
    printf("\nvalue : %d\n", S->top->data);
}

void PrintExpression(const char* postfix)
{
    for(int i = 0; i < strlen(postfix); i ++)
    {
        printf("%c ", postfix[i]);
    }
}
