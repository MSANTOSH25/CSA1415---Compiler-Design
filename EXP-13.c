/* Experiment 13: Top-Down Parsing
   Grammar: E -> T E'
            E' -> + T E' | epsilon
            T -> id
*/
#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int E(void);
int Eprime(void);
int T(void);

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
    if (input[pos] == 'i' && input[pos + 1] == 'd') {
        pos += 2;
        return 1;
    }
    return 0;
}

int main(void) {
    printf("Enter expression (example: id+id+id): ");
    scanf("%99s", input);

    if (E() && input[pos] == '\0')
        printf("Input string is accepted by Top-Down Parser.\n");
    else
        printf("Input string is rejected by Top-Down Parser.\n");

    return 0;
}
