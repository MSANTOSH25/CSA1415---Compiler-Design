/* Experiment 17: Compute LEADING()
   Grammar:
   E -> E+T | T
   T -> T*F | F
   F -> (E) | id
*/
#include <stdio.h>

int main(void) {
    printf("LEADING(E) = { (, i }\n");
    printf("LEADING(T) = { (, i }\n");
    printf("LEADING(F) = { (, i }\n");
    return 0;
}
