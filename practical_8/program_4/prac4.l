%{
int nlines=1,nwords,nchars;
%}

%%
\n {
	nchars++;nlines++; 
	}
 
[^ \n\t]+ {nwords++, nchars=nchars+yyleng;}
. {nchars++;}
%%
int yywrap(void)  
{
 return 1;
}
int main(int argc, char*argv[]) 
{
	yyin=fopen(argv[1],"r");
    yyout = fopen("output.txt","w");
    yylex();
    printf("Lines = %d\nChars=%d\nWords=%d\n",nlines,nchars,nwords);
 
    fprintf(yyout,"Lines = %d",nlines);
    fprintf(yyout,"\nWords = %d",nwords);
    fprintf(yyout,"\nLetters = %d",nchars);

 return 0;
}
 