%{
    #include<stdio.h>
    int i;
%}
keyword main|int|scanf|printf|if|else

%%
{keyword} {
 for(i=0;i<yyleng;i++)
 fprintf(yyout,"%c",toupper(yytext[i]));  }
%%

main()
{
yyin=fopen("input.txt","r");
yyout = fopen("output.txt","w");
yylex();

}

int yywrap()
{
return 1;
}