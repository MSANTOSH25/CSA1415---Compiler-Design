%{
#include <stdio.h>
#include <string.h>
char oldword[50], newword[50];
FILE *out;
%}
%%
[a-zA-Z]+ {
    if(strcmp(yytext,oldword)==0) fprintf(out,"%s",newword);
    else fprintf(out,"%s",yytext);
}
\n { fprintf(out,"\n"); }
.  { fprintf(out,"%s",yytext); }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter word to replace: ");
    scanf("%49s",oldword);
    printf("Enter new word: ");
    scanf("%49s",newword);
    yyin=fopen("input.txt","r");
    out=fopen("output.txt","w");
    if(!yyin || !out){ printf("File opening error\n"); return 1; }
    yylex();
    fclose(yyin);
    fclose(out);
    printf("Word replaced successfully.\n");
    return 0;
}
