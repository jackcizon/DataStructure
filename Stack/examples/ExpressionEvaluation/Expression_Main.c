#include"expression.h"
#include"stack.h"


#define Expression void main(void)

#define BEGIN {

#define END }


    Expression

BEGIN

    char postfix[20];

    InToPost("(4+3)*5", postfix);//right

    PrintExpression(postfix);//right

    PostEval(postfix);    



    puts("\n\nall executions success!");

END