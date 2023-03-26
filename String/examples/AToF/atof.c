#include<ctype.h>
#include"atof.h"
#include<math.h>


/**********
 * approach: iteration method
***********/

//now is better than never
//this function cannot convert like 2e7, maybe later.

double _atof(HeapStr* HS)
{
    int i = 0;
    //ignore prefix spaces
    while(isspace(HS->str[i ++]))
        pass;

    //check sign
    int sign = (HS->str[i] == '-') ? -1 : 1;
    i += (HS->str[i] == '-');

    //integer part
    int int_part = 0;
    while(isdigit(HS->str[i]))
    {
        int_part = 10 * int_part + HS->str[i] - '0';
        i ++;
    }
    /*don't do like this
    while(isdigit(HS->str[i ++]))
    {
        int_part = 10 * int_part + HS->str[i] - '0';
    }
    This is the source of many errors
    */

//Readability counts.

    //if only has integer part
    if(Length(HS) == i)
        return (double)(sign * int_part); 

    //fractional part
    double frac_part = 0.0;
    if(HS->str[i] == '.')
        i ++;

    int power = -1;
    while(i < Length(HS))
    {
        frac_part += pow(10, power) * (HS->str[i] - '0');
        power -= 1;
        i ++;
    }

    return (double)(sign * ((double)(int_part) + frac_part));
}
