#ifndef EXPRESSION_H
#define EXPERSSION_H

void InToPost(const char* infix, char* postfix);

int precedence(char symbol);

void PostEval(const char* postfix);

void PrintExpression(const char* postfix);

#endif
