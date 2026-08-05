%{
#include <stdio.h>
%}

%%

[0-9]      { printf("%s is a Digit\n", yytext); }

.+         { printf("%s is Not a Digit\n", yytext); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter an input:\n");
    yylex();
    return 0;
}