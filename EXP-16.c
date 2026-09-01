/* Experiment 16: Simple back end of a compiler
   Generates target-like assembly instructions for a postfix expression.
   Input operands are single letters/digits and operators + - * /.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop(void) {
    return stack[top--];
}

int main(void) {
    char postfix[100];
    int reg = 0;

    printf("Enter postfix expression (example: ab+c*): ");
    scanf("%99s", postfix);

    printf("\nTarget Code:\n");

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum((unsigned char)ch)) {
            push(ch);
        } else if (strchr("+-*/", ch) && top >= 1) {
            char b = pop();
            char a = pop();

            printf("MOV R%d, %c\n", reg, a);
            switch (ch) {
                case '+': printf("ADD R%d, %c\n", reg, b); break;
                case '-': printf("SUB R%d, %c\n", reg, b); break;
                case '*': printf("MUL R%d, %c\n", reg, b); break;
                case '/': printf("DIV R%d, %c\n", reg, b); break;
            }
            push('T');
            reg++;
        } else {
            printf("Invalid postfix expression.\n");
            return 1;
        }
    }

    printf("Code generation completed.\n");
    return 0;
}
