/* Experiment 12: Recursive Descent Parser
   Grammar:
   E -> T E'
   E' -> + T E' | epsilon
   T -> F T'
   T' -> * F T' | epsilon
   F -> (E) | id
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int pos = 0;

int E(void);
int Eprime(void);
int T(void);
int Tprime(void);
int F(void);

int E(void) {
    return T() && Eprime();
}

int Eprime(void) {
    if (input[pos] == '+') {
        pos++;
        return T() && Eprime();
    }
    return 1;
}

int T(void) {
    return F() && Tprime();
}

int Tprime(void) {
    if (input[pos] == '*') {
        pos++;
        return F() && Tprime();
    }
    return 1;
}

int F(void) {
    if (input[pos] == 'i' && input[pos + 1] == 'd') {
        pos += 2;
        return 1;
    }
    if (input[pos] == '(') {
        pos++;
        if (E() && input[pos] == ')') {
            pos++;
            return 1;
        }
        return 0;
    }
    return 0;
}

int main(void) {
    printf("Enter expression (use id for identifier): ");
    scanf("%99s", input);

    if (E() && input[pos] == '\0')
        printf("String is accepted.\n");
    else
        printf("String is rejected.\n");

    return 0;
}
