%{
#include<stdio.h>
#include<stdlib.h>
%}
/* Rule Section */
%%
[aeiouAEIOU] printf("vowel");
^[^0-9]|[0-9]*[a-zA-Z] printf("not a vowel");
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
