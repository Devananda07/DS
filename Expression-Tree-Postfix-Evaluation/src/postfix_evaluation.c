#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int value) { stack[++top] = value; }
int pop(void) { return stack[top--]; }

int main(void) {
    char postfix[] = "8 3 2 * + 6 2 / -";
    int i, a, b, result;

    printf("Postfix Expression: %s\n\n", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] == ' ') continue;

        if (isdigit((unsigned char)postfix[i])) {
            push(postfix[i] - '0');
            printf("Read %c  -> push %d\n", postfix[i], postfix[i] - '0');
        } else {
            b = pop();
            a = pop();

            switch (postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
            printf("Apply %d %c %d -> %d, push %d\n",
                   a, postfix[i], b, result, result);
        }
    }

    printf("\nFinal Result = %d\n", pop());
    return 0;
}
