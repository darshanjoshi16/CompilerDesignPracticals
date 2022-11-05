%{
#include<stdio.h>

%}

/* defined section */

%%
"scanf"	{  fprintf(yyout,"read"); }           
"printf" { fprintf(yyout,"write");} 
           
%%

int main()
{
	yyin=fopen("input.txt","r");                            
	yyout=fopen("output.txt","w");                           
	yylex();
	printf("Task is completed");

return 0;

}

int yywrap() {}