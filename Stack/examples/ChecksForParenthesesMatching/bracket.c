#include"bracket.h"
#include"stack.h"


stack(char);


bool isMatchPair(char open, char close)
{
    if(open == '(' && close == ')') 
    {
        return true;
    }
    else if(open == '{' && close == '}')
    {
        return true;
    }
    else if(open == '[' && close == ']')
    {
        return true;
    }
    else 
    {
        return false;
    }
}


bool _BracketsMatch(const char* msg)
{
    char_stack* S = char_new();    

    for (int i = 0; i < strlen(msg); i++)
    {
        if (msg[i] == '(' || msg[i] == '{' || msg[i] == '[')
        {
            char_push(S, msg[i]);
        }
        else if(msg[i] == ')' || msg[i] == '}' || msg[i] == ']')
        {
            if (char_empty(S) || !isMatchPair(S->top->data, msg[i]))
            {
                return false;
            }
            else
            {
                char_pop(S);
            }
        }
    }
    if(char_empty(S))
    {
        return true;
    }
    else
    {
        return false;
    }
}