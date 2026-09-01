/* Experiment 11: Symbol Table Operations */
#include <stdio.h>
#include <string.h>

#define MAX 50

struct Symbol {
    char name[30];
    char type[20];
    int address;
};

struct Symbol table[MAX];
int n = 0;

void insert(void) {
    char name[30], type[20];
    int address;

    printf("Enter identifier: ");
    scanf("%29s", name);
    printf("Enter type: ");
    scanf("%19s", type);
    printf("Enter address: ");
    scanf("%d", &address);

    for (int i = 0; i < n; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol already exists.\n");
            return;
        }
    }

    strcpy(table[n].name, name);
    strcpy(table[n].type, type);
    table[n].address = address;
    n++;

    printf("Symbol inserted successfully.\n");
}

void search(void) {
    char name[30];
    printf("Enter identifier to search: ");
    scanf("%29s", name);

    for (int i = 0; i < n; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Identifier: %s\nType: %s\nAddress: %d\n",
                   table[i].name, table[i].type, table[i].address);
            return;
        }
    }
    printf("Symbol not found.\n");
}

void display(void) {
    printf("\nSymbol Table\n");
    printf("Name\tType\tAddress\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%s\t%d\n", table[i].name, table[i].type, table[i].address);
}

int main(void) {
    int choice;

    while (1) {
        printf("\n1.Insert  2.Search  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
