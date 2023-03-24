void InToPost(const char* infix, char* postfix);

int precedence(char symbol);

void PostEval(const char* postfix);

void PrintExpression(const char* postfix);