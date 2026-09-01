/* Experiment 9: Eliminate left recursion
   S -> (L) | a
   L -> L,S | S
*/
#include <stdio.h>

int main(void) {
    printf("Given Grammar:\n");
    printf("S -> (L) | a\n");
    printf("L -> L,S | S\n\n");

    printf("Grammar after eliminating left recursion:\n");
    printf("S  -> (L) | a\n");
    printf("L  -> S L'\n");
    printf("L' -> , S L' | epsilon\n");

    return 0;
}
