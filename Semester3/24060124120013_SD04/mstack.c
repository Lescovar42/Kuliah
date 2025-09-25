#include <stdio.h>
#include <string.h>
#include "stack.h"

int precedence(char op);
void infixToPostfix(const char *infix, int n, Tstack *out);

int main() {
    const char *expr = "3+(4*5)-2";
    int n = strlen(expr);

    Tstack postfix;
    infixToPostfix(expr, n, &postfix);

    printf("Infix   : %s\n", expr);
    printf("Postfix : ");
    printStack(postfix);

    return 0;
}
