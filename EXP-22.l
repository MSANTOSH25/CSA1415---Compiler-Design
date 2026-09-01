%{
#include <stdio.h>
%}
%%
<[^>]+> { printf("HTML Tag: %s\n",yytext); }
.|\n ;
%%
int yywrap(){ return 1; }
int main(){
    yyin=fopen("sample.html","r");
    if(!yyin){ printf("File not found\n"); return 1; }
    yylex();
    fclose(yyin);
    return 0;
}
