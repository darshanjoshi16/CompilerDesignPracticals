/*lex program to count number of words*/
%{
#include<stdio.h>
#include<string.h>
int i = 0;
int nchars = 0;
%}
  
/* Rules Section*/
%%
([a-zA-Z0-9])*[^ \n\t] {i++; nchars = nchars+yyleng;} /* Rule for counting 
                          number of words*/

  
"\n" {printf("Number of words: %d\n", i); i = 0;
	  printf("Number of characters: %d\n",nchars);}
%%
  
int yywrap(void){}
  
int main()
{   
    // The function that starts the analysis
    yylex();
  
    return 0;
}

