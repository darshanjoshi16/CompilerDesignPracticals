/*lex code to count the number of lines,tabs and spaces used in the input*/

%{
#include<stdio.h>
int lc=0, sc=0,nc = 0; /*Global variables*/
%}

/*Rule Section*/
%%
"/*"[a-zA-Z0-9\n\t ]*"*/"  {nc++;} //single line comment counnter
"//"[a-zA-Z0-9\t ]*"\n"   {nc++;} // multiline comment counter
\n lc++; //newline counter
([ ])+ sc++; //space counter

%%

int main()
{
	// The function that starts the analysis
	yylex();
	
	printf("\nNo. of newline charcaters=%d\n", lc);
	printf("\nNo. of spaces=%d\n", sc);
	
	printf("\nNo. of comments=%d\n", nc);
	
}
