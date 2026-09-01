%{
#include <stdio.h>
%}
%%
"int"|"float"|"char"|"double"|"void"|"return"|"if"|"else"
        { printf("Keyword    : %s\n",yytext); }
[0-9]+ { printf("Constant   : %s\n",yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier : %s\n",yytext); }
[+\-*/=<>] { printf("Operator   : %s\n",yytext); }
\"[^\"]*\" { printf("String     : %s\n",yytext); }
[;(),{}] { printf("Symbol     : %s\n",yytext); }
[ \t\n]+ ;
. ;
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
