#include"dict.h"


int main(int argc, char const *argv[])
{
    Dict* D = NewDict(10);
    InsertEntry(D, "hello", "world");
    InsertEntry(D, "fooi", "bar");
    Remove(D, "fooi");

    Update(D, "fooi", "new_value");

    echo(GetValue(D, "hello"));
    echo(GetValue(D, "fooi"));
    Traverse(D);

    puts("");
    Dict* cp = NewDict(0);
    Copy(cp, D);
    Traverse(cp);

    return 0;
}
