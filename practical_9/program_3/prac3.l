%{
#include<stdio.h>
int flag=0;
int count=0;
%}
%%

[a-z]+@[a-z]+[".com"|".in"] {flag=1; 
count++; 
fprintf(yyout," valid Email:%s",yytext);
}
[a-z]+@[0-9]+[".com"|".in"] {fprintf(yyout," ");}
%%
int main()
{
yyin = fopen("input.txt","r");
yyout = fopen("output.txt","w");
yylex();
if(flag==0)
    printf("Not valid "); 
else
printf(" Valid Email Id\n");
fprintf(yyout,"\n Valid count: %d",count);

}
int yywrap()
{
return 1;
}