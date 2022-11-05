
%{
#include<stdio.h>
#include<string.h>
%}

%%
auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short {ECHO; fprintf(yyout," :  KEYWORD\n");} 						

[{};,()]   {ECHO; fprintf(yyout, " : SEPERATOR\n");}						

[+-/=*%]   {ECHO; fprintf(yyout," : OPERATOR\n");}						

([a-zA-Z][0-9])+|[a-zA-Z]* {ECHO; fprintf(yyout," : Identifier\n");}    

.|\n ; 															
%%


int yywrap()								
{
return 1;
}



int main(void)
{
yyin = fopen("input.txt","r");
yyout = fopen("output.txt","w");
yylex();
return 0;
}