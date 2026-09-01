/* Experiment 15: Count characters, words and lines in a file */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char filename[100];
    FILE *fp;
    int c, characters = 0, words = 0, lines = 0, in_word = 0;

    printf("Enter file name: ");
    scanf("%99s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File opening error.\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        characters++;

        if (c == '\n')
            lines++;

        if (isspace(c))
            in_word = 0;
        else if (!in_word) {
            words++;
            in_word = 1;
        }
    }

    fclose(fp);

    printf("Characters = %d\n", characters);
    printf("Words = %d\n", words);
    printf("Lines = %d\n", lines);

    return 0;
}
