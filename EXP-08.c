/* Experiment 8: FOLLOW() for
   S -> AaAb | BbBa
   A -> epsilon
   B -> epsilon
*/
#include <stdio.h>

int main(void) {
    printf("FOLLOW(S) = { $ }\n");
    printf("FOLLOW(A) = { a, b }\n");
    printf("FOLLOW(B) = { a, b }\n");
    return 0;
}
