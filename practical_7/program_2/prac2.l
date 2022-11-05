/*Definition Section*/
%{
#include<stdio.h>
%}

%%

[0-9|()|{}|*|!|@|#|$|%|&] {fprintf(yyout,"%s",yytext);}				
[A-Z|a-z] {}
			
%%


int yywrap(){return 1;}
int main()
{
yyin=fopen("input.txt","r");
yyout=fopen("output.txt","w");

yylex();
return 0;
}
