#include"stack.h"
#include"palindrome.h"


stack(char);


bool isPalindrome(const char* msg)
{
    int len = strlen(msg);

    char_stack* S1 = char_new();

    for(int i = 0; i < len; i ++)
    {
        char_push(S1, msg[i]);
    }  

    char_stack* S2 = char_new();

    for(int i = len - 1; i >= 0; i --)
    {
        char_push(S2, msg[i]);
    }

    char_node* s1 = S1->top;
    char_node* s2 = S2->top;

    while(s1 && s2)
    {
        if(s1->data == s2->data)
        {
            s1 = s1->next;
            s2 = s2->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}