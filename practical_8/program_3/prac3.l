/*Definition Section*/
%{
#include<stdio.h>
%}

%%
\/\/(.*) {};					
\/\*(.*\n)*.*\*\/  {};			
%%


int yywrap() {return 1;}

int main()
{
yyin=fopen("input.txt","r");
yyout=fopen("output.txt","w");
/*call the yylex function.*/
yylex();
return 0;
}

