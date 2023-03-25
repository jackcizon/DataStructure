#include"seqstring.h"
#include<assert.h>

//allocate on the stack will be auto free when lifetime is end,
//the lifetime is limit to the scope of the function.
void Assign(SeqStr* SS, const string str)
{
    SS->len = strlen(str);
    assert(Length(SS) <= MAXSIZE);
    memcpy(SS->str, str, strlen(str) + 1);
}


size_t Length(SeqStr* SS)
{
    return SS->len;
}


bool Empty(SeqStr* SS)
{
    return SS->len == 0 ? true : false;
}


void SubStr(SeqStr* src, SeqStr* sub, size_t begin, size_t length)
{
    assert(begin <= Length(src));
    begin >= Length(src) ?
        sub->len = 0,sub->str[0] = '\0' : pass;
    begin + length > Length(src) ?
        length = Length(src) - begin : pass;
    sub->len = length;
    memcpy(sub->str, src->str + begin, length);
    sub->str[length] = '\0';
}


void Echo(SeqStr* SS)
{
    puts(SS->str);
}


void Clear(SeqStr* SS)
{
    memset(SS->str, 0, sizeof(SeqStr));
    SS->len = 0;
}


int Compare(SeqStr* SS1, SeqStr* SS2)
{
    return memcmp(SS1->str, SS2->str, (SS1->len < SS2->len) ? SS1->len : SS2->len);
}


void Copy(SeqStr* copy, SeqStr* src)
{
    memset(copy, 0, sizeof(SeqStr));
    memcpy(copy, src, sizeof(SeqStr));
}


void Delete(SeqStr* SS, size_t begin, size_t length)
{
    assert(begin <= Length(SS));
    size_t end = begin + length;

    end > Length(SS) ?
        end = SS->len : pass;

    memmove(SS->str + begin, SS->str + end, SS->len - end + 1);
    SS->len = end - begin;
}


void Insert(SeqStr* SS, size_t begin, const string str)
{
    size_t str_len = strlen(str);

    begin > SS->len ?
        begin = SS->len : pass;

    size_t new_len = SS->len + str_len;

    new_len > MAXSIZE ?
        new_len = MAXSIZE,
        str_len = new_len - SS->len : pass;   

    memmove(SS->str + begin + str_len, SS->str + begin, SS->len - begin + 1);
    memcpy(SS->str + begin, str, str_len);
    SS->len = new_len;
}


void Replace(SeqStr* SS, size_t index, string str)
{
    size_t str_len = strlen(str);
    assert(index < Length(SS));
    
    strlen(str) == 0 ?
        //left shift 1 byte
        memmove(SS->str + index, SS->str + index + 1, SS->len - index),
        SS->len -- : pass;

    index + str_len > Length(SS) ?
        str_len = SS->len - index : pass;
    
    memcpy(SS->str + index, str, str_len);
    
    //truncate
    str_len < strlen(str) ?
        SS->str[index + str_len] = '\0' : pass;
}   


void Concat(SeqStr* SS1, SeqStr* SS2)
{
    Length(SS1) + Length(SS2) <= MAXSIZE ?
        memcpy(SS1->str + Length(SS1), SS2->str, Length(SS2) + 1),
        SS1->len = Length(SS1) + Length(SS2) : pass;

    size_t copy_len;

    Length(SS1) + Length(SS2) > MAXSIZE ?
        copy_len = MAXSIZE - Length(SS1),
        memcpy(SS1->str + Length(SS1), SS2->str, copy_len),
        SS1->str[MAXSIZE] = '\0', SS1->len = MAXSIZE : pass;
}


char Get(SeqStr* SS, size_t index)
{
    return SS->str[index];
}


void Set(SeqStr* SS, size_t index, char ch)
{
    assert(index <= Length(SS));
    SS->str[index] = ch;
}