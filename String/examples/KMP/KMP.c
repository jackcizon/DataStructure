#include"KMP.h"

//failure function, partial match table, prefix function
//len(perfix) = len(match.str), and this prefix function
//or table describe how to move if not match


//consider pattren(match) "ABCDABD",
//the perfix function for this string is:

//  A B C D A B D
//  0 0 0 0 1 2 0

//notes, the first entry always 0, beacuse a string
//start has no *proper* prefix.

//the second entry is 0 because the proper perfix of "B"
//is the empty string, and also C is 0, and D.

//but the 5th is "A", and it has a proper perfix to match,
//which is the first "A" suffix

//and 6th entry is 2, because the proper perfix of "AB"
//is "A", which is a proper suffix of "AB"

//the 7th entry is 0, because the proper prefix of "ABD"
//is "AB", which is not a proper suffix of "ABD"

//finally, the 8th is 0, because the proper suffix of entir string
//"ABCDABD" is empty string.
void ComputePrefix(HeapStr* match, int* prefix)
{
    size_t len = Length(match);
    prefix[0] = 0;
    int j = 0;
    for (int i = 1; i < len; i ++) {//when i = 4, has a match, and j will +1, j = 1, and perfix[4] = 1, 
    //and continue while loop, and also match , and j will +1, j = 2, and prefix[5] = 2,
    //and because j = 2 > 0, continue while, str[2] != str[6], j = 0, loop terminate, and prefix[6] = 0, for loop end.
    //so we get a prefix table. which can help me to quick jump if not match.
        while (j > 0 && match->str[j] != match->str[i]) {
            j = prefix[j - 1];
        }
        if (match->str[j] == match->str[i]) {
            j++;
        }
        prefix[i] = j;
    }
}

//Once the prefix function is computed, 
//the actual string matching is done in O(n) time, 
//where n is the length of the text string 
//(i.e., the string we are searching in). 
//The algorithm starts at the beginning of the 
//text string and scans through it character by 
//character. Whenever a mismatch occurs between 
//the text string and the pattern string, 
//the algorithm uses the prefix function to 
//determine the largest prefix of the pattern 
//string that matches a suffix of the substring 
//that has already been scanned. This prefix 
//indicates the position in the pattern string 
//where the next comparison should begin. 
//By avoiding unnecessary backtracking, 
//the algorithm achieves linear time complexity.



int KMPMatch(HeapStr* target, HeapStr* match)
{
    size_t target_len = Length(target);
    size_t match_len = Length(match);

    if (match_len == 0)
    {
        return 0;
    }

    int* prefix = malloc(sizeof(int) * match_len);
    ComputePrefix(match, prefix);//above , table has generate.

    int j = 0;
/*********************************
    //traget:  A B C D A B D
    //         0 0 0 0 1 2 0
    //match    A B D
                   /\
                   ||
                    j = 2, i = 2, and then 'C' and 'D' not match, 
                    jump while loop, and j = prefix[1] = 0, now j = 0, i = 2
now:
    A B C D A B D
        A B D      , this step only i ++, i = 3. and to next for loop, only O(1), because not scan

    A B C D A B D
          A B D   , this also i ++, i = 4, j = 0, O(1).

    A B C D A B D
            A B D ,i = 4, match , j ++, j = 1, i++, i = 5
                    i = 5, j > 0, match , j = 2, i = 6
                    i = 6 , match , j = 3, i = len, end
                
*********************************/

    for (int i = 0; i < target_len; i++)
    {

        while (j > 0 && match->str[j] != target->str[i])//if not match
        {
            j = prefix[j - 1];
        }
        //if match , both i ++ and j ++
        if (match->str[j] == target->str[i])
        {
            j++;
        }
        //if all match
        if (j == match_len)
        {
            free(prefix);
            return i - match_len + 1;
        }
    }

    free(prefix);
    return -1;
}