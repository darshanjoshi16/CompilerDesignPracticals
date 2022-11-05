%{
#include<stdio.h>
#include<string.h>
char line[20];
FILE *yyin,*yyout;
%}
%%
['\n'] { fprintf(yyout,"%s\n",line);}
(..*)  {strcpy(line,yytext);}
%%
int main()
{
yyin=fopen("input.txt","r");
yyout=fopen("output.txt","w");
yylex();
printf("%s\n",line);
}
int yywrap()
{
return 1;
}