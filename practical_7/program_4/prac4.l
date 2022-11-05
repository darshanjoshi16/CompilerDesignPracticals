/*Definition Section*/
%{
#include<stdio.h>
%}


/*Rule Section*/

%%

\/\/(.*) {fprintf(yyout,yytext);};					
[A-Z|a-z |()|{}] {}
\/\*(.*\n)*.*\*\/  {fprintf(yyout,yytext);};			
%%

/*call the yywrap function*/
int yywrap()
{
return 1;
}



/*Auxiliary function*/
/*Driver function*/

int main()
{
yyin=fopen("input.txt","r");
yyout=fopen("output.txt","w");

yylex();
return 0;
}
