%{
    #include<stdio.h>
    #include<string.h>
    int ln = 0;
%}

%%
"\n" {}
.* { ln++; fprintf(yyout,"\n%d: %s",ln,yytext);}
%%

int main()
{
    yyin = fopen("input.txt","r");
    yyout = fopen("output.txt","w");
    yylex();
    return 0;
}

int yywrap() {}