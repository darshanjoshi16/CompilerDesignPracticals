%{
#include<stdio.h>
#include<stdlib.h>
%}
/* Rule Section */
%%
[aeiouAEIOU][A-Za-z0-9]* printf("start with vowel");
^[A-Za-z0-9]* printf("not start with vowel");
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
