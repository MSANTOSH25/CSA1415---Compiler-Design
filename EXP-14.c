/* Experiment 14: Three Address Code Generation */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
char op1, op2;
char a, b, c, d;
int temp = 1;

void print_temp(char x, char y, char op) {
    printf("t%d = %c %c %c\n", temp, x, op, y);
}

int main(void) {
    printf("Enter expression (example: a+b*c): ");
    scanf("%99s", expr);

    int len = strlen(expr);

    /* Handles simple expressions with * or / before + or -. */
    if (len == 5 && (expr[1] == '+' || expr[1] == '-') &&
        (expr[3] == '*' || expr[3] == '/')) {

        char t = '1' + temp - 1;
        printf("t%d = %c %c %c\n", temp, expr[2], expr[3], expr[4]);
        temp++;
        printf("t%d = %c %c t%d\n", temp, expr[0], expr[1], temp - 1);
    }
    else if (len == 5 && (expr[1] == '*' || expr[1] == '/')) {
        printf("t%d = %c %c %c\n", temp, expr[0], expr[1], expr[2]);
        temp++;
        printf("t%d = t%d %c %c\n", temp, temp - 1, expr[3], expr[4]);
    }
    else if (len == 3 && strchr("+-*/", expr[1])) {
        printf("t%d = %c %c %c\n", temp, expr[0], expr[1], expr[2]);
    }
    else {
        printf("Enter a simple expression such as a+b*c.\n");
    }

    return 0;
}
