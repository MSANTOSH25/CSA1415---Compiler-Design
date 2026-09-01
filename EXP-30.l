%{
#include <stdio.h>
int consonants=0;
%}
%%
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] { consonants++; }
[a-zA-Z] ;
[ \t\n]+ ;
. ;
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter a sentence:\n");
    yylex();
    printf("Number of consonants = %d\n",consonants);
    return 0;
}
