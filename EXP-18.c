/* Experiment 18: Compute TRAILING()
   Grammar:
   E -> E+T | T
   T -> T*F | F
   F -> (E) | id
*/
#include <stdio.h>

int main(void) {
    printf("TRAILING(E) = { ), i }\n");
    printf("TRAILING(T) = { ), i }\n");
    printf("TRAILING(F) = { ), i }\n");
    return 0;
}
