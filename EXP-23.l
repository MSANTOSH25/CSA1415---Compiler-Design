%{
#include <stdio.h>
int line=1;
%}
%%
.*\n { printf("%3d  %s",line++,yytext); }
.+    { printf("%3d  %s\n",line++,yytext); }
%%
int yywrap(){ return 1; }
int main(){
    yyin=fopen("sample.c","r");
    if(!yyin){ printf("File not found\n"); return 1; }
    yylex();
    fclose(yyin);
    return 0;
}
