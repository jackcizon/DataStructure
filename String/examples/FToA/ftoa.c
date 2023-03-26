#include"ftoa.h"
#include<stdlib.h>
#include<math.h>


/*****
 * approcah : iteration
*****/

HeapStr* _ftoa(double val)
{
    HeapStr* HS = NewHS("");

    //define integer part
    unsigned int int_part = (unsigned int)fabs(val);
    //define fraction part
    double frac_part = fabs(val) - int_part;

    //handle integer part
    while(int_part != 0)
    {
        Push(HS, ToString(int_part % 10 + 48));
        int_part /= 10;   
    }

    //handle fraction part, we can get 100% fraction part
    Append(HS, ToString('.'));
    for(int i = 0; i < PRECISION; i ++)
    {
        frac_part *= 10;
        Append(HS, ToString((int)frac_part + 48));
        frac_part -= (int)(frac_part);
    }

    //handle sign
    val < 0 ?
        Push(HS, ToString('-')) : pass;

    return HS;
}


string ToString(char c)
{
    string str = malloc(sizeof(char) * 2);
    str[0] = c;
    str[1] = '\0';
    return str;
}