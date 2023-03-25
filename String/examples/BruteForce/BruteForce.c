#include"BruteForce.h"

size_t BF_Index(HeapStr* target, HeapStr* match)
{
    int i = 0;
    int j = 0;
    while(i < Length(target))
    {
        while(j < Length(match))
        {
            if(match->str[j] == target->str[i])
            {
                i ++;
                j ++;
            }
            else
            {
                i = i - j + 1;//or i ++ for simple match
                j = 0;
            }
        }
        if(j == Length(match))
        {
            return i - Length(match);
        }
        else
        {
            return -1;
        }
    }   
}
