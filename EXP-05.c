/* Experiment 5: Count whitespaces and newline characters */
#include <stdio.h>

int main(void) {
    int c, spaces = 0, newlines = 0;

    printf("Enter text (Ctrl+D to finish):\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            spaces++;
        else if (c == '\n')
            newlines++;
    }

    printf("Number of whitespaces = %d\n", spaces);
    printf("Number of newline characters = %d\n", newlines);

    return 0;
}
