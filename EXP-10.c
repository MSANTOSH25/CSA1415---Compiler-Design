/* Experiment 10: Eliminate left factoring
   S -> iEtS | iEtSeS | a
   E -> b
*/
#include <stdio.h>

int main(void) {
    printf("Given Grammar:\n");
    printf("S -> iEtS | iEtSeS | a\n");
    printf("E -> b\n\n");

    printf("Grammar after eliminating left factoring:\n");
    printf("S  -> iEtS S' | a\n");
    printf("S' -> eS | epsilon\n");
    printf("E  -> b\n");

    return 0;
}
