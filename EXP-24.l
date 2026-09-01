%{
#include <stdio.h>
int comments=0;
FILE *out;
%}
%%
"//".* { comments++; }
"/*"([^*]|\*+[^*/])*\*+"/" { comments++; }
\n { fprintf(out,"\n"); }
.  { fprintf(out,"%s",yytext); }
%%
int yywrap(){ return 1; }
int main(){
    yyin=fopen("input.c","r");
    out=fopen("output.c","w");
    if(!yyin || !out){ printf("File opening error\n"); return 1; }
    yylex();
    fclose(yyin);
    fclose(out);
    printf("Number of comments = %d\n",comments);
    printf("Comments removed successfully.\n");
    return 0;
}
