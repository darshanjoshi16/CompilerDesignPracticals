
%{
int flag = 0;
%}

%%
[aeiouAEIOU].[a-zA-Z0-9.]+ {flag=1; fprintf(yyout,"%s",yytext);}
[a-zA-Z0-9]+
%%

int yywrap() {}
main()
{
    yyin = fopen("input.txt","r");
    yyout = fopen("output.txt","w");

yylex();

if (flag == 1)
	printf("Accepted");
else
	printf("Not Accepted");
}
