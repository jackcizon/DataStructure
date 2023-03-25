#include"seqstring.h"


int main(int argc, const string argv[])
{
    //don't use pointer to allocate on the stack, it will cause SIGSEGV,
    SeqStr SS1;
    SeqStr* SS1_ptr = &SS1;
    Assign(SS1_ptr, "will be erased");
    Clear(SS1_ptr);
    Echo(SS1_ptr);
    Empty(SS1_ptr) ? 
        puts("empty.") : puts("not empty");
    printf("length : %d\n", Length(SS1_ptr));
    Assign(SS1_ptr, "new assignment");
    Echo(SS1_ptr);

    SeqStr copy1;
    SeqStr* copy1_ptr = &copy1;
    Assign(copy1_ptr, "");
    Copy(copy1_ptr, SS1_ptr);
    Echo(copy1_ptr);

    SeqStr Sub;
    SeqStr* sub_ptr = &Sub;
    SubStr(SS1_ptr, sub_ptr, 4, 6);
    Echo(sub_ptr);

    Concat(SS1_ptr, sub_ptr);
    Echo(SS1_ptr);


    Compare(sub_ptr, SS1_ptr) < 0 ?
        puts("sub is small") : puts("sub is large");

    Insert(SS1_ptr, Length(SS1_ptr) - 1, " new insertion");
    Echo(SS1_ptr);
    Delete(SS1_ptr, 0, Length(SS1_ptr));
    puts("after delete:");
    Echo(SS1_ptr);

    puts("all executions success!");

    return 0;
}


