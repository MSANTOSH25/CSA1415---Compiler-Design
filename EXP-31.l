%{
#include <stdio.h>
%}
%%
"int"|"float"|"char"|"double"|"void"|"return"|"if"|"else"|"for"|"while"
        { printf("Keyword    : %s\n",yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier : %s\n",yytext); }
[ \t\n]+ ;
. ;
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
