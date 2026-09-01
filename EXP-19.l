%{
#include <stdio.h>
int characters=0, lines=0, words=0;
%}
%%
\n              { lines++; characters++; }
[ \t]+          { characters += yyleng; }
[a-zA-Z0-9_]+   { words++; characters += yyleng; }
.               { characters++; }
%%
int yywrap(){ return 1; }
int main(){
    yyin=fopen("sample.c","r");
    if(!yyin){ printf("File not found\n"); return 1; }
    yylex();
    printf("Characters = %d\n",characters);
    printf("Lines = %d\n",lines);
    printf("Words = %d\n",words);
    fclose(yyin);
    return 0;
}
