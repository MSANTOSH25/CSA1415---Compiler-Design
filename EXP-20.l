%{
#include <stdio.h>
%}
%%
[0-9]+(\.[0-9]+)? { printf("Constant: %s\n",yytext); }
[ \t\n]+ ;
. ;
%%
int yywrap(){ return 1; }
int main(){
    yyin=fopen("sample.c","r");
    if(!yyin){ printf("File not found\n"); return 1; }
    yylex();
    fclose(yyin);
    return 0;
}
