%{#include<stdio.h>
int k=0;
%}

%%
[a-zA-Z]+ {
if(yyleng>k)
{  k= yyleng;
}
printf("%s",yytext);
}
%%

int yywrap()
{}
int main(int argc[],char **argv[])
{
 yyin=fopen("input.txt","r");
 yylex(); 
 
 printf("\nlength of the longest word : %d",k);
 printf("\n");
 return 0;
}
