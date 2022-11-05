%{
#include<stdio.h>
#include<stdlib.h>
%}
/* Rule Section */
%%
^[0-9] printf("single digit");
^[0-9]* printf("multi-digit");
^[^0-9]|[0-9]*[a-zA-Z] printf("string");
. ;
%%
int main()
{
// The function that starts the analysis
yylex();
return 0;
}
int yywrap()
{
return 1;
}
