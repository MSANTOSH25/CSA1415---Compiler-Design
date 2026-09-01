%{
#include <stdio.h>
#include <string.h>
char word[50];
int count=0;
%}
%%
[a-zA-Z]+ { if(strcmp(yytext,word)==0) count++; }
[ \t\n]+ ;
. ;
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter word: ");
    scanf("%49s",word);
    getchar();
    printf("Enter sentence:\n");
    yylex();
    printf("Frequency of %s = %d\n",word,count);
    return 0;
}
