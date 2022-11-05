%{
#include<stdio.h>
int sf=0,pf=0;
%}

/* defined section */

%%
"scanf"	{ sf++; fprintf(yyout,"scanf"); }           
"printf" { pf++; fprintf(yyout,"printf");} 
           
%%

int main()
{
	yyin=fopen("input.txt","r");                            
	yyout=fopen("output.txt","w");                           
	yylex();
	fprintf(yyout,"\n Number of scanfs = %d",sf);
    fprintf(yyout,"\n Number of printfs = %d",pf);

return 0;

}

int yywrap() {}