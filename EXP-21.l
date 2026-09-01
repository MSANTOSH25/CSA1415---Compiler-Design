%{
#include <stdio.h>
int macros=0, headers=0;
%}
%%
^[ \t]*#[ \t]*define.*  { macros++; }
^[ \t]*#[ \t]*include.* { headers++; }
\n ;
. ;
%%
int yywrap(){ return 1; }
int main(){
    yyin=fopen("sample.c","r");
    if(!yyin){ printf("File not found\n"); return 1; }
    yylex();
    printf("Number of Macros = %d\n",macros);
    printf("Number of Header Files = %d\n",headers);
    fclose(yyin);
    return 0;
}
